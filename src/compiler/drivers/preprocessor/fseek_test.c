#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *f;
	f = fopen("tmp.txt", "r");
	
	printf("\nI am at: %d\n", (int)ftell(f));
	getc(f);
	printf("\nNow I am at: %d\n", (int)ftell(f));
	fseek(f, 1, SEEK_CUR);
	printf("\nNow I am back at: %d\n", (int)ftell(f));

	return 0;
}
