#ifndef _CVM_H_
#define _CVM_H_

#include <stdio.h>
#include <stdlib.h>

#include "../compiler/utils.h"

#define OP_ADD    0
#define OP_SUB    1
#define OP_PUSH   2
#define OP_POP    3
#define OP_MUL    4
#define OP_DIV    5
#define OP_AND    6
#define OP_OR     7
#define OP_NOT    8
#define OP_ADDF   9
#define OP_SUBF   10
#define OP_EQL    11
#define OP_NEG    12
#define OP_LSS    13
#define OP_GTR    14
#define OP_LEQ    15
#define OP_GEQ    16
#define OP_EXCH   17
#define OP_DUP    18

typedef unsigned char uchar;  
typedef unsigned int uint;
/* Globals */

size_t sp;
size_t ip;
size_t bp;

uchar *code;
uchar *data;

union stack_TAG {
      int i;
      float f;
} stack[256];

void usage();

void run(char *program);

#endif
