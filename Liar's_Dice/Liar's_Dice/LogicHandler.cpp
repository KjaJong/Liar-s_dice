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



// Check if elements of vec2 are in vec1
// vec2 must be a equal or smaller size then vec1; vec2.size >= vec1.size
bool LogicHandler::vecContentEqual(std::vector<int> vec1, std::vector<int> vec2) {

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