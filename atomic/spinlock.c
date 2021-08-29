#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <atomic>

using namespace std;
using namespace chrono;


//atomic<int> sum(0);
volatile int sum = 0;
mutex mylock;
volatile bool locking[2] = {false, false};
volatile int victim = 0;
//atomic<bool> locking[2] = {false, false};
//atomic<int> victim = 0;


void p_lock(int myid)
{
	int other = 1 - myid;

	locking[myid] = true;
	//__asm__ __volatile__("mfence":::"memory");
	atomic_thread_fence(memory_order_seq_cst);
	victim = myid;
	while((true == locking[other]) && victim == myid)
		;
}

void p_unlock(int myid)
{
	locking[myid] = false;
}

void work(int thr_num, int myid)
{
	for(int i=0; i<50000000/thr_num; ++i)
	{
	//	mylock.lock();
		p_lock(myid);
	//	sum.fetch_add(2);
		sum += 2;
		p_unlock(myid);
	//	mylock.unlock();
	}
}

int main(void)	
{
	for(int thr_num=1; thr_num<=2; thr_num*=2)
	{
		sum = 0;
		vector<thread> thr;
		
		auto start_time = high_resolution_clock::now();
		
		for(int i=0; i<thr_num; ++i)
			thr.emplace_back(work, thr_num, i);
			
		for(auto &e : thr)
			e.join();

		auto end_time = high_resolution_clock::now();
		
		thr.clear();
		auto exec_time = end_time - start_time;
		double exec_ms = duration_cast<milliseconds>(exec_time).count()/(double)1000;
		cout << "thr_num = " << thr_num << " sum = " << sum << " time = "<< exec_ms << "\n";
	}
	return	0;
}

