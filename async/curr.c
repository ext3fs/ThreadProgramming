#include <iostream>
#include <future>

using namespace std;

int foo()
{
	return 7;
}

int main(void)	
{
	//async -> thread create
	auto a1 = async(launch::async, foo);
	cout << a1.get() << endl;
	
	//a2.get() -> thread create
	auto a2 = async(launch::deferred, foo);
	cout << a2.get() << endl;

	return 0;
}

