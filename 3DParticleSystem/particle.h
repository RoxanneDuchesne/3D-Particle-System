#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "constants.h"



class particle
{	
	float mass;
	glm::vec3 velocity;
	glm::vec3 position;

public:
	particle();

	//Function to advance state of particle by time t in ms and force in given direction
	void advance(float, glm::vec3 = glm::vec3(0.0,0.0,0.0));

	glm::vec3 get_position();

	float rand_float();

	~particle(void);
};



