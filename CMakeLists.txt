project(image_processor)

cmake_minimum_required(VERSION 3.8)

add_executable(
        image_processor
        image_processor.cpp

        creators/Creator.cpp
        creators/CreatorApplyMatrix3.cpp
        creators/CreatorCrop.cpp
        creators/CreatorEdgeDetection.cpp
        creators/CreatorGaussianBlur.cpp
        creators/CreatorGrayscale.cpp
        creators/CreatorNegative.cpp
        creators/CreatorSharpening.cpp

        filters/Filter.cpp
        filters/ApplyMatrix3.cpp
        filters/Crop.cpp
        filters/EdgeDetection.cpp
        filters/GaussianBlur.cpp
        filters/Grayscale.cpp
        filters/Negative.cpp
        filters/Sharpening.cpp

        Args.cpp
        BMP.cpp
        help.cpp
        Image.cpp
        Pixel.cpp
)
