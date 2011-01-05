#include "preprocessor.h"


void run_preprocessor(const char *ifilename, const char *ofilename)
{
	int state;
	char c;
	const int IN = 0, OUT = 1;
	
	FILE *f, *o;

	f = fopen("tmp.txt", "r");
	o = fopen("out.data", "w");
		
	remove_comments(f, o);
	
	fclose(f);
	fclose(o);
}



void remove_comments(FILE *f, FILE *o)
{

	/* These next few lines handle the multiline comments removal */
	char c, c_tmp;
	while ( (c = getc(f)) != EOF ){
		if(c == '/' && (fcpeek(f) == '*')){
			c_tmp = getc(f);  /* Holds '*' */
			c_tmp = getc(f);  /* Knock that starter '*' off the file discriptor. */

			while( ( (c_tmp != '*') && (fcpeek(f) != '/') ) && (c_tmp != EOF)){
				c_tmp = getc(f);
			}
			c =  getc(f); /* Holds '*' */
			c =  getc(f); /* Again, know the starter '*' off the file discriptor. */
		}
		putc(c, o);
	}
}




char *get_define_value(char *line)
{
	return NULL;
}
