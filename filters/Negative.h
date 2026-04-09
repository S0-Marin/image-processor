#pragma once
#include "Filter.h"
#include "../Image.h"

class Negative : public Filter {
public:
    Negative();
    Image Apply(const Image& image) const override;
};
