/*
 * Figures.cpp
 *
 *  Created on: 11-nov-2012
 *       Author: Claudio "Dna" Bonesana
 *     Coworker: Nathan Koefer
 */

#include "Figures.h"

using namespace std;


Figures::Figures(GLfloat x, GLfloat y, GLfloat z) {
	this->cx = x;
	this->cy = y;
	this->cz = z;

	this->xrot = 0.0;
	this->yrot = 0.0;
	this->zrot = 0.0;

	GLfloat empty[]={0.0,0.0,0.0,1.0};

	this->setMaterialAmbient(empty);
	this->setMaterialDiffuse(empty);
	this->setMaterialSpecular(empty);
	this->setMaterialShininess(0);
	this->setMaterialEmission(empty);

	this->lighting = true;
	this->material_face = GL_FRONT_AND_BACK;
}

Figures::~Figures() {
	// TODO Auto-generated destructor stub
}

GLvoid Figures::increaseXrot(GLfloat value){
	xrot += value;
}

GLvoid Figures::increaseYrot(GLfloat value){
	yrot += value;
}

GLvoid Figures::increaseZrot(GLfloat value){
	zrot += value;
}

GLvoid Figures::moveX(GLfloat value){
	this->cx += value;
}

GLvoid Figures::moveY(GLfloat value){
	this->cy += value;
}

GLvoid Figures::moveZ(GLfloat value){
	this->cz += value;
}

GLvoid Figures::increaseXrot(){
	xrot += 0.5;
}

GLvoid Figures::increaseYrot(){
	yrot += 0.5;
}

GLvoid Figures::increaseZrot(){
	zrot += 0.5;
}

GLvoid Figures::rotateX(){
	glPushMatrix();

	glTranslatef(cx,cy,cz);
	glRotatef(xrot,1.0,0.0,0.0);
	draw();
	glRotatef(-xrot,1.0,0.0,0.0);
	glTranslatef(-cx,-cy,-cz);

	glPopMatrix();
}

GLvoid Figures::rotateY(){
	glPushMatrix();

	glTranslatef(cx,cy,cz);
	glRotatef(yrot,0.0,1.0,0.0);
	draw();
	glRotatef(-yrot,0.0,1.0,0.0);
	glTranslatef(-cx,-cy,-cz);

	glPopMatrix();
}

GLvoid Figures::rotateZ(){
	glPushMatrix();

	glTranslatef(cx,cy,cz);
	glRotatef(zrot,0.0,0.0,1.0);
	draw();
	glRotatef(-zrot,0.0,0.0,1.0);
	glTranslatef(-cx,-cy,-cz);

	glPopMatrix();
}

GLvoid Figures::rotateXY(){
	glPushMatrix();

	glTranslatef(cx,cy,cz);
	glRotatef(xrot,1.0,0.0,0.0);
	glRotatef(yrot,0.0,1.0,0.0);
	draw();
	glRotatef(-yrot,0.0,1.0,0.0);
	glRotatef(-xrot,1.0,0.0,0.0);
	glTranslatef(-cx,-cy,-cz);

	glPopMatrix();
}

GLvoid Figures::rotateXZ(){
	glPushMatrix();

	glTranslatef(cx,cy,cz);
	glRotatef(xrot,1.0,0.0,0.0);
	glRotatef(zrot,0.0,0.0,1.0);
	draw();
	glRotatef(-zrot,0.0,0.0,1.0);
	glRotatef(-xrot,1.0,0.0,0.0);
	glTranslatef(-cx,-cy,-cz);

	glPopMatrix();
}

GLvoid Figures::rotateYZ(){
	glPushMatrix();

	glTranslatef(cx,cy,cz);
	glRotatef(yrot,0.0,1.0,0.0);
	glRotatef(zrot,0.0,0.0,1.0);
	draw();
	glRotatef(-zrot,0.0,0.0,1.0);
	glRotatef(-yrot,0.0,1.0,0.0);
	glTranslatef(-cx,-cy,-cz);

	glPopMatrix();
}

GLvoid Figures::rotateXYZ(){
	glPushMatrix();

	glTranslatef(cx,cy,cz);
	glRotatef(xrot,1.0,0.0,0.0);
	glRotatef(yrot,0.0,1.0,0.0);
	glRotatef(zrot,0.0,0.0,1.0);
	draw();
	glRotatef(-zrot,0.0,0.0,1.0);
	glRotatef(-yrot,0.0,1.0,0.0);
	glRotatef(-xrot,1.0,0.0,0.0);
	glTranslatef(-cx,-cy,-cz);

	glPopMatrix();
}

GLvoid Figures::setMaterial(
		const GLfloat* ambient,
		const GLfloat* diffuse,
		const GLfloat* specular,
		GLint shininess,
		const GLfloat* emission
){
	this->setMaterialAmbient(ambient);
	this->setMaterialDiffuse(diffuse);
	this->setMaterialSpecular(specular);
	this->setMaterialShininess(shininess);
	this->setMaterialEmission(emission);
}

GLvoid Figures::setMaterialAmbient(const GLfloat *material){
	this->mat_ambient = material;
}

GLvoid Figures::setMaterialDiffuse(const GLfloat *material){
	this->mat_diffuse = material;
}

GLvoid Figures::setMaterialSpecular(const GLfloat *material){
	this->mat_specular = material;
}

GLvoid Figures::setMaterialShininess(GLint material){
	this->mat_shininess = material;
}

GLvoid Figures::setMaterialEmission(const GLfloat *material){
	this->mat_emission = material;
}

GLvoid Figures::enableLighting(){
	this->lighting = true;
}

GLvoid Figures::disableLighting(){
	this->lighting = false;
}

GLvoid Figures::setmaterialFace(GLenum face){
	this->material_face = face;
}
