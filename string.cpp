#pragma once

#include "string.hpp"

namespace my
{
    const std::string string::str() const { return this->data; }
    std::string string::str() { return this->data; }
    size_t string::size() const { return data.size(); }
    bool string::empty() const { return data.empty(); }
    bool string::contains(const std::string& substr) const 
    {
        return this->data.find(substr) != std::string::npos;
    }
    string string::trim() const 
    {
        size_t start = data.find_first_not_of(" \t\n\r");
        size_t end = data.find_last_not_of(" \t\n\r");
        return (start == std::string::npos) ? "" : data.substr(start, end - start + 1);
    }
    string string::to_upper() const 
    {
        string result = data;
        std::transform(result.data.begin(), result.data.end(), result.data.begin(), ::toupper);
        return result;
    }
    string string::to_lower() const 
    {
        string result = data;
        std::transform(result.data.begin(), result.data.end(), result.data.begin(), ::tolower);
        return result;
    }
};
