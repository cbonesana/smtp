/*
 * FiguresCube.h
 *
 *   Created on: 3-dic-2012
 *       Author: Claudio "Dna" Bonesana
 *     Coworker: Nathan Koefer
 *  Description:
 *  	This class is used to create and control a cube.
 */

#ifndef FIGURESCUBE_H_
#define FIGURESCUBE_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

#include "Figures.h"
#include "Wall.h"


class FiguresCube: public Figures {

private:

	GLfloat size;
	/*
	 * Always 6. required by parent class.
	 */
	Wall *faces;
	GLuint texture;

public:
	/*
	 * Parameter rc is the number of subdivision, used to map the texture on the face surface.
	 * The idea is like a very primitive tessellation.
	 */
	FiguresCube(GLfloat x, GLfloat y, GLfloat z, GLfloat size, GLint rc);
	virtual ~FiguresCube();

	GLvoid setTexture(GLuint texture);

	GLvoid draw();
};

#endif /* FIGURESCUBE_H_ */
