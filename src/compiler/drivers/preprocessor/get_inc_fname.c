#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "../../utils.h"

char *get_inc_fname(FILE *i);

int main()
{
	char *name;
	FILE *f = fopen("tmp.txt", "r");
	name = get_inc_fname(f);
	printf("%s\n", name);
	return 0;
}


char *get_inc_fname(FILE *i)
{
	int j = 0;
	char c;
	char *name;
	
	int size = 0;
	int pos; /**> Used to save the start position of the filestream.
                  Will be reverted after size is calculated */

	pos = ftell(i);
	printf("Start file-p position: %d\n", (int)ftell(i));

	while( (c = getc(i)) != EOF ){  /* The 'c' here begins at position 0 of the filename string. */
		
		if( c == '<' ){
			c = getc(i); /* Do not count '<' as it's not part of the string 
                            name, so pop it off the stream */
			while( (c != EOF) && (c != '>') ){
				size++;
				c = getc(i);
			}
			break;
		}
	}

	printf("Size of filename string is: %d\n", size);
	printf("Current file-p position: %d\n", (int)ftell(i));
	fseek(i, -(ftell(i)-pos), SEEK_CUR);
	printf("Reset the file-p position to: %d\n", (int)ftell(i));

	name = (char*)malloc(sizeof(char)*size);

	while( (c = getc(i)) != EOF && (j < size) ){  /* The 'c' here begins at position 0 of the filename string. */
		if( c == '<' ){
			c = getc(i); 
			while( (c != EOF) && (c != '>') ){
					name[j] = c;
					j++;
					c = getc(i);
			}
			break;
		}
	}

	return name;
}
