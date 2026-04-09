#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <memory>
#include "Args.h"
#include "filters/Filter.h"
#include "creators/Creator.h"
#include "creators/CreatorCrop.h"
#include "creators/CreatorGaussianBlur.h"
#include "creators/CreatorGrayscale.h"
#include "creators/CreatorNegative.h"
#include "creators/CreatorSharpening.h"
#include "creators/CreatorEdgeDetection.h"

Args::Args(const int argc, char** argv) {
    if (argc < 3) {
        throw std::runtime_error("Некорректные аргументы.");
    }
    map_filters_["crop"] = std::make_unique<CreatorCrop>();
    map_filters_["gs"] = std::make_unique<CreatorGrayscale>();
    map_filters_["neg"] = std::make_unique<CreatorNegative>();
    map_filters_["sharp"] = std::make_unique<CreatorSharpening>();
    map_filters_["edge"] = std::make_unique<CreatorEdgeDetection>();
    map_filters_["blur"] = std::make_unique<CreatorGaussianBlur>();
    input_filename_ = argv[1];
    output_filename_ = argv[2];
    std::string filter = "";
    std::stringstream filter_args;

    int i = 3;
    int number_args = 0;
    while (i < argc) {
        filter = argv[i];
        if (filter.empty() || filter[0] != '-') {
            throw std::runtime_error("Фильтр должен начинаться с -");
        }
        ++i;
        while (i < argc && argv[i][0] != '-') {
            filter_args << argv[i] << ' ';
            ++number_args;
            ++i;
        }
        if (map_filters_.find(filter.substr(1)) == map_filters_.end()) {
            throw std::runtime_error("Нет такого фильтра.");
        }
        filters_.push_back(map_filters_[filter.substr(1)]->CreateFilter(number_args, filter_args));
        number_args = 0;
        filter_args.clear();
    }
}

const std::vector<std::unique_ptr<Filter>>& Args::GetFilters() const {
    return filters_;
}

std::string Args::GetInput() const {
    return input_filename_;
}

std::string Args::GetOutput() const {
    return output_filename_;
}
