#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <cstddef>

class Allocator
{
public:
    Allocator(std::size_t size);
    ~Allocator();

    void *allocate(std::size_t size);
    void deallocate(void *ptr);

private:
    void *memoryStart;
    std::size_t memorySize;

    // TODO: add metadata structures
};

#endif // ALLOCATOR_HPP
