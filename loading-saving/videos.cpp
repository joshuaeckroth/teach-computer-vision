#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    bool camera = true;
    VideoCapture *capture;
    if(camera)
    {
        capture = new VideoCapture(-1); // use webcam
    } else {
        capture = new VideoCapture("input.mpg"); // use input file
    }
    Mat frame;

    if(capture->isOpened()) {
        int fps = capture->get(CV_CAP_PROP_FPS);
        if(fps == -1) { fps = 30; } // maybe set a default
        int width = capture->get(CV_CAP_PROP_FRAME_WIDTH);
        int height = capture->get(CV_CAP_PROP_FRAME_HEIGHT);
        cout << "FPS: " << fps << ", width: " << width << ", height: " << height << endl;

        VideoWriter writer("output.mpg",
                           CV_FOURCC('P','I','M','1'),
                           fps, cvSize(width, height), 1); // 0 means gray, 1 means color

        if(writer.isOpened()) {
            while(true) {
                *capture >> frame;
                
                /*
                Mat frame_gray = frame.clone();
                cvtColor(frame, frame_gray, CV_RGB2GRAY);
                double m[3][3] = {{0.33, 0.33, 0.33}, {0.33, 0.33, 0.33}};
                Mat kernel = Mat(2, 2, CV_64F, m);
                
                Mat frame_convolve = frame_gray.clone();
                filter2D(frame_gray, frame_convolve, -1, kernel, Point(1, 1));
                */

                writer << frame;
                if(camera)
                {
                    writer << frame;
                }

                if(!frame.empty()) {
                    imshow("Video", frame);
                }
                    
                int key = waitKey(10);
                if((char)key == 'q') { break; }
            }
        }
    }

    return 0;
}
