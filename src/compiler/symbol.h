#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_SLOTS 10000  
#define EMPTY_SLOT -1 /**> This symbolic constant signifies empty slots in the hash map. */

typedef struct record_TAG{
	int addr;
	char type;
	char name[64];
	void *scope;
}record;

typedef struct symbol_table_TAG {
	/* Public Fields */
	double load_factor;
	size_t in_use;
	size_t size;
	record *table;
	
	/* Public Methods */
} symbol_table;

void print_stab(symbol_table *stab);




#endif
