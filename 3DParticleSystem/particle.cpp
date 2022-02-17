#include "Particle.h"

#include <Windows.h>
#include <gl/glut.h>



Particle::Particle(glm::vec3 starting_position) 
{
	// Set mass to a random number between MIN_MASS and MAX_MASS inclusive
	mass = rand() % (MAX_MASS - MIN_MASS + 1) + MIN_MASS;
	lifespan_ms = rand() % (MAX_LIFESPAN_MS - MIN_LIFESPAN_MS + 1) + MIN_LIFESPAN_MS;

	// Set starting velocity
	float starting_velocity_x = rand() % (MAX_INIT_VELOCITY_X - MIN_INIT_VELOCITY_X + 1) + MIN_INIT_VELOCITY_X;
	float starting_velocity_y = rand() % (MAX_INIT_VELOCITY_Y - MIN_INIT_VELOCITY_Y + 1) + MIN_INIT_VELOCITY_Y;
	float starting_velocity_z = rand() % (MAX_INIT_VELOCITY_Z - MIN_INIT_VELOCITY_Z + 1) + MIN_INIT_VELOCITY_Z;

	velocity = glm::vec3(starting_velocity_x, starting_velocity_y, starting_velocity_z);

	// Set starting position to mouse position
	position = starting_position;
}

// Function to update particle by time in ms, returns true if particle is still alive
bool Particle::update(float t)
{
	// Calculate effect of gravity
	velocity.y += GRAVITY * mass * (t / 1000.f);

	// Change Particle Position Based on Velocity
	position = position + glm::vec3(velocity.x * (t / 1000.f), velocity.y * (t / 1000.f), velocity.z * (t / 1000.f));


	elapsed_time_ms += t;

	return elapsed_time_ms < lifespan_ms;
}


Particle::~Particle(void){
}


glm::vec3 Particle :: get_position()
{
	return position;
}

float Particle::get_alpha()
{
	return 1 - (elapsed_time_ms / lifespan_ms);
}


float Particle::rand_float()
{
	float value = rand() / float(RAND_MAX);
	return value;
}