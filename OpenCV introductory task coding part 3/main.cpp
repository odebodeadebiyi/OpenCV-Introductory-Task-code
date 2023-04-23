#include <iostream>
#include <opencv2/opencv.hpp>

// Declare the function readImage
cv::Mat readImage(const std::string& filepath);

int main(int argc, char** argv) {
    std::string filepath = "C:/Users/dodeb/OneDrive/Desktop/University work/Applied Electrical and Electronic Engineering/OpenCV Task/Images/BlueApple.bmp"; // specify the full file path
    //std::string filepath = "C:/Users/dodeb/OneDrive/Desktop/University work/Applied Electrical and Electronic Engineering/OpenCV Task/Images/BlueCar.bmp"; // specify the full file path
    //std::string filepath = "C:/Users/dodeb/OneDrive/Desktop/University work/Applied Electrical and Electronic Engineering/OpenCV Task/Images/RedApple.bmp"; // specify the full file path
    //std::string filepath = "C:/Users/dodeb/OneDrive/Desktop/University work/Applied Electrical and Electronic Engineering/OpenCV Task/Images/RedCar.bmp"; // specify the full file path
    //std::string filepath = "C:/Users/dodeb/OneDrive/Desktop/University work/Applied Electrical and Electronic Engineering/OpenCV Task/Images/GreenApple.bmp"; // specify the full file path
    //std::string filepath = "C:/Users/dodeb/OneDrive/Desktop/University work/Applied Electrical and Electronic Engineering/OpenCV Task/Images/GreenCar.bmp"; // specify the full file path
    cv::Mat image = readImage(filepath); // read image file

    if (image.empty()) { // check if image is successfully read
        std::cerr << "Failed to read image file!" << std::endl;
        return 1;
    }

    // Convert the image to HSV color space
    cv::Mat hsvImage;
    cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);

    // Compute the mean value of the color channels
    cv::Scalar mean = cv::mean(hsvImage);


     std::cout << mean[0] << std::endl;
     //Output the main color as text to the console
    if (mean[0] > 50 && mean[0] < 62 && mean[1] > 80 && mean[1] < 109 && mean[2] > 136) {
        std::cout << "The main color of the image is blue." << std::endl;
    } else if (mean[0] > 34 && mean[0] < 43 && mean[1] > 70 && mean[2] > 137 && mean[2] < 176) {
        std::cout << "The main color of the image is red." << std::endl;
    } else if ((mean[0] > 18 && mean[0] < 84) && mean[1] > 64 && mean[1] < 69 && mean[2] > 118 && mean[2] < 227) {
        std::cout << "The main color of the image is green." << std::endl;
    } else {
        std::cout << "The main color of the image could not be determined." << std::endl;
    }

    return 0;
}

// Define the function readImage
cv::Mat readImage(const std::string& filepath) {
    cv::Mat image = cv::imread(filepath, cv::IMREAD_COLOR); // read image file
    return image;
}

