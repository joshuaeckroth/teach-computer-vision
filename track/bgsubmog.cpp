#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    bool camera = false;
    VideoCapture *capture;
    BackgroundSubtractorMOG2 backsub;

    if(camera)
    {
        capture = new VideoCapture(-1); // use webcam
    } else {
        capture = new VideoCapture("Balcony5_Vis.mpg"); // use input file
    }
    Mat frame;
    Mat fgmask;
    Mat bg;

    if(capture->isOpened()) {
        while(true) {
            *capture >> frame;

            if(!frame.empty())
            {
                fgmask = frame.clone();
                backsub(frame, fgmask, 0.1);
                backsub.getBackgroundImage(bg);

                imshow("Video", frame);
                if(!fgmask.empty())
                {
                    imshow("Foreground mask", fgmask);
                    imshow("Background", bg);
                }
            }
            
            int key = waitKey(10);
            if((char)key == 'q') { break; }
        }
    }

    return 0;
}
