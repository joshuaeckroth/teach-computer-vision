#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("../lena.jpg");

    imshow("Image", img);

    Mat img_blur10x10 = img.clone();
    blur(img, img_blur10x10, Size(10, 10));
    imshow("Blur 10x10", img_blur10x10);
    imwrite("lena-blur10x10.jpg", img_blur10x10);

    Mat img_blur20x20 = img.clone();
    blur(img, img_blur20x20, Size(20, 20));
    imshow("Blur 20x20", img_blur20x20);
    imwrite("lena-blur20x20.jpg", img_blur20x20);

    Mat img_blur20x1 = img.clone();
    blur(img, img_blur20x1, Size(20, 1));
    imshow("Blur 20x1", img_blur20x1);
    imwrite("lena-blur20x1.jpg", img_blur20x1);

    waitKey();

    return 0;
}
