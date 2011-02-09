/** \file scanner.h 
  * \brief Lists the associativity and precedence of all tokens.
  *
  * This is done i order of precedence, with the defines at the top with the highest.
  *
  * The defines here are grouped in order of associativity, and listed
  *	with descending precedence as we go down.
  *
  * The rest are token values for keywords and the like.
  *
  * Everything else normally in a header file comes after.
  */

#ifndef _SCANNER_H_
#define _SCANNER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utils.h"

/*------------------------- Globals -------------------------*/


extern size_t total_newlines;

static char tk_buffer0[5]; /**> Used to write the interger values of lexemes below as strings (easier). */
static char tk_buffer1[5];   


/* Token Defininitions */
        


/* Scope */
#define TK_LEFTBRACKET         0
#define TK_RIGHTBRACKET        1

/* Left To Right Associativity */
#define TK_LEFTPAREN    	   2
#define TK_RIGHTPAREN   	   3
#define TK_LEFT_SQR_BRACKET    4
#define TK_RIGHT_SQR_BRACKET   5
#define TK_DOT                 6
   
/* Right To Left Associativity */
#define TK_UNARY_EXCLAMATION   7
#define TK_UNARY_TILDA         8
#define TK_UNARY_PLUSPLUS      9 
#define TK_UNARY_MINUSMINUS    10
#define TK_UNARY_PLUS          11
#define TK_UNARY_MINUS         12
#define TK_UNARY_STAR          13
#define TK_UNARY_AMPERSAND     14
#define TK_UNARY_CASTING       15
#define TK_UNARY_SIZEOF        16

/* Left To Right Associativity */
#define TK_MULT_STAR           17
#define TK_DIV                 18
#define TK_MOD                 19

/* Left To Right Associativity */
#define TK_PLUS     		   20
#define TK_MINUS   			   21

/* Left To Right Associativity */
#define TK_LEFT_SHIFT  		   22
#define TK_RIGHT_SHIFT   	   23

/* Left To Right Associativity */
#define TK_LESS_LOGIC  		   24
#define TK_RIGHT_LOGIC 		   25
#define TK_RIGHT_EQU_LOGIC 	   26
#define TK_LEFT_EQU_LOGIC 	   27

/* Left To Right Associativity */
#define TK_EQU_EQU_LOGIC	   28
#define TK_NOT_EQU_LOGIC	   29

/* Left To Right Associativity */  
#define TK_BIT_AMPERSAND       30
#define TK_BIT_XOR  		   31
#define TK_BIT_OR  			   32

/* Left To Right Associativity */
#define TK_LOGIC_AND		   33
#define TK_LOGIC_OR		       34

/* Left To Right Associativity */ 
#define TK_QUESTION  		   35
#define TK_COLON 			   36

/* Right To Left Associativity */
#define TK_EQU				   37
#define TK_PLUS_EQU  		   38
#define TK_MINUS_EQU   		   39
#define TK_STAR_EQU  		   40
#define TK_DIV_EQU  		   41
#define TK_MOD_EQU			   42
#define TK_AND_EQU    	 	   43
#define TK_XOR_EQU			   44
#define TK_OR_EQU  			   45
#define TK_LSHIFT_EQU  		   46
#define TK_RSHIFT_EQU  		   47

/* Left To Right Associativity */
#define TK_COMMA			   48

/* Precedence and Associative Irrelavent */

#define TK_KEYWORD			   49
#define TK_IDENTIFIER		   50
#define TK_CONSTANT    	       51
#define TK_STRING			   52

/* ************************************* */

/* Keywords/Reserved */

#define TK_AUTO			       53
#define TK_BREAK			   54
#define TK_CASE			       55
#define TK_CHAR				   56
#define TK_CONST		       57
#define TK_CONTINUE			   58
#define TK_DEFAULT  		   59
#define TK_DO  				   60
#define TK_DOUBLE		       61
#define TK_ELSE			       62
#define TK_ENUM				   63
#define TK_EXTERN			   64
#define TK_FLOAT			   65
#define TK_FOR				   66
#define TK_GOTO 			   67
#define TK_IF  				   68
#define TK_INT				   69
#define TK_LONG 			   70
#define TK_REGISTER			   71
#define TK_RETURN			   72
#define TK_SHORT			   73
#define TK_SIGNED			   74
#define TK_SIZEOF			   75
#define TK_STATIC			   76
#define TK_STRUCT			   77
#define TK_SWITCH			   78
#define TK_TYPEDEF			   79
#define TK_UNION			   80
#define TK_UNSIGNED			   81
#define TK_VOID				   82
#define TK_VOLATILE			   83
#define TK_WHILE			   84


/*------------------------- Globals -------------------------*/


size_t total_char;           /**>  Initialize total character count counter */
size_t total_char_per_line;
size_t total_newlines;       /**>  Initialize newlines, to ready counter    */



/*------------------- Function Prototoypes -------------------*/



/** High level scanner encapsulator.
  */
void run_scanner(file_struct *file);

/** Writes a lexeme out to file, given a name-value pair.
  */
void put_lexeme(FILE *o, char *tk_name, char *tk_value);

/** Writes a uanry lexeme out to file, given a name.
  */
void put_ulexeme(FILE *o, char *tk_name);

/** Tests if the given word is a valid C symbol, or identifier.
  *	If false, returns 0, if true returns the size of the identifier.
  *	This is useful because we can use the size to handle the function
  *	case, in which an identifier can have '(' directly concatenated (no space)
  * with the identifier.  (i.e.  main() vs main () )
  *
  * This function also _RESETS_ the file pointer to where it was at
  * the beginning of the call.
  */
int is_valid_id(char *word);

/**
  */
int parse_tokens(char *word);

/**
  */
char *extract_token(char *word);

/** _MUST_ be freed. BUT THERE IS A PROBLEM.  We cannont free this 
	function freely as it returns constant strings in multiple cases! 
    Must fix this bug.
  */
char *return_keyword(char *word);

/* This is part of the parser! (FIX IT LATER)*/

/** Gets a lexeme.  _MUST_ be freed after use.
  */
//char *get_lexeme(FILE *i)

/** Given a lexeme, returns the ID part.  _MUST_ be freed after call.
  */
//char *get_valid_id(char *lexeme);

/** Given a lexeme, returns the NAME part.  _MUST_ be freed after call.
  */
//char *get_token_name(char *lexeme);






#endif
