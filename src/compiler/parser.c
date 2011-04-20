/** \file parser.c
	\brief 
  */
#include "parser.h"

FILE *input; /**> Global File Discriptor */
FILE *output; /**> Global File Discriptor */

short data_max = 1024; /**>  Default is 1kb, could be more */
short code_max = 1024; /**>  Default is 1kb, could be more  */

short code_count = 0;
short data_count = 0;

Instruction *code; /**> Code is be dynamically allocated too */

char *data;

int dec_rollback = 0;
int str_start = 0; /**> Holds the begining position of statically allocated strings */

void run_parser()
{
     input = fopen(INTERIM_FILENAME, "r");
     output = fopen(file.default_o, "wb");

     if( input == NULL ){
         error(file.filename, 0, 0, "Error processing interim file, exiting...");
     }

     code = (Instruction*)malloc(sizeof(Instruction)*code_max);
     data = (char*)malloc(sizeof(char)*data_max);
     /*
     int c;
     printf("Code Segment: ");
     for(c = 0; c < code_max; c++){
        printf("%x ", data[c]);
     }*/
    
     /* Clear both data and code segment */
     memset(code, 0, sizeof(Instruction)*code_max);
     memset(data, 0, sizeof(char)*data_max);


     //cur_token = get_token();
     
     //Declarations();
     Statements();
	 /*
     int i;
    	for(i = 0; i < code_count; i++)
        	printf("opcode: %d, operand: %d\n", code[i].opcode, code[i].operand.i);		
      */
		
     //CProgram();
     
     //E();
     //L();

     printf("code_count: %d, data_count: %d\n", code_count, data_max);

     /* Write Out Data */
     fwrite(data, sizeof(char), data_max, output);

     /* Write Out Code */
     fwrite(code, sizeof(Instruction), code_count, output);

     /* Write out Static Data Segment Size */
     fwrite(&data_count, sizeof(short), 1, output);

     /* Write out Data Segment Size */
     fwrite(&data_max, sizeof(short), 1, output);

     /* Write out Code Segment Size */
     fwrite(&code_count, sizeof(short), 1, output);

     free(code);
     close(input);
     close(output);

}

void match(char *token)
{
     if( cur_token != NULL ){
         token_package tk = get_sval(token);
         //printf("match: %s, Token Name: %d, tk.val: %d\n", cur_token, get_token_name(cur_token), tk.val);
         /*printf("cur_token: %d, tk: %d\n", get_token_name(cur_token), tk.val); */
         if( tk.val != get_token_name(cur_token) ){
             error(file.filename, 0, 0, "Token mismatch!");
         }
         else {
			 
             free(cur_token);
             cur_token = get_token();
         }
     }

}

void matchi(int token)
{
     int tk = get_token_name(cur_token);
     //printf("match: %s, Token Name: %d, tk: %d\n", cur_token, get_token_name(cur_token), tk);
     if( cur_token != NULL ){
         if( token != tk ){
             error(file.filename, 0, 0, "Does not match current token!");
         }
         else {
             free(cur_token);
             cur_token = get_token();

         }
     }

}


TYPE CProgram()
{
      cur_token = get_token();  /* INITIAL CUR_TOKEN CALL */
      Declarations();
      MainEntry();
}


void MainEntry()
{
	 if(cur_token == NULL){
		fprintf(stderr, "\nFile Is Empty!  Exiting...\n\n");
        exit(EXIT_FAILURE);
	 }
     int tk = get_token_name(cur_token);


     if( tk == TK_INT ){
         match("int");

         /* Main is in the symbol table, so I must get the index first */
         int index = get_token_value(cur_token);

         if(strcmp(id_table->table[index].name, "main") == 0){
            id_table->table[index].addr = -1;
            id_table->table[index].type = 'P';
            cur_token = get_token();
         }
         else {
            print_stab(id_table);
            fprintf(stderr, "Possible collision in symbol table! (Bug)\n"
                            "Apparently 'y2' == 'main' LOL\n");
            fprintf(stderr, "Entry point not specified!  Exiting...\n");
            exit(EXIT_FAILURE);
         }

         match("(");
         // Command Line Arguments
         match(")");

         match("{");

         Declarations();
         Statements();

         match("}");
     }
     else {
        fprintf(stderr, "main() must return int!  Exiting...\n");
        exit(EXIT_FAILURE);
     }
}

