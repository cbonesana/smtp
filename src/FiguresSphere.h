/*
 * FiguresSphere.h
 *
 *  Created on: Dec 17, 2012
 *      Author: Nathan Koefer
 *    Coworker: Claudio "Dna" Bonesana
 * Description:
 * 		This class is used to control Sphere objects.
 */

#ifndef FIGURESSPHERE_H_
#define FIGURESSPHERE_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif


#include "Figures.h"


class FiguresSphere: public Figures {

private:
	GLfloat radius;
	GLint slices;
	GLint stacks;
	GLuint texture;
	GLUquadricObj *qObj;

public:
	FiguresSphere(GLfloat x, GLfloat y, GLfloat z, GLfloat radius);
	virtual ~FiguresSphere();

	GLvoid setTexture(GLuint texture);

	GLvoid draw();

};

#endif /* FIGURESSPHERE_H_ */
