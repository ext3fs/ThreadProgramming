#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

mutex m;
condition_variable cv;
int condition = 0;

void foo()
{
	//auto fn = []{return condition == 1;};
	unique_lock<mutex> lock(m);
	cv.wait(lock, []{return condition == 1;});
	lock.unlock();
}

int main(void)	
{
	thread t1(foo);

	{
		scoped_lock lock(m);
		condition = 1;
	}

	cv.notify_one();
	t1.join();
	return 0;
}

