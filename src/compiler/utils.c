/** \file utils.c
	\brief 
  */

#include "utils.h"

void usage( void )
{
	printf("Usage: c [options] file...\n" 
	       "Options:\n"
		   "  --help\tPrint help screen description.\n"
		   "  --version\tPrint version number.\n"
           "  --verbose\tPrint extra information.\n"
		   "  -o <file>\tSpecify an output file name.\n"
           "  -Sc      \tSpecify the size of the Code Segment (Not Implemented Yet).\n"
           "  -Sd      \tSpecify the size of the Data Segment (Not Implemented Yet).\n"
           "  -Ss      \tSpecify String Symbol Table Hash (Not Implemented Yet).\n"
		   "  -Si      \tSpecify ID Symbol Table Hash (Not Implemented Yet).\n"
		   "  -So      \tPrint VM Assembly to stdout.\n"
		   "\n"
		   );
}

void version( void )
{
	printf("c (C Compiler) %s %d (release) %d - Build: %d\n"
		   "Copyright (c) 2011 Eudis Duran\n"
		   "See LICENSE file for details.\n"
		   ,VERSION, get_build_date(), RELEASE, BUILD_NUMBER);
			
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
	
	/* We first calculate the size of the word */
	while ( (c != EOF) && !isspace(c) ){
		/* Read and count new lines and characters */

        /* This new section handles the string word input count*/
		if ( c == '\"' ){
            size++;
            c = getc(i);
            while( c != '\"' ){

                if( c == '\n' ){
                    error("file-not-known(feature-incomplete)", total_newlines, 0, "Badly formatted string! Exiting\n");
                }

                size++;
                c = getc(i);
               
            }  
        }
		size++;
		c = getc(i);
		if( c == '\n' ){
			total_newlines++;
		}
		
	}
	fseek(i, -(ftell(i) - pos), SEEK_CUR);

	word = (char*)xmalloc(sizeof(char)*size + 1);
   
	c = getc(i);

	/* Then we copy the word the to malloc'ed space */
	while ( ((c != EOF) && !isspace(c)) && (j < size) ){	
        /* This new section handles the new string copy! */
        if ( c == '\"' ){
            word[j] = c;
		    j++;
            c = getc(i);
            word[j] = c;
            
            while( c != '\"' && (j < size) ){
                word[j] = c;
                j++;
                c = getc(i);
            }  
        }
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


int get_build_date()
{
	char buffer[12];
	time_t rtime;
	struct tm *timeinfo;
	
	time( &rtime );
	timeinfo = localtime( &rtime );

	strftime(buffer, 12, "%Y%m%d", timeinfo);
	return atoi(buffer);
}

char *copy_alloced(char *s)
{
	char *t = (char*)xmalloc(sizeof(char)*strlen(s));
	strcpy(t, s);
	return t;
}


int get_column(FILE *i){
	int cur_pos = ftell(i);
	int offset = 0;
	char c = fcpeek(i);

    while( c != '\n' &&  (ftell(i) > 0) && c != EOF){
		fseek(i, -1, SEEK_CUR);
		offset++;
		c = fcpeek(i);
	}	
	fseek(i, cur_pos, SEEK_CUR);
	return offset;
}

int intlit_comp(const void *a, const void *b)
{
    if( *(int*)a > *(int*)b ) return 1;
    if( *(int*)a == *(int*)b ) return 0;
    if( *(int*)a < *(int*)b ) return -1;
}

int floatlit_comp(const void *a, const void *b)
{
    if( *(double*)a > *(double*)b ) return 1;
    if( *(double*)a == *(double*)b ) return 0;
    if( *(double*)a < *(double*)b ) return -1;
}

char *cstr(char *s)
{
     char *tmp = (char*)xmalloc(sizeof(char)*strlen(s) + 1);
     strcpy(tmp, s);
     return tmp;
}




