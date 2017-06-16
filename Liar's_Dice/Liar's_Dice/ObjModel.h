#pragma once

#include <string>
#include <vector>
#include <list>

#include <windows.h>
#include <gl/GL.h>
#include "Vec.h"
#include <math.h>
class Texture;

class dataXYZ
{
public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	bool dataChanged = false;

	float operator[](std::size_t index) 
	{
		switch (index)
		{
			case 0: return x;
			case 1: return y;
			case 2: return z;
		}
		return NAN;
	}
	float operator()(const size_t index) {
		switch (index)
		{
			case 0: return x;
			case 1: return y;
			case 2: return z;
		}
		return NAN;
	}
	void operator=(const float& newValue) { // didn't allow me to name it value
		x = newValue;
		y = newValue;
		z = newValue;
		dataChanged = true;
	}
	void operator+=(const float& newValue) {
		x += newValue;
		y += newValue;
		z += newValue;
		dataChanged = true;
	}
	void operator++() {
		x ++;
		y ++;
		z ++;
		dataChanged = true;
	}
	void operator-=(const float& newValue) {
		x -= newValue;
		y -= newValue;
		z -= newValue;
		dataChanged = true;
	}
	void operator--() {
		x--;
		y--;
		z--;
		dataChanged = true;
	}
	void operator*=(const float& newValue) {
		x *= newValue;
		y *= newValue;
		z *= newValue;
		dataChanged = true;
	}
	void operator/=(const float& newValue) {
		x /= newValue;
		y /= newValue;
		z /= newValue;
		dataChanged = true;
	}

};


class ObjModel
{
private:
	class Vertex
	{
	public:
		int position = -1;
		int normal = -1;
		int texcoord = -1; 
	};

	class Face
	{
	public:
		std::list<Vertex> vertices;
	};
	class MaterialInfo
	{
	public:
		MaterialInfo();
		std::string name;
		Texture* texture;
	};

	class ObjGroup
	{
	public:
		std::string name;
		int materialIndex;
		std::list<Face> faces;
		dataXYZ rotationsf;
	};


	std::vector<Vec3f>	vertices;
	std::vector<Vec3f>	normals;
	std::vector<Vec2f>	texcoords;
	std::vector<MaterialInfo*> materials;

	void loadMaterialFile(const std::string &fileName, const std::string &dirName);
public:
	dataXYZ rotatef;
	dataXYZ translatef;
	dataXYZ scalef;
	std::vector<ObjGroup*> groups;
	ObjModel(const std::string &filename);
	~ObjModel(void);

	void draw();
};

