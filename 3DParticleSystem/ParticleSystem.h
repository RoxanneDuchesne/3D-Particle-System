#pragma once

#include <cmath>
#include "Particle.h"

class ParticleSystem
{
	std::vector<Particle> particles;
	glm::vec3 mouse_position;

public:
	//construct system given n number of particles
	ParticleSystem(int n = 0);
	
	//Function to advance state of particle system by time t in ms
	void update(float t);

	void set_mouse_position(glm::vec3 position = glm::vec3(0, 0, 0));

	void add_particles(int n);

	void render();

	~ParticleSystem(void);
};

