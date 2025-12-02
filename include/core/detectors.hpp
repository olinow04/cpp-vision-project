#pragma once 

#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <vector>
#include <memory>

namespace cvp {
    
    struct Detection {
        cv::Rect2d boundingBox;
        float confidence;
        std::string label;

        Detection(const cv::Rect2d& box, float conf = 1.0f, const std::string& lbl = ""){
            boundingBox = box;
            confidence = conf;
            label = lbl;
        }
    };
}