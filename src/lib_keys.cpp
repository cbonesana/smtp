/*
 * lib_keys.cpp
 *
 *  Created on: 29-dic-2012
 *      Author: Claudio "Dna" Bonesana
 */


#include "lib_keys.h"

int window;

/* Command options */
bool light = true;
bool blend = true;
bool fullscreen = false;
bool wireframe = false;

/* Keyboard */
bool* keyStates = new bool[256];
bool* specialKeyStates = new bool[256];

void createWindow(){
	//window = glutCreateWindow("Jeff Molofee's GL Code Tutorial ... NeHe '99");
	window = glutCreateWindow(WINDOW_NAME);
}

void keyInit(){
	for(int i=0; i<256; i++){
		keyStates[i] = false;
		specialKeyStates[i] = false;
	}
}

void switchFullScreen(){
	if (fullscreen){
		glutReshapeWindow(INITIAL_WINDOW_WIDTH,INITIAL_WINDOW_HEIGHT);
		glutPositionWindow(0,0);
	} else {
		glutFullScreen();
	}
	fullscreen = !fullscreen;
}

void specialKeyPressed(int key, int x, int y){
	switch (key){
	case GLUT_KEY_F1:
		switchFullScreen();
		break;

	default:
		specialKeyStates[key] = true;
		break;
	}
}

void specialKeyReleased(int key, int x, int y){
	specialKeyStates[key] = false;
}

void keyPressed(unsigned char key, int x, int y) {
	if (key >= '0' && key <= '9'){
		// These keys are not used
	}

	switch(key){
	//	case 'q':		// close program
	//	case 'Q':
	case ESCAPE:
		cout << "Exit." << endl;
		glutDestroyWindow(window);
		exit(0);
		break;

	case 'b':		// switch the blend mode between enabled/disabled
	case 'B':
		cout << "B/b pressed; blending is: " << blend << endl;
		blend = !blend;
		if (blend) {
			glEnable(GL_BLEND);
		} else {
			glDisable(GL_BLEND);
		}
		cout << "Blending is now: " << blend << endl;
		break;

	case 'f':		// switch texture filter between 0/1/2
	case 'F':
		cout << "F/f pressed; texture filter is: " << textureFilter << endl;
		textureFilter++;
		if (textureFilter > 2) {
			textureFilter = 0;
		}
		cout << "Filter is now: " << textureFilter << endl;
		break;

	case 'g':		// switch fog filter between 0/1/2
	case 'G':
		cout << "G/g pressed; fog filter is: " << fogfilter << endl;
		fogfilter++;
		if (fogfilter > 2) {
			fogfilter = 0;
		}
		glFogi (GL_FOG_MODE, fogMode[fogfilter]);
		cout << "Fog level is now: " << fogfilter << endl;
		break;

	case 'n':		// switch fog status between enabled/disabled
	case 'N':
		cout << "N/n pressed; fog is: " << fogstatus << endl;
		fogstatus = !fogstatus;
		if (fogstatus){
			glEnable(GL_FOG);
		} else {
			glDisable(GL_FOG);
		}
		cout << "Fog status is now: " << fogfilter << endl;
		break;

	case 'l':		// switch the lighting status between enabled/disabled
	case 'L':
		cout << "L/l pressed; lighting is: " << light << endl;
		light = !light;
		if (light) {
			glEnable(GL_LIGHTING);
		} else {
			glDisable(GL_LIGHTING);
		}
		cout << "Lighting is now: " << light << endl;
		break;

	case 'h':		// switch the wireframe mode between enabled/disabled
	case 'H':
		cout << "H/h pressed; wireframe mode is " << wireframe << endl;
		wireframe = !wireframe;
		if(wireframe){
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		} else{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
		cout << "Wireframe is now: "  << wireframe << endl;
		break;

	default:		// perform standard key operation
		keyStates[key] = true;
		break;
	}
}

void keyReleased(unsigned char key, int x, int y){
	keyStates[key] = false;
}

void keySpecialOperations(){
	if (specialKeyStates[GLUT_KEY_UP]) 				// look up
		player->LookUp();
	if (specialKeyStates[GLUT_KEY_DOWN]) 			// look down
		player->LookDown();
	if (specialKeyStates[GLUT_KEY_LEFT]) 			// look left
		player->LookLeft();
	if (specialKeyStates[GLUT_KEY_RIGHT]) 			// look right
		player->LookRight();
}

void keyOperations () {
	// camera movement
	if(keyStates['w']){				// move forward on camera direction
		player->WalkForward();
	}
	if(keyStates['a']){				// move backward on camera direction
		player->StrafeLeft();
	}
	if(keyStates['s']){				// strafe left on camera direction
		player->WalkBackward();
	}
	if(keyStates['d']){				// strafe right on camera direction
		player->StrafeRight();
	}

	// cube movement
	if(keyStates['W']){				// move cube on -z axis
		cube->moveZ(-0.01);
	}
	if(keyStates['S']){				// move cube on +z axis
		cube->moveZ(0.01);
	}
	if(keyStates['A']){				// move cube on -x axis
		cube->moveX(-0.01);
	}
	if(keyStates['D']){				// move cube on +x axis
		cube->moveX(0.01);
	}
}

