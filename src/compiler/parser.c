/** \file parser.c
	\brief 
  */
#include "parser.h"

FILE *input; /**> Global File Discriptor */
FILE *output; /**> Global File Discriptor */

short data_count = 0; /**> Used to determine the size of the data output */
short code_count = 0; /**> Used to determine the size of the code output */

void run_parser()
{
     input = fopen(INTERIM_FILENAME, "r");
     output = fopen(file.default_o, "wb");

     if( input == NULL ){
         error(file.filename, 0, 0, "Error processing interim file, exiting...");
     }

     /*
     cur_token = get_token(input);
     while( NULL != cur_token ){
         printf("cur_token: %s\n", cur_token);
         cur_token = get_token(input);
     }*/

     cur_token = get_token();


     //Declarations();
     //CProgram();
     //E();

     /* Write out Data Segment */

     /* Write out Code Segment */
     fwrite(&code_count, sizeof(short), 1, output);

     close(input);
     close(output);




     


}

void match(char *token)
{
     if( cur_token != NULL ){
         token_package tk = get_sval(token);
         printf("cur_token: %s, Token Name: %d, tk.val: %d\n", cur_token, get_token_name(cur_token), tk.val);
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
     if( cur_token != NULL ){
         if( token != get_token_name(cur_token) ){
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
      Declarations();
      MainEntry();
}


void Statements()
{
    E();
    match(";");
}


void Declarations()
{
    IntDec();
    FloatDec();
    CharDec();
}

void IntDec()
{
    int tk = get_token_name(cur_token);
    if( tk == TK_INT ){
        matchi(TK_IDENTIFIER);
        match(",");
        IntDec();
    }
    else if( tk == TK_SEMICOLON ){
        match(";");
    }
}

void FloatDec()
{
  
}

void CharDec()
{

}
void MainEntry()
{
     int tk = get_token_name(cur_token);


     if( tk == TK_INT ){
         match("int");
         /* Main is in the symbol table, so I must get the index first */
         int index = get_token_value(cur_token);

         if(strcmp(id_table->table[index].name, "main") == 0){
            cur_token = get_token();
         }
         else {
            fprintf(stderr, "Entry point not specified!  Exiting...\n");
            exit(EXIT_FAILURE);
         }

         match("(");
         // Command Line Arguments
         match(")");

         match("{");
         // Block Begin
         match("return");
           Statements();
         match("}");
     }
     else {
        fprintf(stderr, "main() must return int!  Exiting...\n");
        exit(EXIT_FAILURE);
     }
}




TYPE E()
{
     TYPE t = T(); 
     TYPE t2 = EPrime();
     
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
         
         printf("add\n");
         inst.opcode = OP_ADD;
         inst.operand.i = 0;
         fwrite(&inst, sizeof(Instruction), 1, output);
          
         /* I write code, so I increment counter */
         code_count++;
            
         
         EPrime();
     }
     else if ( tk == TK_MINUS ){
         match("-");
         t = T();
         /* (-) */
         printf("sub\n");
         inst.opcode = OP_SUB;
         inst.operand.i = 0;
         
         fwrite(&inst, sizeof(Instruction), 1, output);
         /* I write code, so I increment counter */
         code_count++;

         
         EPrime();
     }
     else if ( tk == TK_LOGIC_OR ){
         match("||");
         t = T();
         printf("or\n");

         inst.opcode = OP_OR;
         inst.operand.i = 0;
         
         fwrite(&inst, sizeof(Instruction), 1, output);
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

TYPE TPrime()
{
     int tk = get_token_name(cur_token);
     Instruction inst;
     TYPE t;

     if( tk == TK_MULT_STAR ){
         match("*");
         t = T();
         printf("mul\n");
         /* (*) : Need to implement this! */

         inst.opcode = OP_MUL;
         inst.operand.i = 0;
         
         fwrite(&inst, sizeof(Instruction), 1, output);
         /* I write code, so I increment counter */
         code_count++;
        
         TPrime();
     }
     else if ( tk == TK_DIV ){
         match("/");
         t = T();
         printf("div\n");
         /* (/) : Need to implement this! */
         inst.opcode = OP_DIV;
         inst.operand.i = 0;
         
         fwrite(&inst, sizeof(Instruction), 1, output);
         /* I write code, so I increment counter */
         code_count++;
         
         
         TPrime();
     }
     else if ( tk == TK_LOGIC_AND ){
         match("&&");
         t = T();
         printf("and\n");
         /* (&&) : Need to implement this! */
         inst.opcode = OP_AND;
         inst.operand.i = 0;
         
         fwrite(&inst, sizeof(Instruction), 1, output);
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
     }
     else if ( tk == TK_INTLIT ){
       // generate pushi

       printf("pushi %d\n", get_token_value(cur_token) );

       inst.opcode = OP_PUSHI;
       inst.operand.i = get_token_value(cur_token);
       fwrite(&inst, sizeof(Instruction), 1, output);
       /* I write code, so I increment counter */
       code_count++;


       cur_token = get_token();
       return 'I';
     }
     else if ( tk == TK_STRINGLIT ){
       
     }
     else if ( tk == TK_FLOATLIT ){
      // generate pushi 
        
       printf("pushi %f\n", get_token_value_f(cur_token) );

       inst.opcode = OP_PUSHI;
       inst.operand.f = get_token_value(cur_token);
       fwrite(&inst, sizeof(Instruction), 1, output);
      
       code_count++;

       cur_token = get_token(); 
        
       return 'R';
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
          if( t == 'I' || t == 'R' )
              return t;
          else {
               // Type error 
          }
     }
     else if ( tk == TK_MINUS ){
       match("-");
       TYPE t = F();
       if ( t == 'I' || t == 'R' )
          return t;
       else {
            // Type error
       }
     }

     else if ( tk == TK_MULT_STAR ){
       match("*");
       TYPE t = F();
       if ( t == 'I' || t == 'R' )
          return t;
       else {
            // Type error
       }
     }
     else if ( tk == TK_DIV ){
       match("/");
       TYPE t = F();
       if ( t == 'I' || t == 'R' )
          return t;
       else {
            // Type error
       }
     }
     else if ( tk == TK_LOGIC_AND ){
       match("&&");
       TYPE t = F();
       if ( t == 'I' || t == 'B' )
          return t;
       else {
            // Type error
       }
     }
     else if ( tk == TK_LOGIC_OR ){
       match("||");
       TYPE t = F();
       if ( t == 'I' || t == 'B' )
          return t;
       else {
            // Type error
       }
     }

     else if ( tk == TK_UNARY_EXCLAMATION ){ // TK_NOT 
     }
     else {
       
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






