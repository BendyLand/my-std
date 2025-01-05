#pragma once // This file must be header only due to the template usage.

#include <string>
#include <exception>
#include <vector>

namespace my
{
    template <typename T>
    class vector
    {
    private:
        std::vector<T> data;

    public:
        // Constructor, Copy/Move Constructors, Destructor
        vector() : data() {}
        vector(const vector<T>& vec) : data(vec.begin(), vec.end()) {}
        vector(vector<T>&& vec) noexcept : data(std::move(vec.data)) {}
        vector(const std::vector<T>& elements) : data(elements.data()) {}
        vector(const std::initializer_list<T>& elements) : data(elements.begin(), elements.end()) {}

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
        inline size_t capacity() const
        {
            return this->data.capacity();
        }
        inline auto begin() const -> decltype(data.begin()) { return data.begin(); }
        inline auto end() const -> decltype(data.end()) { return data.end(); }
    };
}