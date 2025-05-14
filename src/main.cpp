#include "Allocator.hpp"
#include <iostream>

using namespace std;

int main()
{
    Allocator allocator(1024); // 1KB

    size_t m1 = allocator.mark();
    void *p1 = allocator.allocate(128);
    void *p2 = allocator.allocate(512);

    if (p1 && p2)
    {
        std::cout << "Allocated 128 and 512 bytes.\n";
    }

    allocator.printStatus();

    allocator.reset(m1); // reclaim both p1 and p2
    void *p3 = allocator.allocate(1024);
    if (p3)
    {
        std::cout << "Reset successful, entire pool reused.\n";
    }

    allocator.printStatus();

    allocator.reset(m1); // reclaim p3
    std::cout << "Reset\n";
    allocator.printStatus();

    std::cout << "\n[TEST 1] Basic Allocation + Deallocation\n";
    void *a = allocator.allocate(128);
    allocator.printStatus();

    allocator.deallocate(a); // should succeed
    allocator.printStatus();

    std::cout << "\n[TEST 2] Consecutive Allocations, Invalid Deallocation\n";
    void *b = allocator.allocate(128);
    void *c = allocator.allocate(128);
    allocator.printStatus();

    allocator.deallocate(b); // should fail (not top)
    allocator.printStatus();

    allocator.deallocate(c); // should succeed
    allocator.printStatus();

    std::cout << "\n[TEST 3] Mark + Reset + Deallocation\n";
    size_t mark = allocator.mark();
    void *d = allocator.allocate(256);
    allocator.printStatus();

    allocator.reset(mark);
    allocator.printStatus();

    allocator.deallocate(d); // should fail (d was wiped by reset)
    allocator.printStatus();

    return 0;
}
