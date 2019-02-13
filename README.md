# Parallel-and-Distributed-Systems
Projects/Notes from Marquette's class MSCS 6060 - Parallel and Distributed Systems. This class covers multithreading and programming processors in parallel.

### Thread Interference
Problems can occur when threads have shared variables/memory. This is also known as a race condition. This can be resolved using mutex lock/unlock around the code that read/writes the shared memory, allowing synchronization among threads.

### Compiling Programs into Executables
- C - gcc -o executable_name program_name.c
- C++ - g++ -o executable_name program_name.cpp -std=c++11
