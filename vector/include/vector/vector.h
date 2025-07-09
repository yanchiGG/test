#pragma once
#include <cstddef>

class vector
{
   private:
    int* data;
    size_t sz;
    size_t cap;

    void reallocate(size_t new_cap);

   public:
    vector(size_t size = 0);
    ~vector();
    vector(const vector& other);
    vector& operator=(const vector& other);
    vector(vector&& other) noexcept;
    vector& operator=(vector&& other) noexcept;

    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    int& at(size_t index);
    const int& at(size_t index) const;

    bool empty() const;
    size_t size() const;
    size_t capacity() const;
    void reserve(size_t new_cap);
    void resize(size_t new_size);

    void push_back(int value);
    void insert(size_t index, int value);
};
