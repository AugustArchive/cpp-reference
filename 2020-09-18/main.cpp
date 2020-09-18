#include <iostream>
#include <cstdlib>
#include <cstring>

int memAllocationCounter = 0;
int memDeallocationCounter = 0;

void* operator new(size_t _Size) noexcept {
    memAllocationCounter++;
    return malloc(_Size);
}

void operator delete(void *x) noexcept {
    memDeallocationCounter++;
    free(x);
}

template<typename T>
class Vector {
    private:
    T* ptr = NULL;
    int _Size = 0;

    public:
    Vector(size_t size) {
        ptr = new T[size];
        _Size = size;
    }

    ~Vector() {
        if (ptr == NULL) return;

        delete[] ptr;
    }

    Vector(const Vector<T>& other) {
        ptr = new T[other._Size];
        _Size = other._Size;
        memcpy(ptr, other.ptr, _Size);
    }

    Vector<T>& operator=(const Vector<T>& other) {
        ptr = new T[other._Size];
        memcpy(ptr, other.ptr);
        _Size = other._Size;
    }
    
    Vector(Vector<T>&& other) {
        this->ptr = other.ptr;
        this->_Size = other._Size;
        other._Size = 0;
        other.ptr = NULL;
    }

    Vector<T>& operator=(Vector<T>&& other) {
        this->ptr = other.ptr;
        this->_Size = other._Size;
        other._Size = 0;
        other.ptr = NULL;
    }

    T& operator[](size_t index) {
        return ptr[index];
    }

    const T& operator[](size_t index) const {
        return ptr[index];
    }
};

Vector<int> squareList(int size) {
    Vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = i*i;
    }
    return std::move(vec);
}

int main()
{
    {
        // Vector<int> vec(size);
        Vector<int> fiveSquares = squareList(5);
        fiveSquares[1] = 5;
        Vector<int> faker = fiveSquares;
        faker[1] = 3;
        std::cout << fiveSquares[1] << std::endl;
    }
    std::cout << "Heap Allocations: " << memAllocationCounter << std::endl;
    std::cout << "Heap Deallocations: " <<  memDeallocationCounter << std::endl;
}
