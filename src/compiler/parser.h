/** \file parser.h
	\brief 
  */

#ifndef _PARSER_H_
#define _PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error.h"
#include "utils.h"
#include "symbol.h"
#include "scanner.h"

/* Type defs */
typedef unsigned char uchar;
typedef char TYPE;

/* Globals */
static char *cur_token;

static uchar *data;


/* Externals */
extern file_struct file;
extern symbol_table *string_table;
extern symbol_table *id_table;

/** Gets a lexeme.  _MUST_ be freed after use.
  */
char *get_lexeme(FILE *i);

/** Given a lexeme, returns the NAME part.  _MUST_ be freed after call.
  */
int get_token_name(char *lexeme);

/** Given a lexeme, returns the NAME part.  _MUST_ be freed after call.
  */
int get_token_value(char *lexeme);

/**
  */

char* get_token();

/**
  */
void match(char *token);

/**
  */
void matchi(int token);

/* Expression Productions */
/**
  */
TYPE E();

/**
  */
void EPrime();

/**
  */
TYPE T();

/**
  */
void TPrime();

/**
  */
TYPE F();


/**
  */

#endif
