/** \file scanner.h 
    \brief Lists the associativity and precedence of all tokens
	
	The defines here are grouped in order of associativity, and listed
	in order of precedence, with the defines at the top with the highest
	and with descending precedence as we go down.
	
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


        


   
#define 

#endif