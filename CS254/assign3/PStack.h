#ifndef P_STACK_H
#define P_STACK_H

#include <iostream>

template <typename T>
struct Node<T> {
	T* data;
	int priority;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T>
class PStack {
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int Size = 0;

public:
	void enqueue(T e);
	void enqueue(T e, int p);
	T* dequeue();
	T* peek();
	int size();
	bool isRegular();
	bool empty();
	friend std::ostream& operator <<(std::ostream &strm, const PStack &s);
};

#endif
