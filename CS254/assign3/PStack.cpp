#include "PStack.h"

using namespace std;

template <class T>
std::ostream& operator PStack::<<(std::ostream &strm, const PStack &s) {
	for (int i = 0; i < size - 1; i++) {
		strm << elements[i] << "; "
	}

	return strm << elements[size - 1];
}
