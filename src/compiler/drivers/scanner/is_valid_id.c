#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../utils.h"

int is_valid_id(char *word);

int main()
{
	
	printf("%d", is_valid_id("int;"));
	return 0;
}

//int is_valid_id(FILE *i)
//{
//	printf("Current File Pos: %d\n", ftell(i));
//	int valid = 0;
//	size_t file_pos = ftell(i); /**> Save the current file p. */
//	char *word = getword(i);
//	//free(word);
//	//word = getword(i);
//	
//	printf("Current WORD: %s\n", word);
//	
//	size_t size = strlen(word);
//	
//	
//	printf("Is it valid? ");
//	int j;
//	for(j = 0; j < size; j++){
//		if( !isalpha(word[j]) && !isdigit(word[j]) && word[j] != '_' ){
//			
//			printf("No! (%d)\n", valid);
//			valid = 0;
//			return 0;
//		}
//		valid = 1;
//	}
//	if(valid == 1){
//		printf("YES! (%d)\n", valid);
//		//return size;
//	}
//	
//	fseek(i, -(ftell(i) - file_pos), SEEK_CUR);
//	free(word); /* Release the resource */
//	printf("Ending File Pos: %d\n", ftell(i));
//	return 0;
//}

int is_valid_id(char *word)
{
	size_t size = strlen(word);
	
	int j;
	for(j = 0; j < size; j++){
		if( !isalpha(word[j]) && !isdigit(word[j]) && word[j] != '_' ){
			
			return 0;
		}
		
	}
	

	return size;
}


