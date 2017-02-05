#include <iostream>
#include <cv.h>
#include <highgui.h>

using namespace std;
char key;
int main( int argc, char** argv )
{

    IplImage* img = cvLoadImage( argv[1]);

    cvNamedWindow(argv[1], CV_WINDOW_AUTOSIZE );    //Create lena.jpg window
    cvNamedWindow("capture", CV_WINDOW_AUTOSIZE );    //Create capture window

    CvCapture* capture = cvCaptureFromCAM(0);  //Capture using any camera conne$
    IplImage* frame = cvQueryFrame(capture); //Create image frames from capture

    cvShowImage(argv[1], img);   //Show captured image
    cvShowImage("capture", frame);   //Show captured image
    key = cvWaitKey(0);     //Capture Keyboard stroke
/*
//     while(1)
//     { //Create infinte loop for live streaming

        //IplImage* frame = cvQueryFrame(capture); //Create image frames from c$
        //cvShowImage("display window", frame);   //Show image frames on create$

        //cvShowImage(argv[1], img);   //Show loaded image
        cvShowImage(argv[1], img);   //Show captured image
	cvShowImage("capture", frame);   //Show captured image

        key = cvWaitKey(10);     //Capture Keyboard stroke

	IplImage* frame = cvQueryFrame(capture); //Create image frames from capture

     while(1){ //Create infinte loop for live streaming

        //IplImage* frame = cvQueryFrame(capture); //Create image frames from c$
        //cvShowImage("display window", frame);   //Show image frames on create$

        //cvShowImage(argv[1], img);   //Show loaded image
        cvShowImage(argv[1], frame);   //Show captured image

        key = cvWaitKey(10);     //Capture Keyboard stroke
        if (char(key) == 27){
            break;      //If you hit ESC key loop will break.
        }
      }
*/
cvReleaseCapture(&capture); //Release capture.
cvDestroyWindow(argv[1]); //Destroy Window
cvDestroyWindow("capture"); //Destroy Window
return 0;
}

