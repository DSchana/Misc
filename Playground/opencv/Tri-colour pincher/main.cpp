#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
using namespace cv;

void filterNoise(Mat &src, Mat &dst);
void modifyRange(vector<vector<Point> > contours, int &H_OFFSET, int count);
void boundingPolygon(vector<vector<Point> > &contours, vector<Vec4i> &hierarchy, Mat &in_frame, Mat &out_frame, vector<RotatedRect> &min_rect, Scalar colour);

int main() {
	// Initial Blue HSL
	int H_BLUE = 128;
	int S_BLUE = 128;
	int L_BLUE = 128;

	// Initail Green HSL
	int H_GREEN = 64;
	int S_GREEN = 128;
	int L_GREEN = 128;

	// Initial Red HSL
	int H_RED = 5;
	int S_RED = 128;
	int L_RED = 128;

	// Initial Blue HSL Offset
	int H_BLUE_OFFSET = 15;
	int S_BLUE_OFFSET = 127;
	int L_BLUE_OFFSET = 127;

	// Initial Green HSL Offset
	int H_GREEN_OFFSET = 15;
	int S_GREEN_OFFSET = 127;
	int L_GREEN_OFFSET = 127;

	// Initial Red HSL Offset
	int H_RED_OFFSET = 15;
	int S_RED_OFFSET = 127;
	int L_RED_OFFSET = 127;

	bool pattern_found_left = false;
	bool pattern_found_right = false;

	// Pincher attributes
	Point2f left_centre(0, 0), right_centre(0, 0);
	int left_angle, right_angle;
	int left_dist, right_dist;

	VideoCapture capture(0);
	Mat frame, frame_hls;
	Mat blue_filtered, red_filtered, green_filtered;
	Mat blue_cont, red_cont, green_cont;  // For contours

	if (!capture.isOpened()) {
		printf("No camera found\n");
	}

	capture.set(CV_CAP_PROP_FRAME_WIDTH, 570);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 320);

	while (capture.read(frame)) {
		// TODO: Try bluring frame here

		if (frame.empty()) {	
			printf("No frame captured\n");
			break;
		}

		// Blue thresholds
        	Vec3b min_thresh_blue(H_BLUE - H_BLUE_OFFSET, L_BLUE - L_BLUE_OFFSET, S_BLUE - S_BLUE_OFFSET);
        	Vec3b max_thresh_blue(H_BLUE + H_BLUE_OFFSET, L_BLUE + L_BLUE_OFFSET, S_BLUE + S_BLUE_OFFSET);

		// Red thresholds
		Vec3b min_thresh_red(0, L_RED - L_RED_OFFSET, S_RED - S_RED_OFFSET);
		Vec3b max_thresh_red(H_RED + H_RED_OFFSET, L_RED + L_RED_OFFSET, S_RED + S_RED_OFFSET);

		/*
		Vec3b min_thresh_red_1(0, L_MIN_RED, S_MIN_RED);
        	Vec3b max_thresh_red_1(H_MAX_RED, L_MAX_RED, S_MAX_RED);

        	Vec3b min_thresh_red_2(H_MIN_RED, L_MIN_RED, S_MIN_RED);
        	Vec3b max_thresh_red_2(180, L_MAX_RED, S_MAX_RED))
		*/

		// Green thresholds
		Vec3b min_thresh_green(H_GREEN - H_GREEN_OFFSET, L_GREEN - L_GREEN_OFFSET, S_GREEN - S_GREEN_OFFSET);
                Vec3b max_thresh_green(H_GREEN + H_GREEN_OFFSET, L_GREEN + L_GREEN_OFFSET, S_GREEN + S_GREEN_OFFSET);

		cvtColor(frame, frame_hls, CV_BGR2HLS);

		// Filter colours
		inRange(frame_hls, min_thresh_blue, max_thresh_blue, blue_filtered);
		inRange(frame_hls, min_thresh_green, max_thresh_green, green_filtered);
		inRange(frame_hls, min_thresh_red, max_thresh_red, red_filtered);

		filterNoise(blue_filtered, blue_filtered);
		filterNoise(green_filtered, green_filtered);
		filterNoise(red_filtered, red_filtered);

		blue_filtered.copyTo(blue_cont);
		green_filtered.copyTo(green_cont);
		red_filtered.copyTo(red_cont);

		/*
		// Find and count blobs
		vector<vector<Point> > blue_contours;
		vector<vector<Point> > green_contours;
		vector<vector<Point> > red_contours;
	
		vector<Vec4i> blue_hierarchy;
		vector<Vec4i> green_hierarchy;
		vector<Vec4i> red_hierarchy;

		findContours(blue_cont, blue_contours, blue_hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
		findContours(green_cont, green_contours, green_hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
		findContours(red_cont, red_contours, red_hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
		*/

		// -------------- SEARCH ALGORITHM WOOT WOOT -------------------
		// Step 1 - Find circles in blue and green for left and right
		//	    pincher width.
		// Step 2 - Find closest red.
		// Step 3 - Use centres to map a line representing the pincher's
		// 	    colours.
		// Step 4 - Find the nearest missing colour on the line. This is
		// 	    the last square of the pincher.
		// Step 5 - Ensure the centres of all colours are equdistant and
		// 	    equal to twice the radis of the initial circle.
		// 	    Within a margin of error.
		// Step 6 - Use centre of red as coordinates of entire pincher.

		// NOTE: Use RotatedRect to estimate location of other things.
		// ---------------------- HERE WE GO ---------------------------
		vector<vector<Point> > blue_contours, green_contours, red_contours;
		vector<Vec4i> blue_hierarchy, green_hierarchy, red_hierarchy;
		vector<RotatedRect> blue_rects, green_rects, red_rects;

		/*
		GaussianBlur(blue_filtered, blue_filtered, Size(9, 9), 2, 2 );
                GaussianBlur(green_filtered, green_filtered, Size(9, 9), 2, 2 );
                GaussianBlur(red_filtered, red_filtered, Size(9, 9), 2, 2 );
		*/
		blur(blue_filtered, blue_filtered, Size(3, 3));
		blur(green_filtered, green_filtered, Size(3, 3));
		blur(red_filtered, red_filtered, Size(3, 3));

		boundingPolygon(blue_contours, blue_hierarchy, blue_filtered, frame, blue_rects, Scalar(255, 0, 0));
		boundingPolygon(green_contours, green_hierarchy, green_filtered, frame, green_rects, Scalar(0, 255, 0));
		boundingPolygon(red_contours, red_hierarchy, red_filtered, frame, red_rects, Scalar(0, 0, 255));

		vector<RotatedRect> pot_pincher_left, pot_pincher_right;

		// Check above and below the red squares for blue and green squares
		for (int i = 0; i < red_rects.size(); i++) {
			Point2f p1 = red_rects[i].center + Point2f(red_rects[i].size.height * sin(red_rects[i].angle), red_rects[i].size.height * cos(red_rects[i].angle));
			Point2f p2 = red_rects[i].center - Point2f(red_rects[i].size.height * sin(red_rects[i].angle), red_rects[i].size.height * cos(red_rects[i].angle));

			// Ensure the points are (p1, p2) -> (top, bottom)
			if (p1.y > p2.y) {
				Point2f tmp = p1;
				p1 = p2;
				p2 = tmp;
			}

			Vec3b top_colour = frame_hls.at<Vec3b>(p1);
			Vec3b bot_colour = frame_hls.at<Vec3b>(p2);

			Vec3b min_blue(max(0, H_BLUE - H_BLUE_OFFSET - 10), L_BLUE - L_BLUE_OFFSET, S_BLUE - S_BLUE_OFFSET);
			Vec3b max_blue(min(255, H_BLUE + H_BLUE_OFFSET + 10), L_BLUE + L_BLUE_OFFSET, S_BLUE + S_BLUE_OFFSET);
			Vec3b min_green(max(0, H_GREEN - H_GREEN_OFFSET - 10), L_GREEN - L_GREEN_OFFSET, S_GREEN - S_GREEN_OFFSET);
                        Vec3b max_green(min(255, H_GREEN + H_GREEN_OFFSET + 10), L_GREEN + L_GREEN_OFFSET, S_GREEN + S_GREEN_OFFSET);

			double top_mag = norm(top_colour, CV_L2);
			double bot_mag = norm(bot_colour, CV_L2);
			double min_blue_mag = norm(min_blue, CV_L2);
			double max_blue_mag = norm(max_blue, CV_L2);
			double min_green_mag = norm(min_green, CV_L2);
			double max_green_mag = norm(max_green, CV_L2);

			if (top_mag >= min_blue_mag && top_mag <= max_blue_mag && bot_mag >= min_green_mag && bot_mag <= max_green_mag) {
				// Found Left
				//left_centre = red_rects[i].center;
				//left_angle = red_rects[i].angle;
				pot_pincher_left.push_back(red_rects[i]);
			}

			else if (bot_mag >= min_blue_mag && bot_mag <= max_blue_mag && top_mag >= min_green_mag && top_mag <= max_green_mag) {
                                // Found Right
                                //right_centre = red_rects[i].center;
                                //right_angle = red_rects[i].angle;
				pot_pincher_right.push_back(red_rects[i]);
                        }

			//line(frame, red_rects[i].center, p1, Scalar(0, 0, 255), 2, 8);
			//putText(frame, "*", p1, FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));
			//putText(frame, "*", p2, FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));

			// TODO: Check for green squares above or below, if a square actually exists
		}

		int curr_left = 0;
		int curr_right = 0;

		if (pot_pincher_left.size() > 0) {
			for (int i = 1; i < pot_pincher_left.size(); i++) {
				if (pot_pincher_left[i].size.height * pot_pincher_left[i].size.width > pot_pincher_left[curr_left].size.height * pot_pincher_left[curr_left].size.width) {
					curr_left = i;
				}
			}
			//putText(frame, "L", pot_pincher_left[curr_left].center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255));
			//line(frame, pot_pincher_left[curr_left].center, pot_pincher_left[curr_left].center, Scalar(255, 255, 255), 2, 8);
			circle(frame, pot_pincher_left[curr_left].center, 5, Scalar(255, 255, 255), -1);
		}

		if (pot_pincher_right.size() > 0) {
			for (int i = 1; i < pot_pincher_right.size(); i++) {
                        	if (pot_pincher_right[i].size.height * pot_pincher_right[i].size.width > pot_pincher_right[curr_right].size.height * pot_pincher_right[curr_right].size.width) {
                                	curr_right = i;
                        	}
                	}
			//putText(frame, "  R", pot_pincher_right[curr_right].center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255));
			//line(frame, pot_pincher_right[curr_right].center, pot_pincher_right[curr_right].center, Scalar(0, 0, 255), 2, 8);
			circle(frame, pot_pincher_right[curr_right].center, 5, Scalar(255, 255, 255), -1);
		}
		// -------------------------------------------------------------

		modifyRange(blue_contours, H_BLUE_OFFSET, 4);
		modifyRange(green_contours, H_GREEN_OFFSET, 4);
		modifyRange(red_contours, H_RED_OFFSET, 4);

		putText(blue_filtered, "B_HUE: " + to_string(H_BLUE), Point(10, 25), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255));
		putText(blue_filtered, "B_OFF: " + to_string(H_BLUE_OFFSET), Point(10, 50), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255));
		putText(green_filtered, "G_HUE: " + to_string(H_GREEN), Point(10, 25), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255));
                putText(green_filtered, "G_OFF: " + to_string(H_GREEN_OFFSET), Point(10, 50), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255));
		putText(red_filtered, "R_HUE: " + to_string(H_RED), Point(10, 25), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255));
                putText(red_filtered, "R_OFF: " + to_string(H_RED_OFFSET), Point(10, 50), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255));

		imshow("HLS", frame_hls);
		imshow("blue filtered", blue_filtered);
		imshow("green filtered", green_filtered);
		imshow("red filtered", red_filtered);
		imshow("main", frame);
	}

