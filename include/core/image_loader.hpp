#pragma once

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <optional>
#include <string>
#include <vector>

namespace cvp {
    
    class ImageLoader {
        public:
            ImageLoader() = default;

            std::optional<cv::Mat> load(const std::string& path, int flags = cv::IMREAD_COLOR) const;

            std::optional<cv::Mat> loadResize(const std::string &path, int w, int h, int flags = cv::IMREAD_COLOR) const;

            bool save(const std::string &path, const cv::Mat &img, const std::vector<int>& params = {}) const;

            cv::Mat loadOrThrow(const std::string &path, int flags = cv::IMREAD_COLOR) const;

    };

    }
