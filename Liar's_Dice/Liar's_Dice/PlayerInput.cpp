#include "PlayerInput.h"
#include <opencv2\opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;

Mat frame;

PlayerInput::PlayerInput()
{

}


PlayerInput::~PlayerInput()
{
}

int captureInput()
{
	VideoCapture cap(0);

	// Controle of de camera wordt herkend.
	if (!cap.isOpened())
	{
		std::cout << "Cannot open the video cam" << std::endl;
		return -1;
	}
 
	//double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	//double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	double dWidth = 1920;
	double dHeight = 1080;

	std::cout << "Frame size : " << dWidth << " x " << dHeight << std::endl;


	// Lees een nieuw frame
	bool bSuccess = cap.read(frame);

	// Controlleer of het frame goed gelezen is.
	if (!bSuccess)
	{
		std::cout << "Cannot read a frame from video stream" << std::endl;
	}
	return 0;
}

Mat PlayerInput::getPicture()
{
	captureInput();
	return frame;
}
