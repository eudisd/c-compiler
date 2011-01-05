#include "utils.h"

void usage( void )
{
	printf("Usage: c [options] file...\n" 
	       "Options:\n"
		   "  --help\t\t\t Print help screen description\n"
		   "  --target-help\t\t\t Print target specific help information\n"
		   "  --version\t\t\t Print version number\n"
		   "  -o <file>\t\t\t Specify a file name"
		   );
}

void version( void )
{
	printf("c (C Compiler) %s %d (release) %d - Build: %d\n"
		   "Copyright (c) 2010 Eudis Duran\n"
		   "See LICENSE file for details."
		   ,VERSION, BUILD_DATE, RELEASE, BUILD_NUMBER);
			
}

char *scan_for_o(int argc, char *argv[])
{
	int i;
	for(i = 0; i < argc; i++){
		if(strcmp(argv[i], "-o") == 0){
			return argv[i + 1];
		}
	}
}
