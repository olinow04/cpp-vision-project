#include "core/image_loader.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <filesystem>
#include <stdexcept>

namespace fs = std::filesystem;

namespace cvp {
    
    std::optional<cv::Mat> ImageLoader::load(const std::string& path, int flags) const {
        if (!fs::exists(path)) {
            return std::nullopt;
        }

        cv::Mat img = cv::imread(path, flags);
        if (img.empty()) {
            return std::nullopt;
        }
        return img;
    }

    std::optional<cv::Mat> ImageLoader::loadResize(const std::string &path, int w, int h, int flags) const {
        auto opt = load(path, flags);
        if (!opt) return std::nullopt;
        if (w <= 0 || h <= 0) return *opt;
        cv::Mat out;
        cv::resize(*opt, out, cv::Size(w, h));
        return out;
    }

    bool ImageLoader::save(const std::string &path, const cv::Mat &img, const std::vector<int>& params) const {
        if (img.empty()) return false;
        try {
            return cv::imwrite(path, img, params);
        } catch (...) {
            return false;
        }
    }

    cv::Mat ImageLoader::loadOrThrow(const std::string &path, int flags) const {
        auto opt = load(path, flags);
        if (!opt) {
            throw std::runtime_error("Failed to load image from path: " + path);
        }
        return *opt;
    }
}
