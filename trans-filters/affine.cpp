#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("../lena.jpg");

    imshow("Image", img);

    double m_scale[2][3] = {{0.5, 0.0, 0.0}, {0.0, 0.5, 0.0}};
    Mat kernel_scale = Mat(2, 3, CV_64F, m_scale);
    Mat img_scale = img.clone();
    warpAffine(img, img_scale, kernel_scale, Size(256, 256));
    imshow("Scaled", img_scale);
    imwrite("lena-scaled.jpg", img_scale);

    double m_scale_trans[2][3] = {{0.5, 0.0, 64.0}, {0.0, 0.5, 64.0}};
    Mat kernel_scale_trans = Mat(2, 3, CV_64F, m_scale_trans);
    Mat img_scale_trans = img.clone();
    warpAffine(img, img_scale_trans, kernel_scale_trans, Size(256, 256));
    imshow("Scaled & translated", img_scale_trans);
    imwrite("lena-scaled-trans.jpg", img_scale_trans);

    double m_90_rotate[2][3] = {{0.0, 1.0, 0.0}, {-1.0, 0.0, 256.0}};
    Mat kernel_90_rotate = Mat(2, 3, CV_64F, m_90_rotate);
    Mat img_90_rotate = img.clone();
    warpAffine(img, img_90_rotate, kernel_90_rotate, Size(256, 256));
    imshow("90-degree rotated & translated", img_90_rotate);
    imwrite("lena-90-rotate.jpg", img_90_rotate);

    Mat kernel_45_rotate = getRotationMatrix2D(Point2f(128, 128), 45.0, 1.0);
    Mat img_45_rotate = img.clone();
    warpAffine(img, img_45_rotate, kernel_45_rotate, Size(256, 256));
    imshow("45-degree rotated & translated", img_45_rotate);
    imwrite("lena-45-rotate.jpg", img_45_rotate);

    waitKey();

    return 0;
}
