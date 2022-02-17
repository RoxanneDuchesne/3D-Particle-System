#pragma once

#include <string>

#include <GL/glew.h>
#include <GL/glut.h>
#include "stb_image.h"

class ParticleTexture
{

private:

	GLuint texture_id;

	std::string file_path;

	unsigned char* local_buffer;

	int width, height, BPP;

public:

	ParticleTexture(const std::string& path);
	~ParticleTexture();

	void bind(unsigned int slot = 0) const;
	void unbind() const;

	inline int get_width() const { return width; }
	inline int get_height() const { return height; }
};

