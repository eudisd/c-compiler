/** \file utils.h 
    \brief Interface that holds common functions and housekeeping operations.
*/
#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

#define VERSION "0.0.1" /**< Holds the current version (semver.org). */
#define RELEASE 0 /**< Holds the current release candidate number. */

/** Prints usage information.
*/
inline void usage(void);

/** Prints version information.
   This function uses the C time library to get the current local time.
   It then formats it in a buffer that holds the day of the build.  This
   is then printed out.  We first initialize a raw time variable of type
   t_time.  We also initialize a tm struct which holds component time parts.
   We feed the the raw time to a localtime function.  Finally we use the 
   strftime() to format the local to time a C string.
 */
inline void version(void);

#endif