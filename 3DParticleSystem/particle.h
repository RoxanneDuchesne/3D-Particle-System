#pragma once

#include "Tuning.h"
#include <glm.hpp>

class Particle
{	
private:
	float mass;
	glm::vec3 velocity;
	glm::vec3 position;

	float lifespan_ms;
	float elapsed_time_ms = 0;


public:
	Particle(glm::vec3 starting_position);

	bool update(float t);

	glm::vec3 get_position();
	float get_alpha();

	float rand_float();

	~Particle(void);
};



