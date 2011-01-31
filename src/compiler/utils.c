/** \file utils.c
	\brief 
  */

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

char *getword(FILE *i)
{
	
	int j = 0;
	char c;
	char *word;
	int pos;
	size_t size = 0;

	if(fcpeek(i) == EOF){
		return NULL;
	}
	
	pos = ftell(i);
	c = getc(i);
	if( c == '\n' ){
			total_newlines++;
		}
	//printf("CHECKING: \n\n");
	/* We first calculate the size of the word */
	while ( (c != EOF) && !isspace(c) ){
		/* Read and count new lines and characters */
		
		//printf("%c|", c);
		size++;
		c = getc(i);
		if( c == '\n' ){
			total_newlines++;
		}
		
	}
	//printf("\n\nEND\n\n");
	fseek(i, -(ftell(i) - pos), SEEK_CUR);

	word = (char*)xmalloc(sizeof(char)*size + 1);
	c = getc(i);

	/* Then we copy the word the to malloc'ed space */
	while ( ((c != EOF) && !isspace(c)) && (j < size) ){	
		word[j] = c;
		j++;
		c = getc(i);
	}
	word[size] = '\0';

	
	return word;
}

char *wordpeek(FILE *f)
{
	return NULL;
}

void file_error(char *prog, char *do_this, char *ifilename, char *specifics, char *msg)
{
	fprintf(stderr, "%s: cannot %s %s (%s):\n"
                        "%s.\n", prog, do_this, ifilename, specifics, msg);
	exit(EXIT_FAILURE);
}

char *strip_whitesp(char *str)
{
	return 0;
}


