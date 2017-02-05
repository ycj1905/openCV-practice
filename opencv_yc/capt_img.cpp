#include <iostream>
#include <cv.h>
#include <highgui.h>
 
using namespace std;
char key;
int main() {

	//IplImage* img = cvLoadImage( argv[1]);

    cvNamedWindow("capture window", CV_WINDOW_AUTOSIZE );    //Create window
    
    CvCapture* capture = cvCaptureFromCAM(0);  //Capture using any camera connected to your system
    IplImage* frame = cvQueryFrame(capture); //Create image frames from capture
     
     while(1){ //Create infinte loop for live streaming
 
        //IplImage* frame = cvQueryFrame(capture); //Create image frames from capture
        //cvShowImage("display window", frame);   //Show image frames on created window

	//cvShowImage(argv[1], img);   //Show loaded image 
	cvShowImage("capture window", frame);   //Show captured image

        key = cvWaitKey(10);     //Capture Keyboard stroke
        if (char(key) == 27){
            break;      //If you hit ESC key loop will break.
        }
    }
    cvReleaseCapture(&capture); //Release capture.
    cvDestroyWindow("capture window"); //Destroy Window
    return 0;
}

