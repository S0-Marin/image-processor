#include <memory>
#include <sstream>
#include "CreatorApplyMatrix3.h"
#include "CreatorGrayscale.h"
#include "CreatorEdgeDetection.h"
#include "../filters/Filter.h"
#include "../filters/EdgeDetection.h"

CreatorEdgeDetection::CreatorEdgeDetection() : CreatorGrayscale(), CreatorApplyMatrix3() {
}

std::unique_ptr<Filter> CreatorEdgeDetection::CreateFilter(const int number_args, std::stringstream& args) const {
    if (number_args != 1) {
        throw std::runtime_error("Функция принимает 1 аргумент.");
    }
    double threshold;
    if (!(args >> threshold)) {
        throw std::runtime_error("Некоректные аргументы.");
    }
    return std::make_unique<EdgeDetection>(threshold);
}