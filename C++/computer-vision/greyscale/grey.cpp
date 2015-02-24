#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main(int argc,char** argv) {
	
	if(argc!=2)//checking for correct program call
	{
		cout << "Usage: grey <image-path>" << endl;
		return -1;
	}

	//filenames in string format
	string rgb_file_name = argv[1], gray_file_name = argv[1];

	//initializing image matrices
	Mat rgb, gray;

	//loading the rgb image
	rgb = imread(rgb_file_name, 1);
	cout << "Openening image" << rgb_file_name << "...";
	if(!rgb.data)//checkig for correctly image loaded
	{
		cout << endl << "Cannot open \"" << rgb_file_name << "\"" << endl;
		return -1;
	}
	cout << "done" << endl;
	
	//Computing the gray scale image and writin to disk
	cout << "Computing the gray scale image...";
	cvtColor(rgb,gray, CV_BGR2GRAY);
	cout << "done" << endl;
	cout << "Writing gray image to " << gray_file_name << "...";
	imwrite(gray_file_name,gray); 
	cout << "done" << endl;

	//showing results
	namedWindow("Color Image",CV_WINDOW_NORMAL);
	namedWindow("Gray Image",CV_WINDOW_NORMAL);
	imshow("Color Image",rgb);
	imshow("Gray Image",gray);

	//exit procedure
	waitKey(0);

	return 0;
}