#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#include "../../utils.h"

char *getword(FILE *i);

int main()
{
	char *name;
	FILE *f = fopen("tmp.txt", "r");
	
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
	pos = ftell(i);
	c = getc(i); 
	
	//printf("Start file-p position: %d\n", pos);

	/* We first calculate the size of the word */
	while ( (c != EOF) && !isspace(c) ){
		size++;
		c = getc(i);
	}

	//printf("Current size of word: %d\n", size);
	//printf("Current file-p position: %d\n", (int)ftell(i));

	fseek(i, -(ftell(i) - pos), SEEK_CUR);
	
	//printf("Restored to: %d position\n", (int)ftell(i));

	word = (char*)xmalloc(sizeof(char)*size);
	c = getc(i);
	while ( (c != EOF) && !isspace(c) && (j < size) ){
		word[j] = c;
		j++;
		c = getc(i);
	}

	return word;
}
