#pragma once
#include <vector>
#include "Filter.h"
#include "../Image.h"

class ApplyMatrix3 : virtual public Filter {
public:
    explicit ApplyMatrix3(const std::vector<double>& matrix);
    Image Apply(const Image& image) const override;

private:
    const std::vector<double> matrix_;
    const std::vector<int> row_mask_ = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    const std::vector<int> col_mask_ = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    size_t matrix_size_;
};