#include <stdexcept>
#include <vector>
#include "Image.h"
#include "Pixel.h"

Image::Image(const int width, const int height) : width_(width), height_(height) {
    pixels_.resize(width_ * height_);
}

Image::Image(const int width, const int height, const std::vector<Pixel>& pixels) : width_(width), height_(height) {
    pixels_ = pixels;
}

Image::Image(const Image& other) {
    pixels_ = other.pixels_;
    width_ = other.width_;
    height_ = other.height_;
}

Image& Image::operator=(const Image& other) {
    pixels_ = other.pixels_;
    width_ = other.width_;
    height_ = other.height_;
    return *this;
}

Image& Image::operator=(Image&& other) {
    pixels_ = other.pixels_;
    width_ = other.width_;
    height_ = other.height_;
    return *this;
}

Pixel Image::GetPixel(const int row, const int col) const {
    if (row < 0 || col < 0 || row >= height_ || col >= width_) {
        throw std::runtime_error("обращение к несуществующему пикселю");
    }
    return pixels_[row * width_ + col];
}

void Image::SetPixel(const int row, const int col, const Pixel& pixel) {
    if (row < 0 || col < 0 || row >= height_ || col >= width_) {
        throw std::runtime_error("обращение к несуществующему пикселю");
    }
    pixels_[row * width_ + col] = pixel;
}

const std::vector<Pixel>& Image::GetPixels() const {
    return pixels_;
}

int Image::GetHeight() const {
    return height_;
}

int Image::GetWidth() const {
    return width_;
}
