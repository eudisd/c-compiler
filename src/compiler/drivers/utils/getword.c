#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>

char *getword(FILE *i);
size_t total_newlines;
int main()
{
	char *name;
	FILE *f = fopen("tmp.txt", "r");
	
	printf("%s\n", getword(f));
	printf("%s\n", getword(f));
    printf("%s\n", getword(f));
	printf("%s\n", getword(f));
    printf("%s\n", getword(f));
    printf("%s\n", getword(f));
	printf("%s\n", getword(f));
    printf("%s\n", getword(f));
	printf("%s\n", getword(f));
    printf("%s\n", getword(f));
    printf("%s\n", getword(f));
	printf("%s\n", getword(f));
    printf("%s\n", getword(f));
	printf("%s\n", getword(f));
    printf("%s\n", getword(f));

	return 0;
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
			//total_newlines++;
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
                    printf("String error!\n");
                    exit(EXIT_FAILURE);
                }

                size++;
                c = getc(i);
               
            }  
        }
		size++;
		c = getc(i);
		if( c == '\n' ){
			//total_newlines++;
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
