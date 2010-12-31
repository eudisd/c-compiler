#include "utils.h"

void usage( void )
{
	printf("Usage: c [options] inputfile outputfile\n" 
	       "Options:\n"
		   "  --help\t\t\t Print help screen description\n"
		   "  --target-help\t\t\t Print specific help information\n"
		   "  --version\t\t\t Print version number\n"
		   );

}

void version( void )
{
	printf("c (C Compiler) %s %d (release) %d - Build: %d\n"
		   "Copyright (c) 2010 Eudis Duran\n"
		   "See LICENSE file for details."
		   ,VERSION, BUILD_DATE, RELEASE, BUILD_NUMBER);
			
}
