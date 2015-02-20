// ObjectTracker v2

#include<opencv\cvaux.h>
#include<opencv\highgui.h>
#include<opencv\cxcore.h>

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[]) {
	CvSize size640x480 = cvSize(640, 480);  // 640 x 480 used for all windows

	CvCapture* p_capWebCam;  // video assigned later

	IplImage* p_imgOriginal;  // original image from cam
	IplImage* p_imgProcessed;  // image after processing

	CvMemStorage* p_strStorage;  // necessary storage variable

	CvSeq* p_seqCircles;  // pointer to Opencv sequence, will contain circles

	float* p_fltXYRadius;  // pointer to a 3 element array
						   // [0] is X
						   // [1] is Y
						   // [2] is radius
	p_capWebCam = cvCaptureFromCAM(0);  // get vidoe feed from web cam

	if (p_capWebCam == NULL) {
		printf("error: capture is NULL \n");
		getchar();
			return(-1);
	}

	// Declare windows
	cvNamedWindow("Original", CV_WINDOW_AUTOSIZE);  // create original window
	cvNamedWindow("Processed", CV_WINDOW_AUTOSIZE);  // create processed window

	p_imgProcessed = cvCreateImage(size640x480, IPL_DEPTH_8U, 1);  // size, 8 bit colour depth, 1 channel (grayscale, 3 is colour image)

	while (true) {
		p_imgOriginal = cvQueryFrame(p_capWebCam);  // get frame from web cam capture object
		if (p_imgOriginal == NULL) { // if frame did not capture
			printf("error: frame is NULL \n");
			getchar();
			break;
		}

		cvInRangeS(p_imgOriginal,
			CV_RGB(175, 0, 0),  // min filter value
			CV_RGB(256, 100, 100),  // max filter value
			p_imgProcessed);

		p_strStorage = cvCreateMemStorage(0); // allocate necessary memory

					// in		// out			// filter
		//cvSmooth(p_imgProcessed, p_imgProcessed, CV_GAUSSIAN, 9, 9);   // smooth the processed image

		p_seqCircles = cvHoughCircles(p_imgProcessed, 
									p_strStorage, 
									CV_HOUGH_GRADIENT, 
									2, 
									p_imgProcessed->height / 4,
									100,
									50,
									10,
									400);  // fills sequential structure with circles.
		for (int i = 0; i < p_seqCircles->total; i++) {  // loop through each detected circle
			p_fltXYRadius = (float*)cvGetSeqElem(p_seqCircles, i);  // get i-th element in circles
			printf("Ball position x = %f, y = %f r = %f \n", p_fltXYRadius[0],  // x coord
															 p_fltXYRadius[1],  // y coord
															 p_fltXYRadius[2]);  // radius
			
			// Draw green circle in center if object
			cvCircle(p_imgOriginal,
				cvPoint(cvRound(p_fltXYRadius[0]), cvRound(p_fltXYRadius[1])),
				3,
				CV_RGB(0, 255, 0),
				CV_FILLED);

			// Draw red circle around object
			cvCircle(p_imgOriginal,
				cvPoint(cvRound(p_fltXYRadius[0]), cvRound(p_fltXYRadius[1])),
				cvRound(p_fltXYRadius[2]),  // radius of circle
				CV_RGB(255, 0, 0),
				3);  // 3 pixel thickness instead of filling
		}  // end of for loop

		cvShowImage("Original", p_imgOriginal);  // Orignal image with drawings
		cvShowImage("Processed", p_imgProcessed);  // Processed image is shown

		cvReleaseMemStorage(&p_strStorage);

		if (cvWaitKey(30) == 27) {
			break;
		}

	}  // end of while

	cvReleaseCapture(&p_capWebCam);

	cvDestroyWindow("Original");
	cvDestroyWindow("Processed");

	return 0;
}