#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "ParticleSystem.h"

#include <windows.h>
#include <time.h>
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <chrono>

#include "Constants.h"


ParticleSystem p = ParticleSystem();
float win_width = 1500, win_height = 1500;

std::chrono::steady_clock::time_point last_tick_ms;

//Called when a key is pressed
void handle_keypress(unsigned char key, int x, int y)
{
    switch(key)
    {
	case 'a':
	case 'A':
		p.add_particles(10);
		break;

    case 27:
        exit(0);
		break;
    }
    glutPostRedisplay();
}



//Initializes 3D rendering
void init()
{
	glPointSize(PARTICLE_SIZE);

	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

	//Enable transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}


//Called when the window is resized
void handle_resize(int w, int h)
{
	//setup windows width and height
	win_width = (w==0) ? 1 : w;
	win_height = (h==0) ? 1 : h;

    //Tell OpenGL how to convert from coordinates to pixel values
    glViewport(0, 0, win_width, win_height);

	//Switch to setting the camera perspective
    glMatrixMode(GL_PROJECTION);

    //Set the camera perspective
    glLoadIdentity(); //Reset the camera
	glOrtho(-LENGTH, LENGTH, -LENGTH, LENGTH, -LENGTH, LENGTH);
	
	glMatrixMode(GL_MODELVIEW);
}


//Draws the 3D scene
void draw()
{
	//Calculate Delta Time

	auto current_time_ms = std::chrono::high_resolution_clock::now();
	double delta_time_ms = std::chrono::duration<double, std::milli>(current_time_ms - last_tick_ms).count();

	glLoadIdentity();

	if (delta_time_ms > 10)
	{
		last_tick_ms = current_time_ms;

		p.add_particles(1);

		p.update(delta_time_ms);
	}
	

	//Draw particles
	glPushMatrix();
	p.render();
	glPopMatrix();
	
	//Draw overlaying quad for trail
	glColor4f(0, 0, 0, 0.1);
	glBegin(GL_QUADS);
	glVertex3f(-LENGTH, -LENGTH, 100);
	glVertex3f(LENGTH, -LENGTH, 100);
	glVertex3f(LENGTH, LENGTH, 100);
	glVertex3f(-LENGTH, LENGTH, 100);
	glEnd();

	glutSwapBuffers();
	glutPostRedisplay();
}


//Handle mouse movement
void mouse_movement(int x, int y ){

	float mouse_x = float(x) / (win_width / 2) - 1.0;
	float mouse_y = float(y) / (win_height / 2) - 1.0;

	p.set_mouse_position(glm::vec3(mouse_x * 100, -mouse_y * 100, 100));
}



int main(int argc, char** argv)
{
	srand(time(0));

	last_tick_ms = std::chrono::high_resolution_clock::now();

	//Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(win_width, win_height); //Set the window size

    //Create the window and initialize OpenGL
    glutCreateWindow("Particle System");
    init();

    //Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(draw);
    glutKeyboardFunc(handle_keypress);
    glutReshapeFunc(handle_resize);
	glutPassiveMotionFunc(mouse_movement);
	//glutFullScreen();

	glutMainLoop();
    return 0; //This line is never reached
}