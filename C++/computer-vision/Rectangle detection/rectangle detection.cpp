#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
using namespace cv;

// Global variables

Mat src, src_gray;
Mat dst, cdst, ldst, detected_edges;
vector<Vec4i> lines;

int edgeThresh = 1;
int const lowThreshold = 5;
int const maxThreshold = 200;

int ratio = 3;
int kernel_size = 3;

int main() {

	//Load boxes.bmp into a matrix
	src = imread( "boxes.bmp",1 );

	//convert boxes.bmp into grayscale
	cvtColor( src, src_gray, CV_BGR2GRAY );

	// Reduce noise with a kernel 3x3
	blur( src_gray, detected_edges, Size(3,3) );

	// Canny detector
	Canny( detected_edges, detected_edges, lowThreshold, maxThreshold, kernel_size );

	// Using Canny's output as a mask, we display our result
	src.copyTo( dst, detected_edges);
	cvtColor( dst, cdst, CV_BGR2GRAY );
	HoughLinesP( cdst, lines, 25, CV_PI/180, 1, 0, 0);

	for( size_t i = 0; i < lines.size(); i++ ) {
		int x1 = lines[i][0];
		int x2 = lines[i][2];
		int y1 = lines[i][1];
		int y2 = lines[i][3];
		line( cdst, Point(x1, y1),
		Point(x2, y2), Scalar(255,255,255), 1, 8 );
	}
	imshow( "Source", src );
	imshow( "Detected Lines", cdst );

	waitKey();
};