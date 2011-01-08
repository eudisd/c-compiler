#include "preprocessor.h"


void run_preprocessor(const char *prog, const char *ifilename, const char *ofilename)
{
	/* First we import all included header files into the current c 
       file and output an intermediary file.  
     */
	//include_headers(prog, ifilename, ofilename);

	/* Then we remove all C-Style comments from the file*/
	remove_comments(prog, ifilename, ofilename);

	
	
	
}



void remove_comments(const char *prog, const char *ifilename, const char *ofilename)
{
	

	FILE *i = fopen(ifilename, "r");
	FILE *o = fopen(ofilename, "w");

	if(!i){
		fprintf(stderr, "%s: cannot open %s (for removing comments):\n No such file or directory.\n", prog, ifilename);
		exit(EXIT_FAILURE);
	}
	if(!o){
		fprintf(stderr, "%s: cannot write %s (preproc intermediate file): \n Unknown reason(possibly permissions).\n", prog, ofilename);
		exit(EXIT_FAILURE);
	}

	/* These next few lines handle the multiline comments removal */
	char c, c_tmp;
	while ( (c = getc(i)) != EOF ){
		if(c == '/' && (fcpeek(i) == '*')){
			c_tmp = getc(i);  /* Holds '*' */
			c_tmp = getc(i);  /* Knock that starter '*' off the file discriptor. */

			while( ( (c_tmp != '*') && (fcpeek(i) != '/') ) && (c_tmp != EOF)){
				c_tmp = getc(i);
			}
			c =  getc(i); /* Holds '*' */
			c =  getc(i); /* Again, know the starter '*' off the file discriptor. */
		}
		putc(c, o);
	}

	fclose(i);
	fclose(o);
}


void include_headers(const char *prog, const char *ifilename, const char *ofilename)
{
	FILE *i = fopen(ifilename, "r");
	FILE *o = fopen(ofilename, "w");

	if(!i){
		fprintf(stderr, "%s: cannot open %s (for removing inserting headers):\n No such file or directory.\n", prog, ifilename);
		exit(EXIT_FAILURE);
	}
	if(!o){
		fprintf(stderr, "%s: cannot write %s (preproc intermediate file): \n Unknown reason(possibly permissions).\n", prog, ofilename);
		exit(EXIT_FAILURE);
	}

	/* Stuff Goes Here */

	fclose(i);
	fclose(o);
}

char *get_define_value(char *line)
{
	return NULL;
}
