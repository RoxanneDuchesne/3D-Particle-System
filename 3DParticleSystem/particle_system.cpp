#include "particle_system.h"
#include <GL/glut.h>
#include <math.h>

particle_system::particle_system(int n)
{
	if(n > MAX_PARTICLES)
		n = MAX_PARTICLES;

	for(int i = 0; i < n; i++)
	{
		particle temp;
		particles.push_back(temp);
	}
}


void particle_system::advance(float time)
{
	std::vector<particle>::iterator it;
	for(it = particles.begin(); it != particles.end(); it++)
	{
		glm::vec3 force = glm::vec3((gravity_point - glm::normalize(it->get_position())));
		force = glm::vec3(force.x * FORCE_MAG, force.y * FORCE_MAG, force.z * FORCE_MAG);
		it->advance(time, force);
	}
}


void particle_system::set_gravity(glm::vec3 gravity){
	gravity_point = gravity;
}


bool particle_system :: add_particles(int num)
{
	int i;
	for(i = 0; i < num && particles.size() < MAX_PARTICLES; i++)
	{
		particle p;
		particles.push_back(p);
	}
	return (i >= num);
}


bool particle_system :: delete_particles(int num)
{
	int i;
	for(i = 0; i < num && particles.size() > 0; i++)
	{
		particles.pop_back();
	}

	return (i >= num);
}


void particle_system::draw()
{
	std::vector<particle>::iterator it;
	for(it = particles.begin(); it != particles.end(); it++){
		glm::vec3 pos = it->get_position();

		glm::vec3 j = glm::vec3(gravity_point.x - pos.x, gravity_point.y - pos.y, gravity_point.z - pos.z);
		float k = sqrt(j.x * j.x + j.y * j.y + j.z * j.z) / (1.5 * LENGTH);
		glColor4f(0, k, 30, 1);
		glBegin(GL_POINTS);
			glVertex3f(pos.x, pos.y, pos.z);
		glEnd();
	}
}


particle_system::~particle_system(void)
{
}
