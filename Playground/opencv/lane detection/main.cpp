#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

void detectEdges(Mat frame, Mat three_edgy_five_me, Mat lanes);

int main() {
	VideoCapture capture(0);
	Mat frame, c_frame, three_edgy_five_me, lanes;

	capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

	if (!capture.isOpened()) {
		return -1;
	}

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

		c_frame.copyTo(three_edgy_five_me);
		detectEdges(c_frame, three_edgy_five_me, lanes);

		if (!frame.empty()) {
			imshow("Frame", frame);
			imshow("3 Edgy 5 Me", three_edgy_five_me);
		}

		if (char(waitKey(10)) == 27) {
			break;
		}
	}

	return 0;
}

void detectEdges(Mat frame, Mat three_edgy_five_me, Mat lanes) {
	Mat frame_gray, detected_edges;

	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	blur(frame_gray, detected_edges, Size(3, 3));
	Canny(detected_edges, detected_edges, 100, 300, 3);

	three_edgy_five_me = Scalar::all(0);
	frame.copyTo(three_edgy_five_me, detected_edges);

	//threshold(three_edgy_five_me, three_edgy_five_me, 128, 255, THRESH_BINARY_INV);
	
	cvtColor(three_edgy_five_me, lanes, CV_BGR2GRAY);

	// Hough lines detection
	vector<Vec2f> lines;
	HoughLines(three_edgy_five_me, lines, 1, CV_PI / 180, 100, 0, 0);

	for (size_t i = 0; i < lines.size(); i++) {
		float rho = lines[i][0];
		float theta = lines[i][1];
		Point p1, p2;
		double a = cos(theta);
		double b = sin(theta);
		double x0 = a * rho;
		double y0 = b * rho;

		// TODO: Understand this shit
		p1.x = cvRound(x0 + 1000 * (-b));
		p1.y = cvRound(y0 + 1000 * a);
		p2.x = cvRound(x0 - 1000 * (-b));
		p2.y = cvRound(y0 - 1000 * a);

		line(lanes, p1, p2, Scalar(0, 0, 255), 3, LINE_AA);
	}

	vector<Vec4i> lines;
}
