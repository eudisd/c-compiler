/** \file scanner.c
	\brief Contains all lexical analyzer operations.
  */

#include "scanner.h"

void run_scanner(char *prog, char *filename)
{
	char c;
	char *word;
    
    total_char          = 0; 
	total_newlines      = 0;
	total_char_per_line = 0;
	
	// Remove Comments Here
	
	remove_comments(prog, filename);

	FILE *i = fopen(filename, "r");
	FILE *o = fopen(INTERIM_FILENAME, "w");

	/* getword() returns a string, so a NULL signifies that
     * nothing useful was retrieved from the input stream 
	 */
	while( (word = getword(i)) != NULL ){
		switch(word[0]){
		
			/* First, the possible keyword tokens */
			case 'a':
                /* auto */
				break;
			case 'b':
                /* break */
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
				/* int */
                /* if */
                printf("%s\n", word);
                
                if( !strcmp(word, "int") ) {
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_INT);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                }
                else if ( !strcmp(word, "if") ){
                    sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    sprintf(tk_buffer1, "%d", TK_IF);
                    
                    /* Write out lexeme to output file! */
                    put_lexeme(o, tk_buffer0, tk_buffer1);
                    
                }
                else {
                    char *token = extract_token(word); 
                    size_t step = 0;
                    
                    printf("Token: %s\n", token);
                 
                    //sprintf(tk_buffer0, "%d", TK_KEYWORD);
                    //sprintf(tk_buffer1, "%d", TK_INT);
                    //
                    ///* Write out lexeme to output file! */
                    //put_lexeme(o, tk_buffer0, tk_buffer1);
                
                    free(token);
                    
                }
				
				
				
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
			
			case '%':
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
            
            case ';':
                break;

			/* Constants */

			case '\'':
				break;
		
			/* String Literals */
			case '"':
				break;

			default:
			/* Try To See if it's a identifier, if not: 
			 ERROR! Given token is not part of the lang def. */

				break;
				
		}
		free(word);
	}
	
    printf("Header Inclusion Done.  Total New Lines: %d\n", total_newlines);
	printf("                        Total Characters Read: %d\n", total_char);
	printf("                        Total Characters On This Line Read: %d\n", total_char_per_line);
	
    
	fclose(i);
	fclose(o);
}

void remove_comments(const char *prog, const char *filename)
{

	FILE *i = fopen(filename, "r");
	FILE *o = fopen("data.tmp", "w");
	
	if(!i)
		file_error((char*)prog, "open", (char*)filename, "for removing comments", "No such file or directory.");
	if(!o)
		file_error((char*)prog, "write", (char*)filename, "preproc intermediate file", "Unknown reason(possibly permissions");
	
	/* This code handles the multiline comments removal */
	char c, c_tmp;
	while ( (c = getc(i)) != EOF ){
		
		if( c == '\n' ){
			total_newlines++;
			total_char_per_line = 0;
		}
		
		total_char++;
		total_char_per_line++;
		
		if(c == '/' && (fcpeek(i) == '*')){
			c = getc(i);  /* Holds '*' */
			c = getc(i);  /* Knock that starter '*' off the file discriptor. */
			while( c != EOF ){
				if(c == '*' && fcpeek(i) == '/')
					break;
				c = getc(i);
			}
			
			c = getc(i); /* Pop off the last '*' */
			c = getc(i); /* Pop off the last '/' */
		}
		putc(c, o);
	}

	fclose(i);
	fclose(o);

	remove(filename);
	rename("data.tmp", filename);
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

void put_ulexeme(FILE *o, char *tk_name)
{
	size_t tk_name_size = strlen(tk_name);
	
	putc('<', o);
	fwrite(tk_name, sizeof(char), tk_name_size, o);
	putc('>', o);
}


/* NOTE TO SELF: Still need to handle the multiple character
 * token extractions!! That is, say, '<<' as opposed to '<'
 */

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


