#include "Allocator.hpp"
#include <iostream>
#include <cstdlib> // malloc, free

using namespace std;

Allocator::Allocator(std::size_t size)
{
    memorySize = size;
    memoryStart = std::malloc(size);
    if (!memoryStart)
    {
        cerr << "Failed to allocate initial memory pool.\n";
        exit(1);
    }
}

Allocator::~Allocator()
{
    free(memoryStart);
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
