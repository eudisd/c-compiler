#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *return_string(char *word);


int main()
{
    char *word = "\" \"";
    printf("%s\n", word);
    printf("String: %s\n", return_string(word));
    return 0;
}


char *return_string(char *word)
{
    int i, j;
    size_t size = strlen(word);
    char *tmp;
    for(i = 1; i < size; i++){
        if( word[i] == '"' ){
            i++;
            break;
        }
    }

    tmp = (char*)malloc(sizeof(char)*i + 1);

    for(j = 0; j < i; j++){
        tmp[j] = word[j];
    }

    tmp[i] = '\0';
    
    
    return tmp;
}
