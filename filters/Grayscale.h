#pragma once
#include "Filter.h"
#include "../Image.h"

class Grayscale : virtual public Filter {
public:
    Grayscale();
    Image Apply(const Image& image) const override;

private:
    const Pixel coef_{0.299, 0.587, 0.114};
};