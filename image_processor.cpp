#include <fstream>
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Args.h"
#include "BMP.h"
#include "filters/Filter.h"
#include "help.h"
#include "Image.h"

int main(const int argc, char** argv) {
    try {
        if (argc == 1) {
            Help();
            return 0;
        }
        const Args args(argc, argv);
        BMP bmp;
        Image image = bmp.Read(args.GetInput());
        for (const auto& filter : args.GetFilters()) {
            image = filter->Apply(image);
        }
        bmp.Write(args.GetOutput(), image);
    } catch (const std::exception& exc) {
        std::cout << "Exception caught: " << exc.what() << std::endl;
        return 10;
    } catch (...) {
        std::cout << "Something unexpected..." << std::endl;
        return 100;
    }
}