void Statements()
{
	if(cur_token == NULL){
		return;
	}
    int tk = get_token_name(cur_token);
    
    if( tk == TK_IDENTIFIER ){
		Label();
			
        Assignment();
        Statements();
    }
    else if (tk == TK_WHILE ){
        While();
        Statements();
    }
    else if (tk == TK_FOR){

    }
    else if (tk == TK_SWITCH) {

    }
    else if (tk == TK_FUNCTION_CALL) {

    }
    else if (tk == TK_GOTO) {
		Goto();
		Statements();
    }
    else if (tk == TK_IF){
        IfStatement();
        Statements();
    }
    else if (tk == TK_DO){
        DoWhile();
        Statements();   
    }
    else if (tk == TK_PRINTF){
        
        Instruction inst;

        free(cur_token);
        cur_token = get_token();

        int tk = get_token_name(cur_token);
       
        if (tk == TK_IDENTIFIER){
            
            // Save Type And Address
            int index = get_token_value(cur_token);
            TYPE id_type = id_table->table[index].type;
            int id_addr = id_table->table[index].addr;

            matchi(TK_IDENTIFIER);
            match(";");

            printf("%d: writeintid @%s (Type: %c)\n", code_count, id_table->table[index].name, id_type);

            /* Encode the address into the instruction */
            inst.opcode = OP_WRITEINTID;
            if ( id_type == 'I' ){
                inst.operand.i = id_addr; /* Int */
                code[code_count] = inst;
            }
            else if (id_type == 'C'){
                inst.operand.i = id_addr; /* Char */
                code[code_count] = inst;
            }
            else if (id_type == 'F'){
                inst.opcode = OP_WRITEFLOAT;
                inst.operand.i = id_addr; /* Float */
                code[code_count] = inst;
            }

            code_count++;
        }
        
        else {
            char *peek = peek_next_token();
            int tk2 = get_token_name(peek);
            int str_flag = -1;

            if (tk2 == TK_STRINGLIT){
                str_flag = 0;
            }
            free(peek);

            TYPE t = E();
            match(";");
        
            
            
            // generate print
            

            /* Encode the address into the instruction */
            if( str_flag == 0 ){
                inst.opcode = OP_WRITESTRING;
                printf("%d: writestring @%d\n", code_count, str_start);
                inst.operand.i = str_start;
                code[code_count] = inst;
                code_count++;                
            }
            else if ( t == 'I' ){
                inst.opcode = OP_WRITEINT;
                printf("%d: writeint\n", code_count);
                inst.operand.i = 0;
                code[code_count] = inst;
                code_count++;
            }
            else if (t == 'C'){
                inst.opcode = OP_WRITEINT;
                inst.operand.i = 0;
                code[code_count] = inst;
                code_count++;
            }
            else if (t == 'F'){
                printf("%d: writefloat\n", code_count);
                inst.opcode = OP_WRITEFLOAT;
                inst.operand.i = 0;
                code[code_count] = inst;
                code_count++;
            }

            
        }
        Statements();
    }
    else if (tk == TK_INTLIT ){
        fprintf(stderr, "Singular expression without assignment found! Exiting\n");
        exit(EXIT_SUCCESS);
    }

    

}

