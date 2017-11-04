/*
File: priorityQ.java
Author: Brejvinder Singh Dhillon
Course: 60-254
Task: Assignment 3
Objective: Interface to the implementation
Date created: 2017-11-02
Last revision: 2017-11-02
Revision: Documentation
 */
public interface priorityQ<T> {
	void enqueue(T item, int priority);

	T dequeue();

	T peek();

	void display();

	int size();

	boolean isFull();

	boolean isRegular();

	boolean isEmpty();
}
