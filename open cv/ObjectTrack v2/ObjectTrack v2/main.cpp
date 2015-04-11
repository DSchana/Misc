#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <iostream>

using namespace cv;
using namespace std;

// Global variables
Mat source, gray;
Mat dst, cdst, ldst, detected_edges;
vector<Vec4i> lines;

VideoCapture cap;

int edgeThresh;
int const lowThreshold = 5;
int const maxThreshold = 200;

int ratio = 3;
int kernel_size = 3;

char* window_name1 = "Edge Map";
char* window_name2 = "Line Map";

int main() {
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	cap.open(0);

	namedWindow("Camera Window", 1);

	while (true) {
		try
		{
			cap >> source;  // try to capture image from camera
		}
		catch (Exception& e)  // Image not found, do this
		{
			const char* err_msg = e.what();  // get error
			std::cout << "exception caught: imshow:\n" << err_msg << std::endl;  // display error
		}

		// Convert image to gray
		cv::cvtColor(source, gray, CV_BRG2GRAY);

		// reduce noise
		blur(gray, detected_edges, cv::Size(3x3));

		// Canny detector
		Canny(detected_edges, detected_edges, lowThreshold, maxThreshold, kernel_size);

		// use canny output as a mask
		source.copyTo(dst, detected_edges);
		cvtColor(dst, cdst, CV_BRG2GRAY);
		HoughLines(cdst, lines, 25, CV_PI / 180, 1, 0, 0);

		for (size_t i = 0; i < lines.size(); i++) {
			int x1 = lines[i][0];
			int x2 = lines[i][2];
			int y1 = lines[i][1];
			int y2 = lines[i][3];
			line(cdst, Point(x1, y1), Point(x2, y2), Scalar(255, 255, 255), 1, 8);
		}

		imshow("Source", source);
		imshow("Detected lines", cdst);

		waitKey();
	}
	return 0;
}