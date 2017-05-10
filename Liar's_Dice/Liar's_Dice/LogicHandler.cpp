#include "LogicHandler.h"
#include <iostream>
#include <vector>

LogicHandler::LogicHandler()
{

}


LogicHandler::~LogicHandler()
{

}

void raise(std::vector<int> bit, std::vector<int> current)
{

}

void callBluff(std::vector<int> bit, std::vector<int> current)
{

}

void spotOn(std::vector<int> bit, std::vector<int> current)
{

}



// Check if the content of vector 2 are in the content of vector 1
// Returns true if all elements of vector 2 are in vector 1. Therefor if the size of vector 2 is bigger than vector 1 return false
// ex: vec1[5, 2, 5]; vec2[5,5]; Checks if the two fives from vec2 are in vec1; vec1 contains the elements of vec2 so return true
bool LogicHandler::vecContainsElements(std::vector<int> vec1, std::vector<int> vec2) {
	if (vec2.size() > vec1.size())
		return false;

	for (int i = 0; i < vec1.size(); i++) {
		auto result = std::find(vec2.begin(), vec2.end(), vec1[i]);
		if (result != vec2.end()) {
			vec2.erase(result);
		}
		else
			return false;

		if (vec2.size() == 0)
			return true;
	}
}

bool LogicHandler::vecContains(std::vector<int>* vec, int toFind) {
	return (std::find(vec->begin(), vec->end(), toFind) != vec->end());
}