#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

mutex mt;

void fn(int idx)
{
	for(int i=0; i<10; ++i)
	{
		mt.lock();
		cout << idx << endl;
		mt.unlock();
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

