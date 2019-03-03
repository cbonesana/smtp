/*
 * Player.cpp
 *
 *  Created on: 10-nov-2012
 *      Author: dna
 *     Coworker: Nathan Koefer
 */

#include "Player.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define HEADING_H_STEP	1.0f
#define HEADING_V_STEP	HEADING_H_STEP

float Player::piover180 = 4*atan(1)/180.0;

Player::Player() {
	xpos=0.0f;
	ypos=0.5f;
	zpos=0.0f;

	xcenter=xpos;
	ycenter=ypos;
	zcenter=zpos-1.0f;

	xnormal=xpos;
	ynormal=ypos+1.0;
	znormal=zpos;

	speed=0.01f;

	heading_h=0.0f;
	heading_v=0.0f;

	sin_speed_heading_h = seno(heading_h, speed);
	cos_speed_heading_h = coseno(heading_h, speed);
	sin_speed_heading_v = seno(heading_v, speed);
	cos_speed_heading_v = coseno(heading_v, speed);
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

GLfloat Player::seno(GLfloat heading, GLfloat s){
	return (float)sin(heading*piover180) * s;
}

GLfloat Player::coseno(GLfloat heading, GLfloat s){
	return (float)cos(heading*piover180) * s;
}

GLvoid Player::WalkForward() {
	// To walk both xycenter and xyposition must change
	xpos -= sin_speed_heading_h;
	zpos -= cos_speed_heading_h;

	xcenter -= sin_speed_heading_h;
	zcenter -= cos_speed_heading_h;
}

GLvoid Player::WalkBackward() {
	// To walk both xycenter and xyposition must change
	xpos += sin_speed_heading_h;
	zpos += cos_speed_heading_h;

	xcenter += sin_speed_heading_h;
	zcenter += cos_speed_heading_h;
}

GLvoid Player::StrafeLeft(){
	// To strafe both xycenter and xyposition must change
	xpos += -cos_speed_heading_h;
	zpos += sin_speed_heading_h;

	xcenter += -cos_speed_heading_h;
	zcenter += sin_speed_heading_h;

}

GLvoid Player::StrafeRight(){
	// To strafe both xycenter and xyposition must change
	xpos += cos_speed_heading_h;
	zpos += -sin_speed_heading_h;

	xcenter += cos_speed_heading_h;
	zcenter += -sin_speed_heading_h;
}

GLvoid Player::LookLeft() {
	//heading_h+=0.5f;
	heading_h+=HEADING_H_STEP;
	if (heading_h > 359.5)
		heading_h = 0.0;
	sin_speed_heading_h = seno(heading_h,this->speed);
	cos_speed_heading_h = coseno(heading_h,this->speed);

	// Look left change only the x and zcenter position
	xcenter = xpos-sin_speed_heading_h;
	zcenter = zpos-cos_speed_heading_h;
}

GLvoid Player::LookRight() {
	heading_h-=HEADING_H_STEP;
	if (heading_h < -359.5)
		heading_h = 0.0;
	sin_speed_heading_h = seno(heading_h,this->speed);
	cos_speed_heading_h = coseno(heading_h,this->speed);

	// Look right change the x and zcenter position
	xcenter = xpos-sin_speed_heading_h;
	zcenter = zpos-cos_speed_heading_h;
}

GLvoid Player::LookUp() {
	heading_v-=HEADING_V_STEP;
	if (heading_h < -359.5)
		heading_h = 0.0;
	sin_speed_heading_v = seno(heading_v,this->speed);
	cos_speed_heading_v = coseno(heading_v,this->speed);

	// Look up change only the ycenter vertical position
	ycenter = ypos-sin_speed_heading_v;
}

GLvoid Player::LookDown() {
	heading_v+=HEADING_V_STEP;
	if (heading_h > 359.5)
		heading_h = 0.0;
	sin_speed_heading_v = seno(heading_v,this->speed);
	cos_speed_heading_v = coseno(heading_v,this->speed);

	// Look down change only the ycenter vertical position
	ycenter = ypos-sin_speed_heading_v;
}