void Label()
{	
	char *peek = peek_next_token();
	int tk = get_token_name(peek);
	Instruction inst_hole;

	int hole, save;

	if (tk == TK_COLON){
		int index = get_token_value(cur_token);

		/* First, we check and see if the label has been seen or not already */
		if( id_table->table[index].seen == 0 ){
			printf("\nSee: %d\n", id_table->table[index].addr);
			if (id_table->table[index].addr == -1){
				id_table->table[index].addr = code_count;
			}
			else {
				
				code[id_table->table[index].addr].operand.i = code_count;
				id_table->table[index].seen = 1;
			}
			id_table->table[index].seen = 1;
					
		}		
		

		matchi(TK_IDENTIFIER);
		match(":");
		
		if(peek != NULL){
			free(peek);
		}
		

		Statements();

		
	}
	else {
		if(peek != NULL){
			free(peek);
		}
		return;
	}
	
}
void Goto()
{
	if( cur_token == NULL ){
		return;
	}

	match("goto");

	int index = get_token_value(cur_token);
	Instruction inst_hole;
	int hole;

	/* The label has been seen, so we just generate the actual address jump! */
	if( id_table->table[index].seen == 1 ){
		printf("%d: jmp @%d \n", code_count, id_table->table[index].addr);
		inst_hole.opcode = OP_JMP;
		inst_hole.operand.i = id_table->table[index].addr;
		code[code_count] = inst_hole;
		code_count++;
	}
	/* Generate Dummy Jump here, since the label has not been seen */
	else {
		hole = code_count;
		printf("%d: jmp 0 (Hole)\n", code_count);
		inst_hole.opcode = OP_JMP;
		inst_hole.operand.i = hole; /* Store the hole so that we can restore it later */
		code[hole] = inst_hole;
		code_count++;
		id_table->table[index].addr = hole; 

	}

	matchi(TK_IDENTIFIER);
	match(";");
}

void DoWhile()
{
    int target = code_count;
    Instruction inst;

    match("do");
    match("{");
        Statements();
    match("}");
    match("while");
    match("(");
    TYPE t = L();
    if (t != 'I' && t != 'C'){
        fprintf(stderr, "\n'do-while' conditional expression must be of integer type! Exiting...\n\n");
        exit(EXIT_FAILURE);
    }
    inst.opcode = OP_JTRUE;
    inst.operand.i = target;
    code[code_count] = inst;
    printf("%d: jfalse %d\n", code_count, target);
    code_count++;
    
    match(")");
    match(";");
}

void While()
{
    int target = code_count;
    int hole, save;
    Instruction inst, inst_hole;

    match("while");
    match("(");
    TYPE t = L();
    if( t != 'I' && t != 'C' ){
        fprintf(stderr, "\n'while' conditional expression must be of integer type! Exiting...\n\n");
        exit(EXIT_FAILURE);
    }
    
    hole = code_count;
    inst_hole.opcode = OP_JFALSE;
    inst_hole.operand.i = 0;
    code[code_count] = inst_hole;
    printf("%d: jfalse %d\n", code_count, target);
    code_count++;
    

    match(")");
    match("{");
        Statements();

        inst.opcode = OP_JMP;
        inst.operand.i = target;
        code[code_count] = inst;
        printf("%d: jmp %d\n", code_count, target);
        code_count++;
    
        /* Fill in hole */
        save = code_count;
        code[hole].operand.i = save;

    match("}");

    int i;
    for(i = 0; i < code_count; i++)
        printf("opcode: %d, operand: %d\n", code[i].opcode, code[i].operand.i);
        
    
}

void IfStatement()
{
    Instruction inst;
    int save;
    int hole; 

    match("if");
    match("(");
     TYPE t = L();
     if( t != 'I' && t != 'C' ){
        fprintf(stderr, "\n'if' conditional expression must be of integer type! Exiting...\n\n");
        exit(EXIT_FAILURE);
     }
    
     
    match(")");
    match("{");
     
     hole = code_count;
     /* Generate Code (but don't write it out yet) */
     inst.opcode = OP_JFALSE;
     inst.operand.i = 0;
     code[code_count] = inst;
     printf("%d: jfalse 0\n", code_count);
     code_count++;

    
     Statements();
    match("}");
    int tk = get_token_name(cur_token);
    if(tk == TK_ELSE){
        Instruction inst2;

        save = code_count;

        code[hole].operand.i = save;
        
        inst2.opcode = OP_JTRUE;
        inst2.operand.i = 0;  // Dummy jmp
       
        hole = code_count; /* The hole comes after the jmp */
        code[code_count] = inst2;
       
        printf("%d: jtrue 0\n", code_count);

        code_count++;

        match("else");
        match("{");
         Statements();
        match("}");
    }

    save = code_count;
    code_count = hole;
    code[hole].operand.i = save;
    code_count = save;

    //int i;
    //for(i = 0; i < code_count; i++)
    //    printf("opcode: %d, operand: %d\n", code[i].opcode, code[i].operand.i);
    
    /* Once the else is done, we pop off the value in the
       stack that holds the conditional result */

    Instruction inst3;
    inst3.opcode = OP_POPEMPTY;
    inst3.operand.i = 0;
    code[code_count] = inst3;
    code_count++;
    printf("%d: pop (Empty)\n", code_count);
}

