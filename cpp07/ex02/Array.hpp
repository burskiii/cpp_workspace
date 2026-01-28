#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
private:
    T*            _data;
    unsigned int  _size;

public:
    // Exception type for out-of-bounds
    class OutOfBounds : public std::exception
    {
    public:
        virtual const char* what() const throw() { return "Array index out of bounds"; }
    };

    // 1) Default constructor: empty array
    Array() : _data(NULL), _size(0) {}

    // 2) Constructor with n: n default-initialized elements
    Array(unsigned int n) : _data(NULL), _size(n)
    {
        if (_size == 0)
            _data = NULL;
        else
            _data = new T[_size]; // MUST be new[]
    }

    // 3) Copy constructor: deep copy
    Array(const Array& other) : _data(NULL), _size(0)
    {
        *this = other;
    }

    // 4) Assignment operator: deep copy, self-assign safe
    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] _data;
            _size = other._size;
            _data = (_size == 0) ? NULL : new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _data[i] = other._data[i];
        }
        return *this;
    }

    // Destructor
    ~Array()
    {
        delete[] _data;
    }

    // 5) Subscript operator with bounds check
    T& operator[](unsigned int index)
    {
        if (index >= _size)
            throw OutOfBounds();
        return _data[index];
    }

    // Const subscript operator
    const T& operator[](unsigned int index) const
    {
        if (index >= _size)
            throw OutOfBounds();
        return _data[index];
    }

    // 6) size() const
    unsigned int size() const
    {
        return _size;
    }
};

#endif
