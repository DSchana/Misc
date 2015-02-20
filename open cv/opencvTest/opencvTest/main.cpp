#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace cv;

// initial min and ma of HSV
int H_MIN = 0;
int H_MAX = 255;
int S_MIN = 0;
int S_MAX = 255;
int V_MIN = 0;
int V_MAX = 255;
//default capture width and height
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;
//max number of objects to be detected in frame
const int MAX_NUM_OBJECTS = 50;
//minimum and maximum object area
const int MIN_OBJECT_AREA = 20 * 20;
const int MAX_OBJECT_AREA = FRAME_HEIGHT*FRAME_WIDTH / 1.5;
//names that will appear at the top of each window
const string windowName = "Original Image";
const string windowName1 = "HSV Image";
const string windowName2 = "Thresholded Image";
const string windowName3 = "After Morphological Operations";
const string trackbarWindowName = "Trackbars";

void on_trackbar(int, void*)
{//This function gets called whenever a
	// trackbar position is changed





}
string intToString(int number){


	std::stringstream ss;
	ss << number;
	return ss.str();
}







int main() {

	// Access camera
	Mat image;  // create matrix of image

	VideoCapture cap;  // the screen that will be displaying shit
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);  // cap.set: set properties of the window
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
	cap.open(0);  // cap.open(num): access camers, num is id of camera

	namedWindow("Camera Window", 1);  // window title
	while (true)
	{

		try
		{
			cap >> image;  // try to capture image from camera

			imshow("window", image);  // display the received image in the window
		}
		catch (Exception& e)  // Image not found, do this
		{
			const char* err_msg = e.what();  // get error
			std::cout << "exception caught: imshow:\n" << err_msg << std::endl;  // display error
		}
		waitKey(33);
	}

	// Open images
	/*
	IplImage* img = cvLoadImage("image.png"); //change the name (image.jpg) according to your Image filename.
	cvNamedWindow("Example1", CV_WINDOW_NORMAL);
	cvShowImage("Example1", img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("Example1");
	*/

	return 0;
}