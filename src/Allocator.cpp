#include "Allocator.hpp"
#include <iostream> // cerr
#include <cstdlib>  // malloc, free

using std::size_t;

// ──────────────────────────────────────────────────────────────────────────────
//   Allocator Lifecycle
// ──────────────────────────────────────────────────────────────────────────────

Allocator::Allocator(size_t size)
{
    memorySize = size;
    memoryStart = std::malloc(size);
    offset = 0;
    lastSize = 0;

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

// ──────────────────────────────────────────────────────────────────────────────
//   Allocation & Deallocation
// ──────────────────────────────────────────────────────────────────────────────

void *Allocator::allocate(std::size_t size)
{
    // align to 8 bytes
    size = (size + 7) & ~7;

    if (offset + size > memorySize)
    {
        return nullptr; // not enough memory left
    }

    void *ptr = static_cast<char *>(memoryStart) + offset;
    offset += size;
    lastSize = size;
    std::cout << "Allocating " << size << " bytes at offset " << offset << std::endl;
    return ptr;
}

void Allocator::deallocate(void *ptr)
{
    void *expected = static_cast<char *>(memoryStart) + (offset - lastSize);

    if (ptr == expected)
    {
        offset -= lastSize;
        lastSize = 0; // optional: zero out to invalidate
    }
    else
    {
        std::cerr << "[Allocator] Error: deallocate() called on non-top block.\n";
    }
}

// ──────────────────────────────────────────────────────────────────────────────
//   Diagnostics
// ──────────────────────────────────────────────────────────────────────────────

void Allocator::printStatus() const
{
    double used = static_cast<double>(offset);
    double total = static_cast<double>(memorySize);
    double percent = (used / total) * 100.0;

    std::cout << "[Allocator] Used: " << offset
              << " / " << memorySize
              << " bytes (" << percent << "%)\n";
}

// ──────────────────────────────────────────────────────────────────────────────
//   Stack Control (mark/reset)
// ──────────────────────────────────────────────────────────────────────────────

size_t Allocator::mark() const
{
    return offset;
}

void Allocator::reset(size_t mark)
{
    if (mark <= offset)
    {
        offset = mark;
    }
    // else: silently ignore bad reset (for now)
}
