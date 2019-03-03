/*
 * colors.h
 *
 *   Created on: 29-dic-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 * Description:
 *  	This is a color library. All the color vectors are defined here.
 */

#ifndef COLORS_H_
#define COLORS_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

#include "config.h"

/* color of the fog */
const GLfloat fogColor[4] = {0.3f, 0.4f, 0.5f, 1.0f};

/* Specific material */
const GLfloat mat_glass[]     = {0.1,0.1,0.5,0.2};			// material for the four windows
const GLfloat mat_crate[]	  = {1.0,1.0,1.0,1.0};			// material for walls and tiny walls
const GLfloat mat_crate_amb[] = {0.3,0.3,0.3,1.0};			// standard ambient material color for crates

/* Standard color */
const GLfloat white[]  = {1.0,1.0,1.0,1.0};
const GLfloat empty[]  = {0.0,0.0,0.0,0.0};
const GLfloat black[]  = {0.0,0.0,0.0,1.0};
const GLfloat red[]    = {1.0,0.0,0.0,1.0};
const GLfloat orange[] = {0.7,0.7,0.0,1.0};
const GLfloat yellow[] = {1.0,1.0,0.0,1.0};
const GLfloat green[]  = {0.0,1.0,0.0,1.0};
const GLfloat cyan[]   = {0.0,1.0,1.0,1.0};
const GLfloat blue[]   = {0.0,0.0,1.0,1.0};
const GLfloat pink[]   = {1.0,0.0,1.0,1.0};
const GLfloat gray[]   = {0.5,0.5,0.5,1.0};

/* Specific color */
const GLfloat color_glass[] = {0.3,0.5,0.9,0.5};
const GLfloat color_wall[]  = {1.0,0.5,0.0,1.0};
const GLfloat color_mud[]  = {0.3,0.3,0.3,1.0};

/* Standard light color */
const GLfloat ambient[]   = {0.0,0.0,0.0,0.0};
const GLfloat diffuse[]   = {0.0,0.0,0.0,0.0};
const GLfloat specular[]  = {1.0,1.0,1.0,1.0};
const GLint   shininess   = 128;
const GLfloat emission[]  = {0.0,0.0,0.0,0.0};

/* Specific lights color */
const GLfloat light_ambient[]  = {0.1,0.1,0.1,1.0};
const GLfloat light_diffuese[] = {0.8,0.8,0.8,1.0};
const GLfloat light_specular[] = {0.5,0.5,0.5,1.0};

#endif /* COLORS_H_ */
