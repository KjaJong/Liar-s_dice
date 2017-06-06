#include <gl/freeglut.h>
#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(std::string texturePath)
{
	printf("Loading texture %s\n", texturePath.c_str());
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	int width, height, bpp;
	stbi_set_flip_vertically_on_load(1);
	char* imgData = (char*)stbi_load(texturePath.c_str(), &width, &height, &bpp, 4);

	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGBA,
		width,
		height,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		imgData);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_image_free(imgData);
}


Texture::~Texture()
{
}

void Texture::BindTexture()
{
	glBindTexture(GL_TEXTURE_2D, textureId);
}

