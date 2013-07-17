#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("../lena.jpg");

    imshow("Image", img);

    double m_perspective[3][3] = {{0.53009, -0.47993, 79.0},
                                  {-0.31048, 0.50159, 59.0},
                                  {-0.00094, -0.00131, 1.0}};
    Mat kernel_perspective = Mat(3, 3, CV_64F, m_perspective);
    Mat img_perspective = img.clone();
    warpPerspective(img, img_perspective, kernel_perspective, Size(256, 256));
    imshow("Perspective", img_perspective);
    imwrite("lena-perspective.jpg", img_perspective);


    waitKey();

    return 0;
}
