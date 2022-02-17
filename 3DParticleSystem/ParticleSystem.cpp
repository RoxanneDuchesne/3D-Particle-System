#include "ParticleSystem.h"
#include <GL/glut.h>
#include <math.h>

ParticleSystem::ParticleSystem(int n)
{
	if(n > MAX_PARTICLES)
		n = MAX_PARTICLES;

	add_particles(n);
}


void ParticleSystem::update(float time)
{
	auto it = particles.begin();

	while(it != particles.end())
	{
		bool alive = it->update(time);

		if (!alive)
		{
			it = particles.erase(it);
		}
		else
		{
			it++;
		}
	}
}


void ParticleSystem::set_mouse_position(glm::vec3 position)
{
	this->mouse_position = position;
}


void ParticleSystem :: add_particles(int num)
{
	for(int i = 0; i < num && particles.size() < MAX_PARTICLES; i++)
	{
		Particle p = Particle(mouse_position);
		particles.push_back(p);
	}
}


void ParticleSystem::render()
{
	for(auto it = particles.begin(); it != particles.end(); it++){
		glm::vec3 pos = it->get_position();

		// Calculate Changing Color
		glm::vec3 j = glm::vec3(mouse_position.x - pos.x, mouse_position.y - pos.y, mouse_position.z - pos.z);
		float k = sqrt(j.x * j.x + j.y * j.y + j.z * j.z) / (1.5 * LENGTH);

		glColor4f(k, k, 30, it->get_alpha());

		glBegin(GL_POINTS);
			glVertex3f(pos.x, pos.y, pos.z);
		glEnd();
	}
}


ParticleSystem::~ParticleSystem(void)
{
}
