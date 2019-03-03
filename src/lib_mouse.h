/*
 * lib_mouse.h
 *
 *   Created on: 30-dic-2012
 *       Author: Claudio "Dna" Bonesana
 *  Description:
 *		This file manage movements and input from the mouse signals.
 */

#ifndef LIB_MOUSE_H_
#define LIB_MOUSE_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "object_pool.h"

/**
 * Mouse input function.
 */
void mouse(int button, int state, int x, int y);

/**
 * Mouse movement catch function.
 */
void mouseDragged(int x, int y);

#endif /* LIB_MOUSE_H_ */
