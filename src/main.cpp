#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include "core/image_processor.hpp"
#include "core/effects.hpp"


int main() {
    const std::string image_path = "../assets/nature.jpg";
    const std::string image_path2 = "../assets/flower.jpg";
    const std::string image_path3 = "../assets/night.jpg";
    const std::string image_path4 = "../assets/car.jpg";
    cv::Mat img = cv::imread(image_path);
    cv::Mat img2 = cv::imread(image_path2);
    cv::Mat img3 = cv::imread(image_path3);
    cv::Mat img4 = cv::imread(image_path4);

    if(img.empty()) {
        std::cerr << "Error: Could not load image at " << image_path << std::endl;
        return 1;
    }

    if(img2.empty()) {
        std::cerr << "Error: Could not load image at " << image_path2 << std::endl;
        return 1;
    }

    if(img3.empty()) {
        std::cerr << "Error: Could not load image at " << image_path3 << std::endl;
        return 1;
    }

    if(img4.empty()) {
        std::cerr << "Error: Could not load image at " << image_path4 << std::endl;
        return 1;
    }

    cvp::ImageProcessor processor;
    cv::Mat gray = processor.toGray(img);
    cv::Mat resized = processor.resize(img, 400, 300);
    cv::Mat rotated = processor.rotate(img, 45.0);
    cv::Mat blurred = processor.blur(img2, 10);
    cv::Mat edges = processor.detectEdges(img2, 100, 200);
    cv::Mat thresholded = processor.threshold(img2, 128, 255);
    cv::Mat sharpened = processor.sharpen(img2);
    cv::Mat brightContrast = processor.adjustBrightnessContrast(img2, 1.2, 30);
    cv::Mat histEqualized = processor.histogramEqualization(img3);
    cv::Mat cartoon = cvp::effects::cartoonEffect(img4);
    cv::Mat pixelated = cvp::effects::pixelateEffect(img4, 10);
    cv::Mat motionBlurred = cvp::effects::motionBlur(img4, 15);

    std::vector<std::pair<std::string, cv::Mat>> results = {
        {"gray_image_result.jpg", gray},
        {"resized_image_result.jpg", resized},
        {"rotated_image_result.jpg", rotated},
        {"blurred_image_result.jpg", blurred},
        {"edges_image_result.jpg", edges},
        {"thresholded_image_result.jpg", thresholded},
        {"sharpened_image_result.jpg", sharpened},
        {"bright_contrast_image_result.jpg", brightContrast},
        {"hist_equalized_image_result.jpg", histEqualized},
        {"cartoon_effect_result.jpg", cartoon},
        {"pixelated_effect_result.jpg", pixelated},
        {"motion_blurred_effect_result.jpg", motionBlurred}
    };

    for(const auto& [filename, mat] : results) {
        if(!cv::imwrite("../data/output/" + filename, mat)) {
            std::cerr << "Error: Could not write image to " << filename << std::endl;
        }
    }
    
    return 0;
    
}