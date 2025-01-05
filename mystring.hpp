#pragma once

#include <string>

namespace my
{
    class string
    {
    private:
        // Fields
        std::string data;

    public:
        // Constructor, Copy/Move Constructors, Destructor
        string() : data("") {}
        string(const char* str) : data(str) {}
        string(const std::string& str) : data(str) {}
        string(const my::string& str) : data(str.data) {}
        string(my::string&& str) noexcept : data(std::move(str.data)) {}
        ~string() = default;

        // Operators
        inline operator std::string() const { return this->data; }
        inline string& operator+=(const string& other) 
        {
            data += other.data;
            return *this;
        }

        // Methods
        const std::string str() const; 
        std::string str(); 
        bool contains(const std::string& substr) const;
        string trim() const; 
        string to_upper() const;
        string to_lower() const;

        // Forward std::string methods
        size_t size() const; 
        bool empty() const; 
        inline char& operator[](size_t index) { return data[index]; }
        inline const char& operator[](size_t index) const { return data[index]; }
        inline char& operator[](int index) 
        { 
            if (index >= 0) return data[index]; 
            do {
                index = data.size() + index;
            } while (index < 0);
            return data[index];
        }
        inline const char& operator[](int index) const 
        { 
            if (index >= 0) return data[index]; 
            do {
                index = data.size() + index;
            } while (index < 0);
            return data[index];
        }
    };
};
