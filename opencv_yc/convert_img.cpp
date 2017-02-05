/* convert_img.cpp :Code to display an image using OpenCV

     g++ -o test_3 test_3.cpp `pkg-config opencv --cflags --libs`
     ./test_3 lena.jpg
 
*/

#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){
// 

   Mat image1 = imread(argv[1], CV_LOAD_IMAGE_COLOR); 
   
   IplImage* image2;
   image2 = cvCreateImage(cvSize(image1.cols,image1.rows),8,3);
   IplImage ipltemp=image1;
   cvCopy(&ipltemp,image2);

  cvNamedWindow(argv[1],CV_WINDOW_AUTOSIZE);
// display the image
  cvShowImage(argv[1],image2);  //in VNC viewr wont work--imshow( window_name, dst );


// wait for keystroke
  cvWaitKey(0);
// release the image object
 cvReleaseImage(&image2);
// destroy the window
  cvDestroyWindow(argv[1]);
}

