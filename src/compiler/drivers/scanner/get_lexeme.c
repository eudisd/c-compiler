#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_lexeme(FILE *i);

int main()
{
	FILE *i = fopen("tmp.txt", "r");

	printf("%s\n\n", get_lexeme(i));
	return 0;
}

char *get_lexeme(FILE *i)
{
	char c;
	while ( (c = fget(i)) != '>' ){}
	return NULL;
}
