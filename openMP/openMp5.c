#include <iostream>
#include <omp.h>

using namespace std;

const int kcnt = 1e6;
int c[kcnt];

int main(void)	
{
	int a[kcnt];
	int b[kcnt];
	long long sum = 0;

	#pragma omp parallel num_threads(4)
	{
		for(int i=0; i<kcnt; ++i)
			c[i] = a[i] + b[i];

		#pragma omp critical	
		for(int i=0; i<kcnt; ++i)
			sum += c[i];
	}
	cout << sum << endl;	
	return 0;
}

