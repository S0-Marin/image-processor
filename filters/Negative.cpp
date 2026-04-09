#include "Filter.h"
#include "Negative.h"
#include "../Image.h"

Negative::Negative() : Filter() {
}

Image Negative::Apply(const Image& image) const {
    Image new_image = image;
    for (int row = 0; row < new_image.GetHeight(); ++row) {
        for (int col = 0; col < new_image.GetWidth(); ++col) {
            new_image.SetPixel(row, col, 1 - new_image.GetPixel(row, col));
        }
    }
    return new_image;
}
