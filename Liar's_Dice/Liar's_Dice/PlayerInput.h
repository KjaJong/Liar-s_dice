#pragma once
#include <opencv2/core/mat.hpp>

class PlayerInput
{
public:
	PlayerInput();
	~PlayerInput();
	cv::Mat getPicture();
};

