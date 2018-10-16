/*
 * Title:	main.cpp
 * Author:	Dilrpeet S. Chana
 * Description:	Coding challenge for Nanoleaf
**/

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// PROTOTYPES
size_t tokenize(const string& s, vector<string>& toks, char c);

int main(int arg_c, char** arg_v) {
	// ================= PARSE COMMAND LINE ARGUMENTS =================
	string file_name;
	if (arg_c == 1) {
		cout << "Usage: sim input_file" << endl;
		return -1;
	}
	else {
		file_name = string(arg_v[1]);
	}


	// ================= PARSE FILE =================
	// Light storage
	map<string, int> light_count;  // Map of light colour to number of that light
	vector<string> light_access;   // List of light index to colour for O(1) access
	int to_select = 0;
	int tot_lights = 0;  // Total number of lights

	// File vars
	ifstream light_file;
	string line;

	light_file.open(file_name);

	while (getline(light_file, line)) {
		vector<string> tokens;

		if (tokenize(line, tokens, ' ') != 1) {  // Light count
			light_count[tokens[0]] = stoi(tokens[1]);
			tot_lights += light_count[tokens[0]];

			for (int i = 0; i < light_count[tokens[0]]; i++) {
				light_access.push_back(tokens[0]);
			}
		}
		else {  // Bulbs to select
			to_select = stoi(tokens[0]);
		}
	}

	// ================= FIND NUMBER OF UNIQUE COLOURS RANDOMLY =================
	vector<string> unique_cols;

	srand(time(NULL));

	// Select to_select number of randdom lights
	int removed = 0;
	for (int i = 0; i < to_select; i++) {
		int l = rand() % (tot_lights - removed);

		if (find(unique_cols.begin(), unique_cols.end(), light_access[l]) == unique_cols.end()) {
			unique_cols.push_back(light_access[l]);
			light_access.erase(light_access.begin() + l);
			removed++;
		}
	}

	cout << "A random run of this simulation resulted in " << unique_cols.size() << " unique colours" << endl;

	// ================= FIND NUMBER OF UNIQUE COLOURS MATHEMATICALLY =================
	float avg = 0;

	// Probabalistic count of each colour's selection. Using m/N as a weighted average of each
	// colour being selected. Where m is the redundant count of that colour and N is the total
	// lights avaliable
	int c = 1;  // Number of times looped
	for (auto it = light_count.begin(); it != light_count.end(); it++) {
		avg += 1.0 - pow(1.0 - it->second / float(tot_lights - c), to_select - c);
		c++;
	}

	cout << "The average expected number of unique colours from this simulation is " << avg << " colours" << endl;

	return 0;
}

/*
 * Description:	Split string by a character
 * Parameters:	Constant reference to String -    s: String to split
 *		Reference to list of tokens  - toks: List in which to store the split tokens
 *		Character		     -    c: Character to split the string by
 * Returns:	size_t: number of tokens found in string and stored in toks
**/
size_t tokenize(const string& s, vector<string>& toks, char c) {
	size_t curr_pos = 0;
	size_t next_pos = s.find(c);
	toks.clear();

	// Populate toks
	while (next_pos != string::npos) {
		toks.push_back(s.substr(curr_pos, next_pos - curr_pos + 1));
		curr_pos = next_pos + 1;

		next_pos = s.find(c, curr_pos);
	}

	// Add last token
	toks.push_back(s.substr(curr_pos, min(next_pos, s.size()) - curr_pos + 1));

	return toks.size();
}
