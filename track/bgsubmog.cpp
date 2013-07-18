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
    if(capture->isOpened()) {
        Mat frame;
        Mat fgmask;
        Mat bg;
        Mat combined;
        int w, h;

        *capture >> frame;
        w = frame.size().width;
        h = frame.size().height;

        VideoWriter writer("bgsubmog-output.mpg",
                           CV_FOURCC('P','I','M','1'),
                           25, cvSize(3*w, h), 1); // 0 means gray, 1 means color

        if(writer.isOpened()) {
            while(true) {
                *capture >> frame;

                if(!frame.empty())
                {
                    fgmask = frame.clone();
                    backsub(frame, fgmask, 0.1);
                    backsub.getBackgroundImage(bg);

                    if(!fgmask.empty())
                    {
                        combined = Mat(h, 3*w, CV_8UC3);
                        Mat left(combined, Rect(0, 0, w, h));
                        frame.copyTo(left);
                        Mat right(combined, Rect(w, 0, w, h));
                        Mat fgmask_rgb;
                        cvtColor(fgmask, fgmask_rgb, CV_GRAY2RGB);
                        fgmask_rgb.copyTo(right);
                        Mat right2(combined, Rect(2*w, 0, w, h));
                        bg.copyTo(right2);
                        imshow("Original / Background subtracted / Background model", combined);

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
