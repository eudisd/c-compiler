#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *scan_for_o(int argc, char *argv[])
{
	int i;
	for(i = 0; i < argc; i++){
		if(strcmp(argv[i], "-o") == 0){
			return argv[i + 1];
		}
	}
}

int main()
{
	char *argv[3] = {"program", "-o", "name"};
	
	printf("%s", scan_for_o(3, argv));
	return 0;
}

