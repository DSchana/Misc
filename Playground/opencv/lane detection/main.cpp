#include <cmath>
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

void detectLanes(Mat frame);

// Constants
const Rect SEARCH_AREA(215, 100, 200, 150);

int main() {
	// VideoCapture capture(0);
	Mat frame, search_frame;

	// capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	// capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

	/*
	if (!capture.isOpened()) {
		return -1;
	}
	*/

	frame = imread("images/road2.jpg");

	while (true) {
		/*
		capture >> frame;

		if (frame.empty()) {
			break;
		}
		*/

		search_frame = frame(SEARCH_AREA);

		detectLanes(search_frame);

		if (!frame.empty()) {
			imshow("Frame", frame);
		}

		if (char(waitKey(10)) == 27) {
			break;
		}
	}

	return 0;
}

void detectLanes(Mat frame) {
	Mat frame_gray, detected_edges, detected_edges_inv;
	
	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	blur(frame_gray, detected_edges, Size(3, 3));
	Canny(detected_edges, detected_edges, 100, 250, 3);

	// TODO: Only show lines who's angles match the expected for a road line.
	// Find lines
	vector<Vec4i> lines;
	HoughLinesP(detected_edges, lines, 1, CV_PI / 180, 40, 30, 10);
	
	for (size_t i = 0; i < lines.size(); i++) {
		Point p1(lines[i][0], lines[i][1]);
		Point p2(lines[i][2], lines[i][3]);

		double theta = atan((double)abs(p1.y - p2.y)  / (double)abs(p1.x - p2.x));  // Angle to the horizontal by the 2 points

		if (theta >= CV_PI / 6 && theta <= CV_PI / 2) {
			line(frame, p1, p2, Scalar(229, 181, 51), 3, 8);
		}
	}
}
