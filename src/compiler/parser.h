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

/* Opcodes */

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
#define OP_MOD        30

#define OP_PUSHF 31
#define OP_POPF 32

#define OP_WRITEINTID    33
#define OP_POPEMPTY 34
#define OP_NOP 35

#define OP_NEQ 36
#define OP_EQU 37
#define OP_NEGF 38
#define OP_WRITESTRING 39

/* Type defs */
typedef unsigned char uchar;
typedef char TYPE;

typedef union Operand_TAG {
      int i;
      float f;
} Operand;

typedef struct Instruction_TAG {
    char opcode;   /* 8-bit */
    Operand operand;  /* 32-bit */
}Instruction;

/* Globals */
static char *cur_token;
static int dp = 0;


/* Externals */
extern file_struct file;
extern symbol_table *string_table;
extern symbol_table *id_table;

extern symbol_table *stab_stack[];

/** Gets a lexeme.  _MUST_ be freed after use.
  */
char *get_lexeme(FILE *i);

/** Given a lexeme, returns the NAME part.  _MUST_ be freed after call.
  */
int get_token_name(char *lexeme);

/** Given a lexeme, returns the NAME part.  _MUST_ be freed after call.
  */
int get_token_value(char *lexeme);

float get_token_value_f(char *lexeme);

/**
  */

char* get_token();

/**
  */
void match(char *token);

/**
  */
void matchi(int token);

/**
  */
char *peek_next_token();


/**** PRODUCTIONS ******/

TYPE CProgram();

void Declarations();
void Assignment();
void MainEntry();

int IntDec();
int FloatDec();
int CharDec();

void Statements();
void IfStatement();
void DoWhile();
void While();
void Goto();
void Label();
void Switch();
void Case();

/* Expression Productions */
/**
  */
TYPE E();

/**
  */
TYPE EPrime();

/**
  */
TYPE T();

/**
  */
TYPE TPrime();

/**
  */
TYPE F();


/**
  */

TYPE L();

/**
  */
TYPE LPrime();

#endif
