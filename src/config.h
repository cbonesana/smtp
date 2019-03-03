/*
 * config.h
 *
 *   Created on: 29-dic-2012
 *       Author: Claudio "Dna" Bonesana
 *     Coworker: Nathan Koefer
 *  Description:
 *  	This configuration file is used to define global values.
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

#define WINDOW_NAME "SMTP - Small Material and Texture Project"

#define INITIAL_WINDOW_WIDTH 640	// Default window width, used in initialization
#define INITIAL_WINDOW_HEIGHT 480	// Default window height, used in initialization

#define CUBE_X 0.0					// Starting cube position X
#define CUBE_Y 0.3					// Starting cube position Y
#define CUBE_Z -1.0					// Starting cube position Z
#define CUBE_SIZE 0.2				// Starting cube size

#define SPHERE_X -1.0				// Starting sphere position X
#define SPHERE_Y 0.3				// Starting sphere position Y
#define SPHERE_Z 0.0				// Starting sphere position Z
#define SPHERE_SIZE 0.2				// Starting sphere size

#define SPOT1 1						// Value definition for spot number 1
#define SPOT2 2						// Value definition for spot number 2
#define SPOT3 3						// Value definition for spot number 3
#define SPOT4 4						// Value definition for spot number 4


/* Special spot parameters */
const GLfloat spot0position[]  = { 1.0,0.5,0.0,1.0};
const GLfloat spot0direction[] = { 1.0,0.5,-2.0};

const GLfloat spot1position[]  = {-1.0,0.5,0.0,1.0};
const GLfloat spot1direction[] = {-1.0,0.5,-2.0};

#endif /* CONFIG_H_ */
