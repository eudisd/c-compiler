#include "cvm.h"

int main(int argc, char *argv[])
{
    if( argc == 1 ){
        usage();
    }
    else if ( argc == 2 ){
        run(argv[1]);
    }
	return EXIT_SUCCESS;
}


void usage()
{
    printf("\nC Virtual Machine - By Eudis Duran (Spring 2011 Semester Project)\n"
           "\nUsage: cvm <program-file>\n\n");
}

void run(char *program)
{
    FILE *i = fopen(program, "rb");

    if( i == NULL ){
        printf("\nCould not open program file, exiting...\n");
        exit(EXIT_FAILURE);
    } 

    char *line = (char*)malloc(sizeof(char)*64);
    char *word;
    size_t line_size = 100;
    
    while( -1 != getline(&line, &line_size, i) ){
     while( 0 ){
        switch(line[0])
        {
        case 'a':
            
            if( !strcmp(word, "add") ){
                
            }
            else if ( !strcmp(word, "addf") ){
                
            } 
            else if ( !strcmp(word, "and") ){

            }
            else {

            }
            break;
        case 'p':

            if( !strcmp(word, "push") ){
                
            }
            else if ( !strcmp(word, "pop") ){
                
            } 
            else if ( !strcmp(word, "pushi") ){

            }
            else {

            }

            break;

        case 'e':
            if( !strcmp(word, "exch") ){
                
            }
            else if ( !strcmp(word, "eql") ){
                
            } 
            else if ( !strcmp(word, "and") ){

            }
            else {

            }
            break;

        case 'i':
            if( !strcmp(word, "ip") ){
                
            }
            else {

            }

            break;  

        case 'd':
            if( !strcmp(word, "dp") ){
                
            }
            else if ( !strcmp(word, "dup") ){
                
            } 
            else if ( !strcmp(word, "div") ){

            }
            else {

            }
            break;

        case 'b':
            if( !strcmp(word, "bp") ){
                
            }
            break;

        case 's':
            if( !strcmp(word, "sp") ){
                
            }
            else if ( !strcmp(word, "sub") ){
                
            } 
            else if ( !strcmp(word, "subf") ){

            }
            else {

            }
            break;
        case 'n':
            if( !strcmp(word, "neg") ){
                
            }
            else if ( !strcmp(word, "not") ){
                
            } 
            else {

            }
            break;

        case 'l':
            if( !strcmp(word, "leq") ){
                
            }
            else if ( !strcmp(word, "lss") ){
                
            } 
            else {

            }
            break;
        case 'g':

            if( !strcmp(word, "gtr") ){
                
            }
            else if ( !strcmp(word, "geq") ){
                
            } 
            else {

            }   
            break;
        case 'm':
            if( !strcmp(word, "mul") ){
                
            }
            
            else {

            }
            break;
       
        }
      }
    }
    
    
}
