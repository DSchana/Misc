/*
 * Title:       a1.cpp
 * Author:      Dilpreet Chana 104570850
 * Description: Remove some punctuation from string while
 *              preserving any other characters and any
 *              text between double quotes
**/

#include <iostream>
#include <string>

int main() {
    std::string line, output;
    bool replace = true;

    while (std::getline(std::cin, line)) {
        for (char& c : line) {
            // Stop replacing inside of double quotes
            if (c == '"') {
                replace = !replace;
            }

            if (replace) {
                if (c == '.' || c == ',' || c == '?' || c == '-' || c == '\'') {
                    c = ' ';
                }
            }
        }

        output += line + '\n';
    }

    std::cout << output << std::endl;

    return 0;
}
