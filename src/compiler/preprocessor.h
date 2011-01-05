#ifndef _PREPROCESSOR_H_
#define _PREPROCESSOR_H_

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

// First Pass 

#define MAX_PREPROC_IDENT 2

#define PREPROC_DEFINE  0
#define PREPROC_INCLUDE 1

/** Runs the preprocessor on the specified file.
*/
void run_preporcessor(const char *ifilename, const char *ofilename);

/** Get the next word from the file stream, and increment the file pointer accordingly. 
*/
char *get_next_word(FILE *f);
char *get_define_value(char *line);


#endif
