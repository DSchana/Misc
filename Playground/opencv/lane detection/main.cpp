#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

void detectEdges(Mat frame, Mat three_edgy_five_me);

int main() {
	VideoCapture capture(0);
	Mat frame, three_edgy_five_me;

	capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

	if (!capture.isOpened()) {
		return -1;
	}

	while (capture.read(frame)) {
		capture >> frame;

		frame.copyTo(three_edgy_five_me);
		detectEdges(frame, three_edgy_five_me);

		//namedWindow("Frame", WINDOW_AUTOSIZE);
		//namedWindow("3 Edgy 5 Me", WINDOW_AUTOSIZE);

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

void detectEdges(Mat frame, Mat three_edgy_five_me) {
	Mat frame_gray, detected_edges;

	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	blur(frame_gray, detected_edges, Size(3, 3));
	Canny(detected_edges, detected_edges, 100, 100 * 3, 3);

	three_edgy_five_me = Scalar::all(0);
	frame.copyTo(three_edgy_five_me, detected_edges);
}
