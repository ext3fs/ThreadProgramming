#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int crntScore;
mutex gMutex;

void add(int val)
{
	{
		//c++17 RAII
		scoped_lock lock(gMutex);
		crntScore += val;
	}//mutex unlock 

	cout << "add done" << endl;
}

int main(void)	
{
	thread t1(add, 5);
	thread t2(add, -10);
	return 0;
}

