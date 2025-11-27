#include "core/image_processor.hpp"
#include <opencv2/imgproc.hpp>

namespace cvp {

cv::Mat ImageProcessor::toGray(const cv::Mat &input) const {
    cv::Mat out;
    if (input.channels() == 3) cv::cvtColor(input, out, cv::COLOR_BGR2GRAY);
    else out = input.clone();
    return out;
}

cv::Mat ImageProcessor::resize(const cv::Mat &input, int w, int h) const {
    cv::Mat out;
    if (w <= 0 || h <= 0) return input.clone();
    cv::resize(input, out, cv::Size(w,h));
    return out;
}

cv::Mat ImageProcessor::rotate(const cv::Mat &input, double angle) const {
    cv::Point2f center((float)input.cols/2, (float)input.rows/2);
    cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1.0);
    cv::Mat out;
    cv::warpAffine(input, out, rot, input.size());
    return out;
}

cv::Mat ImageProcessor::blur(const cv::Mat &input, int ksize) const {
    cv::Mat out;
    if( ksize % 2 == 0) ksize += 1; 
    cv::GaussianBlur(input, out, cv::Size(ksize, ksize), 0);
    return out;
}

cv::Mat ImageProcessor::detectEdges(const cv::Mat &input, double lowThreshold, double highThreshold) const {
    cv::Mat gray, blurred, edges;
    if (input.channels() == 3) cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    else gray = input;
    cv::GaussianBlur(gray, blurred, cv::Size(3,3), 0);
    cv::Canny(blurred, edges, lowThreshold, highThreshold);
    return edges;
}

cv::Mat ImageProcessor::threshold(const cv::Mat &input, double thresh, double maxVal) const {
    cv::Mat out;
    if( input.channels() == 3 ) {
        cv::Mat gray;
        cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
        cv::threshold(gray, out, thresh, maxVal, cv::THRESH_BINARY);
    } else
    cv::threshold(input, out, thresh, maxVal, cv::THRESH_BINARY);
    return out;
}

cv::Mat ImageProcessor::sharpen(const cv::Mat &input) const {
    cv::Mat out;
    cv::Mat kernel = (cv::Mat_<float>(3,3) << 
                       0, -1, 0,
                      -1, 5,-1,
                       0, -1, 0);
    cv::filter2D(input, out, -1, kernel);
    return out;
}

cv::Mat ImageProcessor::adjustBrightnessContrast(const cv::Mat &input, double alpha, int beta) const {
    cv::Mat out;
    input.convertTo(out, -1, alpha, beta);
    return out;
}

cv::Mat ImageProcessor::histogramEqualization(const cv::Mat &input) const {
    cv::Mat gray, out;
    if (input.channels() == 3) {
        cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    } else {
        gray = input.clone();
    }
    cv::equalizeHist(gray, out);
    return out;
}

} 


