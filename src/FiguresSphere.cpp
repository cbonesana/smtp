/*
 * FiguresSphere.cpp
 *
 *  Created on: Dec 17, 2012
 *      Author: rea
 */

#include "FiguresSphere.h"

using namespace std;


FiguresSphere::FiguresSphere(GLfloat x, GLfloat y, GLfloat z, GLfloat radius)
: Figures(x,y,z) {

	qObj = gluNewQuadric();
	gluQuadricNormals(qObj, GLU_SMOOTH);
	gluQuadricTexture(qObj, GL_TRUE);
	gluQuadricNormals(qObj, GLU_SMOOTH);
	gluQuadricOrientation(qObj, GLU_OUTSIDE);
	this->radius = radius;
	this->slices = 32;
	this->stacks = 32;

}

FiguresSphere::~FiguresSphere() {
	// TODO Auto-generated destructor stub
}

GLvoid FiguresSphere::draw(){
	glPushMatrix();

	if(!texture){
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);

	glMaterialfv(material_face,GL_AMBIENT,mat_ambient);
	glMaterialfv(material_face,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(material_face,GL_SPECULAR,mat_specular);
	glMateriali(material_face,GL_SHININESS,mat_shininess);
	glMaterialfv(material_face,GL_EMISSION,mat_emission);

	glTranslatef(this->cx,this->cy,this->cz);

	gluSphere(qObj, radius, slices, stacks);
	glNormal3f(0,0,1);	// quick fix for light normal
	glPopMatrix();

}


GLvoid FiguresSphere::setTexture(GLuint texture){
	this->texture = texture;
}
