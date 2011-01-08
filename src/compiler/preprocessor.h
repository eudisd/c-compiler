/** \file preprocessor.h
	\brief Preprocessor defines all the operations necessary for the first pass in the compiler.
*/

#ifndef _PREPROCESSOR_H_
#define _PREPROCESSOR_H_

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/* First Pass */

#define MAX_PREPROC_IDENT 2

#define PREPROC_DEFINE  0
#define PREPROC_INCLUDE 1

/** Runs the preprocessor on the specified file.
*/
void run_preporcessor(const char *prog, const char *ifilename, const char *ofilename);

/** Removes all comments from the import source file, and outputs an intermediary file for 
    further processing.
*/
void remove_comments(const char *prog, const char *ifilename, const char *ofilename);

void include_headers(const char *prog, const char *ifilename, const char *ofilename);

char *get_define_value(char *line);


#endif
