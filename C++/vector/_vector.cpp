#include "_vector.h"

template <typename T>
vector<T>::vector() {
	data = new T[0];
	t_size = 0;
}

template <typename T>
vector<T>::vector(int s, T v) {
	data = new T[s];
	t_size = s;

	for (int i = 0; i < s; i++) {
		data[i] = v;
	}
}

template <typename T>
T* vector<T>::begin() {
	return t_size > 0 ? data : nullptr;
}

template <typename T>
T* vector<T>::end() {
	return t_size > 0 ? (data + t_size - 1) : nullptr;
}

template <typename T>
int vector<T>::size() {
	return t_size;
}

template <typename T>
void vector<T>::resize(int s) {
	T tmp = new T[s];
	for (int i = 0; i < s && i < t_size; i++) {
		tmp[i] = data[i];
	}

	delete[] data;
	data = new T[s];

	data = tmp;
	t_size = s;
}

template <typename T>
void vector<T>::resize(int s, T v) {
	int i = t_size;
	resize(s);
	if (s <= t_size) return;

	for ( ; i < t_size; i++) {
		data[i] = v;
	}
}

template <typename T>
bool vector<T>::empty() {
	return t_size == 0;
}

template <typename T>
T& vector<T>::at(int i) {
	return data[i];
}

template <typename T>
T& vector<T>::operator[](int i) {
	return at(i);
}

template <typename T>
T& vector<T>::front() {
	return t_size > 0 ? at(0) : nullptr;
}

template <typename T>
T& vector<T>::back() {
	return t_size > 0 ? at(t_size - 1) : nullptr;
}

template <typename T>
void vector<T>::push_back(T e) {
	resize(t_size + 1);
	back() = e;
}

template <typename T>
void vector<T>::insert(int l, T v) {
	push_back(v);
	swap(l, t_size - 1);
}

template <typename T>
int vector<T>::erase(int p) {
	if (p >= t_size || p < 0) return -1;

	for (int i = p; i < t_size + 1; i++) {
		data[p] = data[p + 1];
	}

	resize(t_size - 1);

	return 0;
}

template <typename T>
int vector<T>::erase(int p1, int p2) {
	if (p1 > p2 || p2 >= t_size || p1 < 0) return -1;

	for (int i = 0; i < p2 - p1 && p2 + i < t_size; i++) {
		data[p1 + i] = data[p2 + i];
	}

	resize(t_size - p2 - p1);

	return 0;
}

template <typename T>
void vector<T>::swap(int p1, int p2) {
	T tmp = data[p2];
	data[p2] = data[p1];
	data[p1] = tmp;
}

template <typename T>
void vector<T>::clear() {
	delete[] data;
	data = new T[0];
	t_size = 0;
}
