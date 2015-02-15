#include "IntArray.hpp"

IntArray::IntArray(int* array, int sz) {
    _size = sz;
    backing = new int[_size];

    if (!array) {
        for (int i = 0; i < sz; ++i) {
            backing[i] = 0;
        }
    }
    else {
        for (int i = 0; i < sz; ++i) {
            backing[i] = array[i];
        }
    }
}

IntArray::IntArray(const IntArray& rhs)
    : IntArray(rhs.backing, rhs.size()) { }

IntArray::IntArray(int sz) 
    : IntArray(0, sz)      { }

IntArray::~IntArray() {
    delete[] backing;
}

int IntArray::size() {
    return _size;
}

int& IntArray::operator[](int i) {
    assert(i >= 0 && i < _size);
    return backing[i];
}
