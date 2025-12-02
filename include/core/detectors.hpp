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

    struct CornerPoint {
        cv::Point2f position;
        float response;

        CornerPoint(const cv::Point2f& pos, float resp = 0.0f){
            position = pos;
            response = resp;
        }
    };
}