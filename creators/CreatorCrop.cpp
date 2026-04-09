#include <memory>
#include <sstream>
#include "Creator.h"
#include "CreatorCrop.h"
#include "../filters/Filter.h"
#include "../filters/Crop.h"

CreatorCrop::CreatorCrop() : Creator() {
}

std::unique_ptr<Filter> CreatorCrop::CreateFilter(const int number_args, std::stringstream& args) const {
    if (number_args != 2) {
        throw std::runtime_error("Функция должна принимать 2 аргумента.");
    }
    int width;
    int height;
    char add;
    if (!(args >> width) || !(args >> height) || (args >> add)) {
        throw std::runtime_error("Некорректные аргументы.");
    }
    return std::make_unique<Crop>(width, height);
}