/*
 * Player.h
 *
 *  Created on: 10-nov-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 * Description:
 *  	This class create and manage camera-objects. The position of this object should be used in the
 *  	gluLookAt() function parameters.
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

#include <cmath>

class Player {
private:
	/* Eye position */
	GLfloat xpos;
	GLfloat ypos;
	GLfloat zpos;
	/* Target position */
	GLfloat xcenter;
	GLfloat ycenter;
	GLfloat zcenter;
	/* Eye vertical */
	GLfloat xnormal;
	GLfloat ynormal;
	GLfloat znormal;

	GLfloat heading_h;
	GLfloat heading_v;

	GLfloat speed;

	static float piover180;

	GLfloat sin_speed_heading_h;
	GLfloat cos_speed_heading_h;
	GLfloat sin_speed_heading_v;
	GLfloat cos_speed_heading_v;

	GLfloat seno(GLfloat heading, GLfloat speed);
	GLfloat coseno(GLfloat heading, GLfloat speed);

public:
	Player();
	virtual ~Player();

	GLvoid WalkForward();
	GLvoid WalkBackward();
	GLvoid StrafeLeft();
	GLvoid StrafeRight();

	GLvoid LookLeft();
	GLvoid LookRight();
	GLvoid LookUp();
	GLvoid LookDown();

	GLvoid BendLeft();
	GLvoid BendRight();

	GLfloat getXcenter() const {
		return xcenter;
	}

	GLfloat getXnormal() const {
		return xnormal;
	}

	GLfloat getYcenter() const {
		return ycenter;
	}

	GLfloat getYnormal() const {
		return ynormal;
	}

	GLfloat getZcenter() const {
		return zcenter;
	}

	GLfloat getZnormal() const {
		return znormal;
	}

	GLfloat getXpos() const {
		return xpos;
	}

	GLfloat getYpos() const {
		return ypos;
	}

	GLfloat getZpos() const {
		return zpos;
	}

};

#endif /* PLAYER_H_ */
