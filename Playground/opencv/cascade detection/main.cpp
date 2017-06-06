#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

#include <cstdio>
#include <vector>

#define R_WIDTH  640
#define R_HEIGHT 480

using namespace std;
using namespace cv;

// Global constants
const string CASCADE_NAME = "haarcascade_fullbody.xml";
CascadeClassifier cascade;

int main() {
	VideoCapture capture(0);
	Mat frame;

	// Check if camera is open
	if (!capture.isOpened()) {
		printf("Camera's not opening\n");
		return -1;
	}

	// Set resolution
	capture.set(CV_CAP_PROP_FRAME_WIDTH,  R_WIDTH);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, R_HEIGHT);

	// Load the cascade
	if (!cascade.load("Data/" + CASCADE_NAME)) {
		printf("Cascade not loading\n");
		return -1;
	}

	// Variables for cascading
		vector<Rect> obj;
		Mat frame_gray, frame_gray_blur;

	while (true) {
		/*
		capture >> frame;

		if (frame.empty()) {
			break;
		}
		*/
		frame = imread("images/people.jpg");

		cvtColor(frame, frame_gray, CV_BGR2GRAY);
		equalizeHist(frame_gray, frame_gray);
		GaussianBlur(frame_gray, frame_gray_blur, Size(3, 3), 0, 0);  // Remove this bit if the blur is making the detection not work.

		cascade.detectMultiScale(frame_gray, obj, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(80, 80));

		for (size_t i = 0; i < obj.size(); i++) {
			rectangle(frame, Point(obj[i].x, obj[i].y), Point(obj[i].x + obj[i].width, obj[i].y + obj[i].height), Scalar(229, 181, 51), 4);
		}

		imshow("Frame", frame);

		if (char(waitKey(10)) == 27) {
			break;
		}
	}

	return 0;
}
