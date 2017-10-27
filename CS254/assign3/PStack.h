#ifndef P_STACK_H
#define P_STACK_H

#include <vector>
#include <iostream>

template <class T>
class PStack {
private:
	std::vector<T> elements;
	int size;

public:
	PStack();
	void push(T e);
	void push(T e, int p);
	T pop();
	T getTop();
	bool empty();
	std::ostream& operator <<(std::ostream &strm, const PStack &s);
};
