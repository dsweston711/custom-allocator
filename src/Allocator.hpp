#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <cstddef>

using namespace std;

class Allocator
{
public:
    Allocator(size_t size);
    ~Allocator();

    void *allocate(size_t size);
    void deallocate(void *ptr);

private:
    void *memoryStart;
    size_t memorySize;

    // TODO: add metadata structures
};

#endif // ALLOCATOR_HPP
