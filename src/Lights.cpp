/*
 * Lights.cpp
 *
 *  Created on: 18-dic-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 */

#include "Lights.h"

#define X 0
#define Y 1
#define Z 2
#define W 3

Lights::Lights(GLfloat x, GLfloat y, GLfloat z, GLenum light){
	position = new GLfloat[4];

	position[X] = x;
	position[Y] = y;
	position[Z] = z;
	position[W] = 0.0;

	this->light = light;

	color_ambient = 0;
	color_diffuse = 0;
	color_specular = 0;
}

Lights::~Lights(){}

GLenum Lights::getLight(){
	return light;
}

GLvoid Lights::setUpLight(){
	glDisable(light);
	if (color_ambient != 0)
		glLightfv(light,GL_AMBIENT,color_ambient);
	if (color_diffuse != 0)
		glLightfv(light,GL_DIFFUSE,color_diffuse);
	if (color_specular != 0)
		glLightfv(light,GL_SPECULAR,color_specular);
	glLightfv(light,GL_POSITION,position);
	glEnable(light);
}

GLvoid Lights::setColorAmbient(const GLfloat *color){
	color_ambient = color;
}

GLvoid Lights::setColorDiffuse(const GLfloat *color){
	color_diffuse = color;
}

GLvoid Lights::setColorSpecular(const GLfloat *color){
	color_specular = color;
}

GLvoid Lights::clearColorAmbient(){
	color_ambient = 0;
}

GLvoid Lights::clearColorDiffuse(){
	color_diffuse = 0;
}

GLvoid Lights::clearColorSpecular(){
	color_specular = 0;
}

GLvoid Lights::setX(GLfloat x){
	position[X] = x;
}

GLvoid Lights::setY(GLfloat y){
	position[Y] = y;
}

GLvoid Lights::setZ(GLfloat z){
	position[Z] = z;
}

GLfloat *Lights::getPosition(){
	return position;
}
