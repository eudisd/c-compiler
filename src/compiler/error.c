/** \file error.c
	\brief 
  */

#include "error.h"

void error(char* file, int line, int column, char *msg){
	printf("%s:%d:%d: error: %s", file, line, column, msg);
	exit(EXIT_FAILURE);
}

void warning(char* file, int line, int column, char *msg){
	printf("%s:%d:%d: warning: %s", file, line, column, msg);
}




