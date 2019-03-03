/*
 * type.h
 *
 *   Created on: 29-dic-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 * Description:
 *  	Pool of new type definitions.
 */

#ifndef TYPE_H_
#define TYPE_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif


typedef struct {
	GLfloat x, y, z;		// 3D coordinates
	GLfloat r,g,b,a;		// RGBA color
	GLfloat u, v;           // Texture coordinates
} Vertex;

typedef struct {
	Vertex vertex[3];		// Array of three Vertices
} Triangle;

typedef struct {
	int numtriangles;       // Number Of Triangles In Sector
	Triangle* triangle;     // Pointer To Array Of Triangles
} Sector;

#endif /* TYPE_H_ */
