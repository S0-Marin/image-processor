#include <memory>
#include <sstream>
#include "Creator.h"
#include "CreatorGrayscale.h"
#include "../filters/Filter.h"
#include "../filters/Grayscale.h"

CreatorGrayscale::CreatorGrayscale() : Creator() {
}

std::unique_ptr<Filter> CreatorGrayscale::CreateFilter(const int number_args, std::stringstream& args) const {
    if (number_args) {
        throw std::runtime_error("Функция вызывается без аргументов.");
    }
    return std::make_unique<Grayscale>();
}
