#ifndef STACK_H
#define STACK_H

#include <vector>

template <class T>
class Stack {
private:
	std::vector<T> elements;
	int size;

public:
	Stack();
	void push(T n);
	T pop();
	T getTop();
	char* to_string();
};

#endif
