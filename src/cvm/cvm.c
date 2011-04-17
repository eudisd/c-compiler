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

    short code_count = 0;
    short data_count = 0;

    if( i == NULL ){
        printf("\nCould not open program file, exiting...\n");
        exit(EXIT_FAILURE);
    } 

    int cur_pos = ftell(i);
    fseek(i, -4, SEEK_END);

    /* Determine Data Segment size */
    
    fread(&data_count, sizeof(short), 1, i);

    /* Determine Code Segment size */
    
    fread(&code_count, sizeof(short), 1, i);

    fseek(i, cur_pos, SEEK_SET);

    printf("Code_count: %d\n Data_count: %d\n", code_count, data_count);
    


    /* Read in data array (semi last short holds the code size) */

    code = (Instruction*)malloc(sizeof(Instruction)* code_count); 
    fread(code, sizeof(Instruction), code_count, i);

    /* Read in code array (last short holds the code size) */
    
    code = (Instruction*)malloc(sizeof(Instruction)* code_count); 
    fread(code, sizeof(Instruction), code_count, i);
    
    ip = 0;
    sp = 0;
   
    while( ip < code_count ){
           switch( code[ip].opcode ){
                case OP_ADD:
                    stack[sp - 2].i += stack[sp - 1].i;
                    sp--;
                    break;
                case OP_PUSH:
                    //stack[sp].i = code[code[ip]
                    sp++;
                    break;
                case OP_PUSHF:
                    break;
                case OP_PUSHI: 
                    // Here we need to test if we are push an immediate
                    // float or int.
                    stack[sp].i = code[ip].operand.i;
                    sp++;
                    break;
                case OP_POP:
                    
                    break;
                case OP_EXCH:
                    break;
                case OP_DUP:
                    break;
                case OP_ADDF:
                    stack[sp - 2].f += stack[sp - 1].f;
                    sp--;
                    break;
                case OP_SUBF:
                    stack[sp - 2].f -= stack[sp - 1].f;
                    sp--;
                    break;
                case OP_SUB:
                    stack[sp - 2].i -= stack[sp - 1].i;
                    sp--;
                    
                    break;
                case OP_MULF:
                    stack[sp - 2].f *= stack[sp - 1].f;
                    sp--;
                    break;
                case OP_MUL:
                    stack[sp - 2].i *= stack[sp - 1].i;
                    sp--;
                    break;
                case OP_DIV:
                    stack[sp - 2].i /= stack[sp - 1].i;
                    sp--;
                    break;
                case OP_DIVF:
                    stack[sp - 2].f /= stack[sp - 1].f;
                    sp--;
                    break;
                case OP_MOD:   
                    stack[sp - 2].i %= stack[sp - 1].i;
                    sp--;
                    break;
                case OP_AND:
                    stack[sp - 2].i = stack[sp - 2].i && stack[sp - 1].i;
                    sp--;
                    break;
                case OP_OR:
                    stack[sp - 2].i = stack[sp - 2].i && stack[sp - 1].i;
                    sp--;
                    break;
                case OP_EQL:
                    stack[sp - 2].i = stack[sp - 2].i == stack[sp - 1].i;
                    break;
                    break;
                case OP_NEG:
                    stack[sp - 1].i = -stack[sp - 1].i;
                    break;
                case OP_NOT:
                    stack[sp - 1].i = !stack[sp - 1].i;
                    break;
                case OP_LSS:
                    stack[sp - 2].i = stack[sp - 2].i < stack[sp - 1].i;
                    sp--;
                    break;
                case OP_GTR:
                    stack[sp - 2].i = stack[sp - 2].i < stack[sp - 1].i;
                    sp--;
                    break;
                case OP_LEQ:
                    stack[sp - 2].i = stack[sp - 2].i <= stack[sp - 1].i;
                    sp--;
                    break;
                case OP_GEQ:
                    stack[sp - 2].i = stack[sp - 2].i >= stack[sp - 1].i;
                    sp--;
                    break;
                case OP_CVI:
                    break;
                case OP_CVR:
                    break;
                case OP_JMP:
                    break;
                case OP_JFALSE:
                    break;
                case OP_JTRUE:
                    break;
                case OP_HALT:
                    exit(-1);
                    break;
                case OP_WRITEINT:
                    printf("%d\n", stack[sp - 1].i);
                    sp--;
                    break;
                case OP_WRITEFLOAT:
                    printf("%f\n", stack[sp - 1].f);
                    sp--;
                    break;
                default:
                    break;
           }
           ip++;
           printf("Result: %d\n", stack[sp - 1].i);
    }
}
