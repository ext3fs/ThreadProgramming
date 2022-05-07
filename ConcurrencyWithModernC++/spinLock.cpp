#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

class Spinlock
{
	atomic_flag flag;

public:
	Spinlock() : flag(ATOMIC_FLAG_INIT) {}

	void lock() {while(flag.test_and_set());}	
	void unlock() {flag.clear();}	
};

Spinlock spin;

void fn(int idx)
{
	for(int i=0; i<10; ++i)
	{
		spin.lock();
		cout << idx << endl;
		spin.unlock();
	}
}

int main(void)	
{
	thread t1(fn,1);
	thread t2(fn,2);
	t1.join();
	t2.join();
	return 0;
}

