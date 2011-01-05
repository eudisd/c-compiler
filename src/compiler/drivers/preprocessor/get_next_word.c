#include <stdlib.h>
#include <stdio.h>

char *get_next_word(FILE *f);

int main()
{
	FILE *f = fopen("tmp.txt", "r");
	
	//printf("%s", get_next_word(f));
	get_next_word(f);
	get_next_word(f);
	get_next_word(f);
	get_next_word(f);
	return 0;
}


char *get_next_word(FILE *f)
{
	int get_out = 0;
	char c;
	
	while ( (c = getc(f)) != EOF ){
		if(c == ' ' || c == '\t' || c == '\n')
			continue;
		else {
			while(c != EOF){
				if(c != ' ' && c != '\t' && c != '\n'){
					printf("%c", c);
					c = getc(f);	
				}
				else {
					get_out = 1;
					break;
				}
			}
			if(get_out == 1) {
				printf("\n");
				break;
				
			}
		}
	}
	
	return "YO";
}


