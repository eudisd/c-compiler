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
   
/** Prints usage information and a listing of commands.
*/
inline void usage(void);
/** Prints version information.
*/
inline void version(void);

/** Scans the program input for the -o flag, and returns its argument.
*/
inline char *scan_for_o(int argc, char *argv[]);

#endif