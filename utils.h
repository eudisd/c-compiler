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
#define BUILD_NUMBER 21 
#define BUILD_DATE 20101230 
   
inline void usage(void);
inline void version(void);


#endif