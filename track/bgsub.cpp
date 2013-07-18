#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    bool camera = false;
    VideoCapture *capture;
    if(camera)
    {
        capture = new VideoCapture(-1); // use webcam
    } else {
        capture = new VideoCapture("Balcony5_Vis.mpg"); // use input file
    }
    Mat frame;
    Mat frame_gray;
    Mat frame_binary;
    Mat frame_old;
    Mat frame_old_binary;
    Mat frame_sub;

    if(capture->isOpened()) {
        while(true) {
            frame_old = frame_gray.clone();
            *capture >> frame;
            cvtColor(frame, frame_gray, CV_RGB2GRAY);
            
            if(!frame_old.empty())
            {
                frame_binary = frame_gray.clone();
                threshold(frame_gray, frame_binary, 128.0, 255.0, THRESH_BINARY);
                frame_old_binary = frame_old.clone();
                threshold(frame_old, frame_old_binary, 128.0, 255.0, THRESH_BINARY);
                frame_sub = frame_binary - frame_old_binary;
            }

            if(!frame.empty())
            {
                imshow("Video", frame);
                if(!frame_sub.empty())
                {
                    imshow("Sub", frame_sub);
                }
            }
            
            int key = waitKey(10);
            if((char)key == 'q') { break; }
        }
    }

    return 0;
}
