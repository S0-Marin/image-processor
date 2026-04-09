#pragma once
#include <memory>
#include <sstream>
#include "../filters/Filter.h"
#include "Creator.h"

class CreatorApplyMatrix3 : virtual public Creator {
public:
    CreatorApplyMatrix3();
    std::unique_ptr<Filter> CreateFilter(const int number_args, std::stringstream& args) const override;

private:
    const size_t vec_size_ = 9;
};
