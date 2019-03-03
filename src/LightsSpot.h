/*
 * LightsSpot.h
 *
 *   Created on: 31-dic-2012
 *       Author: Claudio "Dna" Bonesana
 *     Coworker: Nathan Koefer
 *  Description:
 *  	This class extends Lights to create Spot objects. Spot object are standard OpenGL spotlight.
 */

#ifndef LIGHTSSPOT_H_
#define LIGHTSSPOT_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

#include "Lights.h"

class LightsSpot: public Lights {
private:
	GLfloat *direction;

	GLfloat spot_cutoff;
	GLfloat spot_exponent;

	GLUquadric *fqobj;

public:
	LightsSpot(GLfloat x, GLfloat y, GLfloat z, GLenum light, GLfloat dirx, GLfloat diry, GLfloat dirz);
	virtual ~LightsSpot();

	GLvoid setUpLight();

	GLvoid setSpotCutoff(GLfloat cutoff);
	GLvoid setSpotExponent(GLfloat exponent);

	GLvoid setDir(GLfloat *direction);
	GLvoid setDirX(GLfloat x);
	GLvoid setDirY(GLfloat y);
	GLvoid setDirZ(GLfloat z);

	GLvoid drawCone();

	GLfloat *getDirection();
};

#endif /* LIGHTSSPOT_H_ */
