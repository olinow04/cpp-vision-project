#include "core/detectors.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/core/utils/filesystem.hpp>
#include <iostream>

namespace cvp {

Detectors::Detectors() {
    initializeCascades();
    initializeFeatureDetector();
}

Detectors::~Detectors() = default;

bool Detectors::initializeCascades() {
    std::string face_cascade_path;
    std::string eye_cascade_path;

    try {
        face_cascade_path = cv::samples::findFile("haarcascades/haarcascade_frontalface_default.xml", false);
    } catch (...) {
        face_cascade_path = "haarcascade_frontalface_default.xml";
    }

    try {
        eye_cascade_path = cv::samples::findFile("haarcascades/haarcascade_eye.xml", false);
    } catch (...) {
        eye_cascade_path = "haarcascade_eye.xml";
    }

    if(!faceCascade.load(face_cascade_path)) {
        std::cerr << "Error: Could not load face cascade classifier" << std::endl;
        return false;
    }

    if(!eyeCascade.load(eye_cascade_path)) {
        std::cerr << "Error: Could not load eye cascade classifier" << std::endl;
        return false;
    }

    return true;
}

bool Detectors::initializeFeatureDetector() {
    try{
        orbDetector = cv::ORB::create(500);
        return orbDetector != nullptr;
    } catch (const std::exception& e) {
        std::cerr << "Error: Could not initialize ORB detector: " << e.what() << std::endl;
        return false;
    }
}

}