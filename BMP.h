#pragma once
#include <string>
#include "Image.h"

class BMP {
public:
    Image Read(const std::string& input_filename);
    void Write(const std::string& output_filename, const Image& image);
};