void Assignment()
{
	if (cur_token == NULL){
		return;
	}
    // Save Type And Address
    int index = get_token_value(cur_token);
    TYPE id_type = id_table->table[index].type;
    int id_addr = id_table->table[index].addr;
    
    Instruction inst;

    free(cur_token);
    cur_token = get_token();
    match("=");
    TYPE t = E();
    match(";");
    // Pop at an address!

    printf("%d: pop @%s (Type: %c)\n", code_count, id_table->table[index].name, id_type);

        /* Encode the address into the instruction */
    inst.opcode = OP_POP;
    if ( id_type == 'I' ){
        inst.operand.i = id_addr; /* Int */
        code[code_count] = inst;
    }
    else if (id_type == 'C'){
        inst.operand.i = id_addr; /* Char */
        code[code_count] = inst;
    }
    else if (id_type == 'F'){
        inst.opcode = OP_POPF;
        inst.operand.i = id_addr; /* Float */
        code[code_count] = inst;
    }

    code_count++;
        
    
}

void Declarations()
{
	if(cur_token == NULL){
		return;
	}
    //printf("\n\n");
    //printf("CUR_TOKEN: %s\n", cur_token);
    
    int tk = get_token_name(cur_token);
   
    
    //printf("Initial Dec: %d\n", dec_rollback);

    if( tk == TK_INT ){
        if( IntDec() != -1 ) { //Exit loop
            Declarations();
        }
        
    }
    
    else if (tk == TK_FLOAT){
        if( FloatDec() != -1 ) { //Exit loop
            Declarations();
        }
    }
    else if (tk == TK_CHAR){
        if( CharDec() != -1 ) { //Exit loop
            Declarations();
        }
    }
    
}

int IntDec()
{
    int tk = get_token_name(cur_token);
    if( tk == TK_INT ){
        
        match("int");

        /* We store the current token first, since we need to test
           if the token indeed matches an ID first before we can operate 
           on the ID table 
           */
        char *tmp = (char*)cstr(cur_token);

        matchi(TK_IDENTIFIER);

    
        /* Test to see that it's not a function */
        if( get_token_name(cur_token) == TK_LEFTPAREN ){
            //printf("\nLooking at the current(int)\n");
            fseek(input, dec_rollback, SEEK_SET);
            free(cur_token);
            cur_token = get_token();
            //printf("now: %s\n", cur_token);
            free(tmp);
            return -1;
        }
        

        int index = get_token_value(tmp);
        printf("\nStoring Identifier: %s at address: %d\n", id_table->table[index].name, dp);

        /* Here I modify the symbol table to account for type and address */
        id_table->table[index].addr = dp;
        id_table->table[index].type = 'I';

        dp += 4;
        
        /* Test here to see if the next token is not = to ',' or not = ot ';'
           then throw error */
    
        int tmp_tk = get_token_name(cur_token);
        if( tmp_tk != TK_COMMA && tmp_tk != TK_SEMICOLON ){
            fprintf(stderr, "Error in 'int' declaration! Exiting...\n");
            exit(EXIT_FAILURE);
        }

        free(tmp);
        
        return IntDec();
    }
    else if( tk == TK_COMMA ){
        match(",");

        char *tmp = (char*)cstr(cur_token);

        matchi(TK_IDENTIFIER);
        
        int index = get_token_value(tmp);
        printf("\nStoring Identifier: %s at address: %d\n", id_table->table[index].name, dp);

        /* Here I modify the symbol table to account for type and address */
        id_table->table[index].addr = dp;
        id_table->table[index].type = 'I';

        dp += 4;

        /* Test here to see if the next token is not = to ',' or not = ot ';'
           then throw error if not */
    
        int tmp_tk = get_token_name(cur_token);
        if( tmp_tk != TK_COMMA && tmp_tk != TK_SEMICOLON ){
            fprintf(stderr, "Error in 'int' declaration! Exiting...\n");
            exit(EXIT_FAILURE);
        }

        free(tmp);
        return IntDec();
    }
    else if (tk == TK_SEMICOLON){
        
        dec_rollback = ftell(input);
        match(";");
        return 0;
    }
    else {
        printf("Error (Int Declaration Part)!\n");
        exit(EXIT_FAILURE);
    }
}

