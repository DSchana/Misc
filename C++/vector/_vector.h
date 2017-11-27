#ifndef _VECTOR_H
#define _VECTOR_H

template <typename T>
class vector {
private:
	T* data;
	int t_size;

public:
	// Constructor
	vector();  // Empty constructor
	vector(int s, T v);  // Fill constructor

	// Iterators
	T* begin();
	T* end();

	// Capacity
	int size();
	void resize(int s);
	void resize(int s, T v);
	bool empty();

	// Element access
	T& operator[](int i);
	T& at(int i);
	T& front();
	T& back();

	// Modifiers
	void push_back(T e);
	T pop_back();
	void insert(int l, T v);
	int erase(int p);
	int erase(int p1, int p2);
	void swap(int p1, int p2);
	void clear();
};

#endif
