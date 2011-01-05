#include "utils.h"

void usage( void )
{
	printf("Usage: c [options] file...\n" 
	       "Options:\n"
		   "  --help\t\t\t Print help screen description\n"
		   "  --target-help\t\t\t Print target specific help information\n"
		   "  --version\t\t\t Print version number\n"
		   "  -o <file>\t\t\t Specify a file name"
		   "\n"
		   );
}

void version( void )
{
	printf("c (C Compiler) %s %d (release) %d - Build: %d\n"
		   "Copyright (c) 2010 Eudis Duran\n"
		   "See LICENSE file for details.\n"
		   ,VERSION, BUILD_DATE, RELEASE, BUILD_NUMBER);
			
}

char *scan_for_o(int argc, char *argv[])
{
	int i;
	for(i = 0; i < argc; i++){
		if(strcmp(argv[i], "-o") == 0){
			return argv[i + 1];
		}
	}
}

char **get_files_from_argv(int argc, char *argv[])
{

}

int get_filesize(char *filename)
{
	FILE *f = fopen(filename, "r");
	fseek(f, 0, SEEK_END);
	return ftell(f);	
}

void *xmalloc(int size)
{
	register void *value = malloc(size);
	if (value == NULL){
		fprintf(stderr, "Virtual Memory Exhausted!\n");
		exit(1);
	}
	else {
		return value;
	}
}

char fcpeek(FILE *f)
{
	char c = getc(f);
	ungetc(c, f);
	return c;
}

char *getword(FILE *f)
{
	return NULL;
}

char *wordpeek(FILE *f)
{
	return NULL;
}

