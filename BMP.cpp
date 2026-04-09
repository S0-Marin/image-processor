#include <cstdint>
#include <fstream>
#include <stdexcept>
#include <vector>
#include "BMP.h"
#include "Image.h"
#include "Pixel.h"

#pragma pack(push, 1)

struct BMPFileHeader {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
};

struct BMPInfoHeader {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};

#pragma pack(pop)
Image BMP::Read(const std::string& input_filename) {
    std::ifstream input(input_filename, std::ios::binary);
    if (!input.is_open()) {
        throw std::runtime_error("Не получается открыть файл " + input_filename);
    }
    BMPFileHeader file_header;
    BMPInfoHeader info_header;
    input.read(reinterpret_cast<char*>(&file_header), sizeof(file_header));
    input.read(reinterpret_cast<char*>(&info_header), sizeof(info_header));

    if (file_header.bfType != 0x4D42) {
        throw std::runtime_error("Не BMP файл.");
    }
    if (info_header.biBitCount != 24) {
        throw std::runtime_error("Поддерживается только 24-bit BMP.");
    }
    if (info_header.biCompression != 0) {
        throw std::runtime_error("Сжатый BMP не поддерживается.");
    }

    int width = info_header.biWidth;
    int height = info_header.biHeight;
    bool bottom_up = true;
    if (height < 0) {
        bottom_up = false;
        height = -height;
    }
    Image image(width, height);
    input.seekg(file_header.bfOffBits, std::ios::beg);
    int row_size = width * 3;
    int padding = (4 - (row_size % 4)) % 4;
    int stride = row_size + padding;
    std::vector<uint8_t> row_data(stride);

    for (int y = 0; y < height; ++y) {
        input.read(reinterpret_cast<char*>(row_data.data()), stride);
        int target_y = bottom_up ? (height - 1 - y) : y;
        for (int x = 0; x < width; ++x) {
            Pixel pixel;
            pixel.blue = row_data[x * 3 + 0] / 255.0;
            pixel.green = row_data[x * 3 + 1] / 255.0;
            pixel.red = row_data[x * 3 + 2] / 255.0;
            image.SetPixel(target_y, x, pixel);
        }
    }
    return image;
}
void BMP::Write(const std::string& output_filename, const Image& image) {
    std::ofstream output(output_filename, std::ios::binary);
    if (!output.is_open()) {
        throw std::runtime_error("Не получается открыть файл " + output_filename);
    }

    int width = image.GetWidth();
    int height = image.GetHeight();
    int row_size = width * 3;
    int padding = (4 - (row_size % 4)) % 4;
    int stride = row_size + padding;
    uint32_t image_size = stride * height;
    BMPFileHeader file_header{};
    BMPInfoHeader info_header{};
    file_header.bfType = 0x4D42;
    file_header.bfOffBits = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);
    file_header.bfSize = file_header.bfOffBits + image_size;
    info_header.biSize = sizeof(BMPInfoHeader);
    info_header.biWidth = width;
    info_header.biHeight = height;
    info_header.biPlanes = 1;
    info_header.biBitCount = 24;
    info_header.biCompression = 0;
    info_header.biSizeImage = image_size;

    output.write(reinterpret_cast<char*>(&file_header), sizeof(file_header));
    output.write(reinterpret_cast<char*>(&info_header), sizeof(info_header));
    std::vector<uint8_t> row_data(stride, 0);

    for (int y = height - 1; y >= 0; --y) {
        for (int x = 0; x < width; ++x) {
            Pixel pixel = image.GetPixel(y, x);
            row_data[x * 3 + 0] = pixel.blue * 255;
            row_data[x * 3 + 1] = pixel.green * 255;
            row_data[x * 3 + 2] = pixel.red * 255;
        }
        output.write(reinterpret_cast<char*>(row_data.data()), stride);
    }
}
