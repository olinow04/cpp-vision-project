#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include "core/image_processor.hpp"
#include "core/effects.hpp"
#include "core/image_loader.hpp"


int main() {
    cvp::ImageLoader loader;

    const std::string image_path = "../assets/nature.jpg";
    const std::string image_path2 = "../assets/flower.jpg";
    const std::string image_path3 = "../assets/night.jpg";
    const std::string image_path4 = "../assets/car.jpg";

    auto img = loader.load(image_path);
    auto img2 = loader.load(image_path2);
    auto img3 = loader.load(image_path3);
    auto img4 = loader.load(image_path4);
    
    if(!img) {
        std::cerr << "Error: Could not load image at " << image_path << std::endl;
        return 1;
    }

    if(!img2) {
        std::cerr << "Error: Could not load image at " << image_path2 << std::endl;
        return 1;
    }

    if(!img3) {
        std::cerr << "Error: Could not load image at " << image_path3 << std::endl;
        return 1;
    }

    if(!img4) {
        std::cerr << "Error: Could not load image at " << image_path4 << std::endl;
        return 1;
    }

    cvp::ImageProcessor processor;
    cv::Mat gray = processor.toGray(*img);
    cv::Mat resized = processor.resize(*img, 400, 300);
    cv::Mat rotated = processor.rotate(*img, 45.0);
    cv::Mat blurred = processor.blur(*img2, 10);
    cv::Mat edges = processor.detectEdges(*img2, 100, 200);
    cv::Mat thresholded = processor.threshold(*img2, 128, 255);
    cv::Mat sharpened = processor.sharpen(*img2);
    cv::Mat brightContrast = processor.adjustBrightnessContrast(*img2, 1.2, 30);
    cv::Mat histEqualized = processor.histogramEqualization(*img3);
    cv::Mat cartoon = cvp::effects::cartoonEffect(*img4);
    cv::Mat pixelated = cvp::effects::pixelateEffect(*img4, 10);
    cv::Mat motionBlurred = cvp::effects::motionBlur(*img4, 15);

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
        if(!loader.save("../data/output/" + filename, mat)) {
            std::cerr << "Error: Could not write image to " << filename << std::endl;
        }
    }
    
    return 0;
    
}