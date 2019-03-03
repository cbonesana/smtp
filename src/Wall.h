/*
 * Wall.h
 *
 *  Created on: 30-dic-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 * Description:
 * 		This class manage wall-type objects. It extends Figures.
 */

#ifndef GLASS_H_
#define GLASS_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

#include "Player.h"
#include "Figures.h"
#include "lib_types.h"


class Wall : public Figures {
private:
	/*
	 * Vertici estremi dei 4 angoli
	 */
	Vertex v[4];
	/*
	 * Colore complessivo dei vertici
	 */
	GLfloat *color;
	/*
	 * Larghezza del riquadro.
	 */
	GLfloat size_x;
	/*
	 * Altezza del riquadro.
	 */
	GLfloat size_y;

	bool draw_back;

	GLuint texture;

	GLint r;	// suddivisione per righe
	GLint c;	// suddivisione per colonne

	Vertex **punti;	/* matrice dei punti */

	GLvoid initializeVertexMatrix();

	GLvoid plus(Vertex *a, Vertex *b);

public:
	Wall(GLfloat cx, GLfloat cy, GLfloat cz, GLfloat size, GLint rc);
	Wall(GLfloat cx, GLfloat cy, GLfloat cz, GLfloat size_x, GLfloat size_y, GLint r, GLint c);
	virtual ~Wall();

	GLvoid setColor(int i, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
	GLvoid setColor(int i, const GLfloat *color);

	GLvoid setTexture(GLuint texture);

	GLvoid draw();
	GLvoid drawFace();

	GLvoid dontDrawBack();
	GLvoid drawBack();
};

#endif /* GLASS_H_ */
