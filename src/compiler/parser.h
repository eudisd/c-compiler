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
#include "scanner.h"

/* Globals */
static char *cur_token;

typedef char TYPE;

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
#endif
