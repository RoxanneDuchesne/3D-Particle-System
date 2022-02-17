#include "particle_system.h"
#include <GL/glut.h>
#include <math.h>

particle_system::particle_system(int n)
{
	if(n > MAX_PARTICLES)
		n = MAX_PARTICLES;

	for(int i = 0; i < n; i++)
	{
		particle temp = particle(mouse_position);
		particles.push_back(temp);
	}

}


void particle_system::advance(float time)
{
	std::vector<particle>::iterator it;
	for(it = particles.begin(); it != particles.end(); it++)
	{
		it->update(time);
	}
}


void particle_system::set_mouse_position(glm::vec3 position){
	mouse_position = position;
}


bool particle_system :: add_particles(int num)
{
	int i;
	for(i = 0; i < num && particles.size() < MAX_PARTICLES; i++)
	{
		particle p = particle(mouse_position);
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

		glm::vec3 j = glm::vec3(mouse_position.x - pos.x, mouse_position.y - pos.y, mouse_position.z - pos.z);
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
