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
    short str_data_end = 0;

    if( i == NULL ){
        printf("\nCould not open program file, exiting...\n");
        exit(EXIT_FAILURE);
    } 

    int cur_pos = ftell(i);
    fseek(i, -6, SEEK_END);

    /* Determine Run Time Data Segment Start */
    fread(&str_data_end, sizeof(short), 1, i);

    /* Determine Data Segment size */
    
    fread(&data_count, sizeof(short), 1, i);

    /* Determine Code Segment size */
    
    fread(&code_count, sizeof(short), 1, i);
 
    fseek(i, cur_pos, SEEK_SET);
    
    /* Allocate data array (semi last short holds the code size) */

    data = (char*)malloc(sizeof(char)* data_count); 
    fread(data, sizeof(char), data_count, i);

    /* Read in code array (last short holds the code size) */
    
    code = (Instruction*)malloc(sizeof(Instruction)* code_count); 
    fread(code, sizeof(Instruction), code_count, i);
    
    ip = 0;
    sp = 0;
    
    /* This tests to see if we have any static strings allocated at all! */
    if( str_data_end != 0){
        dp = str_data_end + 1; /* The last byte is the terminating null, we cannot override it
                              when assigning run time allocation! */
    }
    else {
        dp = 0;
    }   
    
    /*
    int j;
    printf("code_count: %d, data_count: %d, dp: %d\n", code_count, data_count, dp);
    */
    
    int c;
            printf("Code Segment: ");
            for(c = 0; c < data_count; c++){
                printf("%x ", data[c]);
            }

    int alloc = 0;  /**> Used as the base pointer for the static allocations (non-string)*/

    while( ip < code_count ){
            
           switch( code[ip].opcode ){
                case OP_ADD:
                    stack[sp - 2].i += stack[sp - 1].i;
                    sp--;
                    break;
                case OP_PUSH:
                    alloc = code[ip].operand.i;
                    stack[sp].i = *(int*)(data + (dp + alloc));
                    sp++;
                    break;
                case OP_PUSHF:  
                    alloc = code[ip].operand.i;
                    stack[sp].f = *(float*)(data + (dp + alloc));
                    sp++;
                    break;
                case OP_PUSHI: 
                    printf("Push-i: %d\n", code[ip].operand.i);
                    stack[sp].i = code[ip].operand.i;
                    sp++;
                    //print_stack(sp);
                    
                    break;
                case OP_POP:
                    alloc = code[ip].operand.i;
                    *(int*)(data + (dp + alloc)) = stack[sp - 1].i;
                    sp--;
                    break;
                case OP_POPEMPTY:
                    stack[ip - 1].i = 0;
                    sp--;
                    break;
                case OP_POPF:
                    alloc = code[ip].operand.i;
                    *(float*)(data + (dp + alloc)) = stack[sp - 1].f;
                    sp--;
                    break;
                case OP_EXCH:
                    break;
                case OP_DUP:
					stack[sp] = stack[sp - 1];
					sp++;
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
                    sp--;
                    break;
                case OP_NEG:
                    stack[sp - 1].i = -stack[sp - 1].i;
                    break;
                case OP_NEGF:
                    stack[sp - 1].f = -stack[sp - 1].f;
                    break;

                case OP_NOT:
                    stack[sp - 1].i = !stack[sp - 1].i;
                    break;
                case OP_LSS:
                    stack[sp - 2].i = stack[sp - 2].i < stack[sp - 1].i;
                    sp--;
                    break;
                case OP_GTR:
                    stack[sp - 2].i = stack[sp - 2].i > stack[sp - 1].i;
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
                case OP_NEQ:
                    stack[sp - 2].i = stack[sp - 2].i != stack[sp - 1].i;
                    sp--;
                    break;
                case OP_EQU:
                    stack[sp - 2].i = stack[sp - 2].i == stack[sp - 1].i;
                    sp--;
                    break;
                case OP_CVI:
                    stack[sp - 1].i = (int)stack[sp - 1].f;
                    break;
                case OP_CVR:
                    stack[sp - 1].f = (float)stack[sp - 1].i;
                    break;
                case OP_JMP:
                    /*
                    printf("IP: %d\n",ip);
                    printf("code: %d\n", code[ip].opcode);
                    printf("oper: %d\n", code[ip].operand.i);
                    printf("TopofStack: %d\n", stack[sp - 1].i);
                    for(j = 0; j < code_count; j++){
                        printf("%d: opcode: %d, operand: %d\n",j, code[j].opcode, code[j].operand.i);
                    }*/
                    ip = code[ip].operand.i - 1;
                    
                    break;
                case OP_JFALSE:
                    /*
                    printf("IP: %d\n",ip);
                    printf("code: %d\n", code[ip].opcode);
                    printf("oper: %d\n", code[ip].operand.i);
                    printf("TopofStack: %d\n", stack[sp - 1].i);
                    for(j = 0; j < code_count; j++){
                        printf("%d: opcode: %d, operand: %d\n",j, code[j].opcode, code[j].operand.i);
                    }*/
                    if( stack[sp - 1].i == 0 ){
                        ip = code[ip].operand.i - 1;  /* -1 because we increment right after the break here
                                                         so we need code to execute one instruction back on
                                                         the next VM iteration! */
                    }
                    //sp--; /* If it's false, we rid the result */
                    break;
                case OP_JTRUE:
                    if( stack[sp - 1].i != 0 )    
                        ip = code[ip].operand.i - 1;
                    break;
                case OP_HALT:
                    exit(-1);
                    break;
                case OP_WRITEINTID:
                    printf("%d\n", *(int*)(data + code[ip].operand.i));
                    break;
                case OP_WRITEINT:
                    printf("%d\n", stack[sp - 1].i);
                    sp--;
                    break;
                case OP_WRITEFLOAT:
                    printf("%f\n", stack[sp - 1].f);
                    sp--;
                    break;
                case OP_NOP:
                    break;
                case OP_WRITESTRING:
                
                    printf("%s", &data[code[ip].operand.i]);
                    printf("\n");
                    
                    break;

                case OP_GET:
					
					alloc = code[ip].operand.i;
					int addr = stack[sp - 1].i;
                    stack[sp - 1].i = *(int*)(data + (dp + alloc + stack[sp - 1].i));
                    
					printf("\nAddress: %d\n", alloc + addr);
					printf("\nValue: %d\n", stack[sp - 1].i);
					sp++;
					
				case OP_PUT:
					alloc = code[ip].operand.i;
					*(int*)(data + (dp + stack[sp - 2].i)) = stack[sp - 1].i;
                    sp--;
					
                default:
                    break;
           }
           ip++;
    }
	printf("Code Segment: ");
            for(c = 0; c < data_count; c++){
                printf("%x ", data[c]);
            }
}

void print_stack(int sp)
{
    int i;
    printf("\nBottom: ");
    for(i = 0; i < sp; i++){
        printf("%d < ", stack[i].i);

    }
    printf(": Top\n");
}
