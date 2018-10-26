/*
 * Title:	PStack.h
 * Author:	Dilpreet S. Chana
 * Description:	Generic class of priority queue
**/

// Berj: Comment ya scrub
#ifndef P_STACK_H
#define P_STACK_H

#include <iostream>

template <typename T>
struct Node {
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
	char* toString();
};

/*
 * Description:	Overoad << operator for streams
 * Parameters:	ostream strm: cout stream
 *		PStack s: queue to print
 * Returns:	Stream with strng of s
**/
template <typename T>
std::ostream& operator<<(std::ostream& os, PStack<T>& s) {
	os << s.toString();
	return os;
}

#endif
