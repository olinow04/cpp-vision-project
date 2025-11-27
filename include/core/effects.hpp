#pragma once

#include <opencv2/core.hpp>

namespace cvp {
namespace effects {

cv::Mat cartoonEffect(const cv::Mat &input);
cv::Mat pixelateEffect(const cv::Mat &input, int pixelSize);
cv::Mat motionBlur(const cv::Mat &input, int kernelSize);

} 
} 
