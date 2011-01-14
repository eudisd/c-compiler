#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid_id(char *word);

int main()
{
	printf("%d", is_valid_id("main_stu"));
	return 0;
}

int is_valid_id(char *word)
{
	size_t size = strlen(word);
	int i;
	for(i = 0; i < size; i++){
		if( !isalpha(word[i]) && !isdigit(word[i]) && word[i] != '_' ){
			return 0;
		}
	}
	return size;
}

