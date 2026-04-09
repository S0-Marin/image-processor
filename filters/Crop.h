#pragma once
#include "Filter.h"
#include "../Image.h"

class Crop : public Filter {
public:
    Crop(const int new_width, const int new_height);
    Image Apply(const Image& image) const override;

private:
    int new_width_;
    int new_height_;
};
