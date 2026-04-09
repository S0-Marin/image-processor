#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "creators/Creator.h"
#include "filters/Filter.h"

class Args {
public:
    Args(int argc, char** argv);
    const std::vector<std::unique_ptr<Filter>>& GetFilters() const;
    std::string GetInput() const;
    std::string GetOutput() const;

private:
    std::vector<std::unique_ptr<Filter>> filters_;
    std::string input_filename_;
    std::string output_filename_;
    std::unordered_map<std::string, std::unique_ptr<Creator>> map_filters_;
};