/*
 * Title:	Assign2.java
 * Author:	Dilpreet S. Chana
 * Description:	This program starts by recieving n lines of infix equations from a text file.
 * 		It then checks that they're valid. These equations are converted to postfix,
 * 		then are evaluated. This is done by using a Stack ADT to both convert and evaluate
 * 		the equations. Also, every time the stack is pushed or popped, the stack is printed.
**/

import java.util.*;
import java.io.*;

public class Assign2 {
	public static void main(String[]args) throws IOException {

		ArrayList<String> eqns = new ArrayList<String>();
		Scanner input = new Scanner(new BufferedReader(new FileReader("input.txt")));

		// Reads the input file
		while (input.hasNextLine()) {
			eqns.add(input.nextLine());
		}
		input.close();

		// Validates all of the equations
		for (String s : eqns) {
			String[] tokens = s.split(" ");

			String last = "";
			String newInf = "";
			int bracketCount = 0;
			boolean invalid = false;

			for (int i=0; i<tokens.length; i++) {
				String t = tokens[i];

				// When the unary negation operator is found, it is changed to a unique character different from the minus sign
				if (t.equals("-") && (i == 0 || getPri(last) > 0) && !last.equals(")")) {
					newInf = newInf + "~ ";
					last = t;
				}
				else {
					if (t.equals("(")) bracketCount ++;
					else if (t.equals(")")) bracketCount --;

					if ((i != 0 && ((getPri(last) > 0 && getPri(t) > 0 && getPri(last) < 5 && getPri(t) < 5) || (getPri(last) == 0 && getPri(t) == 0))) || bracketCount < 0){
						System.out.println("Invalid Operation");
						invalid = true;
					}
					else {
						newInf = newInf + "" + t + " ";
						last = t;
					}
				}
			}

			if(bracketCount != 0) {
				System.out.println("Invalid Infix Operation");
				invalid = true;
			}

			// Proceeds to the conversion to postfix if the eqn is valid
			if (!invalid) {
				String[] tokens2 = newInf.split(" ");
				Stack<String> ops = new Stack<String>();
				String post = "";

				System.out.println("Operators stack: " + ops);

				// Converts to postfix
				for (String tok : tokens2) {
					int pri = getPri(tok);

					if (pri > 0) {
						String top = ops.getTop();

						if (top != null) {
							int topPri = getPri(top);

							if (top.equals("~") && tok.equals("~")) {
								System.out.println("Operators stack: " + ops);
								ops.push(tok);
								System.out.println("Operators stack: " + ops);
							}
							else if (pri <= topPri && topPri != 5) {
								System.out.println("Operators stack: " + ops);
								post = post + ops.pop() + " ";
								System.out.println("Operators stack: " + ops);

								top = ops.getTop();
								if(ops.getTop() != null) topPri = getPri(top);
								while(pri < topPri &&  ops.getTop() != null && topPri != 5){
									post = post + ops.pop() + " ";
									System.out.println("Operators stack: " + ops);
								}
								ops.push(tok);
								System.out.println("Operators stack: " + ops);
							}
							else if(tok.equals(")")){
								System.out.println("Operators stack: " + ops);
								while(!ops.getTop().equals("(")){
									post = post + ops.pop() + " ";
									System.out.println("Operators stack: " + ops);
								}
								ops.pop();
								System.out.println("Operators stack: " + ops);
							}
							else{
								System.out.println("Operators stack: " + ops);
								ops.push(tok);
								System.out.println("Operators stack: " + ops);
							}
						}
						else{
							System.out.println("Operators stack: " + ops);
							ops.push(tok);
							System.out.println("Operators stack: " + ops);
						}
					}
					else{
						post = post + tok + " ";
					}
				}
				System.out.println("Operators stack: " + ops);
				while(ops.getTop() != null){
					post = post + ops.getTop() + " ";
					ops.pop();
					System.out.println("Operators stack: " + ops);
				}

				System.out.println(post + "\n");


				String[] tokens3 = post.split(" ");
				Stack<Integer> nums = new Stack<Integer>();

				System.out.println("Nums stack: " + nums);

				// Evaluates the postfix operation
				for(String tok : tokens3){
					if(getPri(tok) == 0){
						nums.push(Integer.parseInt(tok));
						System.out.println("Nums stack: " + nums);
					}
					else{
						int newNum;
						if(tok.equals("~")){
							System.out.println("Nums stack: " + nums);
							int n1 = nums.pop();
							newNum = -1 * n1;
						}
						else{
							System.out.println("Nums stack: " + nums);
							int n1 = nums.pop();
							System.out.println("Nums stack: " + nums);
							int n2 = nums.pop();
							newNum = eval(n1, n2, tok);
						}
						System.out.println("Nums stack: " + nums);
						nums.push(newNum);
						System.out.println("Nums stack: " + nums);
					}
				}

				System.out.println("Answer: " + nums.getTop() + "\n");
			}
		}
	}

	// Returns the priority of a operator
	public static int getPri(String op){
		String[] pri1 = {"+" , "-"};
		String[] pri2 = {"*" , "/"};
		String[] pri3 = {"~"};
		String[] pri4 = {"^"};
		String[] pri5 = {"(" , ")"};

		if(Arrays.asList(pri1).contains(op)) return 1;
		else if(Arrays.asList(pri2).contains(op)) return 2;
		else if(Arrays.asList(pri3).contains(op)) return 3;
		else if(Arrays.asList(pri4).contains(op)) return 4;
		else if(Arrays.asList(pri5).contains(op)) return 5;

		return 0;
	}

	// Evaluates an operation given the two inputs and the operator
	public static int eval(int n1, int n2, String op){
		if(op.equals("+")) return n2 + n1;
		else if(op.equals("-")) return n2 - n1;
		else if(op.equals("*")) return n2 * n1;
		else if(op.equals("/")) return n2 / n1;
		else if(op.equals("^")) return (int)Math.pow(n2,n1);
		return 0;
	}
}
