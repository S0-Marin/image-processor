#pragma once
#include <memory>
#include <sstream>
#include "Creator.h"
#include "../filters/Filter.h"

class CreatorGaussianBlur : public Creator {
public:
    CreatorGaussianBlur();
    std::unique_ptr<Filter> CreateFilter(const int number_args, std::stringstream& args) const override;
};
