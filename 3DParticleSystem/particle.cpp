#include <Windows.h>
#include <gl/glut.h>

#include "particle.h"


particle::particle(glm::vec3 starting_position) 
{
	// Set mass to a random number between MIN_MASS and MAX_MASS inclusive
	mass = rand() % (MAX_MASS - MIN_MASS + 1) + MIN_MASS;

	// Set starting velocity
	float starting_velocity_x = rand() % (MAX_INIT_VELOCITY_X - MIN_INIT_VELOCITY_X + 1) + MIN_INIT_VELOCITY_X;
	float starting_velocity_y = rand() % (MAX_INIT_VELOCITY_Y - MIN_INIT_VELOCITY_Y + 1) + MIN_INIT_VELOCITY_Y;
	float starting_velocity_z = rand() % (MAX_INIT_VELOCITY_Z - MIN_INIT_VELOCITY_Z + 1) + MIN_INIT_VELOCITY_Z;

	velocity = glm::vec3(starting_velocity_x, starting_velocity_y, starting_velocity_z);

	// Set starting position to mouse position
	position = starting_position;

	float mass;
	glm::vec3 velocity;
	glm::vec3 position;

	float lifespan;
	float rotation;
	float scale;

}

//function to advance state by time t in ms
bool particle::update(float t)
{
	// Calculate effect of gravity
	velocity.y += GRAVITY * mass * (t / 1000);

	// Change Particle Position Based on Velocity
	position = position + glm::vec3(velocity.x * (t / 1000.0), velocity.y * (t / 1000.0), velocity.z * (t / 1000.0));


	elapsed_time += t;

	return elapsed_time < lifespan;
}


particle::~particle(void){
}


glm::vec3 particle :: get_position()
{
	return position;
}



float particle::rand_float()
{
	float value = rand() / float(RAND_MAX);
	return value;
}