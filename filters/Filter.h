#pragma once
#include "../Image.h"

class Filter {
public:
    Filter() = default;
    virtual Image Apply(const Image& image) const = 0;
    virtual ~Filter() = default;
};