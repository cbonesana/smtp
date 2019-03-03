/*
 * This code was initially created by Jeff Molofee '99 and ported to Linux/GLUT by Richard Campbell '99.
 * Visit him at www.demonews.com/hosted/nehe
 * (email Richard Campbell at ulmont@bellsouth.net)
 *
 * It was extended in 2012 by Claudio Bonesana and Nathan Koefer at SUPSI-DTI.
 *
 * Author: 					Claudio "Dna" Bonesana
 * 							Nathan Koefer
 * Project Name:			SMTP - Small Material and Texture Project
 * Project Objective: 		Texture in OpenGL.
 * Date:					1-10-2012 - 13-1-2013
 * Version:					1.0
 *
 */

#ifndef _LINUX_GL_LIBRARIES
#define _LINUX_GL_LIBRARIES

#include <GL/glut.h>    				// Header File For The GLUT Library
#include <GL/gl.h>						// Header File For The OpenGL32 Library
#include <GL/glu.h>						// Header File For The GLu32 Library

#endif

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string.h>

#include "config.h"
#include "object_pool.h"

#include "lib_colors.h"
#include "lib_keys.h"
#include "lib_mouse.h"
#include "lib_texture.h"
#include "lib_types.h"
#include "lib_utility.h"

#include "Lights.h"

using namespace std;


GLsizei window_w = INITIAL_WINDOW_WIDTH;
GLsizei window_h = INITIAL_WINDOW_HEIGHT;

/* Iamge data used for the textures */
char files[5][16] = {
		"Data/world.txt",
		"Data/crate.bmp",
		"Data/glass.bmp",
		"Data/tech.bmp",
		"Data/3kHD.bmp"
};

