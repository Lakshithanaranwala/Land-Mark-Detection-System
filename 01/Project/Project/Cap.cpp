#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"
#include "stdio.h"
#include "string"
#include <stdlib.h>

using namespace cv;
using namespace std;

int lowerH = 168;
int upperH = 256;

int lowerS = 175;
int upperS = 256;

int lowerV = 0;
int upperV = 256;

IplImage* frame = 0;
IplImage* frame2 = 0;
IplImage* imgHSV = 0;
IplImage* imgThresh = 0;



void draw_conture(IplImage * temp)
{
	

	CvSeq* contour;  
	CvSeq* result;   
	CvMemStorage *storage = cvCreateMemStorage(0);

	cvFindContours(temp, storage, &contour, sizeof(CvContour),
		CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));

	for (; contour != 0; contour = contour->h_next)
	{
		result = cvApproxPoly(contour, sizeof(CvContour),
			storage, CV_POLY_APPROX_DP, cvContourPerimeter(contour)*0.02, 0);
		CvRect rect = cvBoundingRect(contour, 0);
		if (cvContourArea(result, CV_WHOLE_SEQ, 0) >= 1000)
		{
			
			frame2 = cvCreateImage(cvGetSize(frame), frame->depth, frame->nChannels);
			cvCopy(frame, frame2);
			cvRectangle(frame2, cvPoint(rect.x, rect.y),
				cvPoint(rect.x + rect.width, rect.y + rect.height), CV_RGB(0, 0, 255), 2, 8, 0);
		}
	}
	cvShowImage("Object Color Range", frame2);
}

#pragma region trackbar

void on_trackbar1(int position)
{
	lowerH = position;
	cvInRangeS(imgHSV, cvScalar(lowerH, lowerS, lowerV), cvScalar(upperH, upperS, upperV), imgThresh);
	cvShowImage("Object Detected", imgThresh);
	draw_conture(imgThresh);
}

void on_trackbar2(int position)
{
	upperH = position;
	cvInRangeS(imgHSV, cvScalar(lowerH, lowerS, lowerV), cvScalar(upperH, upperS, upperV), imgThresh);
	cvShowImage("Object Detected", imgThresh);
	draw_conture(imgThresh);
}

void on_trackbar3(int position)
{
	lowerS = position;
	cvInRangeS(imgHSV, cvScalar(lowerH, lowerS, lowerV), cvScalar(upperH, upperS, upperV), imgThresh);
	cvShowImage("Object Detected", imgThresh);
	draw_conture(imgThresh);
}

void on_trackbar4(int position)
{
	upperS = position;
	cvInRangeS(imgHSV, cvScalar(lowerH, lowerS, lowerV), cvScalar(upperH, upperS, upperV), imgThresh);
	cvShowImage("Object Detected", imgThresh);
	draw_conture(imgThresh);
}

void on_trackbar5(int position)
{
	lowerV = position;
	cvInRangeS(imgHSV, cvScalar(lowerH, lowerS, lowerV), cvScalar(upperH, upperS, upperV), imgThresh);
	cvShowImage("Object Detected", imgThresh);
	draw_conture(imgThresh);
}

void on_trackbar6(int position)
{
	upperV = position;
	cvInRangeS(imgHSV, cvScalar(lowerH, lowerS, lowerV), cvScalar(upperH, upperS, upperV), imgThresh);
	cvShowImage("Object Detected", imgThresh);
	draw_conture(imgThresh);
}

#pragma endregion trackbar

