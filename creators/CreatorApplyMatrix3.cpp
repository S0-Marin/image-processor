#include <memory>
#include <sstream>
#include "../filters/Filter.h"
#include "../filters/ApplyMatrix3.h"
#include "Creator.h"
#include "CreatorApplyMatrix3.h"

CreatorApplyMatrix3::CreatorApplyMatrix3() : Creator() {
}

std::unique_ptr<Filter> CreatorApplyMatrix3::CreateFilter(const int number_args, std::stringstream& args_str) const {
    if (number_args != 1) {
        throw std::runtime_error("Функция принимает 1 аргумент.");
    }
    std::vector<double> args;
    double arg;
    while (args_str >> arg) {
        args.push_back(arg);
    }
    if (args.size() != vec_size_) {
        throw std::runtime_error("Некорректный размер вектора.");
    }
    return std::make_unique<ApplyMatrix3>(args);
}
