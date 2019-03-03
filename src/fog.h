/*
 * fog.h
 *
 *   Created on: 29-dic-2012
 *       Author: Claudio "Dna" Bonesana
 *  Description:
 *  	This file is used to control fog status, fog levels and fog global mode.
 */

#ifndef FOG_H_
#define FOG_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

/* Fog */
const GLuint fogMode[]= { GL_EXP, GL_EXP2, GL_LINEAR };	// Storage for three types of fog
extern GLuint fogfilter;                    			// Which fog to use
extern bool fogstatus;                    				// Enable or disable fog

#endif /* FOG_H_ */
