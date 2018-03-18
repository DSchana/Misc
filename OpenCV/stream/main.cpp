#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;

int main() {
	VideoCapture cap1(0);
	//VideoCapture cap2(1);
	Mat frame1, frame2;

	cap1.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	cap1.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	//cap2.set(CV_CAP_PROP_FRAME_WIDTH, 640);
	//cap2.set(CV_CAP_PROP_FRAME_HEIGHT, 480);

	while (cap1.read(frame1) /*|| cap2.read(frame2)*/) {
		imshow("Frame1", frame1);
		//imshow("Frame2", frame2);

		if (char(waitKey(10)) == 27) {
			break;
		}
	}

	return 0;
}