return 0;
}

void filterNoise(Mat &src, Mat &dst) {
	erode(src, dst, Mat(), Point(-1, -1), 3, 1, 1);
	dilate(src, dst, Mat(), Point(-1, -1), 2, 1, 1);
}

void modifyRange(vector<vector<Point> > contours, int &H_OFFSET, int count) {
	if (contours.size() > count && H_OFFSET > 0) {
		H_OFFSET--;
	}
	else if (H_OFFSET < 180) {
		H_OFFSET++;
	}
}

void boundingPolygon(vector<vector<Point> > &contours, vector<Vec4i> &hierarchy, Mat &in_frame, Mat &out_frame, vector<RotatedRect> &min_rect, Scalar colour) {
	findContours(in_frame, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	min_rect.resize(contours.size());
	vector<RotatedRect> min_ellipse(contours.size());

	for (int i = 0; i < contours.size(); i++) {
		min_rect[i] = minAreaRect(Mat(contours[i]));
		if (contours[i].size() > 5) {
			min_ellipse[i] = fitEllipse(Mat(contours[i]));
		}
	}

	for (int i = 0; i < contours.size(); i++) {
		drawContours(in_frame, contours, i, colour, 1, 8, vector<Vec4i>(), 0, Point());
		//ellipse(out_frame, min_ellipse[i], colour, 2, 8);
		Point2f rect_points[4];
		min_rect[i].points(rect_points);
		for (int j = 0; j < 4; j++) {
			//line(out_frame, rect_points[j], rect_points[(j + 1) % 4], colour, 1, 8);
		}
		//putText(out_frame, to_string(min_rect[i].angle), min_rect[i].center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255));
	}	
}
