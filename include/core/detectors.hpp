#pragma once 

#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/features2d.hpp>
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

    class Detectors {
        public:
            Detectors();
            ~Detectors();

            std::vector<Detection> detectFaces(const cv::Mat& image);
            
            std::vector<Detection> detectEyes(const cv::Mat& image);

            std::vector<CornerPoint> detectCorners(const cv::Mat& image, int maxCorners = 200);

            std::vector<cv::KeyPoint> detectFeatures(const cv::Mat& image);

            std::vector<std::vector<cv::Point>> detectContours(const cv::Mat& image);

            std::vector<cv::Vec3f> detectCircles(const cv::Mat& image, double dp = 1.0, double minDist = 50);
            
            std::vector<cv::Vec4f> detectLines(const cv::Mat& image, double rho = 1.0, double theta = CV_PI/180.0);

            std::vector<Detection> detectQRCodes(const cv::Mat& image);

            std::vector<Detection> detectObjectsByColor(const cv::Mat& image, const cv::Scalar& lowerBound, const cv::Scalar& upperBound);

            
        private:
            cv::CascadeClassifier faceCascade;
            cv::CascadeClassifier eyeCascade;
            cv::Ptr<cv::ORB> orbDetector;

            bool initializeCascades();

            bool initializeFeatureDetector();
    };
}