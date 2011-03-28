/** \file parser.h
	\brief 
  */

#ifndef _PARSER_H_
#define _PARSER_H_

#include <stdio.h>
#include <stdlib.h>

/** Gets a lexeme.  _MUST_ be freed after use.
  */
char *get_lexeme(FILE *i)

/** Given a lexeme, returns the ID part.  _MUST_ be freed after call.
  */
char *get_valid_id(char *lexeme);

/** Given a lexeme, returns the NAME part.  _MUST_ be freed after call.
  */
char *get_token_name(char *lexeme);

/** 
  */
char *get_token(char *lexeme);

#endif
