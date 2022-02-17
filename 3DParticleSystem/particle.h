#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "constants.h"



class particle
{	
	float mass;
	glm::vec3 velocity;
	glm::vec3 position;

	float lifespan;
	float rotation;
	float scale;

	float elapsed_time = 0;


public:
	particle(glm::vec3 starting_position);

	//Function to update particle by time in ms, returns true if particle is still alive
	bool update(float t);

	glm::vec3 get_position();

	float rand_float();

	~particle(void);
};