void print_string(char* str, GLfloat x, GLfloat y, GLfloat z, GLfloat scale){
	glPushMatrix();
		glPushAttrib(GL_DEPTH_TEST);
			glDisable(GL_DEPTH_TEST);
			glColor4fv(green);
			glPointSize(0.1);
			glTranslatef(x,y,z);
			glScalef(scale,scale,scale);
			glDisable(GL_TEXTURE);
			glDisable(GL_TEXTURE_2D);
			glDisable(GL_LIGHTING);

			if (str && strlen(str)){
				while(*str){
					glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *str);
					str++;
				}
			}

			glEnable(GL_TEXTURE);
			glEnable(GL_TEXTURE_2D);
			glEnable(GL_LIGHTING);
		glPopAttrib();
	glPopMatrix();
}

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
bool InitGL(int width, int height)	        // We call this right after our OpenGL window is created.
{
	LoadGLTextures(files[1],0,texture);
	LoadGLTextures(files[2],3,texture);
	LoadGLTextures(files[3],6,texture);
	LoadGLTextures(files[4],9,texture);

	// This Will Clear The Background Color To Black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glMatrixMode(GL_PROJECTION);

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
	glViewport(0,0,width,height);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);

	glMatrixMode(GL_MODELVIEW);


	/* Abilitazioni variabili di stato */
	glEnable(GL_DEPTH_TEST);				// enables depth testing.
	glEnable(GL_COLOR_MATERIAL);			// enables use of materials.
	glEnable(GL_TEXTURE_2D);				// enables textures
	glEnable(GL_TEXTURE_BINDING_2D);
	glEnable(GL_CULL_FACE);
	glEnable(GL_POLYGON_MODE);				// enables surfaces (not wires)
	glEnable(GL_NORMALIZE);
	glEnable(GL_AUTO_NORMAL);

	glClearDepth(1.0);						// Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS);					// type of depth test to do.

	glCullFace(GL_BACK);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);		// Set the blending function for translucency (note off at init time)

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);

	glPolygonMode(GL_FRONT, GL_FILL);		// fill front face
	glPolygonMode(GL_BACK, GL_FILL);		// fill back face
	glFrontFace(GL_CCW);

	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SEPARATE_SPECULAR_COLOR);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,gray);

	/* Fancy fog */
	glClearColor(0.2f,0.2f,0.2f,1.0f);          // We'll Clear To The Color Of The Fog
	glFogi(GL_FOG_MODE, fogMode[fogfilter]);    // Fog Mode
	glFogfv(GL_FOG_COLOR, fogColor);            // Set Fog Color
	glFogf(GL_FOG_DENSITY, 0.35f);              // How Dense Will The Fog Be
	glHint(GL_FOG_HINT, GL_DONT_CARE);          // Fog Hint Value
	glFogf(GL_FOG_START, 1.0f);             	// Fog Start Depth
	glFogf(GL_FOG_END, 5.0f);               	// Fog End Depth
	glEnable(GL_FOG);                   		// Enables GL_FOG


	/* Objects initialization */

	/* Player camera initialization */
	buildPlayer();

	/* Cube initialization and settings */
	buildCube(CUBE_X,CUBE_Y,CUBE_Z,CUBE_SIZE);
	cube->setMaterial(
			gray,
			white,
			pink,
			16,
			black
	);

	cube->increaseXrot(45.0);
	cube->increaseZrot(45.0);

	/* Sphere initialization and settings */
	buildSphere(-0.5, 0.5, 0.0, 0.1);

	/* Glass initialization*/
	buildGlass(0.0,0.5,-2.0,1.0);
	glass->setMaterial(
			mat_glass,
			white,
			white,
			4,
			mat_glass
	);

	/* Wall initialization */
	buildWall(-1.0,0.5,-2.0,1.0);
	wall->setMaterial(
			red,
			white,
			white,
			32,
			black
	);

	/* Wall Tiny initialization */
	buildWallTiny(0.0,0.5,0.0,0.5*sqrt(2.0),1.0);
	wall_tiny->setMaterial(
			red,
			white,
			white,
			16,
			black
	);

	/* Floor initialization */
	buildMud(0.0,0.0,0.0,4.0);
	mud->setMaterial(
			red,
			white,
			white,
			16,
			black
	);


	/* Colors initialization */
	for (int i=0; i<4; i++){
		glass->setColor(i,color_glass);
		wall->setColor(i,color_wall);
		wall_tiny->setColor(i,color_wall);
		mud->setColor(i,color_mud);
	}

	/* Lights setup */
	buildSpot(SPOT1,1.0,CUBE_Y,CUBE_Z,GL_LIGHT0,CUBE_X,CUBE_Y,CUBE_Z);
	spot1->setColorSpecular(red);
	spot1->setSpotCutoff(10.0);
	spot1->setSpotExponent(2.0);

	buildSpot(SPOT2,-1.0,CUBE_Y,CUBE_Z,GL_LIGHT1,CUBE_X,CUBE_Y,CUBE_Z);
	spot2->setColorSpecular(green);
	spot2->setSpotCutoff(10.0);
	spot2->setSpotExponent(2.0);

	buildSpot(SPOT3,CUBE_X,CUBE_Y,2.0,GL_LIGHT2,CUBE_X,CUBE_Y,CUBE_Z);
	spot3->setColorSpecular(cyan);
	spot3->setSpotCutoff(10.0);
	spot3->setSpotExponent(5.0);

	buildSpot(SPOT4,CUBE_X,CUBE_Y,-2.0,GL_LIGHT2,CUBE_X,CUBE_Y,CUBE_Z);
	spot4->setColorSpecular(orange);
	spot4->setSpotCutoff(10.0);
	spot4->setSpotExponent(5.0);

	glLoadIdentity();

	return true;
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
GLvoid ReSizeGLScene(GLsizei width, GLsizei height)
{
	if (height==0)							// Prevent A Divide By Zero If The Window Is Too Small
		height=1;

	window_h = height;
	window_w = width;

	glViewport(0, 0, width, height);		// Reset The Current Viewport And Perspective Transformation

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window
	glMatrixMode(GL_MODELVIEW);
}

