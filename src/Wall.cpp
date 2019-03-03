/*
 * Wall.cpp
 *
 *  Created on: 30-dic-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 */

#include "Wall.h"

using namespace std;


Wall::Wall(GLfloat cx, GLfloat cy, GLfloat cz, GLfloat size, GLint rc) : Figures(cx,cy,cz){
	this->size_x = size;
	this->size_y = size;

	this->r = rc;
	this->c = rc;

	draw_back = true;

	v[0].x = cx-size/2;
	v[0].y = cy+size/2;
	v[0].z = cz;
	v[0].u = 0.0;
	v[0].v = 1.0;
	v[1].x = cx-size/2;
	v[1].y = cy-size/2;
	v[1].z = cz;
	v[1].u = 0.0;
	v[1].v = 0.0;
	v[2].x = cx+size/2;
	v[2].y = cy-size/2;
	v[2].z = cz;
	v[2].u = 1.0;
	v[2].v = 0.0;
	v[3].x = cx+size/2;
	v[3].y = cy+size/2;
	v[3].z = cz;
	v[3].u = 1.0;
	v[3].v = 1.0;

	this->initializeVertexMatrix();
}

Wall::Wall(GLfloat cx, GLfloat cy, GLfloat cz, GLfloat size_x, GLfloat size_y, GLint r, GLint c) : Figures(cx,cy,cz){
	this->size_x = size_x;
	this->size_y = size_y;

	this->r = r;
	this->c = c;

	draw_back = true;

	v[0].x = cx-size_x/2;
	v[0].y = cy+size_y/2;
	v[0].z = cz;
	v[0].u = 0.0;
	v[0].v = 1.0;
	v[1].x = cx-size_x/2;
	v[1].y = cy-size_y/2;
	v[1].z = cz;
	v[1].u = 0.0;
	v[1].v = 0.0;
	v[2].x = cx+size_x/2;
	v[2].y = cy-size_y/2;
	v[2].z = cz;
	v[2].u = 1.0;
	v[2].v = 0.0;
	v[3].x = cx+size_x/2;
	v[3].y = cy+size_y/2;
	v[3].z = cz;
	v[3].u = 1.0;
	v[3].v = 1.0;

	this->initializeVertexMatrix();
}

Wall::~Wall() {
	// TODO Auto-generated destructor stub
}

GLvoid Wall::setColor(int i, GLfloat r, GLfloat g, GLfloat b, GLfloat a){
	v[i].r = r;
	v[i].g = g;
	v[i].b = b;
	v[i].a = a;
}

GLvoid Wall::setColor(int i, const GLfloat *color){
	v[i].r = color[0];
	v[i].g = color[1];
	v[i].b = color[2];
	v[i].a = color[3];
}

GLvoid Wall::setTexture(GLuint texture){
	this->texture = texture;
}

GLvoid Wall::plus(Vertex *a, Vertex *b){
	a->x = a->x+b->x;
	a->y = a->y+b->y;
	a->z = a->z+b->z;
}

GLvoid Wall::initializeVertexMatrix(){
	punti = new Vertex*[r+1];
	for(int i = 0; i < r+1; ++i)
	    punti[i] = new Vertex[c+1];

	punti[0][0] = v[0];
	punti[r][0] = v[1];
	punti[0][c] = v[2];
	punti[r][c] = v[3];

	/* spostamento "verticale" sul vettore v1->v2 */
	GLfloat riga_d_x = fabs(v[0].x-v[1].x)/r;
	GLfloat riga_d_y = fabs(v[0].y-v[1].y)/r;
	GLfloat riga_d_z = fabs(v[0].z-v[1].z)/r;

	/* spostamento "orizzontale" sul vettore v1->v4 */
	GLfloat colo_d_x = fabs(v[0].x-v[3].x)/c;
	GLfloat colo_d_y = fabs(v[0].y-v[3].y)/c;
	GLfloat colo_d_z = fabs(v[0].z-v[3].z)/c;

	/* spostamento per la texture */
	GLfloat tex_u = 1.0/c;
	GLfloat tex_v = 1.0/r;

	Vertex temp = v[0];
	for (int j=0; j<=r; j++){

		for (int i=0; i<=c; i++){
			punti[j][i].x = temp.x;
			punti[j][i].y = temp.y;
			punti[j][i].z = temp.z;
			punti[j][i].u = temp.u;
			punti[j][i].v = temp.v;

			temp.x += colo_d_x;
			temp.y -= colo_d_y;
			temp.z += colo_d_z;
			temp.u += tex_u;
		}

		temp = punti[j][0];
		temp.x += riga_d_x;
		temp.y -= riga_d_y;
		temp.z += riga_d_z;
		temp.v -= tex_v;
	}

}

GLvoid Wall::drawFace(){
	glBegin(GL_TRIANGLE_STRIP);

	for (int j=0; j<r; j++){
		for (int i=0; i<=c; i++){
			glTexCoord2f(punti[j][i].u,punti[j][i].v);
			glVertex3f(punti[j][i].x,punti[j][i].y,punti[j][i].z);
			glTexCoord2f(punti[j+1][i].u,punti[j+1][i].v);
			glVertex3f(punti[j+1][i].x,punti[j+1][i].y,punti[j+1][i].z);
		}
	}

	glEnd();
}

GLvoid Wall::draw(/*Player *p*/){
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);

	glMaterialfv(material_face,GL_AMBIENT,mat_ambient);
	glMaterialfv(material_face,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(material_face,GL_SPECULAR,mat_specular);
	glMateriali(material_face,GL_SHININESS,mat_shininess);
	glMaterialfv(material_face,GL_EMISSION,mat_emission);

	/* Front face */
	glColor4f(v[0].r,v[0].g,v[0].b,v[0].a);
	this->drawFace();

	/* Back face */
	if(draw_back){
		glTranslatef(0.0,0.0,0.001);

		glBegin(GL_POLYGON);
		for (int i=3; i>=0; i--){
			glColor4f(v[i].r,v[i].g,v[i].b,v[i].a);
			glTexCoord2f(v[i].u,v[i].v);
			glVertex3f(v[i].x,v[i].y,v[i].z);
		}
		glEnd();
	}
	glPopMatrix();
}

GLvoid Wall::dontDrawBack(){
	draw_back = false;
}

GLvoid Wall::drawBack(){
	draw_back = true;
}
