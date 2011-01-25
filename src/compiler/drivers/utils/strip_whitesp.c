#include <stdio.h>
#include <stdlib.h>

char *strip_whitesp(char *str);

int main()
{
	char s[] = "       crap     ";
	printf("Before:'%s'\n", s);
	
	printf("After:'%s'\n", strip_whitesp(s));
	return 0;
}

char *strip_whitesp(char *str)
{
	return NULL;
}