/* The main drawing function. */
GLvoid DrawGLScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer

	keyOperations();
	keySpecialOperations();

	glPushMatrix();

		/* Set look at */
		gluLookAt(
				player->getXpos(),
				player->getYpos(),
				player->getZpos(),
				player->getXcenter(),
				player->getYcenter(),
				player->getZcenter(),
				player->getXnormal(),
				player->getYnormal(),
				player->getZnormal()
		);

		/* Set lights fixed with the world */
		spot1->setUpLight();
		spot2->setUpLight();
		spot3->setUpLight();
		spot4->setUpLight();

		if(blend) glEnable(GL_BLEND);

		/* Draw Axis */
		glBegin(GL_LINES);
		glMaterialfv(GL_FRONT,GL_EMISSION,red);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(-5.0,  0.0,  0.0);
		glVertex3f( 5.0,  0.0,  0.0);
		glMaterialfv(GL_FRONT,GL_EMISSION,green);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f( 0.0, -5.0,  0.0);
		glVertex3f( 0.0,  5.0,  0.0);
		glMaterialfv(GL_FRONT,GL_EMISSION,yellow);
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f( 0.0,  0.0, -5.0);
		glVertex3f( 0.0,  0.0,  5.0);
		glEnd();

		/* Cube drawing */
		cube->setTexture(texture[6+textureFilter]);
		cube->rotateXYZ();	// draw rotating cube on XYZ axis

		/* Sphere drawing */
		sphere->setTexture(texture[6+textureFilter]);
		glPushMatrix();
			glTranslatef(0.0,-0.5,0.0);
			sphere->rotateY();	//draw a sphere that rotate on Y
		glPopMatrix();
		sphere->draw();		// draw a static sphere

		/* Wall drawing */
		wall->setTexture(texture[0+textureFilter]);
		glPushMatrix();
			for (int i=0; i<4; i++){
				glPushMatrix();
				wall->draw();
				glTranslatef(2.0,0.0,0.0);
				wall->draw();
				glPopMatrix();
				glRotatef(90.0,0.0,1.0,0.0);
			}
		glPopMatrix();

		/* Wall Tiny drawing */
		wall_tiny->setTexture(texture[0+textureFilter]);
		glPushMatrix();
			for (int i=0; i<4; i++){
				glPushMatrix();
				glTranslatef(-1.75,0.0,-1.75);
				glRotatef(45.0,0.0,1.0,0.0);
				wall_tiny->draw();
				glPopMatrix();
				glRotatef(90.0,0.0,1.0,0.0);
			}
		glPopMatrix();

		/* Floor drawing */
		mud->setTexture(texture[9+textureFilter]);
		glPushMatrix();
			glRotatef(-90.0,1.0,0.0,0.0);
			mud->draw();
		glPopMatrix();

		/* Glass drawing with fix draw order by player position */
		glass->setTexture(texture[3+textureFilter]);
		glPushMatrix();
			if (
					player->getZpos() > 0.0 &&
					player->getXpos() > -player->getZpos() &&
					player->getXpos() < player->getZpos()
			){
				//P1: Player is in South position
				glRotatef(-90.0,0.0,1.0,0.0);
				for (int i=0; i<4; i++){
					glass->draw();
					glRotatef(90.0,0.0,1.0,0.0);
				}
			} else if (
					player->getXpos() > 0.0 &&
					player->getZpos() > -player->getXpos() &&
					player->getZpos() < player->getXpos()
			){
				//P2: Player is in Est position
				for (int i=0; i<4; i++){
					glass->draw();
					glRotatef(90.0,0.0,1.0,0.0);
				}
			} else if (
					player->getZpos() < 0.0 &&
					player->getXpos() < -player->getZpos() &&
					player->getXpos() > player->getZpos()
			){
				//P3: Player is in North position
				glRotatef(90.0,0.0,1.0,0.0);
				for (int i=0; i<4; i++){
					glass->draw();
					glRotatef(90.0,0.0,1.0,0.0);
				}
			} else if (
					player->getXpos() < 0.0 &&
					player->getZpos() < -player->getXpos() &&
					player->getZpos() > player->getXpos()
			){
				//P4: Player is in West position
				glRotatef(180.0,0.0,1.0,0.0);
				for (int i=0; i<4; i++){
					glass->draw();
					glRotatef(90.0,0.0,1.0,0.0);
				}
			} else {
				//Player is near the center
				for (int i=0; i<4; i++){
					glass->draw();
					glRotatef(90.0,0.0,1.0,0.0);
				}
			}
		glPopMatrix();

		/* Text info */
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
			glLoadIdentity();
			glOrtho(0,window_w,0,window_h,-1.0f,1.0f);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
				glLoadIdentity();

				char str[255];

				sprintf(str,"Window size: % 2.3f x % 2.3f \n", (float)window_h, (float)window_w);
				print_string(str,5.0,50.0,0,0.1);
				sprintf(str,"Player: % 2.3f , % 2.3f , % 2.3f \n", player->getXpos(), player->getYpos(), player->getZpos());
				print_string(str,5.0,35.0,0,0.1);
				sprintf(str,"Center: % 2.3f , % 2.3f , % 2.3f \n", player->getXcenter(), player->getYcenter(), player->getZcenter());
				print_string(str,5.0,20.0,0,0.1);
				sprintf(str,"Normal: % 2.3f , % 2.3f , % 2.3f \n", player->getXnormal(), player->getYnormal(), player->getZnormal());
				print_string(str,5.0,5.0,0,0.1);
				sprintf(str,"+");
				print_string(str,window_w/2.0,window_h/2.0,0.0,0.1);

				/* Keys status */
				sprintf(str,"(B)  Blends: %d", blend);
				print_string(str,5.0,window_h-20.0,0,0.1);
				sprintf(str,"(N)  Fog status: %d", fogstatus);
				print_string(str,5.0,window_h-35.0,0,0.1);
				sprintf(str,"(G)  Fog filter: %d", fogfilter);
				print_string(str,5.0,window_h-50.0,0,0.1);
				sprintf(str,"(F)  Texture filter: %d", textureFilter);
				print_string(str,5.0,window_h-65.0,0,0.1);
				sprintf(str,"(H)  Wireframe: %d", wireframe);
				print_string(str,5.0,window_h-80.0,0,0.1);
				sprintf(str,"(L)  Lights: %d", light);
				print_string(str,5.0,window_h-95.0,0,0.1);
				sprintf(str,"(F1) Fullsceen: %d", fullscreen);
				print_string(str,5.0,window_h-110.0,0,0.1);

				glMatrixMode(GL_PROJECTION);

			glPopMatrix();
			glMatrixMode(GL_MODELVIEW);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);

	glPopMatrix();

	glFlush();
	glutSwapBuffers(); 		// since this is double buffered, swap the buffers to display what just got drawn.
}

