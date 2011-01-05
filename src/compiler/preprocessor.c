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
		
	while( (c = getc(f)) != EOF ){
		if(c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
		}
		else {
			state = IN;
		}
		if (state == IN && c == '#'){
			c = getc(f);
		
		}
	}
	
	fclose(f);
	fclose(o);
}

char *get_next_word(FILE *f)
{
	return NULL;
}
char *get_define_value(char *line)
{
	return NULL;
}