int main()
{
	cvNamedWindow("Object Color Range", 1);
	//cvNamedWindow("Object Detected", 1);
	
	int capacity=0;
	int section;
	int view;
	//int x;
	while (capacity++ <= 4) {
		cout << "\t\t''''Peradeniya University''''\n ";
		cout << "\n\t\t\t\t'''SECTION'''\n";
		cout << "\t1.Runnig Track\n";
		cout << "\t2.Cricket Ground\n";
		cout << "\t3.Indoor Stadium\n";
		cout << "\t4.River\n";
		cout << "\t5.Ruger ground\n";
		cout << "\nselect section :";
		cin >> section;
		cout << "\nEnter view :\n";
		cin >> view;

		



		if (section == 1)// Running Track
		{
			if (view == 1) {
				frame = cvLoadImage("1.png", 1);
			}
			if (view == 2) {
				frame = cvLoadImage("2.png", 1);
			}
			if (view == 3) {
				frame = cvLoadImage("3.png", 1);
			}

			lowerH = 55; upperH = 154;
			lowerS = 0; upperS = 40;
			lowerV = 97; upperV = 142;
		}


		else if (section == 2)//Cricket Ground
		{
			if (view == 1) {
				frame = cvLoadImage("1.png", 1);
			}
			if (view == 2) {
				frame = cvLoadImage("2.png", 1);
			}
			if (view == 3) {
				frame = cvLoadImage("3.png", 1);
			}
			lowerH = 47; upperH = 189;
			lowerS = 49; upperS = 222;
			lowerV = 143; upperV = 215;
		}
		else if (section == 3)//Indoor Stadium
		{
			if (view == 1) {
				frame = cvLoadImage("1.png", 1);
			}
			if (view == 2) {
				frame = cvLoadImage("2.png", 1);
			}
			if (view == 3) {
				frame = cvLoadImage("3.png", 1);
			}
			lowerH = 70; upperH = 116;
			lowerS = 10; upperS = 155;
			lowerV = 148; upperV = 256;
		}
		else if (section == 4)//River
		{
			if (view == 1) {
				frame = cvLoadImage("1.png", 1);
			}
			if (view == 2) {
				frame = cvLoadImage("2.png", 1);
			}
			if (view == 3) {
				frame = cvLoadImage("3.png", 1);
			}
			lowerH = 0; upperH = 96;
			lowerS = 3; upperS = 46;
			lowerV = 96; upperV = 126;
		}

		else if (section == 5)//RugerGround
		{
			if (view == 1) {
				frame = cvLoadImage("1.png", 1);
			}
			if (view == 2) {
				frame = cvLoadImage("4.png", 1);
			}
			if (view == 3) {
				frame = cvLoadImage("3.png", 1);
			}
			lowerH = 18; upperH = 192;
			lowerS = 32; upperS = 222;
			lowerV = 143; upperV = 215;
		}



		cvCreateTrackbar("LowerH", "Object Detected", &lowerH, 256, on_trackbar1);
		cvCreateTrackbar("UpperH", "Object Detected", &upperH, 256, on_trackbar2);
		cvCreateTrackbar("LowerS", "Object Detected", &lowerS, 256, on_trackbar3);
		cvCreateTrackbar("UpperS", "Object Detected", &upperS, 256, on_trackbar4);
		cvCreateTrackbar("LowerV", "Object Detected", &lowerV, 256, on_trackbar5);
		cvCreateTrackbar("UpperV", "Object Detected", &upperV, 256, on_trackbar6);
		//frame = cvLoadImage("1.png", 1);

		imgHSV = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
		imgThresh = cvCreateImage(cvGetSize(imgHSV), IPL_DEPTH_8U, 1);
		cvCvtColor(frame, imgHSV, CV_BGR2HSV);
		cvInRangeS(imgHSV, cvScalar(lowerH, lowerS, lowerV), cvScalar(upperH, upperS, upperV), imgThresh);

		//cvShowImage("Object Detected", imgThresh);
		cvShowImage("Object Color Range", frame);

		draw_conture(imgThresh);
		cvWaitKey(0);

		cvReleaseImage(&imgHSV);
		cvReleaseImage(&imgThresh);
		cvReleaseImage(&frame);


		cvDestroyAllWindows();
	}

	cout << "\t\t\tTHANK YOU!!\n";
	return 0;
}