#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;

int main() {
	VideoCapture capture(0);
	Mat frame;

	if (!capture.isOpened()) {
		return -1;
	}

	while (capture.read(frame)) {
		imshow("Frame", frame);

		if (char(waitKey(10)) == 27) {
			break;
		}
	}

	return 0;
}
