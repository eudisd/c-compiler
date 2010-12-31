#include "error.h"

void error(char* file, int line, int column, char *msg){
	printf("%s:%d:%d: error: %s", file, line, column, msg);
}

void warning(char* file, int line, int column, char *msg){
	printf("%s:%d:%d: warning: %s", file, line, column, msg);
}

int get_line(char *file){
	return 0;
}

int get_column(char *file){
	return 0;
}


