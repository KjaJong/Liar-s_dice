#pragma once
#include <opencv2/core/mat.hpp>

class PlayerInput
{
public:
	PlayerInput();
	~PlayerInput();
	int captureInput();
	cv::Mat getPicture();
};

