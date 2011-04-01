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

    ip = 0;
    sp = 0;

    while( 1 ){
           switch( code[ip++] ){
                case OP_ADD:
                     stack[sp + 1].i += stack[sp].i;
                     sp++;
                     break;
                case OP_SUB:
                     break;
                case OP_PUSH:
                     break;
                case OP_POP:
                     break;
                case OP_MUL:
                     break;
                case OP_DIV:
                     break;
                case OP_AND:
                     break;
                case OP_OR:
                     break;
                case OP_NOT:
                     break;
                case OP_ADDF:
                     break;
                case OP_SUBF:
                     break;
                case OP_EQL:
                     break;
                case OP_NEG:
                     break;
                case OP_LSS:
                     break;
                case OP_GTR:
                     break;
                case OP_LEQ:
                     break;
                case OP_GEQ:
                     break;
                case OP_EXCH:
                     break;
                case OP_DUP:
                     break;
           }
    }
}
