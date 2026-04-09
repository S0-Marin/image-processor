#include <memory>
#include <sstream>
#include "Creator.h"
#include "CreatorSharpening.h"
#include "../filters/Filter.h"
#include "../filters/Sharpening.h"

CreatorSharpening::CreatorSharpening() : Creator() {
}

std::unique_ptr<Filter> CreatorSharpening::CreateFilter(const int number_args, std::stringstream& args) const {
    if (number_args) {
        throw std::runtime_error("Функция вызывается без аргументов.");
    }
    return std::make_unique<Sharpening>();
}