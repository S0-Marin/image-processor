#pragma once
#include "../filters/Filter.h"
#include <memory>
#include <sstream>

class Creator {
public:
    virtual std::unique_ptr<Filter> CreateFilter(int number_args, std::stringstream& args) const = 0;
    virtual ~Creator() = default;
};