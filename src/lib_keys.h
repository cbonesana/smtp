/*
 * lib_keys.h
 *
 *   Created on: 29-dic-2012
 *       Author: Claudio "Dna" Bonesana
 *  Description:
 *		This file manage key and special keys input signals from the keyboard.
 */

#ifndef LIB_KEYS_H_
#define LIB_KEYS_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

#include <cstdlib>
#include <cstdio>
#include <iostream>

#define ESCAPE 27						// ascii code for the escape key

#include "fog.h"
#include "lib_texture.h"
#include "object_pool.h"

using namespace std;

/* Key status values */
extern bool light;				// light on/off
extern bool blend;				// blend mode on/off
extern bool fullscreen;			// fullscreen mode on/off
extern bool wireframe;			// wireframe mode on/off

/**
 * Key values initialization function.
 */
void keyInit();

/**
 * Create window wrapper function.
 */
void createWindow();

/**
 * Fullscreen switch wrapper function.
 */
void switchFullScreen();

/**
 * Special keys pressed manager function: what to do when a special key is pressed?
 */
void specialKeyPressed(int key, int x, int y);

/**
 * Special keys release manager function: what to do when a special key is released?
 */
void specialKeyReleased(int key, int x, int y);

/**
 * Standard key pressed manager function: what to do when a standard key is pressed?
 */
void keyPressed(unsigned char key, int x, int y);

/**
 * Standard key released manager function: what to do when a standard key is released?
 */
void keyReleased(unsigned char key, int x, int y);

/**
 * Perform special keys operation.
 */
void keySpecialOperations();

/**
 * Perform standard keys operation.
 */
void keyOperations ();

#endif /* LIB_KEYS_H_ */
