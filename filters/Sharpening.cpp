#include "ApplyMatrix3.h"
#include "Sharpening.h"
#include "../Image.h"


Sharpening::Sharpening() : ApplyMatrix3({0, -1, 0, -1, 5, -1, 0, -1, 0}) {
}

Image Sharpening::Apply(const Image& image) const {
    return ApplyMatrix3::Apply(image);
}
