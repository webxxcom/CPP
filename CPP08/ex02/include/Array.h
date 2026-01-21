/* --- Array.h --- */

/* ------------------------------------------
Author: undefined
Date: 1/20/2026
------------------------------------------ */

#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>
#include <cstring>
#include <stdexcept>

template<typename T>
class Array {
public:
    Array() : _data(NULL) { this->init(); }
    Array(unsigned int n) : _data(NULL) { this->init(n); }
    Array(Array const& other) : _data(NULL) { *this = other; }
    ~Array()
    {
        if (this->_data)
            delete[] _data;
    }

    Array &operator=(Array const& other)
    {
        if (this->_data)
            delete[] _data;
        this->init(other._capacity);
        std::memcpy(this->_data, other._data, other._capacity);
        return (*this);
    }

    T &operator[](size_t const index)
    {
        if (index >= _size)
            throw std::out_of_range("Index is out of range");
        return (_data[index]);
    }

    T const& operator[](size_t const index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index is out of range");
        return (_data[index]);
    }

    size_t size() const { return this->_size; };

private:
    T *_data;
    size_t _size;
    size_t _capacity;

    // default capacity is 8
    void init() { this->init(8); }
    void init(size_t capacity)
    {
        this->_capacity = capacity;
        this->_size = capacity;
        this->_data = new T[capacity]();
    }
};

#endif // ARRAY_H
