/*
 * Lights.h
 *
 *  Created on: 18-dic-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 * Description:
 * 		This class is used to manage light position, color and orientation.
 */

#ifndef LIGHTS_H_
#define LIGHTS_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

using namespace std;


class Lights {

protected:
	/*
	 * Array of 3 float.
	 */
	GLfloat *position;

	/*
	 * OpenGL light name.
	 */
	GLenum light;

	const GLfloat *color_ambient;
	const GLfloat *color_diffuse;
	const GLfloat *color_specular;

public:
	Lights(GLfloat x, GLfloat y, GLfloat z, GLenum light);
	virtual ~Lights();

	/*
	 * Return the OpenGL light name.
	 */
	GLenum getLight();

	/*
	 * Activate the light.
	 */
	GLvoid setUpLight();

	GLvoid setColorAmbient(const GLfloat *color);
	GLvoid setColorDiffuse(const GLfloat *color);
	GLvoid setColorSpecular(const GLfloat *color);

	GLvoid clearColorAmbient();
	GLvoid clearColorDiffuse();
	GLvoid clearColorSpecular();

	GLvoid setX(GLfloat x);
	GLvoid setY(GLfloat y);
	GLvoid setZ(GLfloat z);

	GLfloat *getPosition();
};

#endif /* LIGHTS_H_ */
