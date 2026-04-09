#include <memory>
#include <sstream>
#include <iostream>
#include "Creator.h"
#include "CreatorGaussianBlur.h"
#include "../filters/Filter.h"
#include "../filters/GaussianBlur.h"

CreatorGaussianBlur::CreatorGaussianBlur() : Creator() {
}

std::unique_ptr<Filter> CreatorGaussianBlur::CreateFilter(const int number_args, std::stringstream& args) const {
    if (number_args != 1) {
        throw std::runtime_error("Функция принимает 1 аргумент.");
    }
    double sigma;
    if (!(args >> sigma)) {
        throw std::runtime_error("Некоректные аргументы.");
    }
    return std::make_unique<GaussianBlur>(sigma);
}
