#pragma once

#include "Particle.h"
#include <glm.hpp>
#include <vector>

class ParticleSystem
{
	std::vector<Particle> particles;
	glm::vec3 mouse_position;

public:
	ParticleSystem(int n = 0);
	
	void update(float t);
	void render();

	void set_mouse_position(glm::vec3 position = glm::vec3(0, 0, 0));
	void add_particles(int n);

	~ParticleSystem(void);
};

