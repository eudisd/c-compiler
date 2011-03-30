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

    char *line = "push 1";
    char *inst = "push";

    switch(line[0])
    {
        case 'a':
            
            if( !strcmp(inst, "add") ){
                
            }
            else if ( !strcmp(inst, "addf") ){
                
            } 
            else if ( !strcmp(inst, "and") ){

            }
            else {

            }
            break;
        case 'p':

            if( !strcmp(inst, "push") ){
                
            }
            else if ( !strcmp(inst, "pop") ){
                
            } 
            else if ( !strcmp(inst, "pushi") ){

            }
            else {

            }

            break;

        case 'e':
            if( !strcmp(inst, "exch") ){
                
            }
            else if ( !strcmp(inst, "eql") ){
                
            } 
            else if ( !strcmp(inst, "and") ){

            }
            else {

            }
            break;

        case 'i':
            if( !strcmp(inst, "ip") ){
                
            }
            else {

            }

            break;  

        case 'd':
            if( !strcmp(inst, "dp") ){
                
            }
            else if ( !strcmp(inst, "dup") ){
                
            } 
            else if ( !strcmp(inst, "div") ){

            }
            else {

            }
            break;

        case 'b':
            if( !strcmp(inst, "bp") ){
                
            }
            break;

        case 's':
            if( !strcmp(inst, "sp") ){
                
            }
            else if ( !strcmp(inst, "sub") ){
                
            } 
            else if ( !strcmp(inst, "subf") ){

            }
            else {

            }
            break;
        case 'n':
            if( !strcmp(inst, "neg") ){
                
            }
            else if ( !strcmp(inst, "not") ){
                
            } 
            else {

            }
            break;

        case 'l':
            if( !strcmp(inst, "leq") ){
                
            }
            else if ( !strcmp(inst, "lss") ){
                
            } 
            else {

            }
            break;
        case 'g':

            if( !strcmp(inst, "gtr") ){
                
            }
            else if ( !strcmp(inst, "geq") ){
                
            } 
            else {

            }   
            break;
        case 'm':
            if( !strcmp(inst, "mul") ){
                
            }
            
            else {

            }
            break;
       
    }
}
