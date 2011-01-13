/** \file scanner.h 
    \brief Lists the associativity and precedence of all tokens
	
	in order of precedence, with the defines at the top with the highest
	The defines here are grouped in order of associativity, and listed
	and with descending precedence as we go down.
	
	The rest are token values for keywords and the like.
  */

#ifndef _SCANNER_H_
#define _SCANNER_H_

/* Token Defininitions */

/* Scope */
#define TK_LEFTBRACKET  
#define TK_RIGHTBRACKET 

/* Left To Right Associativity */
#define TK_LEFTPAREN    
#define TK_RIGHTPAREN   
#define TK_LEFT_SQR_BRACKET   
#define TK_RIGHT_SQR_BRACKET
#define TK_DOT          
   
/* Right To Left Associativity */
#define TK_UNARY_EXCLAMATION  
#define TK_UNARY_TILDA        
#define TK_UNARY_PLUSPLUS     
#define TK_UNARY_MINUSMINUS   
#define TK_UNARY_PLUS         
#define TK_UNARY_MINUS        
#define TK_UNARY_STAR   
#define TK_UNARY_AMPERSAND    
#define TK_UNARY_CASTING      
#define TK_UNARY_SIZEOF    

/* Left To Right Associativity */
#define TK_MULT_STAR 
#define TK_DIV          
#define TK_MOD  

/* Left To Right Associativity */
#define TK_PLUS
#define TK_MINUS

/* Left To Right Associativity */
#define TK_LEFT_SHIFT
#define TK_RIGHT_SHIFT

/* Left To Right Associativity */
#define TK_LESS_LOGIC
#define TK_RIGHT_LOGIC
#define TK_RIGHT_EQU_LOGIC
#define TK_LEFT_EQU_LOGIC

/* Left To Right Associativity */
#define TK_EQU_EQU_LOGIC
#define TK_NOT_EQU_LOGIC

/* Left To Right Associativity */
#define TK_BIT_AMPERSAND
#define TK_BIT_XOR
#define TK_BIT_OR

/* Left To Right Associativity */
#define TK_LOGIC_AND
#define TK_LOGIC_OR

/* Left To Right Associativity */
#define TK_QUESTION
#define TK_COLON

/* Right To Left Associativity */
#define TK_EQU
#define TK_PLUS_EQU
#define TK_MINUS_EQU
#define TK_STAR_EQU
#define TK_DIV_EQU
#define TK_MOD_EQU
#define TK_AND_EQU
#define TK_XOR_EQU
#define TK_OR_EQU
#define TK_LSHIFT_EQU
#define TK_RSHIFT_EQU

/* Left To Right Associativity */
#define TK_COMMA

/* Precedence and Associative Irrelavent */

#define TK_KEYWORD
#define TK_IDENTIFIER
#define TK_CONST  
#define TK_STRING

/* ************************************* */

#define TK_AUTO
#define TK_BREAK
#define TK_CASE
#define TK_CHAR
#define TK_CONST
#define TK_CONTINUE
#define TK_DEFAULT
#define TK_DO
#define TK_DOUBLE
#define TK_ELSE
#define TK_ENUM
#define TK_EXTERN
#define TK_FLOAT
#define TK_FOR
#define TK_GOTO
#define TK_IF
#define TK_INT
#define TK_LONG
#define TK_REGISTER
#define TK_RETURN
#define TK_SHORT
#define TK_SIGNED
#define TK_SIZEOF
#define TK_STATIC
#define TK_STRUCT
#define TK_SWITCH
#define TK_TYPEDEF
#define TK_UNION
#define TK_UNSIGNED
#define TK_VOID
#define TK_VOLATILE
#define TK_WHILE


#endif