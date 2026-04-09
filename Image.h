#pragma once
#include <vector>
#include "Pixel.h"

class Image {
public:
    Image(const int width, const int height);
    Image(const int width, const int height, const std::vector<Pixel>& pixels);
    Image(const Image& other);
    Image& operator=(const Image& other);
    Image& operator=(Image&& other);
    Pixel GetPixel(const int row, const int col) const;
    void SetPixel(const int row, const int col, const Pixel& pixel);
    const std::vector<Pixel>& GetPixels() const;
    int GetHeight() const;
    int GetWidth() const;

private:
    std::vector<Pixel> pixels_;
    int width_;
    int height_;
};