int FloatDec()
{
    int tk = get_token_name(cur_token);
    if( tk == TK_FLOAT ){
        match("float");

        char *tmp = (char*)cstr(cur_token);

        matchi(TK_IDENTIFIER);

        /* Test to see that it's not a function */
        if( get_token_name(cur_token) == TK_LEFTPAREN ){
            
            fseek(input, dec_rollback, SEEK_SET);
            free(cur_token);
            cur_token = get_token();
            //printf("now: %s\n", cur_token);
            free(tmp);
            return -1;
        }

        int index = get_token_value(tmp);
        printf("\nStoring Identifier: %s at address: %d\n", id_table->table[index].name, dp);

        id_table->table[index].addr = dp;
        id_table->table[index].type = 'F';

        dp += 4;

        int tmp_tk = get_token_name(cur_token);
        if( tmp_tk != TK_COMMA && tmp_tk != TK_SEMICOLON ){
            fprintf(stderr, "Error in 'float' declaration! Exiting...\n");
            exit(EXIT_FAILURE);
        }

        free(tmp);
        FloatDec();
    }
    else if( tk == TK_COMMA ){
        match(",");

        char *tmp = (char*)cstr(cur_token);

        matchi(TK_IDENTIFIER);
        
        int index = get_token_value(tmp);
        printf("\nStoring Identifier: %s at address: %d\n", id_table->table[index].name, dp);
        
        id_table->table[index].addr = dp;
        id_table->table[index].type = 'F';

        dp += 4;

        int tmp_tk = get_token_name(cur_token);
        if( tmp_tk != TK_COMMA && tmp_tk != TK_SEMICOLON ){
            fprintf(stderr, "Error in 'float' declaration! Exiting...\n");
            exit(EXIT_FAILURE);
        }

        free(tmp);
        FloatDec();
    }
    else if (tk == TK_SEMICOLON){
        dec_rollback = ftell(input);
        match(";");
        return 0;
    }
    else {
        printf("Error (Float Declaration Part)!\n");
        exit(EXIT_FAILURE);
    }
}

int CharDec()
{
    int tk = get_token_name(cur_token);
    if( tk == TK_CHAR ){
        match("char");

        char *tmp = (char*)cstr(cur_token);

        matchi(TK_IDENTIFIER);


        /* Test to see that it's not a function */
        if( get_token_name(cur_token) == TK_LEFTPAREN ){
            
            fseek(input, dec_rollback, SEEK_SET);
            free(cur_token);
            cur_token = get_token();
            //printf("now: %s\n", cur_token);
            free(tmp);
            return -1;
        }

        int index = get_token_value(tmp);
        printf("\nStoring Identifier: %s at address: %d\n", id_table->table[index].name, dp);
        
        id_table->table[index].addr = dp;
        id_table->table[index].type = 'C';

        dp += 1;

        int tmp_tk = get_token_name(cur_token);
        if( tmp_tk != TK_COMMA && tmp_tk != TK_SEMICOLON ){
            fprintf(stderr, "Error in 'char' declaration! Exiting...\n");
            exit(EXIT_FAILURE);
        }

        free(tmp);
        CharDec();
    }
    else if( tk == TK_COMMA ){
        match(",");

        char *tmp = (char*)cstr(cur_token);

        matchi(TK_IDENTIFIER);
        
        int index = get_token_value(tmp);
        printf("\nStoring Identifier: %s at address: %d\n", id_table->table[index].name, dp);

        id_table->table[index].addr = dp;
        id_table->table[index].type = 'C';


        dp += 1;

        int tmp_tk = get_token_name(cur_token);
        if( tmp_tk != TK_COMMA && tmp_tk != TK_SEMICOLON ){
            fprintf(stderr, "Error in 'char' declaration! Exiting...\n");
            exit(EXIT_FAILURE);
        }

        free(tmp);
        CharDec();
    }
    else if (tk == TK_SEMICOLON){
        dec_rollback = ftell(input);
        match(";");
        return 0;
    }
    else {
        printf("Error (Char Declaration Part)!\n");
        exit(EXIT_FAILURE);
    }
}





