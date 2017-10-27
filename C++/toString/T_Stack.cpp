#include "T_Stack.h"
#include <cstdio>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
Stack<T>::Stack() {
	size = 0;
}

template <typename T>
void Stack<T>::push(T n) {
	elements.push_back(n);
	size++;
}

template <typename T>
bool Stack<T>::empty() {
	if (size == 0) {
		return true;
	}
	return false;
}

template <typename T>
T Stack<T>::pop() {
	assert(size > 0);

	T tmp = elements[size - 1];
	elements.erase(elements.end());
	size--;

	return tmp;
}

template <typename T>
T Stack<T>::getTop() {
	assert(size > 0);

	return elements[size - 1];
}

template <typename T>
char* Stack<T>::to_string() {
	stringstream ss;

	for (int i = 0; i < size; i++) {
		ss << elements[i] << ' ';
	}

	char ret[1024];
	strcpy(ret, ss.str().c_str());

	return ret;
}

template <typename T>
ostream& operator<<(std::ostream &strm, const Stack<T> &s) {
	for (int i = 0; i < s.size(); i++) {
		strm << s[i] << " ";
	}

	return strm;
}
