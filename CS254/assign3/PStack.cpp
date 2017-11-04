/*
 * Title:	PStack.cpp
 * Author:	Dilpreet S. Chana
 * Description:	Implementation of PStack class
**/

#include "PStack.h"
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

/*
 * Description:	Add queue with priority 5
 * Parameters:	T e: new element of type T
 * Returns:	void
**/
template <typename T>
void PStack<T>::enqueue(T e) {
	enqueue(e, 5);
}

/*
 * Description:	Add to queue with specified priority
 * Parameters:	T e: new element of type T
 *		Integer p: priority of element
 * Returns:	void
**/
template <typename T>
void PStack<T>::enqueue(T e, int p) {
	Node<T>* n = new Node<T>;

	n->data = new T;
	*(n->data) = e;

	n->priority = p;
	n->next = nullptr;
	n->prev = nullptr;

	// Empty queue
	if (!head || !tail) {
		head = n;
		tail = n;
		Size++;
		return;
	}

	Node<T>* curr = head;

	// Brej: Check for head and tail change
	// New head
	if (curr->priority <= p) {
		n->next = curr;
		curr->prev = n;
		head = n;

		Size++;
		return;
	}

	for (int i = 0; i < Size; i++) {
		// New tail
		if (!curr->next) {
			n->next = curr->next;
			curr->next = n;
			n->prev = curr;
			tail = n;

			Size++;
			break;
		}
		// Insert
		else if (curr->next->priority <= p) {
			n->next = curr->next;
			curr->next->prev = n;
			curr->next = n;
			n->prev = curr;

			Size++;
			break;
		}
		curr = curr->next;
	}
}

/*
 * Description:	Remove highest priority element and return
 * Parameters:	void
 * Returns:	Pointer to highest priority element
**/
template <typename T>
T* PStack<T>::dequeue() {
	if (Size == 0) return nullptr;

	T* ret = peek();
	delete[] tail->data;
	tail = tail->prev;;
	Size--;
	
	return ret;
}

/*
 * Description:	Return highest priority element
 * Parameters:	void
 * Returns:	Pointer to highest priority element
**/
template <typename T>
T* PStack<T>::peek() {
	if (Size == 0) return nullptr;

	return tail->data;
}

/*
 * Description:	Get size of queue
 * Parameters:	void
 * Returns:	Size of queue
**/
template <typename T>
int PStack<T>::size() {
	return Size;
}

/*
 * Description:	Determine if queue has uniform priority
 * Parameters:	void
 * Returns:	true if all elements have same priority
 *		false if not
**/
template <typename T>
bool PStack<T>::isRegular() {
	if (Size == 0) return true;
	return head->priority == tail->priority;
}

/*
 * Description:	Determine if queue is empty
 * Parameters:	void
 * Returns:	true if queue is empty
 *		false if not
**/
template <typename T>
bool PStack<T>::empty() {
	return Size == 0;
}

/*
 * Description:	Get printable version of queue
 * Parameters:	void
 * Returns:	string of queue
**/
template <typename T>
char* PStack<T>::toString() {
	stringstream ss;

	Node<T>* curr = tail;
	for (int i = 0; i < Size - 1; i++) {
		if (!curr) break;

		//cout << *(curr->data) << " " << curr->priority << endl;
		ss << "Data: " << *(curr->data) << ", Priotity: " << curr->priority << "\n";

		curr = curr->prev;
	}
	ss << "Data: " << *(head->data) << ", Priotity: " << head->priority;

	char* ret = new char[ss.str().size()];
	strcpy(ret, ss.str().c_str());

	return ret;
}
