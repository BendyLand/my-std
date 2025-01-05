#pragma once

#include <exception>
#include <string>
#include <vector>

namespace my
{
    //todo
    class test
    {

    };
};

namespace my
{
    //todo: eventually replace std::exceptions with my own
    class exception
    {

    };
};

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
        inline const std::string str() const { return this->data; }
        inline std::string str() { return this->data; }
        inline bool contains(const std::string& substr) const
        {
            return this->data.find(substr) != std::string::npos;
        }
        inline string trim() const
        {
            size_t start = data.find_first_not_of(" \t\n\r");
            size_t end = data.find_last_not_of(" \t\n\r");
            return (start == std::string::npos) ? "" : data.substr(start, end - start + 1);
        }
        //todo: make overloads that accept 'from' and/or 'to' for specific ranges to be changed
        inline string to_upper() const
        {
            string result = data;
            std::transform(result.data.begin(), result.data.end(), result.data.begin(), ::toupper);
            return result;
        }
        inline string to_lower() const
        {
            string result = data;
            std::transform(result.data.begin(), result.data.end(), result.data.begin(), ::tolower);
            return result;
        }

        // Forward std::string methods
        inline size_t size() const { return data.size(); }
        inline bool empty() const { return data.empty(); }
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
    };
};

namespace my
{
    class regex
    {
    private:
        // Fields
        my::string pattern;

    public:
        // Constructor, Copy/Move Constructors, Destructor
        regex() : pattern("") {}
        regex(const my::string& p) : pattern(p) {}
        regex(const my::regex& r) : pattern(r.pattern) {}
        regex(my::regex&& r) noexcept : pattern(std::move(r.pattern)) {}
        ~regex() = default;

        // Methods
        //TODO
    };
};

namespace my
{
    template <typename T>
    class vector
    {
    private:
        std::vector<T> data;

    public:
        // Constructor, Copy/Move Constructors, Destructor
        vector() : data(nullptr) {}
        vector(const vector<T>& vec)
        {
            this->data.assign(vec.begin(), vec.end());
        }
        vector(vector<T>&& vec) noexcept : data(std::move(vec.data)) {}
        vector(const std::initializer_list<T>& elements)
        {
            this->data.assign(elements.begin(), elements.end());
        }
        vector(const std::vector<T>& elements) : data(elements.data()) {}

        // Operators
        inline operator std::vector<T>() const { return this->data; }
        inline vector& operator=(const vector<T>& vec)
        {
            if (this != &vec) {
                vector temp(vec);
                std::swap(data, temp.data);
            }
            return *this;
        }
        inline vector& operator=(vector<T>&& vec) noexcept
        {
            if (this != &vec) {
                data = std::move(vec.data);
            }
            return *this;
        }
        inline T& operator[](int index)
        {
            if (index >= 0) {
                if (index >= this->size()) throw std::out_of_range("Index out of bounds");
                return data[index];
            }
            do {
                index = this->size() + index;
            } while (index < 0);
            return data[index];
        }
        inline const T& operator[](int index) const
        {
            if (index >= 0) {
                if (index >= this->size()) throw std::out_of_range("Index out of bounds");
                return data[index];
            }
            do {
                index = this->size() + index;
            } while (index < 0);
            return data[index];
        }

        // Methods
        template <typename... Args>
        inline void emplace(Args&&... args)
        {
            this->data.emplace_back(std::forward<Args>(args)...);
        }
        inline void push(const T& value)
        {
            this->data.push_back(value);
        }
        inline void push(T&& value)
        {
            this->data.push_back(value);
        }
        inline T pop()
        {
            if (this->size() == 0) throw std::length_error("Vector is empty.");
            T result = this->data[this->data.size()-1];
            this->data.pop_back();
            return result;
        }
        inline size_t size() const
        {
            return this->data.size();
        }
        inline auto begin() const -> decltype(data.begin()) { return data.begin(); }
        inline auto end() const -> decltype(data.end()) { return data.end(); }
    };
}
