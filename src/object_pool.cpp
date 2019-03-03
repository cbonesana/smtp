/*
 * object_pool.cpp
 *
 *  Created on: 29-dic-2012
 *      Author: Claudio "Dna" Bonesana
 *    Coworker: Nathan Koefer
 */

#include "object_pool.h"

Player *player;
Figures *cube;
Figures *sphere;

Wall *glass;
Wall *wall;
Wall *wall_tiny;

Wall *mud;

Lights *light0;

LightsSpot *spot1;
LightsSpot *spot2;
LightsSpot *spot3;
LightsSpot *spot4;

bool flag_player    = false;
bool flag_cube      = false;
bool flag_sphere    = false;
bool flag_glass     = false;
bool flag_wall      = false;
bool flag_wall_tiny = false;
bool flag_mud 		= false;

bool flag_light0 = false;
bool flag_spot1  = false;
bool flag_spot2  = false;
bool flag_spot3  = false;
bool flag_spot4  = false;

Player *buildPlayer(){
	if (!flag_player){
		player = new Player();
		flag_player = true;
	}
	return player;
}

Figures *buildCube(GLfloat x, GLfloat y, GLfloat z, GLfloat size){
	if (!flag_cube){
		cube = (Figures *) (new FiguresCube(x,y,z,size,16));
		flag_cube = true;
	}
	return cube;
}

Figures *buildSphere(GLfloat x, GLfloat y, GLfloat z, GLfloat size){
	if (!flag_sphere){
		sphere = (Figures *) (new FiguresSphere(x,y,z,size));
		flag_sphere = true;
	}
	return sphere;
}

Wall *buildGlass(GLfloat x, GLfloat y, GLfloat z, GLfloat size){
	if (!flag_glass){
		glass = new Wall(x,y,z,size,32);
		flag_glass = true;
	}
	return glass;
}

Wall *buildWall(GLfloat x, GLfloat y, GLfloat z, GLfloat size){
	if (!flag_wall){
		wall = new Wall(x,y,z,size,32);
		flag_wall= true;
	}
	return wall;
}

Wall *buildWallTiny(GLfloat x, GLfloat y, GLfloat z, GLfloat size_x, GLfloat size_y){
	if (!flag_wall_tiny){
		wall_tiny = new Wall(x,y,z,size_x,size_y,16,32);
		flag_wall_tiny= true;
	}
	return wall_tiny;
}

Wall *buildMud(GLfloat x, GLfloat y, GLfloat z, GLfloat size){
	if (!flag_mud){
		mud = new Wall(x,y,z,size,64);
		flag_mud= true;
	}
	return mud;
}

LightsSpot *buildSpot(int id, GLfloat x, GLfloat y, GLfloat z, GLenum light, GLfloat dirx, GLfloat diry, GLfloat dirz){
	switch (id) {
	case 1:
		if (!flag_spot1){
			spot1 = new LightsSpot(x,y,z,GL_LIGHT1,dirx,diry,dirz);
		}
		return spot1;
	case 2:
		if (!flag_spot2){
			spot2 = new LightsSpot(x,y,z,GL_LIGHT2,dirx,diry,dirz);
		}
		return spot2;
	case 3:
		if (!flag_spot3){
			spot3 = new LightsSpot(x,y,z,GL_LIGHT3,dirx,diry,dirz);
		}
		return spot3;
	case 4:
		if (!flag_spot4){
			spot4 = new LightsSpot(x,y,z,GL_LIGHT4,dirx,diry,dirz);
		}
		return spot4;
	default:
		return NULL;
	}
}

Lights *buildLight(int id, GLfloat x, GLfloat y, GLfloat z, GLenum light){
	switch (id) {
	case 0:
		if (!flag_light0){
			light0 = new Lights(x,y,z,GL_LIGHT0);
		}
		return light0;
	default:
		return NULL;
	}
}

