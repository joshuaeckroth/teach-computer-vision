#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("../lena.jpg");

    imshow("Image", img);

    Mat img_gray = img.clone();
    cvtColor(img, img_gray, CV_RGB2GRAY);

    Mat img_binary = img_gray.clone();
    threshold(img_gray, img_binary, 128.0, 255.0, THRESH_BINARY);
    imshow("Binary", img_binary);
    imwrite("lena-binary.jpg", img_binary);

    Mat kernel = Mat::ones(Size(4, 4), CV_8U);

    Mat img_binary_erode4x4 = img_binary.clone();
    erode(img_binary, img_binary_erode4x4, kernel);
    imshow("Erode binary 4x4", img_binary_erode4x4);
    imwrite("lena-binary-erode4x4.jpg", img_binary_erode4x4);

    Mat img_erode4x4 = img_binary.clone();
    erode(img, img_erode4x4, kernel);
    imwrite("lena-erode4x4.jpg", img_erode4x4);

    waitKey();

    return 0;
}
