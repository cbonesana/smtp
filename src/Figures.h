/*
 * Figures.h
 *
 *  Created on: 11-nov-2012
 *       Author: Claudio "Dna" Bonesana
 *     Coworker: Nathan Koefer
 *  Description:
 *  	This is the main class that will be extended by every single Figures (cubes, walls, spheres, glass).
 *  	It offers a standard set of function to control position, orientation and mouvements.
 */

#ifndef FIGURES_H_
#define FIGURES_H_

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

#include "lib_types.h"

#include <iostream>
#include <cstdio>

#define F_CUBE 6

class Figures {
protected:
	GLfloat cx,cy,cz;
	GLfloat xrot,yrot,zrot;
	int vertex_per_faces;

	Vertex *vdata;

	/**
	 * Default: empty = {0.0,0.0,0.0,1.0}
	 */
	const GLfloat *mat_ambient;
	const GLfloat *mat_diffuse;
	const GLfloat *mat_specular;
	GLint mat_shininess;
	const GLfloat *mat_emission;

	/**
	 * Default: true
	 */
	GLboolean lighting;

	/**
	 * Default: GL_FRONT_AND_BACK
	 */
	GLenum material_face;

public:
	Figures(GLfloat x, GLfloat y, GLfloat z);
	virtual ~Figures();

	virtual GLvoid draw() = 0;
	virtual GLvoid setTexture(GLuint texture) = 0;

	GLvoid increaseXrot(GLfloat value);
	GLvoid increaseYrot(GLfloat value);
	GLvoid increaseZrot(GLfloat value);

	GLvoid moveX(GLfloat value);
	GLvoid moveY(GLfloat value);
	GLvoid moveZ(GLfloat value);

	GLvoid increaseXrot();
	GLvoid increaseYrot();
	GLvoid increaseZrot();

	/**
	 * Draw a figure rotate of xrot degree on X axis.
	 */
	GLvoid rotateX();
	/**
	 * Draw a figure rotate of yrot degree on Y axis.
	 */
	GLvoid rotateY();
	/**
	 * Draw a figure rotate of zrot degree on Z axis.
	 */
	GLvoid rotateZ();

	/**
	 * Draw a figure rotate of xrot degree on X axis and yrot degree on Y axis.
	 */
	GLvoid rotateXY();
	/**
	 * Draw a figure rotate of xrot degree on X axis and zrot degree on Z axis.
	 */
	GLvoid rotateXZ();
	/**
	 * Draw a figure rotate of yrot degree on Y axis and zrot degree on Z axis.
	 */
	GLvoid rotateYZ();

	/**
	 * Draw a figure rotate of xrot degree on X axis, yrot degree on Y axis and zrot degree on Z axis.
	 */
	GLvoid rotateXYZ();

	GLvoid setMaterial(
			const GLfloat* ambient,
			const GLfloat* diffuse,
			const GLfloat* specular,
			GLint shininess,
			const GLfloat* emission
	);

	GLvoid setMaterialAmbient(const GLfloat* material);
	GLvoid setMaterialDiffuse(const GLfloat* material);
	GLvoid setMaterialSpecular(const GLfloat* material);
	GLvoid setMaterialShininess(GLint material);
	GLvoid setMaterialEmission(const GLfloat* material);

	GLvoid enableLighting();
	GLvoid disableLighting();

	GLvoid setmaterialFace(GLenum face);
};

#endif /* FIGURES_H_ */
