/*
 * lib_mouse.cpp
 *
 *  Created on: 30-dic-2012
 *      Author: Claudio "Dna" Bonesana
 */

#include "lib_mouse.h"

#define DIV 1
#define FREEDOM 200

using namespace std;

void mouse(int button, int state, int x, int y){
	cout << "[Mouse] Button: " << button << endl;
	cout << "[Mouse] State: " << state << endl;
	cout << "[Mouse] x and y: " << x << " " << y << endl;
	// what else? :D
}

void mouseDragged(int x, int y){
	static int xOld = 0;
	static int yOld = 0;
	int xNow = x/DIV;
	int yNow = y/DIV;
	int delta;
	static bool first = true;

	if(first){
		first = false;
		delta = 0;
		xOld = 0;
		yOld = 0;
	} else {
		delta = xOld - xNow;
		if(delta > 0) {
			player->LookLeft();
		} else if(delta < 0) {
			player->LookRight();
		}

		delta = yOld - yNow;
		if(delta > 0) {
			player->LookUp();
		} else if(delta < 0) {
			player->LookDown();
		}
	}

	if(
			(abs(x-glutGet(GLUT_WINDOW_WIDTH)/2)>FREEDOM) ||
			(abs(y-glutGet(GLUT_WINDOW_HEIGHT)/2)>FREEDOM)
	) {
		first = true;
		glutWarpPointer(
				glutGet(GLUT_WINDOW_X)+glutGet(GLUT_WINDOW_WIDTH)/2,
				glutGet(GLUT_WINDOW_Y)+glutGet(GLUT_WINDOW_HEIGHT)/2
		);
	} else {
		xOld = x/DIV;
		yOld = y/DIV;
	}
}
