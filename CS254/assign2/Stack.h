#ifndef STACK_H
#define STACK_H

#include <vector>
#include <assert.h>

template <class T>
class Stack {
private:
	std::vector<T> elements;
	int size;

public:
	Stack();
	void push(T n);
	bool empty();
	T pop();
	T getTop();
	char* to_string();
};

#endif
