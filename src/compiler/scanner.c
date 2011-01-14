/** \file scanner.c
	\brief Contains all lexical analyzer operations.
  */

#include "scanner.h"

void run_scanner(char *filename)
{
	char c;

	FILE *i = fopen(filename, "r");
	FILE *o = fopen(INTERIM_FILENAME, "w");
	
	while( (c = fcpeek(i)) != EOF ){
		switch(c){

			/* First, the possible keyword tokens */
			case 'a':
				break;
			case 'b':
				break;
			case 'c':
				/* case */
				/* char */
				/* const */
				/* continue */
				break;
			
			case 'd':
				/* default */
				/* do */
				/* double */
				break;

			case 'e':
				/* else */
				/* enum */
				/* extern */
				break;
			case 'f':
				/* float */
				/* for */
				break;

			case 'g':
				/* goto */
				break;
	
			case 'i':
				/* if */
				/* int */
				break;

			case 'l':
				/* long */
				break;
			
			case 'r':
				/* register */
				/* return */
				break;
		
			case 's':
				/* short */
				/* signed */
				/* sizeof */
				/* static */
				/* struct */
				/* switch */
				break;

			case 't':
				/* typedef */
				break;

			case 'u':
				/* union */
				/* unsigned */
				break;

			case 'v':
				/* void */
				/* volatile */
				break;

			case 'w':
				/* while */
				break;

			/* Now, we deal with other tokens (operators, constants, id's, etc) */

			case '{':
				break;

			case '}':
				break;

			case '(':
				/* ( */
				/* (casting) */
				break;

			case ')':
				break;

			case ']':
				break;

			case '[':
				break;

			case '.':
				break;

			case '!':
				break;

			case '~':
				/* ~ */
				/* ~= */
				break;
			
			case '+':
				/* + */
				/* ++ */
				/* += */
				break;

			case '-':
				/* - */
				/* -- */
				/* -= */
				break;

			case '*':
				/* * */
				/* *= */
				break;

			case '&':
				/* & */
				/* && */
				/* &= */
				break;

			case '/':
				/* / */
				/* /= */
				break;
			
			case '%'::
				/* % */
				/* %= */
				break;

			case '<':
				/* < */
				/* << */
				/* <= */
				/* <<= */
				break;

			case '>':
				/* > */
				/* >> */
				/* >= */
				/* >>= */			
				break;

			case '=':
				/* = */
				/* == */
				break;

			case '|':
				/* | */
				/* || */
				/* |= */
				break;

			case '^':
				/* ^ */
				/* ^= */
				break;

			case '?':
				break;

			case ':':
				break;

			/* Constants */

			case ''':
				break;
		
			/* String Literals */
			case '"':
				break;

			default:

			/* ERROR! Given token is not part of the lang def */

				break;
				
		}
	}
}

void put_lexeme(FILE *o, char *tk_name, char *tk_value)
{
	size_t tk_name_size = strlen(tk_name);
	size_t tk_value_size = strlen(tk_value);
	
	putc('<', o);
	fwrite(tk_name, sizeof(char), tk_name_size, o);
	putc(',', o);
	fwrite(tk_value, sizeof(char), tk_value_size, o);
	putc('>', o);
}



/* This is part of the parser! */
/*
char *get_lexeme(FILE *i)
{
	return NULL;
}

char *get_valid_id(char *lexeme)
{
	return NULL;
}

char *get_token_name(char *lexeme)
{
	return NULL;
}
*/


