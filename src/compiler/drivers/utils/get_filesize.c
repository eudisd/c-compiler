#include <stdlib.h>
#include <stdio.h>

int get_filesize(char *filename);

int main()
{
	printf("FILESIZE: %d-bytes\n", get_filesize("tmp.txt"));
	#if defined(__linux)
		system("wc -c tmp.txt");
	#endif
	return 0;
}

int get_filesize(char *filename)
{
	FILE *f = fopen(filename, "r");
	fseek(f, 0, SEEK_END);
	return ftell(f);	
}
