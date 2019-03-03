/*
 * object_pool.h
 *
 *  Created on: 29-dic-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 * Description:
 * 		This is a simple pool of object. Every object used in this scene is create by these builder functions,
 * 		but they can be invoked using their variable names or using builder functions.
 */

#ifndef OBJECT_POOL_H_
#define OBJECT_POOL_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

#include "vector"

#include "lib_types.h"
#include "lib_colors.h"

#include "Player.h"
#include "Figures.h"
#include "FiguresCube.h"
#include "FiguresSphere.h"
#include "Wall.h"

#include "Lights.h"
#include "LightsSpot.h"

/* Object in the scene */
extern Player *player;
extern Figures *cube;
extern Figures *sphere;

extern Wall *glass;
extern Wall *wall;
extern Wall *wall_tiny;

extern Wall *mud;

extern Lights *light0;

extern LightsSpot *spot1;
extern LightsSpot *spot2;
extern LightsSpot *spot3;
extern LightsSpot *spot4;

/**
 * Builder for the camera.
 */
Player *buildPlayer();

/**
 * Builder for the cube.
 */
Figures *buildCube(GLfloat x, GLfloat y, GLfloat z, GLfloat size);

/**
 *  Builder for the sphere.
 */
Figures *buildSphere(GLfloat x, GLfloat y, GLfloat z, GLfloat size);

/**
 * Builder for the glass-wall.
 */
Wall *buildGlass(GLfloat x, GLfloat y, GLfloat z, GLfloat size);

/**
 * Builder for the main wall portion.
 */
Wall *buildWall(GLfloat x, GLfloat y, GLfloat z, GLfloat size);

/**
 * Builder for the tiny wall portion.
 */
Wall *buildWallTiny(GLfloat x, GLfloat y, GLfloat z, GLfloat size_x, GLfloat size_y);

/**
 * Builder for the floor.
 */
Wall *buildMud(GLfloat x, GLfloat y, GLfloat z, GLfloat size);

/**
 * Builder for all the spot lights. Id is the number of the spot from 1 to 4.
 */
LightsSpot *buildSpot(int id, GLfloat x, GLfloat y, GLfloat z, GLenum light, GLfloat dirx, GLfloat diry, GLfloat dirz);

/**
 * Builder for standard light. Actually only id 0 is used.
 */
Lights *buildLight(int id, GLfloat x, GLfloat y, GLfloat z, GLenum light);


#endif /* OBJECT_POOL_H_ */
