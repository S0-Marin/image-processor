#include <iostream>

void Help() {
    std::cout << "Usage" << std::endl;
    std::cout << "Filters:" << std::endl;
    std::cout << "-crop <width> <height> обрезает изображение до заданных размеров" << std::endl;
    std::cout << "-gs преобразует изображение в оттенки серого" << std::endl;
    std::cout << "-neg преобразует изображение в негатив" << std::endl;
    std::cout << "-sharp повышение резкости" << std::endl;
    std::cout << "-edge <threshold> выделение границ" << std::endl;
    std::cout << "-blur <sigma> Гауссово размытие" << std::endl;
    std::cout << "вызов без аргментов - справка" << std::endl;
}
