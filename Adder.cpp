#include<stdio.h>
#include<thread>
#include<mutex>

using namespace std;

std::mutex add_mutex;
int global_sum = 0;

void add(int threadId, int *arr, int numberThreads, int N)
{
  int start = (threadId *N) / numberThreads;
  int end = ((threadId+1)*N) / numberThreads;
	int local_sum = 0;

	for(int i = start; i < end; i++)
	{
		local_sum = local_sum + arr[i];
	}
	printf("Thread Id = [%d], local sum = %d \n", threadId, local_sum);

	add_mutex.lock();
	global_sum = global_sum + local_sum;
	add_mutex.unlock();
}

int main(int argc, const char * argv[])
{
  const int size = 10000;
  int arr[size];

  for(int i=0; i<size; i++)
  {
    arr[i] = 1;
  }
	
  int numberThreads = 4;

  printf("Number of threads = [%d] \n", numberThreads);

  for(int i=0; i<numberThreads; i++)
  {
    thread t(add, i, arr, numberThreads, size);
    t.join();
  }

	printf("Final sum = %d \n", global_sum);
	return 0;
}
