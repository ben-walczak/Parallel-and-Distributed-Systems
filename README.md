# Parallel-and-Distributed-Systems
Projects/Notes from Marquette's class MSCS 6060 - Parallel and Distributed Systems. This class covers multithreading and programming processors in parallel.

### Difference between Parallel and Concurrent Processes
Work in progress

### Thread Interference
Problems can occur when threads have shared variables/memory. This is also known as a race condition. This can be resolved using mutex lock/unlock around the code that read/writes the shared memory, allowing synchronization among threads.

### Processes vs. Threads
A Process is a program in execution. A thread is a context of execution, which can be executed in parallel. Therefore, a process can have one or many threads. 
- Processes cannot share information, so they must use message passing
- Threads are light-weight, processes are not b/c context switching is expensive

### Memory System Performance
- Memory Wall = fetching memory is the biggest bottleneck in system performance
- Memory system performance is affected by latency and bandwith
- Latency = time of fetching memory to time data is in processor (time)
- Bandwith = rate of data that can be pumped into processor (data/time

### Caches and Latency
- Caches are a fast intermediate memory source, where memory that is repeatedly accessed is stored
- Hit Ratio = fraction of data that is successfully retrieved from cache

### Utilizing Cache for Performance
summing columns of a matrix
```c++
for ( i = 0; i < 1000; i++)
  column_sum[i] = 0.0;
  for ( j = 0; j < 1000; j++)
    column_sum[i] += b[j][i];
```
is slower than...
```c++
for (i = 0; i < 1000; i++)
  column_sum[i] = 0.0;
for (j = 0; j < 1000; j++)
  for (i = 0; i < 1000; i++)
    column_sum[i] += b[j][i];
```
this is an example of utlizing spatial locality

### Spatial and Temporal Activity
spatial locality = tendency of a processor to access the same set of memory locations repetitively over a short period of time
Linked Lists or Arrays?
... arrays are faster because
- linked list memory locations can be far and wide apart, which slows down fetch time or latency
- arrays are stored in the same memory block, which speeds up fetch time or latency

### Pipelining
- Optimizes instruction execution to run in parallel
- One instruction can be executed, while another is decoded
- FEMW is implemented in parallel to optimize assembly code
- FEMW = fetch, execute, memory, write

### Superscalar Execution
- Data dependencies can often waste time, to circumvent this instructions can be issued out-of-order
- True Data Dependency: The result of one operation is an input to the next. 
- Resource Dependency: Two operations require the same resource. 
- Branch Dependency: Scheduling instructions across conditional branch statements cannot be done deterministically a-priori. 
- The scheduler, a piece of hardware looks at a large number of instructions in an instruction queue and selects appropriate number of instructions to execute concurrently based on these factors. 


### Compiling Programs into Executables
- C - gcc -o executable_name program_name.c
- C++ - g++ -o executable_name program_name.cpp -std=c++11
- MPI C - mpicc -o mpihello mpihello.c OR /opt/openmpi/bin/mpicc -o mpihello mpihello.c
  - mpiexec -np 8 ./mpihello // np is number of processes (must specify at startup)
