#pragma once
#include "ApplyMatrix3.h"
#include "Grayscale.h"
#include "../Image.h"

class EdgeDetection : public Grayscale, public ApplyMatrix3 {
public:
    explicit EdgeDetection(const double threshold);
    Image Apply(const Image& image) const override;

private:
    const std::vector<double> matrix_ = {0, -1, 0, -1, 4, -1, 0, -1, 0};
    double threshold_;
};
