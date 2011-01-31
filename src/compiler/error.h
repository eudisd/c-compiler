/** \file error.h
	\brief Header file containing all of the error handling primatives for the compiler.
           These primatives are for error output in terms of the runtime compiler, not the 
           development environment for this code.
  */
	
#ifndef _ERROR_H_
#define _ERROR_H_

#include <stdio.h>
#include <stdlib.h>

enum {
	  TYPE_ERR,
	  TOKEN_ERR,
	  SYNTAX_ERR,
	  TYPE_WARN,
	  TOKEN_WARN,
	  SYNTAX_WARN
	};
	

size_t lines;
size_t columns;

/** Prints an error message in standard UNIX(GNU/GCC) format
*/
inline void error(char* file, int line, int column, char *msg);
/** Prints an warning message in standard UNIX(GNU/GCC) format
*/
inline void warning(char* file, int line, int column, char *msg);

/** Get the line number where the error occurred.
*/
inline int get_line(FILE *i);

/** Get the column number where the error occurred.
*/
inline int get_column(FILE *i);


	  
#endif
