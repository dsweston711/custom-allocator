# Custom Allocator

This project mimics one of the assignments I had in CS 354, wherein we studied and emulated an allocator.

---

# Current understanding and brief introduction of files

## `Allocator.hpp`

- `Allocator` is the class that owns and manages a chunk of raw memory
- `memoryStart` points to the beginning of the memory pool
- `memorySize` stores its total size in bytes
- `allocate()` will eventually simulate `malloc`
- `deallocate()` will simluate `free`

And so, this will be a manual heap.

## `Allocator.cpp`

regarding constructor/deconstructor logic

- uses `malloc` to grab one raw block of memory
- this is now your heap simulation
- later, we'll carve this into blocks with headers and footers

### rest of the file

- meat of the allocator; traverse memory, check size and metadata, return a pointer to usable space, mark blocks as free or used, coalesce adjacent free blocks

## `main.cpp`

- testing usage
- creates an allocator object with a fixed memory size
- this will be the test harness througout this project

## makefile

- self explanatory
