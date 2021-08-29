#include <iostream>
#include <omp.h>

using namespace std;

int main(void)	
{	
	#pragma omp parallel
	{
		cout << "hello"<< endl;
	}

	return 0;
}

