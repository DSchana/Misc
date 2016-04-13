// HashTable.java
// Dilpreet Chana
// Class implements basic HashTable data structure
// which has O(1) look up time.

import java.util.*;

public class HashTable<T> {
	private ArrayList<LinkedList<T>> table;
	private int size;
	private double maxLoad;

	public HashTable() {
		size = 0;
		maxLoad = 0.7;
		table = blank(10);
	}

	// Add new value to HashTable based on hashCode
	public void add(T val) {
		int h = Math.abs(val.hashCode());
		int pos = h % table.size();

		if (table.get(pos) == null) {
			table.set(pos, new LinkedList<T>());
		}
		table.get(pos).add(val);
		size++;

		if ((double)size / table.size() > maxLoad) {
			resize();
		}
	}

	// Remove value from HashTable based on hashCode
	public void remove(T val) {
		int h = Math.abs(val.hashCode());
		int pos = h % table.size();

		if (table.get(pos) != null) {
			if (table.get(pos).remove(val)) {
				size--;
			}
		}
	}

	// Return item from HashTable with specified hashCode
	public T get(int key) {
		int pos = Math.abs(key) % table.size();
		LinkedList<T> itemList = table.get(pos);

		if (itemList == null)
			return null;

		for (T item : itemList) {
			if (Math.abs(item.hashCode()) == key)
				return item;
		}
		return null;
	}

	// Return the current load of HashTable
	public float getLoad() {
		return (float)size/table.size();
	}

	// Return elements of HashTable in array
	public ArrayList<T> toArray() {
		ArrayList<T> ret = new ArrayList<T>();
		for (LinkedList<T> itemList : table) {
			if (itemList != null) {
				for (T item : itemList) {
					ret.add(item);
				}
			}
		}
		return ret;
	}

	public String toString() {
		String ans = "{ ";
		for (LinkedList<T> lst : table) {
			if (lst != null) {
				for (T val : lst) {
					ans += val + ", ";
				}
			}
		}
		if (ans.length() > 2) {
			ans = ans.substring(0, ans.length()-2);
		}
		return ans + " }";
	}

	// Create new blank table of size n
	public ArrayList<LinkedList<T>> blank(int n) {
		ArrayList<LinkedList<T>> tmp = new ArrayList<LinkedList<T>>();
		for (int i = 0; i < n; i++) {
			tmp.add(null);
		}
		return tmp;
	}

	public void resize() {
		ArrayList<LinkedList<T>> tmp = table;
		table = blank(size * 2);
		size = 0;
		for (LinkedList<T> lst : table) {
			if (lst != null) {
				for (T val : lst) {
					add(val);
				}
			}
		}
	}

	public void resize(int s) {
		ArrayList<LinkedList<T>> tmp = table;
		table = blank(s);
		size = 0;
		for (LinkedList<T> lst : table) {
			if (lst != null) {
				for (T val : lst) {
					add(val);
				}
			}
		}
	}

	public void setMaxLoad(int l) {
		if (l < 0.1 || l > 0.8)
			return;
		maxLoad = l;
	}

	// Resize table so it as specified load
	public void setLoad(float l) {
		if (l < 0.1 || l > 0.8 || l > maxLoad) {
			return;
		}

		resize((int)((float)size/l));
	}
}