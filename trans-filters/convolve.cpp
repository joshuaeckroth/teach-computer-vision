#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("../lena.jpg");

    imshow("Image", img);

    double m[2][2] = {{0.25, 0.25}, {0.25, 0.25}};
    Mat kernel = Mat(2, 2, CV_64F, m);

    Mat img_convolve = img.clone();
    filter2D(img, img_convolve, -1, kernel, Point(1, 1));
    imshow("Convolved", img_convolve);

    waitKey();

    return 0;
}
