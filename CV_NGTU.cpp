#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
    // Загрузка изображения
    cv::Mat inputImage = cv::imread("C:/Users/zayka/Source/Repos/CV_NGTU/img.jpg", cv::IMREAD_COLOR);

    if (inputImage.empty()) {
        cout << "Unable to read the image \n";
        return 1;
    }

    cv::Size imageSize = inputImage.size();
    int halfWidth = imageSize.width / 2;
    int halfHeight = imageSize.height / 2;

    // Обрезанные части изображения
    cv::Mat croppedImage1 = inputImage(cv::Rect(0, 0, halfWidth, halfHeight));
    cv::Mat croppedImage2 = inputImage(cv::Rect(halfWidth, 0, halfWidth, halfHeight));
    cv::Mat croppedImage3 = inputImage(cv::Rect(0, halfHeight, halfWidth, halfHeight));
    cv::Mat croppedImage4 = inputImage(cv::Rect(halfWidth, halfHeight, halfWidth, halfHeight));

    // Создание маски и применение ее к изображению
    cv::Mat mask = cv::Mat::zeros(inputImage.size(), inputImage.type());
    cv::Mat maskedImage;
    cv::circle(mask, cv::Point(mask.cols / 2, mask.rows / 2), 200, cv::Scalar(255, 255, 255), -1, 8, 0);
    inputImage.copyTo(maskedImage, mask);

    // Отображение изображений
    cv::imshow("Masked Image", maskedImage);
    cv::imshow("Cropped Image 1", croppedImage1);
    cv::imshow("Cropped Image 2", croppedImage2);
    cv::imshow("Cropped Image 3", croppedImage3);
    cv::imshow("Cropped Image 4", croppedImage4);

    cv::moveWindow("Masked Image", 0, 0);
    cv::moveWindow("Cropped Image 1", halfWidth, 0);
    cv::moveWindow("Cropped Image 2", 0, 0);
    cv::moveWindow("Cropped Image 3", halfWidth, halfHeight);
    cv::moveWindow("Cropped Image 4", 0, halfHeight);

    cv::waitKey(0);
    return 0;
}