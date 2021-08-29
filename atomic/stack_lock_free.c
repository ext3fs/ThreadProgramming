#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
using namespace std;

template <typename T>
struct node
{
	T data;
	node* next;
	node(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class stack
{
	atomic<node<T>*> head;
	public:
		void push(const T& data)
		{
			node<T>* new_node = new node<T>(data);

			new_node->next = head.load();

			while(false == head.compare_exchange_weak(new_node->next, new_node))
				;
		}
};

int main(void)	
{
	stack<int> stk;

	stk.push(1);
	return 0;
}

