#include "ReadDice.h"
#include "PlayerInput.h"
#include <iostream>
#include <sstream>
#include <opencv2/core.hpp>
#include "opencv2/objdetect.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2\opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp" 
#include "opencv2/highgui/highgui.hpp"

using cv::Mat;
using cv::Point;
using std::vector;

ReadDice::ReadDice()
{

}
ReadDice::~ReadDice()
{

}

int countPips(Mat area)
{
	Mat dice = area;

	resize(dice, dice, cv::Size(150, 150));

	floodFill(dice, cv::Point(0, 0), cv::Scalar(255));
	floodFill(dice, cv::Point(0, 149), cv::Scalar(255));
	floodFill(dice, cv::Point(149, 0), cv::Scalar(255));
	floodFill(dice, cv::Point(149, 149), cv::Scalar(255));

	//search for blobs
	cv::SimpleBlobDetector::Params params;

	//filter by interia defines how elongated a shape is
	params.filterByInertia = true;
	params.minInertiaRatio = 0.5;

	std::vector<cv::KeyPoint> keypoints;

	//create blob
	cv::Ptr<cv::SimpleBlobDetector> blobDetector = cv::SimpleBlobDetector::create(params);

	blobDetector->detect(dice, keypoints);

	return keypoints.size();
}

std::vector<int> ReadDice::CheckDice()
{
	vector<int> dice;

	PlayerInput PI = PlayerInput();
	//Mat pic = PI.getPicture();
	Mat pic = cv::imread("C:/Users/Tom Remeeus/Documents/GitHub/Liar-s_dice/Liar's_Dice/DicePics/test2.jpg", 1);
	Mat buffer = pic;

	//edit picture
	cvtColor(buffer, buffer, CV_BGR2GRAY);
	threshold(buffer, buffer, 125, 255, CV_THRESH_BINARY);

	/*TEST
	//cv::namedWindow("test", CV_WINDOW_AUTOSIZE);
	//imshow("test", pic);
	//cv::waitKey(0);
	END TEST*/

	//detect dice
	vector<vector<Point> > contours;
	vector<cv::Vec4i> hierarchy;
	findContours(buffer, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
	
	//iterate over dice contours
	for (int i = 0; i < contours.size(); i++)
	{
		double diceContourArea = contourArea(contours[i]);

		//filter small contours 
		if (diceContourArea > 6000)
		{
			//get bounding rect
			cv::Rect diceBoundsRect = boundingRect(Mat(contours[i]));
			Mat dicePic = pic(diceBoundsRect);

			//edit dice picture
			cvtColor(dicePic, dicePic, CV_BGR2GRAY);
			threshold(dicePic, dicePic, 150, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
			Canny(dicePic, dicePic, 2, 2*2, 3, false);

			/*TEST
			cv::namedWindow("void", CV_WINDOW_AUTOSIZE);
			imshow("void", dicePic);
			cv::waitKey(0);
			END TEST*/

			//count number of pips and add dice to vector
			int pips = countPips(dicePic);
			dice.push_back(pips);
		}
	}

	return dice;
}