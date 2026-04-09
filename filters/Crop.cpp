#include "Crop.h"
#include "Filter.h"
#include "../Image.h"
#include "../Pixel.h"

Crop::Crop(const int new_width, const int new_height) : Filter(), new_width_(new_width), new_height_(new_height) {
}

Image Crop::Apply(const Image& image) const {
    if (new_width_ >= image.GetWidth() and new_height_ >= image.GetHeight()) {
        return image;
    }
    std::vector<Pixel> new_pixels;
    const std::vector<Pixel> pixels = image.GetPixels();
    const int width = image.GetWidth();
    const int height = image.GetHeight();
    for (int row = 0; row < std::min(new_height_, height); ++row) {
        for (int col = 0; col < std::min(new_width_, width); ++col) {
            new_pixels.push_back(pixels[row * width + col]);
        }
    }
    return Image(new_width_, new_height_, new_pixels);
}
