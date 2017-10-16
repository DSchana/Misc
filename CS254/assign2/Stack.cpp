#include <Stack.h>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

Stack::Stack() {
	size = 0;
}

void Stack::push(T n) {
	elements.push_back(n);
	size++;
}

T Stack::pop() {
	if (size > 0) {
		T tmp = elements[size - 1];
		elements.erase(elements.end());
		size--;

		return tmp;
	}

	return NULL;
}

T Stack::getTop() {
	if (size > 0) {
		return elements[size - 1];
	}

	return NULL;
}

char* Stack::to_string() {
	stringstream ss;

	for (int i = 0; i < size; i++) {
		ss << elements[i] << ' ';
	}

	return ss.str().c_str();
}
