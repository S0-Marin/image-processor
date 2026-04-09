#pragma once
#include <memory>
#include <sstream>
#include "Creator.h"
#include "../filters/Negative.h"

class CreatorNegative : public Creator {
public:
    CreatorNegative();
    std::unique_ptr<Filter> CreateFilter(const int number_args, std::stringstream& args) const override;
};
