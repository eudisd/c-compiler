#include <stdio.h>
#include <stdlib.h>
#include "../../utils.h"

int get_column(FILE *i);

int main()
{
	FILE *i = fopen("tmp.txt", "r");
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	getc(i);
	printf("Answer: %d\n", get_column(i));
	return 0;
}

int get_column(FILE *i){
	int cur_pos = ftell(i);
	int offset = 0;
	char c = fcpeek(i);

    while( c != '\n' &&  (ftell(i) > 0) && c != EOF){
		fseek(i, -1, SEEK_CUR);
		offset++;
		c = fcpeek(i);
	}	
	fseek(i, cur_pos, SEEK_CUR);
	return offset;
}
