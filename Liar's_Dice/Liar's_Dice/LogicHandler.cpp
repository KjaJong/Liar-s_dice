#include "LogicHandler.h"
#include <iostream>
#include <vector>
using namespace std;

LogicHandler::LogicHandler()
{

}


LogicHandler::~LogicHandler()
{

}

void raise(vector<int> bit, vector<int> current)
{

}

void callBluff(vector<int> bit, vector<int> current)
{

}

void spotOn(vector<int> bit, vector<int> current)
{

}



// Check if the content of vector 2 are in the content of vector 1
// Returns true if all elements of vector 2 are in vector 1. Therefor if the size of vector 2 is bigger than vector 1 return false
// ex: vec1[5, 2, 5]; vec2[5,5]; Checks if the two fives from vec2 are in vec1; vec1 contains the elements of vec2 so return true
bool LogicHandler::vecContainsElements(vector<int> vec1, vector<int> vec2) {
	if (vec2.size() > vec1.size())
		return false;

	for (int i = 0; i < vec1.size(); i++) {
		auto result = find(vec2.begin(), vec2.end(), vec1[i]);
		if (result != vec2.end()) {
			vec2.erase(result);
		}
		else
			return false;

		if (vec2.size() == 0)
			return true;
	}
}

bool LogicHandler::vecContains(vector<int>* vec, int toFind) {
	return (find(vec->begin(), vec->end(), toFind) != vec->end());
}