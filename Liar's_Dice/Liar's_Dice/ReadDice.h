#pragma once
#include <opencv2/core/mat.hpp>
#include <vector>

class ReadDice
{
public:
	ReadDice();
	~ReadDice();
	std::vector<int> CheckDice(int amount);
};

