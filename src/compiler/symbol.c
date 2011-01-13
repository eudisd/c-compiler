/** \file symbol.c
	\brief Defines all of the symbol table primitives.
*/

#include "symbol.h"

void print_stab(symbol_table *stab)
{
	int i;
	printf("\n\nCurrent STAB Status:\n"
           "Total Used: %4d\t Size: %4d\t Load Factor: %4.2f\n"
		   "\n", stab->in_use, stab->size, stab->load_factor);
	printf("-------\t----\t-----\t----\n"
		   "Address\tName\tValue\tSlot\n");
	for(i = 0; i < stab->size; i++){
		if( stab->table[i].slot != EMPTY_SLOT ){
			printf("%4d\t%s\t%s\t%d\n",
                   stab->table[i].addr, stab->table[i].name, 
                   stab->table[i].value, stab->table[i].slot);
		}
	} 	
}

size_t hash(char *key,  size_t limit)
{
	int hash_value = 0;
	int i = 0;
	size_t size = strlen(key);

	for(i = 0; i < size; i++){
		hash_value = 31*hash_value + key[i];
	}	
	return (size_t)(hash_value%limit);
}

symbol_table *create_stab(size_t max)
{
	int i;
	symbol_table *stab = (symbol_table*)xmalloc(sizeof(symbol_table)*1);
	
	stab->table = (record*)xmalloc(sizeof(record)*max);
	stab->in_use = 0;
	stab->load_factor = 0;
	stab->size = max;

	for(i = 0; i < max; i++){
		stab->table[i].addr = 0;
		stab->table[i].slot = EMPTY_SLOT;
	}

	return stab;
}

void stab_insert(record *rec, symbol_table *stab)
{	
	int addr;
	char type;
	char name[64];
	char *value;
	int slot;         /**> Either EMPTY_SLOT or NOT_EMPTY */
	char *scope;
	
	size_t index = hash(rec->name, stab->size);
	rec->slot = index;
	
	stab->table[index] = *rec;

	stab->in_use++;
		
	stab->load_factor = ((float)stab->in_use) / stab->size;
}

record *get_record(char *name, char*val, char type, int slot, char *scope)
{
	
	record *rec = (record*)xmalloc(sizeof(record)*1);

	/* NOTE: I have to purge all these allocations in the freeing of the records! */
	
	rec->value = (char*)xmalloc(sizeof(char)*strlen(val));
	rec->scope = (char*)xmalloc(sizeof(char)*strlen(scope));

	strcpy(rec->name, name);
	strcpy(rec->value, val);
	rec->type = type;
	rec->slot = slot;
	strcpy(rec->scope, scope);

	return rec;
}

void purge_record(record *rec)
{
}

void destroy_stab(symbol_table *stab)
{
	
}


