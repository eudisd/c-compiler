#include "preprocessor.h"

const char *ident[MAX_PREPROC_IDENT] = {"define", "include"};

void run_preprocessor(const char *ifilename, const char *ofilename)
{
	int state;
	char c;
	const int IN = 0, OUT = 1;
	
	FILE *f, *o;

	f = fopen("tmp.txt", "r");
	o = fopen("out.data", "w");
		
	
	
	fclose(f);
	fclose(o);
}

char *get_next_word(FILE *f)
{
	return NULL;
}

void remove_comments(FILE *f, FILE *o)
{
	char c;
	while ( (c = getc(f)) != EOF) ){
		
		putc(c, o);
	}
}




char *get_define_value(char *line)
{
	return NULL;
}
