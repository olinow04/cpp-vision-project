#pragma once

#include <opencv2/core.hpp>

namespace cvp {

class ImageProcessor {
public:
    ImageProcessor() = default;
    cv::Mat toGray(const cv::Mat &input) const;
    cv::Mat resize(const cv::Mat &input, int w, int h) const;
    cv::Mat rotate(const cv::Mat &input, double angle) const;
    cv::Mat blur(const cv::Mat &input, int ksize) const;
    cv::Mat detectEdges(const cv::Mat &input, double lowThreshold, double highThreshold) const;
    cv::Mat threshold(const cv::Mat &input, double thresh, double maxVal) const;
    cv::Mat sharpen(const cv::Mat &input) const;
    cv::Mat adjustBrightnessContrast(const cv::Mat &input, double alpha, int beta) const;
    cv::Mat histogramEqualization(const cv::Mat &input) const;
};

} 
