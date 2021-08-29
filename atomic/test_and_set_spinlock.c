#include <iostream>
#include <thread>
#include <vector>
#include <atomic>

using namespace std;

#define THREAD_N 10
#define LOOPED_N 9999999

class Counter
{
	atomic_flag flag;
	int value;

	public:
		Counter() : value(0) {}
	
		void count()
		{
			while(flag.test_and_set())
				;
			value	+= 1;
			flag.clear();
		}

		int get() {return value;}	
};

Counter	counter;

void multiCount()
{
	int T = LOOPED_N;
	while(T--)
		counter.count();
}

int main(void)	
{
	vector<thread>	t_arr;

	for(int i=0; i<THREAD_N; ++i)
		t_arr.emplace_back(multiCount);	
	
	for(int i=0; i<THREAD_N; ++i)
		t_arr[i].join();

	cout << "desired : " << THREAD_N * LOOPED_N << endl;
	cout << "return  : " << counter.get() << endl;
	return 0;
}

