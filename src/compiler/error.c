/** \file error.c
	\brief 
  */

#include "error.h"

void error(char* file, int line, int column, char *msg){
	printf("\n%s:%d:%d: error: %s\n", file, line, column, msg);
	exit(EXIT_FAILURE);
}

void warning(char* file, int line, int column, char *msg){
	printf("\n%s:%d:%d: warning: %s\n", file, line, column, msg);
}




