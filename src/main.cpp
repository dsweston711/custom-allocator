#include "Allocator.hpp"
#include <iostream>

using namespace std;

int main()
{
    Allocator allocator(1024); // 1KB pool

    void *ptr = allocator.allocate(64);
    if (ptr)
    {
        cout << "Allocated 64 bytes.\n";
        allocator.deallocate(ptr);
    }
    else
    {
        cout << "Allocation failed.\n";
    }

    return 0;
}
