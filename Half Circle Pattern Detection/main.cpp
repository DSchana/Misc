#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <cstdio>

#define WINDOW_NAME "Pinch"

using namespace cv;
using namespace std;

// Function Prototypes
void terminate(VideoCapture &cap);

int main() {
	VideoCapture capture(0);
	Mat frame, hsv_frame, blur_frame, gray_frame;
	Mat red_filtered, red_filtered_2, blue_filtered, blue_filtered_2, red_blue_filtered;

	if (!capture.isOpened()) {
		printf("Error opening camera");
		return -1;
	}

	// Set resolution
	capture.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 240);

	while (capture.read(frame)) {
		if (frame.empty()) {
			printf("No captured frame");
			break;
		}

		if (char(waitKey(10) == 27)) {  // ESC
			break;
		}

		//GaussianBlur(frame, blur_frame, Size(9, 9), 2, 2);
		medianBlur(frame, blur_frame, 11);
		cvtColor(blur_frame, hsv_frame, CV_BGR2HSV);
		cvtColor(blur_frame, gray_frame, CV_BGR2GRAY);

		// Filter Red
		inRange(hsv_frame, Scalar(0, 70, 50), Scalar(10, 255, 255), red_filtered);

		// Filter Blue
		inRange(hsv_frame, Scalar(85, 50, 40), Scalar(135, 255, 255), blue_filtered);

		// Merge red and blue filters
		add(red_filtered, blue_filtered, red_blue_filtered);
		//red_blue_filtered *= 255;
		GaussianBlur(red_blue_filtered, red_blue_filtered, Size(9, 9), 2, 2);
		erode(red_blue_filtered, red_blue_filtered, Mat(), Point(-1, -1), 2, 1, 1);
		dilate(red_blue_filtered, red_blue_filtered, Mat(), Point(-1, -1), 2, 1, 1);

		// Detect circles
		vector<Vec3f> circles_rb, circles_r, circles_b;
		HoughCircles(red_blue_filtered, circles_rb, CV_HOUGH_GRADIENT, 2, frame.rows/8, 200, 100, 0, 0);
		HoughCircles(red_filtered, circles_r, CV_HOUGH_GRADIENT, 2, frame.rows/8, 200, 80, 0, 0);
		HoughCircles(blue_filtered, circles_b, CV_HOUGH_GRADIENT, 2, frame.rows/8, 200, 80, 0, 0);

		//cout << circles.size() << endl;
		// Draw circles
		for(size_t i = 0; i < circles_rb.size(); i++) {
			Point center(cvRound(circles_rb[i][0]), cvRound(circles_rb[i][1]));
			int radius = cvRound(circles_rb[i][2]);
			bool draw = true;

			for (size_t r = 0; r < circles_r.size(); r++) {
				Point center_n(cvRound(circles_r[i][0]), cvRound(circles_r[i][1]));
				if (norm(center_n - center) < 200) {
					draw = false;
					break;
				}
			}

			//cout << circles_b.size() << endl;
			for (size_t r = 0; r < circles_b.size(); r++) {
                                Point center_n(cvRound(circles_b[i][0]), cvRound(circles_b[i][1]));
				//cout << norm(center_n - center) << " " << center_n.x << ", " << center_n.y << endl;
                                if (norm(center_n - center) < 200) {
                                        draw = false;
					break;
                                }
                        }

			if (!draw) continue;

   			// circle center
   			circle(frame, center, 3, Scalar(0,255,0), -1, 8, 0);
   			// circle outline
   			circle(frame, center, radius, Scalar(0,0,255), 3, 8, 0);
		}

		imshow(WINDOW_NAME, frame);
		//imshow("R", red_filtered);
		//imshow("B", blue_filtered);
		//imshow("RB", red_blue_filtered);
	}

	terminate(capture);
	return 0;
}

// Exit program after cleaning up
void terminate(VideoCapture &cap) {
	destroyAllWindows();
	cap.release();
	exit(EXIT_SUCCESS);
}
