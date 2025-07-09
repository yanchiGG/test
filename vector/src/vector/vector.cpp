#include "../include/vector/vector.h"
#include <algorithm>
#include <stdexcept>

vector::vector(size_t size) : sz(size), cap(size), data(size ? new int[size]() : nullptr)
{
}

vector::~vector()
{
    delete[] data;
}

vector::vector(const vector& other)
    : sz(other.sz), cap(other.cap), data(other.cap ? new int[other.cap] : nullptr)
{
    std::copy(other.data, other.data + sz, data);
}

vector& vector::operator=(const vector& other)
{
    if (this != &other)
    {
        delete[] data;
        sz = other.sz;
        cap = other.cap;
        data = cap ? new int[cap] : nullptr;
        std::copy(other.data, other.data + sz, data);
    }
    return *this;
}

vector::vector(vector&& other) noexcept : sz(other.sz), cap(other.cap), data(other.data)
{
    other.data = nullptr;
    other.sz = 0;
    other.cap = 0;
}

vector& vector::operator=(vector&& other) noexcept
{
    if (this != &other)
    {
        delete[] data;
        data = other.data;
        sz = other.sz;
        cap = other.cap;

        other.data = nullptr;
        other.sz = 0;
        other.cap = 0;
    }
    return *this;
}

int& vector::operator[](size_t index)
{
    return data[index];
}
const int& vector::operator[](size_t index) const
{
    return data[index];
}

int& vector::at(size_t index)
{
    if (index >= sz)
        throw std::out_of_range("Index out of range");
    return data[index];
}
const int& vector::at(size_t index) const
{
    if (index >= sz)
        throw std::out_of_range("Index out of range");
    return data[index];
}

bool vector::empty() const
{
    return sz == 0;
}

size_t vector::size() const
{
    return sz;
}

size_t vector::capacity() const
{
    return cap;
}

void vector::reserve(size_t new_cap)
{
    if (new_cap > cap)
    {
        reallocate(new_cap);
    }
}

void vector::resize(size_t new_size)
{
    if (new_size > cap)
    {
        reallocate(new_size);
    }
    if (new_size > sz)
    {
        std::fill(data + sz, data + new_size, 0);
    }
    sz = new_size;
}

void vector::push_back(int value)
{
    if (sz == cap)
    {
        reserve(cap == 0 ? 1 : cap * 2);
    }
    data[sz++] = value;
}

void vector::insert(size_t index, int value)
{
    if (index > sz)
        throw std::out_of_range("Insert position out of bounds");
    if (sz == cap)
    {
        reserve(cap == 0 ? 1 : cap * 2);
    }
    for (size_t i = sz; i > index; --i)
    {
        data[i] = data[i - 1];
    }
    data[index] = value;
    ++sz;
}

void vector::reallocate(size_t new_cap)
{
    int* new_data = new int[new_cap];
    if (data)
    {
        std::copy(data, data + sz, new_data);
        delete[] data;
    }
    data = new_data;
    cap = new_cap;
}
