/*
 * lib_utility.c
 *
 *  Created on: 29-dic-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 */

#include "lib_utility.h"

float rad(float angle){
	return angle * piover180;
}

void readstr(FILE *f,char *string) {
	do {
		fgets(string, 255, f);
	} while ((string[0] == '/') || (string[0] == '\n'));
	return;
}

unsigned int getInt(FILE *fp) {
	int c, c1, c2, c3;

	// get 4 bytes
	c = getc(fp);
	c1 = getc(fp);
	c2 = getc(fp);
	c3 = getc(fp);

	return ((unsigned int) c) +	(((unsigned int) c1) << 8) + (((unsigned int) c2) << 16) +(((unsigned int) c3) << 24);
}

unsigned int getShort(FILE *fp) {
	int c, c1;

	//get 2 bytes
	c = getc(fp);
	c1 = getc(fp);

	return ((unsigned int) c) + (((unsigned int) c1) << 8);
}

unsigned long bufferToLong(int n, unsigned char *buffer){
	unsigned long x=0;
	for (int i=0; i<n; i++){
		x = 256*x + buffer[n-i-1];
	}
	return x;
}
