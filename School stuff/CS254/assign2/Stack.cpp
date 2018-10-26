#include "Stack.h"
#include <cstdio>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

template <class T>
Stack<T>::Stack() {
	size = 0;
}

template <class T>
void Stack<T>::push(T n) {
	elements.push_back(n);
	size++;
}

template <class T>
bool Stack<T>::empty() {
	if (size == 0) {
		return true;
	}
	return false;
}

template <class T>
T Stack<T>::pop() {
	assert(size > 0);

	T tmp = elements[size - 1];
	elements.erase(elements.end());
	size--;

	return tmp;
}

template <class T>
T Stack<T>::getTop() {
	assert(size > 0);

	return elements[size - 1];
}

template <class T>
char* Stack<T>::to_string() {
	stringstream ss;

	for (int i = 0; i < size; i++) {
		ss << elements[i] << ' ';
	}

	char ret[1024];
	strcpy(ret, ss.str().c_str());

	return ret;
}

template <class T>
friend std::ostream& operator Stack<T>::<<(std::ostream &strm, const Stack &s) {
	return strm << to_string;
}
