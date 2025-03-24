#include "Allocator.hpp"
#include <iostream>

int main()
{
    Allocator allocator(1024); // 1KB pool

    void *ptr = allocator.allocate(64);
    if (ptr)
    {
        std::cout << "Allocated 64 bytes.\n";
        allocator.deallocate(ptr);
    }
    else
    {
        std::cout << "Allocation failed.\n";
    }

    return 0;
}
