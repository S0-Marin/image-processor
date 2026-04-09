#include <algorithm>
#include <vector>
#include "ApplyMatrix3.h"
#include "Filter.h"
#include "../Image.h"

ApplyMatrix3::ApplyMatrix3(const std::vector<double>& matrix) : Filter(), matrix_(matrix), matrix_size_(matrix.size()) {
}

Image ApplyMatrix3::Apply(const Image& image) const {
    Image new_image = image;
    for (int row = 0; row < image.GetHeight(); ++row) {
        for (int col = 0; col < image.GetWidth(); ++col) {
            Pixel new_pixel(0, 0, 0);
            for (size_t i = 0; i < matrix_size_; ++i) {
                const int new_row = std::min(image.GetHeight() - 1, std::max(0, row + row_mask_[i]));
                const int new_col = std::min(image.GetWidth() - 1, std::max(0, col + col_mask_[i]));
                new_pixel += image.GetPixel(new_row, new_col) * matrix_[i];
            }
            new_pixel.Normalise();
            new_image.SetPixel(row, col, new_pixel);
        }
    }
    return new_image;
}
