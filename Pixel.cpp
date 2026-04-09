#include <algorithm>
#include "Pixel.h"

Pixel::Pixel() {
    red = 0;
    green = 0;
    blue = 0;
}

void Pixel::Normalise() {
    red = std::min(1.0, std::max(0.0, red));
    green = std::min(1.0, std::max(0.0, green));
    blue = std::min(1.0, std::max(0.0, blue));
}

Pixel::Pixel(const double red, const double green, const double blue) : red(red), green(green), blue(blue) {
}

Pixel::Pixel(const Pixel& other) : red(other.red), green(other.green), blue(other.blue) {
}

Pixel& Pixel::operator=(const Pixel& other) {
    red = other.red;
    green = other.green;
    blue = other.blue;
    return *this;
}

Pixel& Pixel::operator=(Pixel&& other) {
    red = other.red;
    green = other.green;
    blue = other.blue;
    return *this;
}

Pixel Pixel::operator+(const Pixel& other) const {
    return Pixel(red + other.red, green + other.green, blue + other.blue);
}

Pixel Pixel::operator+(const double x) const {
    return Pixel(red + x, green + x, blue + x);
}

Pixel Pixel::operator*(const Pixel& other) const {
    return Pixel(red * other.red, green * other.green, blue * other.blue);
}

Pixel Pixel::operator*(const double x) const {
    return Pixel(red * x, green * x, blue * x);
}

Pixel Pixel::operator-(const Pixel& other) const {
    return Pixel(red - other.red, green - other.green, blue - other.blue);
}

Pixel Pixel::operator-(const double x) const {
    return Pixel(red - x, green - x, blue - x);
}

void Pixel::operator+=(const Pixel& other) {
    red += other.red;
    green += other.green;
    blue += other.blue;
}

void Pixel::operator+=(const double x) {
    red += x;
    green += x;
    blue += x;
}

void Pixel::operator-=(const Pixel& other) {
    red -= other.red;
    green -= other.green;
    blue -= other.blue;
}

void Pixel::operator-=(const double x) {
    red -= x;
    green -= x;
    blue -= x;
}

void Pixel::operator*=(const Pixel& other) {
    red *= other.red;
    green *= other.green;
    blue *= other.blue;
}

void Pixel::operator*=(const double x) {
    red *= x;
    green *= x;
    blue *= x;
}

Pixel operator+(const double x, const Pixel& pixel) {
    return Pixel(x + pixel.red, x + pixel.green, x + pixel.blue);
}

Pixel operator*(const double x, const Pixel& pixel) {
    return Pixel(x * pixel.red, x * pixel.green, x * pixel.blue);
}

Pixel operator-(const double x, const Pixel& pixel) {
    return Pixel(x - pixel.red, x - pixel.green, x - pixel.blue);
}
