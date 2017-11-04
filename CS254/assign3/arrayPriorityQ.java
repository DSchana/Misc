/*
File: arrayPriorityQ.java
Author: Brejvinder Singh Dhillon
Review Partner: Dilpreet S Chana
Course: 60-254 Data Structures and Algorithms
Task: Assignment 3 (Array implementation)
Objective: Implement an abstract data type called a Priority Que
Date created: 2017-10-27
Last revision: 2017-11-02
Revision: Formatting and commenting

A Note on Implementation:
This Implementation is primarily based on simplicity.
Efficiency is also a major factor , being implemented to the best of my ability.
a) 2 Generic arrays are used to store item and priority
b) Que isnt circular
	i)  Don't need to track the head and/or tail
	ii) Simplifies insertion, printing and deletion 
	iii)Reduces overhead as much as possible since 
		we are dealing with 2 arrays
c) 
 */
public class arrayPriorityQ<T> implements priorityQ<T> {
	// Dillpreet: Add interface instead of just calling the implementation
	private int maxSize;
	private T[] queueArray;
	private int[] priArray;
	private int numItems;
	private int defaultPriority;

	// Constructor
	@SuppressWarnings("unchecked")
	public arrayPriorityQ(int size) {
		maxSize = size;
		queueArray = (T[]) new Object[maxSize];
		priArray = new int[maxSize];
		numItems = 0;
		defaultPriority = 5;
	}

	// Simply call enqueue with the default priority
	public void enqueue(T item) {
		enqueue(item, defaultPriority);
	}

	// O(n) : Priority given
	public void enqueue(T item, int priority) {
		if (!isFull()) {
			int j;

			if (isEmpty()) {
				queueArray[numItems] = item;
				priArray[numItems++] = priority;
			} else {
				for (j = numItems - 1; j >= 0; j--) {
					if (priority >= priArray[j]) {
						queueArray[j + 1] = queueArray[j];
						priArray[j + 1] = priArray[j];
					} else {
						break;
					}
				} // End for
				queueArray[j + 1] = item;
				priArray[j + 1] = priority;
				numItems++;
			}
		} else {
			fullError();
		}
	}

	// O(1)
	public T dequeue() {
		if (!isEmpty()) {
			return queueArray[--numItems];
		} else {
			emptyError();
			return null;
		}
	}

	public T peek() {
		if(!isEmpty()) {
		return queueArray[numItems - 1];
		}
		else {
			emptyError();
			return null;
		}
	}

	public int size() {
		return numItems;
	}

	// Simply check the last item , if there is one item then its regular
	// Dillpreet: Include the edge case for when numItems = 1
	public boolean isRegular() {
		if (!isEmpty()) {
			if (numItems == 1) {
				return true;
			} else {
				return (priArray[0] == priArray[numItems - 1]);
			}
		}
		emptyError();
		return true;
	}

	public boolean isEmpty() {
		return (numItems == 0);
	}

	public boolean isFull() {
		return (numItems == maxSize);
	}

	// O(n)
	public void display() {
		for (int i = numItems - 1; i >= 0 && !isEmpty(); i--) {
			System.out.println("Element : " + queueArray[i] + " Priority: " + priArray[i]);
		}
	}

	public void fullError() {
		System.out.println("Error: Priority Q is full");
	}

	public void emptyError() {
		System.out.println("Error: Priority Q is empty");
	}
	
	public void newDefaultPriority(int priority) {
		defaultPriority = priority;
	}
}
/*
 * A note on deletion of item from arrays(dequeueing): Dilpreet suggested that I
 * delete the value of the item once its dequeued. However, this isnt necesarry as
 * the queue isn't a circular queu and extra deletion would add to the overhead.
 * Items are only accecible up to the registered number of items.
 */