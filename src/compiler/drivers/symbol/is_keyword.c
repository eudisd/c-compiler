#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define KEYWORD_TOTAL 30

char *keywords[] = {
    "auto", 
	"break",
	"case", 
	"char", 
	"const",
	"continue",
    "default",  
	"do",
	"double",
	"else",
	"extern",
	"float",
	"goto",
    "int",
    "if",
    "long",
	"register",
	"return",
	"short",
	"signed",
	"sizeof",
	"static",
	"struct",
	"switch",
	"typedef",
	"union",
	"unsigned",
	"void",
	"volatile",
	"while" 
};

int is_keyword(char *lexeme);

int main(){
	/* Driver: Test All Cases Test Correctly */
	int i = 0;

	
	for(i = 0; i < KEYWORD_TOTAL; i++){
		/* These should all print '1' for Answer!*/
		printf("Is %s a keyword? Answer: %d\n", keywords[i], is_keyword(keywords[i]));
	}
	return 0;
}

int is_keyword(char *lexeme)
{
	switch(lexeme[0]){
			case 'a':
                /* auto */
				if( !strcmp(lexeme, "auto") )
					return TRUE;
				return FALSE;
			case 'b':
                /* break */
				if( !strcmp(lexeme, "break") )
					return TRUE;
				return FALSE;
			case 'c':
				/* case */
				/* char */
				/* const */
				/* continue */
				if( !strcmp(lexeme, "case")     ||
					!strcmp(lexeme, "char")     ||
					!strcmp(lexeme, "const")    ||
					!strcmp(lexeme, "continue") 
					)
					return TRUE;
				return FALSE;
			case 'd':
				/* default */
				/* do */
				/* double */
				if( !strcmp(lexeme, "default")||
					!strcmp(lexeme, "do")     ||
					!strcmp(lexeme, "double") 
					)
					return TRUE;
				return FALSE;
			case 'e':
				/* else */
				/* enum */
				/* extern */
				if( !strcmp(lexeme, "else")   ||
					!strcmp(lexeme, "enum")   ||
					!strcmp(lexeme, "extern") 
					)
					return TRUE;
				return FALSE;
			case 'f':
				/* float */
				/* for */
				if( !strcmp(lexeme, "float")||
					!strcmp(lexeme, "for")  
					)
					return TRUE;
				return FALSE;
			case 'g':
				/* goto */
				if( !strcmp(lexeme, "goto") )
					return TRUE;
				return FALSE;
	
			case 'i':
				/* int */
                /* if */
                if( !strcmp(lexeme, "int") ||
					!strcmp(lexeme, "if")  
					)
					return TRUE;
				return FALSE;
			case 'l':
				/* long */
				if( !strcmp(lexeme, "long") )
					return TRUE;
				return FALSE;
			case 'r':
				/* register */
				/* return */
				if( !strcmp(lexeme, "register")||
					!strcmp(lexeme, "return")  
					)
					return TRUE;
				return FALSE;
			case 's':
				/* short */
				/* signed */
				/* sizeof */
				/* static */
				/* struct */
				/* switch */
				if( !strcmp(lexeme, "short")   ||
					!strcmp(lexeme, "signed")  ||
					!strcmp(lexeme, "sizeof")  ||
					!strcmp(lexeme, "static")  ||
					!strcmp(lexeme, "struct")  ||
					!strcmp(lexeme, "switch")  
					)
					return TRUE;
				return FALSE;
			case 't':
				/* typedef */
				if( !strcmp(lexeme, "typedef") )
					return TRUE;
				return FALSE;
			case 'u':
				/* union */
				/* unsigned */
				if( !strcmp(lexeme, "union")   ||
					!strcmp(lexeme, "unsigned")   
					)
					return TRUE;
				return FALSE;
			case 'v':
				/* void */
				/* volatile */
				if( !strcmp(lexeme, "void")   ||
					!strcmp(lexeme, "volatile") 
					)
					return TRUE;
				return FALSE;
			case 'w':
				/* while */
				if( !strcmp(lexeme, "while") )
					return TRUE;
				return FALSE;
			default:
				return FALSE;
	}
}
