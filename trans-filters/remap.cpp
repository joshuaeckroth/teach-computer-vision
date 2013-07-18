#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("../lena.jpg");

    imshow("Image", img);

    int w = img.size().width;
    int h = img.size().height;
    Mat map(w, h, CV_32FC2);
    for(int r = 0; r < h; r++)
    {
        for(int c = 0; c < w; c++)
        {
            map.at<Point2f>(r, c) = Point2f(1.2*c+0.2*r, 0.9*r);
        }
    }

    Mat img_remapped = img.clone();
    remap(img, img_remapped, map, Mat(), INTER_LINEAR);
    imshow("Remapped", img_remapped);

    waitKey();

    return 0;
}
