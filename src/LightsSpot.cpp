/*
 * LightsSpot.cpp
 *
 *  Created on: 31-dic-2012
 *      Author: Claudio "Dna" Bonesana
 */

#include "LightsSpot.h"

#define W 3
#define dX 0
#define dY 1
#define dZ 2

#include <cmath>

using namespace std;


LightsSpot::LightsSpot(GLfloat x, GLfloat y, GLfloat z, GLenum light, GLfloat dirx, GLfloat diry, GLfloat dirz) : Lights(x,y,z,light) {
	position[W] = 1.0;

	direction = new GLfloat[3];
	direction[dX] = dirx-x;
	direction[dY] = diry-y;
	direction[dZ] = dirz-z;

	spot_cutoff = 30.0;
	spot_exponent = 2.0;

	fqobj = gluNewQuadric();
	gluQuadricDrawStyle(fqobj,GLU_FILL);
	gluQuadricOrientation(fqobj,GLU_OUTSIDE);
	gluQuadricNormals(fqobj,GLU_SMOOTH);

}

LightsSpot::~LightsSpot() {}

GLvoid LightsSpot::setUpLight(){
	glDisable(light);
	if (color_ambient != 0)
		glLightfv(light,GL_AMBIENT,color_ambient);
	if (color_diffuse != 0)
		glLightfv(light,GL_DIFFUSE,color_diffuse);
	if (color_specular != 0)
		glLightfv(light,GL_SPECULAR,color_specular);
	glLightf(light,GL_SPOT_CUTOFF,spot_cutoff);
	glLightf(light,GL_SPOT_EXPONENT,spot_exponent);
	glLightfv(light,GL_POSITION,position);
	glLightfv(light,GL_SPOT_DIRECTION,direction);
	glEnable(light);
}

GLvoid LightsSpot::setSpotCutoff(GLfloat cutoff){
	spot_cutoff = cutoff;
}

GLvoid LightsSpot::setSpotExponent(GLfloat exponent){
	spot_exponent = exponent;
}

GLvoid LightsSpot::setDir(GLfloat direction[3]){
	this->direction = direction;
}

GLvoid LightsSpot::setDirX(GLfloat x){
	direction[dX] = x;
}

GLvoid LightsSpot::setDirY(GLfloat y){
	direction[dY] = y;
}

GLvoid LightsSpot::setDirZ(GLfloat z){
	direction[dZ] = z;
}

GLfloat *LightsSpot::getDirection(){
	return direction;
}

GLvoid LightsSpot::drawCone(){
	glPushMatrix();

	GLfloat mat[] = {1.0,1.0,1.0,1.0,};
	GLfloat black[] = {0.0,0.0,0.0,1.0};

	glColor3f(1.0,1.0,1.0);
	glColorMaterial(GL_FRONT,GL_EMISSION);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	glMateriali(GL_FRONT,GL_SHININESS,0);

	gluCylinder(fqobj,0.2,0.0,1.0,16,16);

	glPopMatrix();
}
