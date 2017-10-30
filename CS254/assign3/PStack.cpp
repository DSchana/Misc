#include "PStack.h"

using namespace std;

template <typename T>
void PStack::enqueue(T e) {
	enqueue(e, 5);
}

template <typename T>
void PStack::enqueue(T e, int p) {
	Node* n;
	n->data = e;
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

	Node* curr = head;
	for (int i = 0; i < Size - 1; i++) {
		if (!curr->next) {
			n->next = curr->next;
			curr->next = n;
			n->prev = curr;

			Size++;
			break;
		}
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

template <typename T>
T* PStack::dequeue() {
	if (Size == 0) return nullptr;

	T ret = peek();
	tail = tail->prev;;
	Size--;
	
	return ret;
}

template <typename T>
T* PStack::peek() {
	if (Size == 0) return nullptr;

	return tail->data;
}

template <typename T>
int PStack::size() {
	return Size;
}

template <typename T>
bool PStack::isRegular() {
	if (Size == 0) return true;
	return head->priority == tail->priority;
}

template <typename T>
bool PStack::empty() {
	return Size == 0;
}

template <typename T>
std::ostream& operator <<(std::ostream &strm, const PStack &s) {
	for (Node* curr = head; !(curr->next->next); curr = curr->next) {
		strm << "Data: " << *(curr->data) << ", Priotity: " << curr->priority << endl;
	}

	return strm << "Data: " << *(tail->data) << ", Priotity: " << tail->priority;
}
