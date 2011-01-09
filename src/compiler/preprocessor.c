#include "preprocessor.h"


void run_preprocessor(const char *prog, const char *ifilename, const char *ofilename)
{
	/* First we import all included header files into the current c 
       file and output an intermediary file.  
     */
	include_headers(prog, ifilename, ofilename);

	/* Then we remove all C-Style comments from the file*/
	//remove_comments(prog, ifilename);

	
	
	
}

void include_headers(const char *prog, const char *ifilename, const char *ofilename)
{
	char c;
	char *inc_fname;
	char *inc_keyword;
	char *fname;

	FILE *i = fopen(ifilename, "r");
	FILE *o = fopen(ofilename, "w");

	if(!i){
		fprintf(stderr, "%s: cannot open %s (for removing inserting headers):\n"
                        "No such file or directory.\n", prog, ifilename);
		exit(EXIT_FAILURE);
	}
	if(!o){
		fprintf(stderr, "%s: cannot write %s (preproc intermediate file): \n"
                        "Unknown reason(possibly permissions).\n", prog, ofilename);
		exit(EXIT_FAILURE);
	}
	
	/* Here we write out the included file to the intermediary preprocessor file */
	while( (c = getc(i)) != EOF ){
		if(c == '#' && (fcpeek(i) == 'i')){
			inc_keyword = getword(i);
			inc_fname = (char*)get_inc_fname((char*)getword(i));

			printf("%s = ", inc_keyword);
			printf("'%s' \n", inc_fname);
			
			
			
			
			free(inc_keyword);
			free(inc_fname);	
			//free(fname);
			

			/*
			c = getc(i);
			while( c != EOF && c != '\n' ){
				if( fcpeek(i) == '<' ){
					inc_fname = get_inc_fname(i);
					printf("%s\n", inc_fname);
					exit(1);
				}
				c = getc(i);
			}*/
		}
	}
	

	fclose(i);
	fclose(o);
}



void remove_comments(const char *prog, const char *filename)
{

	FILE *i = fopen(filename, "r");
	FILE *o = fopen("data", "w");
	
	if(!i){
		fprintf(stderr, "%s: cannot open %s (for removing comments):\n No such file or directory.\n", prog, filename);
		exit(EXIT_FAILURE);
	}
	if(!o){
		fprintf(stderr, "%s: cannot write %s (preproc intermediate file): \n"
                        "Unknown reason(possibly permissions).\n", prog, filename);
		exit(EXIT_FAILURE);
	}
	

	/* This code handles the multiline comments removal */
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

	remove(filename);
	rename("data", filename);
}

char *get_inc_fname(char *n)
{
	int i;
	size_t size = strlen(n);
	char *new_word = (char*)xmalloc(sizeof(char)*(size-2)); /* + 1 for the '\0' terminator */
	
	
	for(i = 0; i < (size-2); i++){
		new_word[i] = n[i+1];
		
	}

	new_word[size-2] = '\0';
	free(n);
	return new_word;
}


char *get_define_value(char *line)
{
	return NULL;
}
