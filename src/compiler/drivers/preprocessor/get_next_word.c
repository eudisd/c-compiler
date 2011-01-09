#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

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
	char *word;
	int get_out = 0;
	char c;
	int start_pos = ftell(f);
	int count = 0;
	int last_run = 0;

	while ( (c = getc(f)) != EOF ){
		if(c == ' ' || c == '\t' || c == '\n')
			continue;
		else {
			while(c != EOF){
				if(c != ' ' && c != '\t' && c != '\n'){
					(!last_run)? count++ : count;
					printf("%c", c);
					c = getc(f);	
				}
				else {
					get_out = last_run = 1;
			
					break;
				}
			}
			if(get_out == 1) {
				fseek(f, -count, SEEK_CUR); // Offset by word length amount
				if(last_run == 1){
					word = (char*)malloc(sizeof(char)*count);
					printf(" :Word Length: %d\n", count);
				}
				break;
				
			}
		}
	}
	return "YO";
}


