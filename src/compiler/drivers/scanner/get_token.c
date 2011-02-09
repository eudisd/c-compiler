#include <stdio.h>
#include <stdlib.h>
#include "../../utils.h"
#include "../../scanner.h"


int main()
{
	char *word = "int;here";
	char *token = extract_token(word);
	printf("%s\n", token);
	return 0;
}
