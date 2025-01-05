#include "mystring.hpp"

namespace my
{
    const std::string string::str() const { return this->data; }
    std::string string::str() { return this->data; }
    bool string::contains(const std::string& substr) const
    {
        return this->data.find(substr) != std::string::npos;
    }
    string string::ltrim() const
    {
        size_t start = data.find_first_not_of(" \t\n\r");
        return (start == std::string::npos) ? "" : data.substr(start);
    }
    string string::rtrim() const
    {
        size_t end = data.find_last_not_of(" \t\n\r");
        return (end == std::string::npos) ? "" : data.substr(0, end + 1);
    }
    string string::trim() const
    {
        size_t start = data.find_first_not_of(" \t\n\r");
        size_t end = data.find_last_not_of(" \t\r\n");
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
    string string::to_upper(size_t from) const
    {
        string result = data;
        std::transform(result.data.begin()+from, result.data.end(), result.data.begin()+from, ::toupper);
        return result;
    }
    string string::to_lower(size_t from) const
    {
        string result = data;
        std::transform(result.data.begin()+from, result.data.end(), result.data.begin()+from, ::tolower);
        return result;
    }
    string string::to_upper(size_t from, size_t to) const
    {
        string result = data;
        std::transform(result.data.begin()+from, result.data.begin()+to, result.data.begin()+from, ::toupper);
        return result;
    }
    string string::to_lower(size_t from, size_t to) const
    {
        string result = data;
        std::transform(result.data.begin()+from, result.data.begin()+to, result.data.begin()+from, ::tolower);
        return result;
    }

    // Forward std::string methods
    size_t string::size() const { return data.size(); }
    bool string::empty() const { return data.empty(); }
};