TYPE E()
{
     TYPE t = T(); 
     TYPE t2 = EPrime();
     return t;
}

TYPE EPrime()
{
     Instruction inst;
     int tk = get_token_name(cur_token);
     TYPE t = -1;

     if( tk == TK_PLUS ){
         match("+");
         t = T();
         /* (+) */
         if( t == 'I' ){
            printf("%d: add\n", code_count);
            inst.opcode = OP_ADD;
            inst.operand.i = 0;
            code[code_count] = inst;
         }
         else if( t == 'F' ){
            printf("%d: addf\n", code_count);
            inst.opcode = OP_ADDF;
            inst.operand.i = 0;
            code[code_count] = inst;
         }
          
         /* I write code, so I increment counter */
         code_count++;
            
         
         EPrime();
     }
     else if ( tk == TK_MINUS ){
         match("-");
         t = T();
         /* (-) */
         printf("%d: sub\n", code_count);
         inst.opcode = OP_SUB;
         inst.operand.i = 0;
         
         code[code_count] = inst;
         /* I write code, so I increment counter */
         code_count++;

         
         EPrime();
     }
     else if ( tk == TK_LOGIC_OR ){
         match("||");
         t = T();
         printf("%d: or\n", code_count);

         inst.opcode = OP_OR;
         inst.operand.i = 0;
         
         code[code_count] = inst;
         /* I write code, so I increment counter */
         code_count++;

         
         /* (||) */
         EPrime();
     }
     
     return t;
}

TYPE T()
{
     TYPE t = F();
     TYPE t2 = TPrime();
     //printf("Type1: %c, Type2: %c, %d, %d\n", t, t2, t, t2);
     return t;
}

TYPE L()
{
    TYPE t = E();
    TYPE t2 = LPrime();
}


TYPE LPrime()
{
    int tk = get_token_name(cur_token);
    TYPE t;
    Instruction inst;
    if( tk == TK_LESS_LOGIC ){
        match("<");
        t = L();
        printf("%d: lss\n", code_count);
        /* (<) */
        inst.opcode = OP_LSS;
        inst.operand.i = 0;
         
        code[code_count] = inst;
        /* I write code, so I increment counter */
        code_count++;
        LPrime();
    }
    else if( tk == TK_GREATER_LOGIC ){
        match(">");
        t = L();
        printf("%d: gtr\n", code_count);
        /* (>) */
        inst.opcode = OP_GTR;
        inst.operand.i = 0;
         
        code[code_count] = inst;
        /* I write code, so I increment counter */
        code_count++;
        LPrime();
    }
    else if( tk == TK_LESS_EQU_LOGIC ){
        match("<=");
        t = L();
        printf("%d: leq\n", code_count);
        /* (<=) */
        inst.opcode = OP_LEQ;
        inst.operand.i = 0;
         
        code[code_count] = inst;
        /* I write code, so I increment counter */
        code_count++;
        LPrime();
    }
    else if( tk == TK_GREATER_EQU_LOGIC ){
        match(">=");
        t = L();
        printf("%d: geq\n", code_count);
        /* (>=) */
        inst.opcode = OP_GEQ;
        inst.operand.i = 0;
         
        code[code_count] = inst;
        
        code_count++;
        LPrime();
    }
    else if( tk == TK_NOT_EQU_LOGIC ){
        match("!=");
        t = L();
        printf("%d: neq\n", code_count);
        /* (!=) */
        inst.opcode = OP_NEQ;
        inst.operand.i = 0;
         
        code[code_count] = inst;
        /* I write code, so I increment counter */
        code_count++;
        LPrime();
    }
    else if( tk == TK_EQU_EQU_LOGIC ){
        match("==");
        t = L();
        printf("%d: equ\n", code_count);
        /* (==) */
        inst.opcode = OP_EQU;
        inst.operand.i = 0;
         
        code[code_count] = inst;
        /* I write code, so I increment counter */
        code_count++;
        LPrime();
    }
    
    return t;
}

