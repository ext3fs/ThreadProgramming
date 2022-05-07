#include <iostream>
using namespace std;

int main(void)	
{
	//compile 단계에서 에러
	static_assert(sizeof(int)==8, "int is 8byte");

	cout << "hellow, world!!" << endl;
	return 0;
}

