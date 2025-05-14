#ifndef ALLOCATOR_HPP // "If this macro hasn't been defined yet..."
#define ALLOCATOR_HPP // "...define it now to mark it as included."

#include <cstddef>
using std::size_t;

class Allocator
{
public:
    Allocator(size_t size); // constructor
    ~Allocator();           // deconstructor. runs when the object is destroyed

    // memory operations
    void *allocate(size_t size); // aligned stack allocation
    void deallocate(void *ptr);  // only frees most recent block

    size_t mark() const;     // save the stack position
    void reset(size_t mark); // roll back to a mark

    // diagnostics
    void printStatus() const;

private:
    void *memoryStart;
    size_t memorySize;
    std::size_t offset;   // tracks top of the stack
    std::size_t lastSize; // size of the most recently allocated block
};

#endif // ALLOCATOR_HPP ← "...end the guard."
