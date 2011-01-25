#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../utils.h"

int is_valid_id(char *word);
char *extract_token(char *word);
char *return_keyword(char *word);

int main()
{
	//char ar[] =  "int;";
	//printf("%c\n", ar[3]);
	printf("keyword: '%s'\n\n", extract_token("(int"));
	return 0;
}

char *extract_token(char *word)
{
	switch(word[0]){
		case '{':
			return "{";
		case '}':
			return "}";
		case '(':
			return "(";
		case ')':
			return ")";
		case ']':
			return "]";
		case '[':
			return "[";
		case '.':
			return ".";
		case '!':
			return "!";
		case '~':
			return "~";
				/* ~ */
				/* ~= */
		case '+':
			return "+";
			/* + */
			/* ++ */
			/* += */
		case '-':
			return "-";
			/* - */
			/* -- */
			/* -= */
		case '*':
			return "*";
			/* * */
			/* *= */
		case '&':
			return "&";
			/* & */
			/* && */
			/* &= */
		case '/':
			return "/";
			/* / */
			/* /= */	
		case '%':
			return "%";
			/* % */
			/* %= */
		case '<':
			return "<";
			/* < */
			/* << */
			/* <= */
			/* <<= */
		case '>':
			return ">";
			/* > */
			/* >> */
			/* >= */
			/* >>= */			
		case '=':
			return "=";
			/* = */
			/* == */
		case '|':
			return "|";
			/* | */
			/* || */
			/* |= */
		case '^':
			return "^";
			/* ^ */
			/* ^= */
		case '?':
			return "?";
		case ':':
			return ":";
		case ';':
			return ";";
		/* Constants */

		case '\'':
			return "'";
		/* String Literals */
		/* Questioning if this even belongs here?*/
		case '"':
			return "\"";
			break;
		
		default:
			return return_keyword(word);
			break;
		
		
	}
    return NULL;
}

char *return_keyword(char *word)
{
	
	size_t size = strlen(word);
	int i;
	printf("\n");
	for(i = 0; i < size; i++){
		if( !isdigit(word[i]) && !isalpha(word[i]) && word[i] != '_'){
			break;	
		}
	}
	/* 'i' is the size of the valid keyword or id */
	char *keyword = (char *)xmalloc(sizeof(char)* i  + 1);
	
	strcpy(keyword, word);
	keyword[i] = '\0';
	
	return keyword;
	
}


int is_valid_id(char *word)
{
	size_t size = strlen(word);
	
	int j;
	for(j = 0; j < size; j++){
		if( !isalpha(word[j]) && !isdigit(word[j]) && word[j] != '_' ){
			
			return 0;
		}
		
	}
	

	return size;
}

