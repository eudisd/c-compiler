/** \file symbol.h
	\brief 
  */

#ifndef _SYMBOL_H_
#define _SYMBOL_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "utils.h"       /* For TRUE and FALSE constants */
#include "error.h"       /* For reporting ID errors, among other things */

#define MAX_SLOTS 10000  /**> Total number of identifiers possible in memory */
#define EMPTY_SLOT -1    /**> This symbolic constant signifies empty slots in the hash map. */

typedef struct record_TAG{
	int addr;
	char type;
	char name[64];
	char *value;
	int slot;         /**> Either EMPTY_SLOT or NOT_EMPTY */
	char *scope;
}record;

typedef struct symbol_table_TAG {
	/* Public Fields */
	char t_name[32];    /**> Table identifier. */
	double load_factor;  /**> Load factor.  If it is > 0.5, it is bad. */
	size_t in_use;       /**> How many slots are in use for this one symbol table */
	size_t size;         /**> Total Size of the symbol talbe */
	record *table;       /**> An array of all the records currently in use. */
	
	/* Public Methods */
} symbol_table;

/**
 */
void print_stab(symbol_table *stab);

/**
 */
symbol_table *create_stab(char *t_name, size_t max);

/**
 */
void stab_insert(char* filename, record *rec, symbol_table *stab);

/**
 */
record *get_record(char *name, char *val, char type, int slot, char *scope);

/**
 */
void purge_record(record *rec);

/**
 */
size_t hash(char *key, size_t limit);

/**
 */
int is_keyword(char *lexeme);

/**
*/
int return_value(symbol_table *stab, int target);

#endif
