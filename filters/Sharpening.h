#pragma once
#include "ApplyMatrix3.h"
#include "../Image.h"

class Sharpening : public ApplyMatrix3 {
public:
    Sharpening();
    Image Apply(const Image& image) const override;

private:
    const std::vector<double> matrix_ = {0, -1, 0, -1, 5, -1, 0, -1, 0};
};
