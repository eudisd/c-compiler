#include <stdio.h>
#include <stdlib.h>

char fcpeek(FILE *f);

int main()
{
	FILE *f = fopen("tmp.txt", "r");
	printf("Char: %c\n", fcpeek(f));
	printf("Current Pos: %d\n", (long int)ftell(f));
	return 0;
}

char fcpeek(FILE *f)
{
	char c = getc(f);
	ungetc(c, f);
	return c;
}
