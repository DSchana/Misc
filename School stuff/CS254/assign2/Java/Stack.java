/*
 * Title:	Stack.java
 * Author:	Dilpreet S. Chana
 * A General Stack ADT using ArrayList
**/

import java.util.*;

public class Stack<T>{
	private ArrayList<T> nodes;
	private T top;
	private int size;

	// Constructor
	public Stack(){
		nodes = new ArrayList<T>();
		top = null;
		size = 0;
	}

	public T getTop(){
		return top;
	}

	public void push(T node){
		nodes.add(node);
		top = nodes.get(size);
		size ++;
	}
	public T pop(){
		T tmp = top;

		if(size > 0){
			nodes.remove(size - 1);
			size --;

			if(size > 0) top = nodes.get(size - 1);
			else top = null;
		}
		return tmp;
	}

	@Override
	public String toString(){
		String val = "";

		for(T cur : nodes){
			val += cur.toString() + " ";
		}
		return val;
	}
}
