/*
 * texture.h
 *
 *  Created on: 10-nov-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 * Description:
 * 		This library manage the load and creation of textures from BMP files. Only BMP files are supported.
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "lib_utility.h"

#define TEXTURE_NUMBER 12

using namespace std;

/* Image type - contains height, width, and data */
typedef struct {
	unsigned long sizeX;
	unsigned long sizeY;
	char *data;
} Image;

extern GLuint textureFilter;
extern GLuint texture[TEXTURE_NUMBER];

/**
 * Load an image file and put his data in an Image struct.
 */
bool ImageLoad(char *filename, Image *image);

/**
 * Load an image and convert his data in a texture.
 */
bool LoadGLTextures(char *filename, int lvl, GLuint *texture);

#endif /* TEXTURE_H_ */
