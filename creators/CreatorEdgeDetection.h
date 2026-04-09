#pragma once
#include <memory>
#include <sstream>
#include "CreatorApplyMatrix3.h"
#include "CreatorGrayscale.h"
#include "../filters/Filter.h"

class CreatorEdgeDetection : public CreatorGrayscale, public CreatorApplyMatrix3 {
public:
    CreatorEdgeDetection();
    std::unique_ptr<Filter> CreateFilter(const int number_args, std::stringstream& args) const override;
};
