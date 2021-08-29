#include <iostream>
#include <vector>
using namespace std;

const int kcnt = 2e9;

__global__ void add(int, float* x, float* y, float* z)
{
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	
	if(i < n)
		z[i] = x[i] + y[i];
}

int main(void)	
{
	vector<int> x(kcnt, 1);
	vector<int> y(kcnt, 2);
	vector<int> z(kcnt);
	long long sum = 0;

	float *divice_x, *divice_y, *divice_z;
	cudaMalloc(&divece_x, kcnt * sizeof(float));
	cudaMalloc(&divece_y, kcnt * sizeof(float));
	cudaMalloc(&divece_z, kcnt * sizeof(float));

	cudaMemcpy(divice_x, x.data(), kcnt*sizeof(float), cudaMemcpyHostToDivice);
	cudaMemcpy(divice_y, y.data(), kcnt*sizeof(float), cudaMemcpyHostToDivice);

	add<<<1,kcnt>>>(divice_x, divice_y, divice_z, kcnt);
	cudaMemcpy(z.data(), divice_z, kcnt*sizeof(float), cudaMemcpyDivideToHost);

	for(int i=0; i<kcnt; ++i)
		sum += z[i];		
	
	cout << sum << endl;	
	return 0;
}

