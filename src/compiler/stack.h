#ifndef _STACK_H_
#define _STACK_H_

#include "symbol.h"

/* Types of Nodes */

typedef struct stack_stab_TAG {
    symbol_table *stab;
    struct stack_stab_TAG *next;
} stack_stab;

/* Prototypes */
void push_stab(stack_stab *s, symbol_table *stab);
symbol_table *pop_stab(stack_stab *s);

#endif
