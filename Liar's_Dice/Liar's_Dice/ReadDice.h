#pragma once
#include <opencv2/core/mat.hpp>
#include <vector>

class ReadDice
{
private: 


public:
	ReadDice();
	~ReadDice();
	std::vector<int> CheckDice(cv::Mat picture);
};

