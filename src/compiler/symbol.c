/** \file symbol.c
	\brief Defines all of the symbol table primitives.
  */

#include "symbol.h"

void print_stab(symbol_table *stab)
{
	int i;
	printf("\n\nCurrent Symbol Table: '%s' \n - Status -\n"
           "Total Used: %4d\t Size: %4d\t Load Factor: %4.2f\n"
		   "\n", stab->t_name, (int)stab->in_use, (int)stab->size, stab->load_factor);
	printf("-------\t----\t-----\t----\t-----\n"
		   "Address\tName\tValue\tSlot\tType\tScope\tIsArray\tArray-Size\n");
	for(i = 0; i < stab->size; i++){
		if( stab->table[i].slot != EMPTY_SLOT ){
			printf("%4d\t%s\t%s\t%d\t%c\t%d\t%c\t%d\n",
                   stab->table[i].addr, stab->table[i].name, 
                   stab->table[i].value, stab->table[i].slot,
                   stab->table[i].type,
                   stab->table[i].scope,
                   stab->table[i].isarray,
                   stab->table[i].arraysize);
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

symbol_table *create_stab(char* t_name, size_t max)
{
	int i;
	symbol_table *stab = (symbol_table*)xmalloc(sizeof(symbol_table)*1);
	
	stab->table = (record*)xmalloc(sizeof(record)*max);
	stab->in_use = 0;
	stab->load_factor = 0;
	stab->size = max;
	strcpy(stab->t_name, t_name);

	for(i = 0; i < max; i++){
		stab->table[i].addr = -1;
		stab->table[i].slot = EMPTY_SLOT;
		stab->table[i].seen = 0;
	}

	return stab;
}

void stab_insert(char* filename, record *rec, symbol_table *stab)
{	
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

	strcpy(rec->name, name);
	strcpy(rec->value, val);
	rec->type = type;
	rec->slot = slot;
	rec->scope = 0;

	return rec;
}

int return_value(symbol_table *stab, int target)
{
    return 1;
}

void purge_record(record *rec)
{
}

void destroy_stab(symbol_table *stab)
{
}

int is_keyword(char *lexeme)
{
	switch(lexeme[0]){
			case 'a':
                /* auto */
				if( !strcmp(lexeme, "auto") )
					return TRUE;
				return FALSE;
			case 'b':
                /* break */
				if( !strcmp(lexeme, "break") )
					return TRUE;
				return FALSE;
			case 'c':
				/* case */
				/* char */
				/* const */
				/* continue */
				if( !strcmp(lexeme, "case")     ||
					!strcmp(lexeme, "char")     ||
					!strcmp(lexeme, "const")    ||
					!strcmp(lexeme, "continue") 
					)
					return TRUE;
				return FALSE;
			case 'd':
				/* default */
				/* do */
				/* double */
				if( !strcmp(lexeme, "default")||
					!strcmp(lexeme, "do")     ||
					!strcmp(lexeme, "double") 
					)
					return TRUE;
				return FALSE;
			case 'e':
				/* else */
				/* enum */
				/* extern */
				if( !strcmp(lexeme, "else")   ||
					!strcmp(lexeme, "enum")   ||
					!strcmp(lexeme, "extern") 
					)
					return TRUE;
				return FALSE;
			case 'f':
				/* float */
				/* for */
				if( !strcmp(lexeme, "float")||
					!strcmp(lexeme, "for")  
					)
					return TRUE;
				return FALSE;
			case 'g':
				/* goto */
				if( !strcmp(lexeme, "goto") )
					return TRUE;
				return FALSE;
	
			case 'i':
				/* int */
                /* if */
                if( !strcmp(lexeme, "int") ||
					!strcmp(lexeme, "if")  
					)
					return TRUE;
				return FALSE;
			case 'l':
				/* long */
				if( !strcmp(lexeme, "long") )
					return TRUE;
				return FALSE;
			case 'r':
				/* register */
				/* return */
				if( !strcmp(lexeme, "register")||
					!strcmp(lexeme, "return")  
					)
					return TRUE;
				return FALSE;
			case 's':
				/* short */
				/* signed */
				/* sizeof */
				/* static */
				/* struct */
				/* switch */
				if( !strcmp(lexeme, "short")   ||
					!strcmp(lexeme, "signed")  ||
					!strcmp(lexeme, "sizeof")  ||
					!strcmp(lexeme, "static")  ||
					!strcmp(lexeme, "struct")  ||
					!strcmp(lexeme, "switch")  
					)
					return TRUE;
				return FALSE;
			case 't':
				/* typedef */
				if( !strcmp(lexeme, "typedef") )
					return TRUE;
				return FALSE;
			case 'u':
				/* union */
				/* unsigned */
				if( !strcmp(lexeme, "union")   ||
					!strcmp(lexeme, "unsigned")   
					)
					return TRUE;
				return FALSE;
			case 'v':
				/* void */
				/* volatile */
				if( !strcmp(lexeme, "void")   ||
					!strcmp(lexeme, "volatile") 
					)
					return TRUE;
				return FALSE;
			case 'w':
				/* while */
				if( !strcmp(lexeme, "while") )
					return TRUE;
				return FALSE;
			default:
				return FALSE;
	}
}


