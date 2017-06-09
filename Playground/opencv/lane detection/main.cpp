#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

void detectEdges(Mat frame, Mat detected_edges);

int main() {
	// VideoCapture capture(0);
	Mat frame, c_frame, detected_edges;

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

		// Area to search for lines in
		Rect search_area(215, 100, 200, 150);

		c_frame = frame(search_area);

		detectEdges(c_frame, detected_edges);

		if (!frame.empty()) {
			imshow("Frame", frame);
		}

		if (char(waitKey(10)) == 27) {
			break;
		}
	}

	return 0;
}

void detectEdges(Mat frame, Mat detected_edges) {
	Mat frame_gray, detected_edges_inv;

	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	blur(frame_gray, detected_edges, Size(3, 3));
	Canny(detected_edges, detected_edges, 100, 250, 3);
	threshold(detected_edges, detected_edges_inv, 128, 255, THRESH_BINARY_INV);

	// DISPLAY
	imshow("Edges", detected_edges_inv);

	// Find lines 
}
