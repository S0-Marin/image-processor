#include "Filter.h"
#include "GaussianBlur.h"
#include "../Image.h"

GaussianBlur::GaussianBlur(const double sigma) : Filter() {
}

Image GaussianBlur::Apply(const Image& image) const {
    return image;
}
