/** \file parser.c
	\brief 
  */
#include "parser.h"

extern file_struct file;

void run_parser()
{
     FILE *i = fopen(INTERIM_FILENAME, "r");


     cur_token = (char*)cstr("!");
     match("1");
}

void match(char *token)
{
     if( token != cur_token ){
         error(file.filename, 0, 0, "Does not match current token!");
     }
     else 
          get_token();
}

void get_token(FILE *i)
{
     char *lexeme = get_lexeme(i);
}

char *get_lexeme(FILE *in)
{
	int i=0, j;
    char *token;
    int pos = ftell(in);
    char c = getc(in);
    if(c == '<' && c != EOF){
        while( (c = getc(in)) != EOF ){
            i++;
            if(c == '>')
                break;
            
        }
    }
    else {
        return NULL;
    }
    
    token = (char*)malloc(sizeof(char)*i + 1);

    fseek(in, pos, SEEK_SET);

    i = 0;

    while( (c = getc(in)) != EOF ){
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



