#ifndef _CVM_H_
#define _CVM_H_

#include <stdio.h>
#include <stdlib.h>

#include "../compiler/utils.h"

#define OP_PUSH  0
#define OP_PUSHI 1
#define OP_POP   2
#define OP_EXCH  3
#define OP_DUP   4
#define OP_ADDF  5
#define OP_ADD   6
#define OP_SUBF  7
#define OP_SUB   8
#define OP_MULF  9
#define OP_MUL   10
#define OP_DIV   11
#define OP_DIVF  12
#define OP_AND   13
#define OP_OR    14
#define OP_EQL   15
#define OP_NEG   16
#define OP_NOT   17
#define OP_LSS   18
#define OP_GTR   19
#define OP_LEQ   20
#define OP_GEQ   21
#define OP_CVI   22
#define OP_CVR   23
#define OP_JMP   24
#define OP_JFALSE     25
#define OP_JTRUE      26
#define OP_HALT       27
#define OP_WRITEINT   28
#define OP_WRITEFLOAT 29
#define OP_MOD 30

#define OP_PUSHF 31
#define OP_POPF 32

#define OP_WRITEINTID 33
#define OP_POPEMPTY 34

#define OP_NOP 35
#define OP_NEQ 36
#define OP_EQU 37
#define OP_NEGF 38

#define OP_WRITESTRING 39

typedef unsigned char uchar;  
typedef unsigned int uint;
typedef union Operand_TAG {
      int i;
      float f;
} Operand;

typedef struct Instruction_TAG {
    char opcode;   /* 8-bit */
    Operand  operand;  /* 32-bit */
}Instruction;

/* Globals */

size_t sp;
size_t ip;
size_t bp;
size_t dp;

Instruction *code;
char *data;

union stack_TAG {
      int i;
      float f;
} stack[256];



void usage();

void run(char *program);


void print_stack();
#endif
