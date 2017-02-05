#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main(int argc, char** argv)
{
    int i1 = 1;
if( argc == 2) 
	{
		i1 = atoi(argv[1]);
        } 
    VideoCapture cap;
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if(!cap.open(0))
        return 0;
 Mat frame[20];
int i=0;
	for(i=0;i<=i1;i++)
    {
          
          cap >> frame[i];
     }

stringstream ss;
//ss <<"img"<< i<<".jpg";
string str = ss.str();

Size size(128,128);//the dst image size,e.g.100x100
Mat dst;//dst image
//Mat src;//src image
//resize(src,dst,size);//resize image
	for(i=0;i<=i1;i++)
    {
          ss <<"img"<< i<<".jpg";
          str = ss.str();
	  ss.str("");

          resize(frame[i],dst,size);//resize image
	  imshow(str, dst);
	  imwrite(str, frame[i]);
     }
         
           waitKey(0);
    
    // the camera will be closed automatically upon exit
    // cap.close();
    return 0;
}

