# Parallel-and-Distributed-Systems
Projects/Notes from Marquette's class MSCS 6060 - Parallel and Distributed Systems. This class covers multithreading and programming processors in parallel.

### Thread Interference
Problems can occur when threads have shared variables/memory. This is also known as a race condition. This can be resolved using mutex lock/unlock around the code that read/writes the shared memory, allowing synchronization among threads.

### Processes vs. Threads
A Process is a program in execution. A thread is a context of execution, which can be executed in parallel. Therefore, a process can have one or many threads. 
- Processes cannot share information, so they must use message passing
- Threads are light-weight, processes are not b/c context switching is expensive

### Compiling Programs into Executables
- C - gcc -o executable_name program_name.c
- C++ - g++ -o executable_name program_name.cpp -std=c++11
- MPI C - mpicc -o mpihello mpihello.c
  - mpiexec -np 8 ./mpihello // np is number of processes (must specify at startup)
