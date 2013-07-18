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
    if(capture->isOpened()) {
        Mat frame;
        Mat frame_gray;
        Mat frame_binary;
        Mat frame_old;
        Mat frame_old_binary;
        Mat frame_sub;
        Mat combined;
        int w, h;
        *capture >> frame;
        w = frame.size().width;
        h = frame.size().height;

        VideoWriter writer("bgsub-output.mpg",
                           CV_FOURCC('P','I','M','1'),
                           25, cvSize(2*w, h), 1); // 0 means gray, 1 means color
        if(writer.isOpened()) {
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
                    if(!frame_sub.empty())
                    {
                        combined = Mat(h, 2*w, CV_8UC3);
                        Mat left(combined, Rect(0, 0, w, h));
                        frame.copyTo(left);
                        Mat right(combined, Rect(w, 0, w, h));
                        Mat frame_sub_rgb;
                        cvtColor(frame_sub, frame_sub_rgb, CV_GRAY2RGB);
                        frame_sub_rgb.copyTo(right);
                        imshow("Combined", combined);

                        writer << combined;
                    }
                }
            
                int key = waitKey(10);
                if((char)key == 'q') { break; }
            }
        }
    }

    return 0;
}
