#include <stdio.h>
#include <stdlib.h>
#include "../../utils.h"
#include "../../scanner.h"
#include <string.h>

int write_tokens();

int main()
{
	write_tokens();
	return 0;
}

int write_tokens()
{
	size_t n, m;
	
	char *word = "int;here";
	char *token = extract_token(word);
	char *tmp;
	size_t tk_size = strlen(token);
	size_t word_size = strlen(word);
	size_t diff = word_size - tk_size;
	size_t upto = tk_size;

	printf("%s\n", token);
	printf("tk_size: %d\n", tk_size);
	printf("word_size: %d\n", word_size);
	printf("diff: %d\n\n", diff);

	while(tk_size > 0){
		tmp = (char*)xmalloc(sizeof(char)*diff + 1);

		
		for(n = 0, m = upto; n < diff; n++, m++){
			tmp[n] = word[m];
		}	
		tmp[diff] = '\n';
		
		printf("Token: %s\n", token);
		printf("Tmp: %s\n\n", tmp);

		free(token);
		token = extract_token(tmp);
		tk_size = strlen(token);

		upto += tk_size;
		diff = word_size - upto;
		free(tmp);
		
	}

}
