#include	<iostream>
#include	<thread>
#include <vector>
#include <atomic>

using namespace std;

#define THREAD_N 10000
#define LOOPED_N 10000

class Counter
{
	atomic<int> value;

	public:
		Counter() : value(0) {}
	
		void count()
		{
			int old = value.load();
			
			while(false == value.compare_exchange_weak(old, old+1))
				;
		}

		int get() {return value;}	
};

Counter counter;

void multiCount()
{
	int T = LOOPED_N;
	
	while(T--)
		counter.count();
}

int main(void)	
{
	vector<thread> t_arr;

	for(int i=0; i<THREAD_N; ++i)
		t_arr.emplace_back(multiCount);	
	
	for(int i=0; i<THREAD_N; ++i)
		t_arr[i].join();

	cout << "      " << THREAD_N * LOOPED_N << endl;
	cout << "ret = " << counter.get() << endl;
	return 0;
}

