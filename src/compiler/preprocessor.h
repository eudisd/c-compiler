/** \file preprocessor.h
	\brief Preprocessor defines all the operations necessary for the first pass in the compiler.
*/

#ifndef _PREPROCESSOR_H_
#define _PREPROCESSOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

/* First Pass */

#define MAX_PREPROC_IDENT 2

#define PREPROC_DEFINE  0
#define PREPROC_INCLUDE 1

#define DEFAULT_INC_DIR "/usr/include/"
#define DEFAULT_LIB_DIR "/usr/lib/"

char *sys_inc_dir;
char *sys_lib_dir;

/** Runs the preprocessor on the specified file.
 */
void run_preporcessor(const char *prog, const char *ifilename, const char *ofilename);

/** Removes all comments from the import source file, and outputs an intermediary file for 
    further processing.
 */

void include_headers(const char *prog, const char *ifilename, const char *ofilename);

void remove_comments(const char *prog, const char *filename);

/** This gets the next include name from the #include preprocessor directive.
    It is malloced internally.  It _MUST_ be freed after each use.
  */
char *get_inc_fname(char *n);

char *get_define_value(char *line);


#endif
