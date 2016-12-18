#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
//#include "Test.h"

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#define WINDOW_NAME "Playground"

#define H_BLUE_MAX 144 // Largest centre for blue hue
#define H_BLUE_MIN 80  // Smallest centre for blue hue

// Blue threshold values
int H_MIN_BLUE = 81;
int H_MAX_BLUE = 135;

int S_MIN_BLUE = 0;
int S_MAX_BLUE = 255;

int L_MIN_BLUE = 25;
int L_MAX_BLUE = 230;

// Red threshold values
int H_MIN_RED = 165;
int H_MAX_RED = 15;

int S_MIN_RED = 0;  // 100
int S_MAX_RED = 255;

int L_MIN_RED = 80;  // 74
int L_MAX_RED = 255;

using namespace std;
using namespace cv;

void filterNoise(Mat &src, Mat &dst);
void averageHue(vector<vector<Point> > &contours, Mat &src, int &avg_hue);
bool findPattern(vector<vector<Point> > &contours, Mat &src);

int main() {
	//Test nums(2, 3);
	//printf("Number: %d\n", nums.sum());

	// Initial Blue HSL
	int H_BLUE = 128;
	int S_BLUE = 128;
	int L_BLUE = 128;

	// Initial Blue HSL Offset
	int H_BLUE_OFFSET = 15;
	int S_BLUE_OFFSET = 127;
	int L_BLUE_OFFSET = 127;  // 103

	bool pattern_found = false;  // true if the pattern is found

	VideoCapture capture(0);
	Mat frame, frame_hls;
	Mat blue_filtered, red_filtered, r1, r2;  // r1 and r2 for different sides of spectrum
	Mat blue_cont, red_cont;

	if (!capture.isOpened()) {
		printf("Error when opening camera\n");
		return -1;
	}

	// Set resolution
	capture.set(CV_CAP_PROP_FRAME_WIDTH, 320);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 240);

	while (capture.read(frame)) {
		if (frame.empty()) {
			printf("No capture frame\n");
			break;
		}

		// Blue thresholds
        	Vec3b min_thresh_blue(H_BLUE - H_BLUE_OFFSET, L_BLUE - L_BLUE_OFFSET, S_BLUE - S_BLUE_OFFSET);
        	Vec3b max_thresh_blue(H_BLUE + H_BLUE_OFFSET, L_BLUE + L_BLUE_OFFSET, S_BLUE + S_BLUE_OFFSET);

        	// Red thresholds
        	Vec3b min_thresh_red_1(0, L_MIN_RED, S_MIN_RED);
        	Vec3b max_thresh_red_1(H_MAX_RED, L_MAX_RED, S_MAX_RED);

        	Vec3b min_thresh_red_2(H_MIN_RED, L_MIN_RED, S_MIN_RED);
        	Vec3b max_thresh_red_2(180, L_MAX_RED, S_MAX_RED);

		// TODO: Crop frame to restrict search area

		cvtColor(frame, frame_hls, CV_BGR2HLS);

		// cout << frame_hls.at<Vec3b>(0, 0) << endl;
		inRange(frame_hls, min_thresh_blue, max_thresh_blue, blue_filtered);
		inRange(frame_hls, min_thresh_red_1, max_thresh_red_1, r1);
		inRange(frame_hls, min_thresh_red_2, max_thresh_red_2, r2);

		red_filtered = r1 + r2;

		filterNoise(blue_filtered, blue_filtered);
		filterNoise(red_filtered, red_filtered);

		blue_filtered.copyTo(blue_cont);
		red_filtered.copyTo(red_cont);

		// Find and count blobs
		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;
		findContours(blue_cont, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

		cout << contours.size() << endl;
		if (contours.size() > 6 && H_BLUE_OFFSET > 0) {
			// Narrow hue
			H_BLUE_OFFSET--;
		}
		else if (!pattern_found && H_BLUE_OFFSET < 180) {
			// Widen hue
			H_BLUE_OFFSET++;
		}

		// TODO: create pattern search function to search the contours for the pattern

		// Recentre hue
		/*
		if (contours.size() > 0) {
			//averageHue(contours, frame_hls, H_BLUE);
		}
		*/

		// Manual force calibration
		if (char(waitKey(10)) == char('c')) {
			int dim = 30;
			Rect calib_rect = Rect((frame.cols - dim) / 2, (frame.rows - dim) / 2, dim, dim);
			rectangle(frame, calib_rect, Scalar(229, 181, 51), 4);
			Scalar colour = mean(frame_hls(calib_rect));
			H_BLUE = colour[0];
		}

		//findPattern(contours, frame_hls);

		putText(blue_filtered, "HUE: " + to_string(H_BLUE), Point(10, 25), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255));
		putText(blue_filtered, "OFF: " + to_string(H_BLUE_OFFSET), Point(10, 50), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255));

		imshow(WINDOW_NAME, frame);
		imshow("HLS", frame_hls);
		imshow("blue filtered", blue_filtered);
		//imshow("red filtered", red_filtered);
	}

	cout << "Done" << endl;
	return 0;
}

void filterNoise(Mat &src, Mat &dst) {
	erode(src, dst, Mat(), Point(-1, -1), 3, 1, 1);
	dilate(src, dst, Mat(), Point(-1, -1), 2, 1, 1);
}

void averageHue(vector<vector<Point> > &contours, Mat &src, int &avg_hue) {
	avg_hue = 0;

	for (int i = 0; i < contours.size(); i++) {
		// Get bounding box on contour
		vector<Point> contours_poly;
		approxPolyDP(Mat(contours[i]), contours_poly, 3, true);
		Rect bounding_rect = boundingRect(Mat(contours_poly));

		avg_hue += mean(src(bounding_rect))[0];
	}

	avg_hue /= contours.size();
}

bool findPattern(vector<vector<Point> > &contours, Mat &src) {
	int cont_size = contours.size();
	vector<vector<Point> > contours_poly(cont_size);
	vector<float> radii(cont_size);
	vector<Point2f> centres(cont_size);
	int dist_blues;  // Distance between blue dots

	for (int i = 0; i < cont_size; i++) {
		// Get bounding circle on contour
		// NOTE: the circle is mapped as if the half circle were a full one.
		// ie. the radius here is the apparent radius of the circle
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
		minEnclosingCircle((Mat)contours_poly[i], centres[i], radii[i]);

		// TODO: estimate where the next circle should be relative to this one. Maybe do it as a separate function.
	}

	// A bit hacky but not a bad approximation
	// Find most frequent radius
	// TODO: Allow for margin of error in radius size
	vector<int> frequency(*max_element(radii.begin(), radii.end()));
	fill(frequency.begin(), frequency.end(), 0);
	for (int i = 0; i < cont_size; i++) {
		frequency[radii[i]]++;
	}

	// Get largest radius with the greatest frequency
	// TODO: Maybe consider finding only radius that occurs 3 times
	int most_probable_radius = -1;
	int max_freq = 0;
	for (int i = frequency.size(); i > 0; i--) {
		if (frequency[i] > max_freq) {
			max_freq = frequency[i];
			most_probable_radius = i;
		}
	}

	/*
	for (int i = 0; i < cont_size; i++) {
		// Temp.
		circle(src, centres[i], (int)radii[i], Scalar(0, 255, 0), 2, 8, 0);

		while (points.size() < 3) {
			for (int j = 0; j < contours.size(); j++) {
				int dist = sqrt(pow(, 2) + pow(, 2));
			}
		}
	}
	*/

	return false;
}
