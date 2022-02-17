#pragma once

#include <cmath>
#include "particle.h"

class particle_system
{
	std::vector<particle> particles;
	glm::vec3 mouse_position;

public:
	//construct system given n number of particles
	particle_system(int);
	
	//Function to advance state of particle system by time t in ms
	void advance(float);

	void set_mouse_position(glm::vec3 = glm::vec3(0, 0, 0));

	bool add_particles(int);

	bool delete_particles(int);

	void draw();

	~particle_system(void);
};

