#include "ParticleTexture.h"


ParticleTexture::ParticleTexture(const std::string& path)
	: texture_id(0), file_path(path), local_buffer(nullptr), width(0), height(0), BPP(0)
{

	stbi_set_flip_vertically_on_load(1);
	local_buffer = stbi_load(path.c_str(), &width, &height, &BPP, 4);

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, local_buffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (local_buffer)
		stbi_image_free(local_buffer);
}

ParticleTexture::~ParticleTexture()
{
	glDeleteTextures(1, &texture_id);
}

void ParticleTexture::bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, texture_id);
}

void ParticleTexture::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

