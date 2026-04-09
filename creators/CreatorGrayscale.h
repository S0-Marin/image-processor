#pragma once
#include <memory>
#include <sstream>
#include "Creator.h"
#include "../filters/Filter.h"

class CreatorGrayscale : virtual public Creator {
public:
    CreatorGrayscale();
    std::unique_ptr<Filter> CreateFilter(const int number_args, std::stringstream& args) const override;
};
