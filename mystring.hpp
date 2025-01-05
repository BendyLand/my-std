#pragma once

#include <string>
#include <exception>

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
        inline string& operator=(const string& other)
        {
            data = other.data;
            return *this;
        }
        inline string& operator=(string&& other)
        {
            data = std::move(other.data);
            return *this;
        }
        inline string& operator+=(const string& other)
        {
            data += other.data;
            return *this;
        }
        inline string& operator<<(const string& other)
        {
            data += other.data;
            return *this;
        }
        inline friend std::ostream& operator<<(std::ostream& os, const string& other)
        {
            os << other.data;
            return os;
        }
        inline char& operator[](int index)
        {
            if (index >= 0) {
                if (index >= data.size()) throw std::out_of_range("Index out of bounds");
                return data[index];
            }
            do {
                index = data.size() + index;
            } while (index < 0);
            return data[index];
        }
        inline const char& operator[](int index) const
        {
            if (index >= 0) {
                if (index >= data.size()) throw std::out_of_range("Index out of bounds");
                return data[index];
            }
            do {
                index = data.size() + index;
            } while (index < 0);
            return data[index];
        }

        // Methods
        std::string str(); 
        const std::string str() const; 
        bool contains(const std::string& substr) const;
        string ltrim() const;
        string rtrim() const;
        string trim() const;
        string to_upper() const;
        string to_lower() const;
        string to_upper(size_t from) const;
        string to_lower(size_t from) const;
        string to_upper(size_t from, size_t to) const;
        string to_lower(size_t from, size_t to) const;

        // Forward std::string methods
        size_t size() const; 
        bool empty() const; 
    };
};