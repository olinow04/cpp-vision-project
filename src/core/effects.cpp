#include "core/effects.hpp"
#include <opencv2/imgproc.hpp>
#include <algorithm>

namespace cvp {
namespace effects {

cv::Mat cartoonEffect(const cv::Mat &input) {
    cv::Mat gray, edges, color_filtered, out;
    if (input.channels() == 3) cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    else gray = input.clone();

    cv::medianBlur(gray, gray, 7);
    cv::adaptiveThreshold(gray, edges, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 9, 2);
    cv::bilateralFilter(input, color_filtered, 9, 250, 250);
    cv::bitwise_and(color_filtered, color_filtered, out, edges);
    return out;
}

cv::Mat pixelateEffect(const cv::Mat &input, int pixelSize) {
    cv::Mat temp, out;
    if (pixelSize <= 0) pixelSize = 1;
    int px = std::min(pixelSize, std::max(1, std::min(input.cols, input.rows)));
    int w = std::max(1, input.cols / px);
    int h = std::max(1, input.rows / px);
    cv::resize(input, temp, cv::Size(w, h), 0, 0, cv::INTER_LINEAR);
    cv::resize(temp, out, input.size(), 0, 0, cv::INTER_NEAREST);
    return out;
}

cv::Mat motionBlur(const cv::Mat &input, int kernelSize) {
    if (kernelSize <= 1) return input.clone();
    cv::Mat out;
    cv::Mat kernel = cv::Mat::zeros(kernelSize, kernelSize, CV_32F);
    for (int i = 0; i < kernelSize; i++) {
        kernel.at<float>(i, i) = 1.0f / kernelSize;
    }
    cv::filter2D(input, out, -1, kernel);
    return out;
}

} 
} 
