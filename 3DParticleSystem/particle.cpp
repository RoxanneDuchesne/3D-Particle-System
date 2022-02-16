#include <Windows.h>
#include <gl/glut.h>

#include "particle.h"


particle::particle() 
{

	mass = rand() % (MAX_MASS - MIN_MASS) + MIN_MASS;

	glm::vec3 normalized_velocity = glm::normalize(glm::vec3(rand_float(), rand_float(), rand_float()));
	float velocity_magnitude = MIN_INIT_VELOCITY + rand() % (MAX_INIT_VELOCITY - MIN_INIT_VELOCITY);

	velocity = glm::vec3(normalized_velocity.x * velocity_magnitude, normalized_velocity.y * velocity_magnitude, normalized_velocity.z * velocity_magnitude);
	position = glm::vec3((1 - 2 * rand_float()) * LENGTH, (1.f - 2 * rand_float()) * LENGTH, (1 - 2 * rand_float()) * LENGTH);

}

//function to advance state by time t in ms
void particle::advance(float t, glm::vec3 force)
{
	//calculating acceleration
	glm::vec3 acc = glm::vec3(force.x / mass, force.y / mass, force.z /mass);

	//calculating velocity *
	velocity = velocity + glm::vec3(acc.x * (t / 1000.0), acc.y * (t / 1000.0), acc.z * (t / 1000.0));
	
	// Get vector magnitutde * 
	if (sqrt(velocity.x * velocity.x + velocity.y * velocity.y + velocity.z * velocity.z) >= MAX_VELOCITY)
	{
		glm::vec3 normalized_velocity = glm::normalize(velocity);
		velocity = glm::vec3(normalized_velocity.x * MAX_VELOCITY, normalized_velocity.y * MAX_VELOCITY, normalized_velocity.z * MAX_VELOCITY);
	}

	//changing position
	position = position + glm::vec3(velocity.x * (t/1000.0), velocity.y * (t / 1000.0), velocity.z * (t / 1000.0));

	if(position.x <= -LENGTH)
		position.x = LENGTH;
	else if(position.x >= LENGTH)
		position.x = -LENGTH;

	if(position.y <= -LENGTH)
		position.y = LENGTH;
	else if(position.y >= LENGTH)
		position.y = -LENGTH;

	if(position.z <= -LENGTH)
		position.z = LENGTH;
	else if(position.z >= LENGTH)
		position.z = -LENGTH;
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