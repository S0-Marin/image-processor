#pragma once

struct Pixel {
    double red;
    double green;
    double blue;

    Pixel();
    void Normalise();
    Pixel(const double red, const double green, const double blue);
    Pixel(const Pixel& other);
    Pixel& operator=(const Pixel& other);
    Pixel& operator=(Pixel&& other);
    Pixel operator+(const Pixel& other) const;
    Pixel operator+(const double x) const;
    Pixel operator*(const Pixel& other) const;
    Pixel operator*(const double x) const;
    Pixel operator-(const Pixel& other) const;
    Pixel operator-(const double x) const;
    void operator+=(const Pixel& other);
    void operator+=(const double x);
    void operator-=(const Pixel& other);
    void operator-=(const double x);
    void operator*=(const Pixel& other);
    void operator*=(const double x);
};

Pixel operator+(const double x, const Pixel& pixel);
Pixel operator*(const double x, const Pixel& pixel);
Pixel operator-(const double x, const Pixel& pixel);
