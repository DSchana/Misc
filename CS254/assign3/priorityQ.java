/*
 * Author: Brejvinder
 * priorityQ.java
 */
public class priorityQ<T> {
	private int maxSize;
	private T[] queArray;  // SUGGESTION: Do with segmented array
	private int[] priArray;
	private int numItems;

	//Constructor
	@SuppressWarnings("unchecked")
	public priorityQ(int size) {
		maxSize = size;
		queArray = (T[]) new Object[maxSize];
		priArray = new int[maxSize];
		numItems = 0;
	}

	//Priority given
	public void enque(T item, int priority) {
		if (!isFull()) {
			int j;

			if (isEmpty()) {
				queArray[numItems] = item;
				priArray[numItems++] = priority;
			} else {
				for (j = numItems - 1; j >= 0; j--) {
					if (priority >= priArray[j]) {
						queArray[j + 1] = queArray[j];
						priArray[j + 1] = priArray[j];
					} else {
						break;
					}
				} // End for
				queArray[j + 1] = item;
				priArray[j + 1] = priority;
				numItems++;
			}
		} else {
			System.out.println("PriorityQ is Full");
		}
	}

	//When priority not given it automatically set to 5, the lowest priority
	public void enque(T item) {  // NOTE: Call enque(item, 5)
		enqueue(item, 5);

		int priority = 5;
		if (!isFull()) {
			int j;

			if (isEmpty()) {
				queArray[numItems] = item;
				priArray[numItems++] = priority;
			} else {
				for (j = numItems - 1; j >= 0; j--) {
					if (priority >= priArray[j]) {
						queArray[j + 1] = queArray[j];
						priArray[j + 1] = priArray[j];
					} else {
						break;
					}
				} // End for
				queArray[j + 1] = item;
				priArray[j + 1] = priority;
				numItems++;
			}
		} else {
			System.out.println("PriorityQ is Full");
		}
	}

	public T deque() {
		return queArray[--numItems];
	}

	public T peek() {
		return queArray[numItems - 1];
	}

	public int size() {
		return numItems;
	}

	public boolean isRegular() {
		// NOTE: Since the list is sorted by priority, if the first and last
		//	 priorities match, it implies everything in between has the
		//	 same priority.

		if (!isEmpty()) {
			for (int i = 1; i < priArray.length; i++) {
				if (priArray[0]!=priArray[i])
					return false;
			}
			return true;
		}
		System.out.println("Array is empty");
		return true;
	}

	public boolean isEmpty() {
		return (numItems == 0);
	}

	public boolean isFull() {
		return (numItems == maxSize);
	}

	public void display() {
		for (int i = numItems - 1; i >= 0; i--) {
			System.out.println("Element : " + queArray[i] + " Priority: " + priArray[i]);
		}
	}
}
