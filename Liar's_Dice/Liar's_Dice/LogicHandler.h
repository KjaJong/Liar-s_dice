#pragma once
#include <vector>

using std::vector;
using std::string;

class LogicHandler {
	public:
		//TODO vector<int>* bid from opencv module. This comes directly from OpenCV, so it will be scrapped soon
		bool raise(const std::vector<int>*, const std::vector<int>*);

		//TODO vector<int>* bid from opencv module. This comes directly from OpenCV, so it will be scrapped soon
		bool callBluff(std::vector<int>*, std::vector<int>*);

		//TODO vector<int>* bid from opencv module. This comes directly from OpenCV, so it will be scrapped soon
		bool spotOn(std::vector<int>*, std::vector<int>*);

		bool containsElements(std::vector<int>, std::vector<int>);
		bool vecContains(std::vector<int>*, int);
		bool sameValues(const std::vector<int>*);
		bool validDice(const std::vector<int>*);
		bool validDie(int);
};
