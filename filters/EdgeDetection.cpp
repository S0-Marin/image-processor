#include "ApplyMatrix3.h"
#include "EdgeDetection.h"
#include "Filter.h"
#include "Grayscale.h"
#include "../Image.h"

EdgeDetection::EdgeDetection(const double threshold)
    : Grayscale(), ApplyMatrix3({0, -1, 0, -1, 4, -1, 0, -1, 0}), threshold_(threshold) {
}

Image EdgeDetection::Apply(const Image& image) const {
    Image new_image = ApplyMatrix3::Apply(Grayscale::Apply(image));
    for (int row = 0; row < image.GetHeight(); ++row) {
        for (int col = 0; col < image.GetWidth(); ++col) {
            Pixel new_pixel = new_image.GetPixel(row, col);
            new_pixel.red = new_pixel.red > threshold_ ? 1 : 0;
            new_pixel.green = new_pixel.green > threshold_ ? 1 : 0;
            new_pixel.blue = new_pixel.blue > threshold_ ? 1 : 0;
            new_image.SetPixel(row, col, new_pixel);
        }
    }
    return new_image;
}
