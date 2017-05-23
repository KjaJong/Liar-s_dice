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

int countPips(cv::Mat dice)
{
	// resize
	cv::resize(dice, dice, cv::Size(150, 150));

	// convert to grayscale
	cvtColor(dice, dice, CV_BGR2GRAY);

	// threshold
	cv::threshold(dice, dice, 150, 255, cv::THRESH_BINARY | CV_THRESH_OTSU);

	// floodfill
	cv::floodFill(dice, cv::Point(0, 0), cv::Scalar(255));
	cv::floodFill(dice, cv::Point(0, 149), cv::Scalar(255));
	cv::floodFill(dice, cv::Point(149, 0), cv::Scalar(255));
	cv::floodFill(dice, cv::Point(149, 149), cv::Scalar(255));

	// search for blobs
	cv::SimpleBlobDetector::Params params;

	// filter by interia defines how elongated a shape is.
	params.filterByInertia = true;
	params.minInertiaRatio = 0.5;

	// will hold our keyponts
	std::vector<cv::KeyPoint> keypoints;

	// create new blob detector with our parameters
	cv::Ptr<cv::SimpleBlobDetector> blobDetector = cv::SimpleBlobDetector::create(params);

	// detect blobs
	blobDetector->detect(dice, keypoints);

	// return number of pips
	return keypoints.size();
}

std::vector<int> ReadDice::CheckDice()
{
	PlayerInput PI = PlayerInput();
	Mat pic = PI.getPicture();
	Mat buffer;

	vector<vector<Point>> contours;
	vector<cv::Vec4i> hierarchy;
	vector<int> dice;

	//convert to grayscale
	cvtColor(pic, buffer, CV_BGR2GRAY);
	pic = buffer;

	// threshold
	threshold(pic, buffer, 150, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
	pic = buffer;

	// applying canny edge filter
	Canny(pic, buffer, 2, 2 * 2, 3, false);
	pic = buffer;

	// detect dice shapes
	findContours(pic, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
	
	// iterate over dice contours
	for (int i = 0; i < contours.size(); i++)
	{
		// get contour area
		double diceContourArea = contourArea(contours[i]);

		// filter contours based on our dice size
		if (diceContourArea > 2000 && diceContourArea < 3500)
		{
			// get bounding rect
			cv::Rect diceBoundsRect = cv::boundingRect(Mat(contours[i]));

			// set dice roi
			Mat diceROI = pic(diceBoundsRect);

			// count number of pips and add dice to vector
			int numberOfPips = countPips(diceROI);
			dice.push_back(numberOfPips);

			//TEMP CODE
			std::cout << "Read dice: " << numberOfPips << std::endl;
		}
	}

	return dice;
}