#include <cstdio>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Stack.h"

using namespace std;

// TODO: Try to redo infix if not working

int getPrecedence(string c);
int evaluate(int n1, int n2, string op);
vector<string> split(string s);

int main() {
	ifstream infile("input.txt");
	vector<string> eqns;
	string line;

	while (getline(infile, line)) eqns.push_back(line);

	for (string e : eqns) {
		int bracket_count = 0;
		bool invalid = false;
		string last = "";
		vector<string> tokens = split(e);

		for (size_t i = 0; i < tokens.size(); i++) {
			string c = tokens[i];

			// Check for unary negation
			if (c == "-" && (i == 0 || getPrecedence(last)) && last != ")") {
				int space_count = 0;
				for (int j = 0; j < e.size(); j++) {
					if (e[j] == ' ') {
						space_count++;
					}

					// Assume '-' is isolated by spaces
					if (space_count == i) {
						e[j + 1] = '~';
					}
				}

				c = "~";
				last = c;
			}
			else {
				if (c == "(") bracket_count++;
				else if (c == ")") bracket_count--;

				if (i != 0 && ((getPrecedence(last) > 0 && getPrecedence(c) > 0) || (getPrecedence(last) == 0 && getPrecedence(c) == 0) || (bracket_count < 0))) {
					printf("Invalid: %s\n", c.c_str());
					invalid = true;
				}
				else {
					last = c;
				}
			}
		}

		if (bracket_count != 0) invalid = true;

		// Pass equation if invalid
		if (invalid) {
			printf("Equation: %s  is not valid infix\n", e.c_str());
			continue;
		}

		Stack<string> ops;
		string post = "";

		printf("Operator stack: %s\n", ops.to_string());

		// Convert to postfix
		for (int i = 0; i < tokens.size(); i++) {
			string curr = tokens[i];

			int curr_prec = getPrecedence(curr);

			if (curr_prec > 0) {  // Operator
				if (ops.getTop() != NULL) {
					string top = ops.getTop();

					int top_prec = getPrecedence(top);

					if (top == "~" && curr == "~") {
						printf("Operator stack: %s\n", ops.to_string());
						ops.push(curr);
						printf("Operator stack: %s\n", ops.to_string());
					}
					else if (curr_prec <= top_prec && top_prec != 5) {
						printf("Operator stack: %s\n", ops.to_string());
						post += (string)ops.pop() + " ";
						printf("Operator stack: %s\n", ops.to_string());

						top = ops.getTop();

						if (ops.getTop() != NULL) top_prec = getPrecedence(top);
						while (ops.getTop() != NULL && curr_prec < top_prec && top_prec != 5) {
							post += ops.pop() + " ";
							printf("Operator stack: %s\n", ops.to_string());
						}
						ops.push(curr);
						printf("Operator stack: %s\n", ops.to_string());
					}
					else if (curr == ")") {
						printf("Operator stack: %s\n", ops.to_string());
						while (ops.getTop() != "(") {
							post += ops.pop() + " ";
							printf("Operator stack: %s\n", ops.to_string());
						}

						ops.pop();
						printf("Operator stack: %s\n", ops.to_string());
					}
					else {
						printf("Operator stack: %s\n", ops.to_string());
						ops.push(curr);
						printf("Operator stack: %s\n", ops.to_string());
					}
				}
				else {
					printf("Operator stack: %s\n", ops.to_string());
					ops.push(curr);
					printf("Operator stack: %s\n", ops.to_string());
				}
			}
			else {
				post += curr + " ";
			}
		}
		printf("Operator stack: %s\n", ops.to_string());
		while (ops.getTop() != NULL) {
			post += ops.getTop() + " ";
			ops.pop();
			printf("Operator stack: %s\n", ops.to_string());
		}

		printf("Post: %s\n\n", post.c_str());

		Stack<int> nums;
		printf("Nums: %s\n", nums.to_string());

		// Evaluate
		vector<string> toks = split(post);
		for (string t : toks) {
			if (getPrecedence(t) == 0) {
				nums.push(stoi(t));
				printf("Nums: %s\n", nums.to_string());
			}
			else {
				int n_num;
				if (t == "~") {
					printf("Nums: %s\n", nums.to_string());
					int n1 = nums.pop();
					n_num = -1 * n1;
				}
				else {
					printf("Nums: %s\n", nums.to_string());
					int n1 = nums.pop();
					printf("Nums: %s\n", nums.to_string());
					int n2 = nums.pop();
					n_num = evaluate(n1, n2, t);
				}

				printf("Nums: %s\n", nums.to_string());
				nums.push(n_num);
				printf("Nums: %s\n", nums.to_string());
			}
		}

		printf("Answer: %d\n", nums.getTop());
	}

	return 0;
}

int getPrecedence(string c) {
	if (c == "+" || c == "-") return 1;
	else if (c == "*" || c == "/") return 2;
	else if (c == "~") return 3;
	else if (c == "^") return 4;
	else if (c == "(" || c == ")") return 5;

	return 0;
}

int evaluate(int n1, int n2, string op) {
	if (op == "+") return n2 + n1;
	else if (op == "-") return n2 - n1;
	else if (op == "*") return n2 * n1;
	else if (op == "/") return n2 / n1;
	else if (op == "^") return (int)pow(n2, n1);
	return 0;
}

vector<string> split(string s) {
	vector<string> ret;

	while (s.find(" ") != string::npos) {
		size_t pos = s.find(" ");
		ret.push_back(s.substr(0, pos));
		s.erase(s.begin(), s.begin() + pos);
	}
	ret.push_back(s);

	return ret;
}
