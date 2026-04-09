#include <memory>
#include <sstream>
#include "Creator.h"
#include "CreatorNegative.h"
#include "../filters/Negative.h"

CreatorNegative::CreatorNegative() : Creator() {
}

std::unique_ptr<Filter> CreatorNegative::CreateFilter(const int number_args, std::stringstream& args) const {
    if (number_args) {
        throw std::runtime_error("Функция вызывается без аргументов.");
    }
    return std::make_unique<Negative>();
}
