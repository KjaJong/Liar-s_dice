#pragma once
#include <string>

class Texture
{
	GLuint textureId;
public:
	Texture(std::string);
	~Texture();
	void BindTexture();
};

