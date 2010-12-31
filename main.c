#include "main.h"

int main(int argc, char *argv[])
{
	switch(argc){
		case 1:
			printf("c: no input files");
			break;
		case 2:
			if(strcmp(argv[1], "--help") == 0){
				usage();
			}
			if(strcmp(argv[1], "--version") == 0){
				version();
			}
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
	}
	return EXIT_SUCCESS;
}
