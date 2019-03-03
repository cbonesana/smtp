/*
 * lib_utility.h
 *
 *  Created on: 29-dic-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 * Description:
 *  	Utilitiy functions used in various classes and other files.
 */

#ifndef LIB_UTILITY_H_
#define LIB_UTILITY_H_

#include <cstdlib>
#include <cstdio>
#include <cmath>

/* Value of Pi */
const float piover180 = 4*atan(1)/180.0;

/**
 * Transformation from degrees to radians: 2 PI radians = 360 degrees
 */
float rad(float angle);

/**
 * Helper function for SetupWorld: reads a file into a string until a nonblank,
 * non-comment line  is found ("/" at the start indicating a comment); assumes
 * lines < 255 characters long.
 */
void readstr(FILE *f,char *string);

/*
 * Helper functions getint and getshort are used to load the bitmap byte by byte on
 * SPARC platform (actually, just makes the thing work on platforms of either
 * endianness, not just Intel's little endian).
 */
unsigned int getInt(FILE *fp);
unsigned int getShort(FILE *fp);

/**
 * Convert a buffer of n elements in a unsigned long. It is used to convert data from
 * the image files to unsigned long values.
 */
unsigned long bufferToLong(int n, unsigned char *buffer);


#endif /* LIB_UTILITY_H_ */
