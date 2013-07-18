#include <opencv2/opencv.hpp>

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;
using namespace cv;

vector<Point> locations;
vector<int> last_seen;

int t = 0;

int figure_out_id(Rect box)
{
    int best_id = -1;
    double min_dist;
    double dist;
    for(unsigned int i = 0; i < locations.size(); i++)
    {
        dist = sqrt(pow(locations[i].x - box.x, 2.0) + pow(locations[i].y - box.y, 2.0));
        if((t - last_seen[i]) < 300 && (best_id == -1 || dist < min_dist))
        {
            min_dist = dist;
            best_id = i;
        }
    }
    // if min_dist is too large or empty, we
    // probably have a new object
    if(best_id == -1 || min_dist > 100)
    {
        locations.push_back(Point(box.x, box.y));
        last_seen.push_back(t);
        best_id = locations.size();
    }
    locations[best_id] = Point(box.x, box.y);

    return best_id;
}

int main(int argc, const char** argv)
{
    CvCapture* capture;
    Mat frame;
    Mat frame_prior;
    BackgroundSubtractorMOG backsub;

    //capture = cvCaptureFromCAM(-1);
    capture = cvCaptureFromFile("../Balcony4_Vis.mpg");
    if(capture)
    {
        while(true)
        {
            frame_prior = frame.clone();
            frame = cvQueryFrame(capture);

            if(!frame.empty())
            {
                Mat fgmask = frame.clone();
                backsub(frame, fgmask, 0.1);

                vector<vector<Point> > contours;
                Mat fgmask_contours = fgmask.clone();
                findContours(fgmask_contours, contours,
                             CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
                vector<vector<Point> >::const_iterator it = contours.begin();
                while(it != contours.end()) {
                    Rect box = boundingRect(Mat(*it));
                    if(box.width > 5 && box.height > 5) {
                        rectangle(frame, box, Scalar(255), 1);
                        
                        // figure out id
                        int best_id = figure_out_id(box);
                        char* id = new char[10];
                        sprintf(id, "%d", best_id);
                        putText(frame, id, Point(box.x, box.y-5), 
                                FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255), 1);
                    }
                    ++it;
                }
                drawContours(frame, contours, -1, Scalar(255), 1);

                if(t > 0) {
                    imshow("Track FG Mask", fgmask);
                }

                imshow("Track", frame);

                t++;
            }
            else
            { printf(" --(!) No captured frame -- Break!"); break; }

            int key = waitKey(10);
            if((char)key == 'q') { break; }
        }
    }
    return 0;
}
