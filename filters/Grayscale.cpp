#include "Grayscale.h"
#include "Filter.h"
#include "../Image.h"

Grayscale::Grayscale() : Filter() {
}

Image Grayscale::Apply(const Image& image) const {
    Image new_image = image;
    for (int row = 0; row < image.GetHeight(); ++row) {
        for (int col = 0; col < image.GetWidth(); ++col) {
            const Pixel pixel = image.GetPixel(row, col) * coef_;
            const double color = pixel.red + pixel.green + pixel.blue;
            new_image.SetPixel(row, col, Pixel(color, color, color));
        }
    }
    return new_image;
}