TYPE TPrime()
{
     int tk = get_token_name(cur_token);
     Instruction inst;
     TYPE t;

     if( tk == TK_MULT_STAR ){
         match("*");
         t = T();
         printf("%d: mul\n", code_count);
         /* (*) : Need to implement this! */

         inst.opcode = OP_MUL;
         inst.operand.i = 0;
         
         code[code_count] = inst;
         /* I write code, so I increment counter */
         code_count++;
        
         TPrime();
     }
     else if ( tk == TK_DIV ){
         match("/");
         t = T();
         printf("%d: div\n", code_count);
         /* (/) : Need to implement this! */
         inst.opcode = OP_DIV;
         inst.operand.i = 0;
         
         code[code_count] = inst;
         /* I write code, so I increment counter */
         code_count++;
         
         
         TPrime();
     }
     else if ( tk == TK_LOGIC_AND ){
         match("&&");
         t = T();
         printf("%d: and\n", code_count);
         /* (&&) : Need to implement this! */
         inst.opcode = OP_AND;
         inst.operand.i = 0;
         
         code[code_count] = inst;
         /* I write code, so I increment counter */
         code_count++;
         
         TPrime();
     }
     return t;
}

TYPE F()
{
     int tk = get_token_name(cur_token);
     Instruction inst;
     
     if( tk == TK_IDENTIFIER ){
       // Get type from stab
       // genarate push
       // return type
        int index = get_token_value(cur_token);
        TYPE id_type = id_table->table[index].type;
        int id_addr = id_table->table[index].addr;

        printf("%d: push @%s (Type: %c)\n", code_count, id_table->table[index].name, id_type);
        
        /* Encode the address into the instruction */
        inst.opcode = OP_PUSH;
        if ( id_type == 'I' ){
            inst.operand.i = id_addr; /* Int */
            code[code_count] = inst;
        }
        else if (id_type == 'C'){
            inst.operand.i = id_addr; /* Char */
            code[code_count] = inst;
        }
        else if (id_type == 'F'){
            inst.opcode = OP_PUSHF;
            inst.operand.i = id_addr; /* Float */
            code[code_count] = inst;
        }

        code_count++;
        
        free(cur_token);
        cur_token = get_token();
        
        return id_table->table[index].type;
     }
     else if ( tk == TK_INTLIT ){
       // generate pushi

       printf("%d: pushi %d (Type: %c)\n", code_count, get_token_value(cur_token), 'I' );

       inst.opcode = OP_PUSHI;
       inst.operand.i = get_token_value(cur_token);
       code[code_count] = inst;
       
       /* I write code, so I increment counter */
       code_count++;

       free(cur_token);
       cur_token = get_token();
       return 'I';
     }
     else if ( tk == TK_STRINGLIT ){
            
            int index = 0; //get_token_value(cur_token);
            matchi(TK_STRINGLIT);
            
            int i;

            str_start = data_count;
          

            for(i = 1; i < strlen(string_table->table[index].name) - 1; i++){
                //printf("%x ", string_table->table[index].name[i]);
			/*
                data[data_count] = string_table->table[index].name[i];
                data_count++;*/
            }
            /* These strings are null terminated, just like in real C. */
            data_count++;
            
            /*
            int c;
            printf("Code Segment: ");
            for(c = 0; c < code_max; c++){
                printf("%x ", data[c]);
            }*/

            /* Put the string in the proper data segment */
			exit(-1);

            return 'S';
     }
     else if ( tk == TK_FLOATLIT ){
      // generate pushi 
        
       printf("%d: pushi %f (Type: %c)\n", code_count, get_token_value_f(cur_token), 'F' );

       inst.opcode = OP_PUSHI;
       inst.operand.f = get_token_value_f(cur_token);
       
       code[code_count] = inst;
      
       code_count++;

       free(cur_token);
       cur_token = get_token(); 
        
       return 'F';
     }
     else if ( tk == TK_LEFTPAREN ){
          match("(");

          TYPE t = E();

          match(")");
          return t;  
     }
     else if ( tk == TK_PLUS ){
          match("+");
          // Generate add

          TYPE t = F();
          if( t == 'I' || t == 'F' )
              return t;
          else {
               // Type error 
          }
     }
     else if ( tk == TK_MINUS ){
       match("-");
       TYPE t = F();

       if( t == 'I' ){
           printf("%d: neg\n", code_count);

           inst.opcode = OP_NEG;
           inst.operand.i = 0;
           code[code_count] = inst;
       
           code_count++;
           return t;
       }
       if (t == 'F'){

           printf("%d: negf\n", code_count);

           inst.opcode = OP_NEGF;
           inst.operand.i = 0;
           code[code_count] = inst;
       
           code_count++;
           return t;
       }
        
       else {
            // Type error
       }
     }

     else if ( tk == TK_MULT_STAR ){
       match("*");
       TYPE t = F();
       if ( t == 'I' || t == 'F' )
          return t;
       else {
            // Type error
       }
     }
     else if ( tk == TK_DIV ){
       match("/");
       TYPE t = F();
       if ( t == 'I' || t == 'F' )
          return t;
       else {
            // Type error
       }
     }
     else if ( tk == TK_LOGIC_AND ){
       match("&&");
       TYPE t = F();
       if ( t == 'I' || t == 'C' )
          return t;
       else {
            // Type error
       }
     }
     else if ( tk == TK_LOGIC_OR ){
       match("||");
       TYPE t = F();
       if ( t == 'I' || t == 'C' )
          return t;
       else {
            // Type error
       }
     }

     else if ( tk == TK_UNARY_EXCLAMATION ){ // TK_NOT 
     }
     else {
       return 'V'; // Return VOID
     }
}

