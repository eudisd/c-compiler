#include "utils.h"

void usage( void )
{
	printf("Usage: c [options] inputfile outputfile\n" 
	       "Options:\n"
		   "  --help\t\t\t\t Print help screen description\n"
		   "  --target-help\t\t\t Print specific help information\n"
		   "  --version\t\t\t Print version number\n"
		   );

}

void version( void )
{
	time_t raw_time;
	struct tm *timeinfo;
	char *build_date = ( char* )malloc( sizeof(char) * 9 );
	
	time( &raw_time );
	timeinfo = localtime( &raw_time );
	
	strftime(build_date, 9, "%Y%m%d", timeinfo);
	
	printf("c (C Compiler) %s %s (release) %d\n"
		   "Copyright (c) 2010 Eudis Duran\n"
		   "See LICENSE file for details."
		   , VERSION, build_date, RELEASE);
			
	free(build_date);
}
