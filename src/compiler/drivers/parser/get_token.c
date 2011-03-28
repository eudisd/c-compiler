#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *get_lexeme(FILE *i);
int get_token_name(char *lexeme);
char *get_token_value(char *lexeme);

int main()
{
    char *tk_stream = "<10,20><30,40><50,60>";
    FILE *in = fopen("test.c", "rb");

    char *token = get_lexeme(in);

    printf("\n\nGet Token: '%s', token_name: %d, token_value: %d\n\n", token, get_token_name(token), get_token_value(token) );
    token = get_lexeme(in);

    printf("\n\nGet Token: '%s', token_name: %d, token_value: %d\n\n", token, get_token_name(token), get_token_value(token) );
    free(token);

    token = get_lexeme(in);

    printf("\n\nGet Token: '%s', token_name: %d, token_value: %d\n\n", token, get_token_name(token), get_token_value(token) );
    token = get_lexeme(in);

    printf("\n\nGet Token: '%s', token_name: %d, token_value: %d\n\n", token, get_token_name(token), get_token_value(token) );

    

    return 0;
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

char *get_token_value(char *lexeme)
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
