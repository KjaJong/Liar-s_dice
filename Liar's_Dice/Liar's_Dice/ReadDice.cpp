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

	//TEST
	//cv::namedWindow("void", CV_WINDOW_AUTOSIZE);
	//imshow("void", dice);
	//cv::waitKey(0);
	//END TEST

	//set blob parameters
	cv::SimpleBlobDetector::Params params;
	params.filterByCircularity = true;
	params.minCircularity = 0.8;

	//params.filterByArea = true;
	//params.minArea = 10;
	//params.maxArea = 25;

	//check for blobs using the parameters
	std::vector<cv::KeyPoint> keypoints;
	cv::Ptr<cv::SimpleBlobDetector> blobDetector = cv::SimpleBlobDetector::create(params);

	//count blobs
	blobDetector->detect(dice, keypoints);

	return keypoints.size();
}

//take a picture and check the contours for dice. If player is setting a bid, make sure to set the int amount to 0.
std::vector<int> ReadDice::CheckDice(int amount)
{
	vector<int> dice;
	int count;

	PlayerInput PI = PlayerInput();
	Mat pic = PI.getPicture();
	int minThresh = 150;

	//read bet
	if (amount == 0)
	{
		while (true)
		{
			Mat buffer = pic;
			count = 0;

			//edit picture
			cvtColor(buffer, buffer, CV_BGR2GRAY);
			threshold(buffer, buffer, minThresh, 255, CV_THRESH_BINARY);

			//detect dice
			vector<vector<Point> > contours;
			vector<cv::Vec4i> hierarchy;
			findContours(buffer, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

			for (int i = 0; i < contours.size(); i++)
			{
				double area = contourArea(contours[i]);

				if (area > 600 && area < 1400)
				{
					count++;
				}
			}

			if (count == 2)
			{
				//iterate over dice contours
				for (int i = 0; i < contours.size(); i++)
				{
					double diceContourArea = contourArea(contours[i]);

					//filter small contours 
					if (diceContourArea > 600 && diceContourArea < 1400)
					{
						//get bounding rect
						cv::Rect diceBoundsRect = boundingRect(Mat(contours[i]));
						Mat dicePic = pic(diceBoundsRect);

						//count number of pips and add dice to vector
						int pips = countPips(dicePic);

						if (pips > 0 && pips < 7)
						{
							dice.push_back(pips);

							//TEST
							//std::cout << pips << std::endl;
							//END TEST
						}
					}
				}

				break;
			}
			if (minThresh >= 255)
			{
				break;
			}
			else
			{
				minThresh = minThresh + 1;
			}
		}
	}
	//read dice
	else
	{
		while (true)
		{
			Mat buffer = pic;
			count = 0;

			//edit picture
			cvtColor(buffer, buffer, CV_BGR2GRAY);
			threshold(buffer, buffer, minThresh, 255, CV_THRESH_BINARY);

			//detect dice
			vector<vector<Point> > contours;
			vector<cv::Vec4i> hierarchy;
			findContours(buffer, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

			for (int i = 0; i < contours.size(); i++)
			{
				double area = contourArea(contours[i]);

				if (area > 600 && area < 1400)
				{
					count++;
				}
			}

			if (count == amount)
			{
				//iterate over dice contours
				for (int i = 0; i < contours.size(); i++)
				{
					double diceContourArea = contourArea(contours[i]);

					//filter small contours 
					if (diceContourArea > 600 && diceContourArea < 1400)
					{
						//get bounding rect
						cv::Rect diceBoundsRect = boundingRect(Mat(contours[i]));
						Mat dicePic = pic(diceBoundsRect);

						//count number of pips and add dice to vector
						int pips = countPips(dicePic);

						if (pips > 0 && pips < 7)
						{
							dice.push_back(pips);

							//TEST
							//std::cout << pips << std::endl;
							//END TEST
						}
					}
				}

				break;
			}
			if (minThresh >= 255)
			{
				break;
			}
			else
			{
				minThresh = minThresh + 1;
			}
		}
	}

	return dice;
}