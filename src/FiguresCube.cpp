/*
 * FiguresCube.cpp
 *
 *  Created on: 3-dic-2012
 *      Author: Claudio "Dna" Bonesana
 */

#include "FiguresCube.h"

using namespace std;


FiguresCube::FiguresCube(GLfloat x, GLfloat y, GLfloat z, GLfloat size, GLint rc) : Figures(x,y,z){
	this->size = size;
	faces = new Wall(0.0,0.0,0.0,size,rc);
}

FiguresCube::~FiguresCube() {
	// TODO Auto-generated destructor stub
}

GLvoid FiguresCube::setTexture(GLuint texture){
	this->texture = texture;
}


GLvoid FiguresCube::draw(){

	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);

	if (mat_ambient != 0) glMaterialfv(material_face,GL_AMBIENT,mat_ambient);
	if (mat_diffuse != 0) glMaterialfv(material_face,GL_DIFFUSE,mat_diffuse);
	if (mat_specular != 0) glMaterialfv(material_face,GL_SPECULAR,mat_specular);
	if (mat_shininess != 0) glMateriali(material_face,GL_SHININESS,mat_shininess);
	if (mat_emission != 0) glMaterialfv(material_face,GL_EMISSION,mat_emission);

	glColor4f(1.0,1.0,1.0,1.0);

	// Draw 4 faces
	for (int i=0; i<4; i++){
		glTranslatef(0.0,0.0,size/2);
		faces->drawFace();
		glTranslatef(0.0,0.0,-size/2);
		glRotatef(90.0,0.0,1.0,0.0);
	}

	// Draw last 2 faces
	glRotatef(90.0,1.0,0.0,0.0);
	for (int i=0; i<2; i++){
		glTranslatef(0.0,0.0,size/2);
		faces->drawFace();
		glTranslatef(0.0,0.0,-size/2);
		glRotatef(180.0,0.0,1.0,0.0);
	}

	glTranslatef(this->cx,this->cy,this->cz);

	glPopMatrix();
}
