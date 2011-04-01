/** \file parser.c
	\brief 
  */
#include "parser.h"

FILE *input; /**> Global File Discriptor */
FILE *output; /**> Global File Discriptor */

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

     E();

     close(input);
     close(output);



     /* Write out Data Segment */

     /* Write out Code Segment */

}

void match(char *token)
{
     if( cur_token != NULL ){
         token_package tk = get_sval(token);
         /*printf("cur_token: %d, tk: %d\n", get_token_name(cur_token), tk.val); */
         if( tk.val != get_token_name(cur_token) ){

             error(file.filename, 0, 0, "Does not match current token!");
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

TYPE E()
{
     TYPE t = T(); 
     EPrime();

     /*
     int tk = get_token_name(cur_token);

     while(tk == TK_PLUS ||
           tk == TK_MINUS ||
           tk == TK_LOGIC_OR){
           int op = tk;
           printf("%d\n", tk);
           matchi(op);
           T();
           }*/
           /* (op) */




}

void EPrime()
{
     int tk = get_token_name(cur_token);

     if( tk == TK_PLUS ){
         match("+");
         T();
         /* (+) */
         fprintf(output, "add\n");
         EPrime();
     }
     else if ( tk == TK_MINUS ){
         match("-");
         T();
         /* (-) */
         fprintf(output, "minus\n");
         EPrime();
     }
     else if ( tk == TK_LOGIC_OR ){
         match("||");
         T();
         fprintf(output, "or\n");
         /* (||) */
         EPrime();
     }
     else {
       
     }
}

TYPE T()
{
     F();
     TPrime();
}

void TPrime()
{
     int tk = get_token_name(cur_token);
     if( tk == TK_MULT_STAR ){
         match("*");
         T();
         printf("mul\n");
         /* (*) : Need to implement this! */
         TPrime();
     }
     else if ( tk == TK_DIV ){
         match("/");
         T();
         printf("div\n");
         /* (/) : Need to implement this! */
         TPrime();
     }
     else if ( tk == TK_LOGIC_AND ){
         match("&&");
         T();
         printf("and\n");
         /* (&&) : Need to implement this! */
         TPrime();
     }
     else {

     }
}

TYPE F()
{
     int tk = get_token_name(cur_token);

     if( tk == TK_IDENTIFIER ){
       // Get type from stab
       // genarate push
       // return type
     }
     else if ( tk == TK_INTLIT ){
       // generate pushi
       char *tmp = "pushi\n";

       fprintf(output, "pushi %d\n", get_token_value(cur_token) );
       cur_token = get_token();
       return 'I';
     }
     else if ( tk == TK_STRINGLIT ){
       
     }
     else if ( tk == TK_FLOATLIT ){
       // generate pushf
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

int get_token_name(char *lexeme)
{
    if(lexeme == NULL){
        return -1;
    }

    int start = 1;

    int end = 0;

    int i = 0;
    while(end < strlen(lexeme)){
        if( lexeme[end] == ',' ){
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






