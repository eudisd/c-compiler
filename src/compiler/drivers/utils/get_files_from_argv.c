#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char **get_files_from_argv(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	int i;
	char **a = (char**)get_files_from_argv(argc, argv);

	for(i = 1; i < argc; i++){
		printf("%s\n", a[i]);
	}
	return 0;
}

char **get_files_from_argv(int argc, char *argv[])
{
	char **files = (char**)malloc(sizeof(char*)*argc);
	int i;
	size_t size;

	for(i = 1; i < argc; i++){
		size = strlen(argv[i]);
		files[i] = (char*)malloc(sizeof(char)*size);
		strcpy(files[i], argv[i]);
	}

	return files;
}
