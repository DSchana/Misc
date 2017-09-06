#include <cstdio>
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

using namespace std;
using namespace cv;

int main() {
	VideoCapture capture(0);
	Mat frame, frame_hsl;

	int lightness;

	if (!capture.isOpened()) {
		return -1;
	}

	capture >> frame;
	cvtColor(frame, frame_hsl, CV_RGB2HLS);

	// Create trackbars for HSL
	createTrackbar("Hue", "Frame", &lightness);

	while (capture.read(frame)) {
		cvtColor(frame, frame_hsl, CV_RGB2HLS);

		imshow("Frame", frame_hsl);

		if (char(waitKey(10)) == 27) {
			break;
		}
	}

	return 0;
}