void timerCubeFunc(int n){
	/* */
	cube->increaseZrot();
	sphere->increaseYrot(1.5);

	glutPostRedisplay();
	glutTimerFunc(10, &timerCubeFunc, 0);
}

/*
 * Main program
 */
int main(int argc, char **argv)
{
	keyInit();

	/* Initialize GLUT state - glut will take any command line arguments that pertain to it or X Windows */
	glutInit(&argc, argv);

	/* Select type of Display mode: Double buffer, RGBA color, Alpha components supported, Depth buffer */
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

	/* get a 640 x 480 window */
	glutInitWindowSize(window_w, window_h);

	/* the window starts at the upper left corner of the screen */
	glutInitWindowPosition(0, 0);

	/* Open a window */
	createWindow();

	/* Register the function to do all our OpenGL drawing. */
	glutDisplayFunc(&DrawGLScene);

	/* Even if there are no events, redraw our gl scene. */
	glutIdleFunc(&DrawGLScene);

	/* Register the function called when our window is resized. */
	glutReshapeFunc(&ReSizeGLScene);

	/* Register the function called when the keyboard is pressed. */
	glutKeyboardFunc(&keyPressed);
	glutKeyboardUpFunc(&keyReleased);

	/* Register the function called when special keys (arrows, page down, etc) are pressed. */
	glutSpecialFunc(&specialKeyPressed);
	glutSpecialUpFunc(&specialKeyReleased);

	/* Mouse functions */
	glutPassiveMotionFunc(&mouseDragged);

	/* Timered functions */
	glutTimerFunc(10,&timerCubeFunc,10);

	/* Initialize our window. */
	InitGL(640, 480);

	/* Start Event Processing Engine */
	glutMainLoop();

	return 1;
}
