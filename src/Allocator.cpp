#include "Allocator.hpp"
#include <iostream>
#include <cstdlib> // malloc, free

Allocator::Allocator(std::size_t size)
{
    memorySize = size;
    memoryStart = std::malloc(size);
    if (!memoryStart)
    {
        std::cerr << "Failed to allocate initial memory pool.\n";
        std::exit(1);
    }
}

Allocator::~Allocator()
{
    std::free(memoryStart);
}

void *Allocator::allocate(std::size_t size)
{
    // TODO: Implement custom allocation logic
    return nullptr;
}

void Allocator::deallocate(void *ptr)
{
    // TODO: Implement custom deallocation logic
}
