/** \file utils.h 
    \brief Interface that holds common functions and housekeeping operations.
  */
#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

#define VERSION "0.0.1"     /**< Holds the current version (semver.org). */
#define RELEASE 0           /**< Holds the current release candidate number. */
#define BUILD_NUMBER 51     /**< Holds the current build number. */
#define BUILD_DATE 20101231 /**< Holds the current build date in Year-Month-Day format. */

#define INTERIM_FILENAME "data"
#define DEFAULT_OUTPUT "a.out"

#define TRUE 1
#define FALSE 0

typedef struct file_struct_Tag {
	char calling_prog[64];
	char filename[64];
	char default_o[64];
	int cur_line;
	int cur_column;
	char cur_word[64];
} file_struct;


/* Globals */

extern file_struct file;
extern size_t total_newlines;

   
/** Prints usage information and a listing of commands.
  */
inline void usage(void);
/** Prints version information.
  */
inline void version(void);

/** Scans the program input for the -o flag, and returns its argument.
  */
inline char *scan_for_o(int argc, char *argv[]);

inline char **get_files_from_argv(int argc, char *argv[]);

/** Returns the current filesize of a file.  It does this by fseeking to the 
    last byte of the file, and return ftell().
  */
int get_filesize(char *filename);

/** Safety wrapper for malloc.  Exits on error allocation. */
void *xmalloc(int size);

/** Returns the current character pointed to by the file discriptor.  Does not
    modify the current file pointer
  */
char fcpeek(FILE *f);

/** Get the next word from the file stream, and increment the file pointer accordingly. 
	All calls to this function return a malloc'ed string.  It _must_ be freed.
  */
char *getword(FILE *i); 

/** Peek the next word from the file stream, and do not increment the file pointer.
	All calls to this function return a malloc'ed string.  It _must_ be freed.  
    Further, 
  */

char *wordpeek(FILE *f);

/** General file error function.
  */
void file_error(char *prog, char *do_this, char *ifilename, char *specifics, char *msg);

/** 
  */
int get_build_date();

/**
  */
int get_column(FILE *i);

/* Debug Functions */

/** 
  */
char *strip_whitesp(char *str);



#endif