char *get_token()
{
	int i=0, j;
    char *token;
    int pos = ftell(input);
    char c = getc(input);
    if(c == '<' && c != EOF){
        while( (c = getc(input)) != EOF ){
            i++;
            if(c == '>')
                break;
            
        }
    }
    else {
        return NULL;
    }
    
    token = (char*)malloc(sizeof(char)*i + 1);

    fseek(input, pos, SEEK_SET);

    i = 0;

    while( (c = getc(input)) != EOF ){
        token[i] = c;
        i++;
        if(c == '>')
            break;
            
    }

    token[i] = '\0';
    return token;
}

int get_token_value(char *lexeme)
{
	if(lexeme == NULL){
        return -1;
    }

    int k = 0;
    while( lexeme[k] != ',' ){
        k++;
    }
    
    int start = k + 1;

    int end = 0;

    int i = 0;
    while(end < strlen(lexeme)){
        if( lexeme[end] == '>' ){
            break;
        }
        end++;
    }

    char *tmp = (char*)malloc(sizeof(char)*(end - start)+1);
    int j;

    for(j = 0; j < (end - start + 1); j ++){
        tmp[j] = lexeme[start + j];
    }
    tmp[(end - start)] = '\0';
    
    int x = atoi(tmp);
    free(tmp);

	return x;
}

float get_token_value_f(char *lexeme)
{
	if(lexeme == NULL){
        return -1;
    }

    int k = 0;
    while( lexeme[k] != ',' ){
        k++;
    }
    
    int start = k + 1;

    int end = 0;

    int i = 0;
    while(end < strlen(lexeme)){
        if( lexeme[end] == '>' ){
            break;
        }
        end++;
    }

    char *tmp = (char*)malloc(sizeof(char)*(end - start)+1);
    int j;

    for(j = 0; j < (end - start + 1); j ++){
        tmp[j] = lexeme[start + j];
    }
    tmp[(end - start)] = '\0';
    
    float x = atof(tmp);
    free(tmp);

	return x;
}

int get_token_name(char *lexeme)
{
    if(lexeme == NULL){
        return -1;
    }

    int start = 1;

    int end = 0;

    int i = 0;
    while(end < strlen(lexeme)){
        if( lexeme[end] == ',' || lexeme[end] == '>'){
            break;
        }
        end++;
    }

    char *tmp = (char*)malloc(sizeof(char)*(end - start)+1);
    int j;

    for(j = 0; j < (end - start + 1); j ++){
        tmp[j] = lexeme[start + j];
    }
    tmp[(end - start)] = '\0';

    int x = atoi(tmp);
    free(tmp);

	return x;
}

char *peek_next_token()
{
    int pos = ftell(input);
    char *tmp = get_token();
    fseek(input, pos, SEEK_SET);
    return tmp;
}






