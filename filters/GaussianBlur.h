#pragma once
#include "Filter.h"
#include "../Image.h"

class GaussianBlur : public Filter {
public:
    explicit GaussianBlur(const double sigma);
    Image Apply(const Image& image) const override;
};