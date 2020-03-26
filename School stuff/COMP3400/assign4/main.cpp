/**
 * @file    main.cpp
 * @author  Dilpreet Chana 104570850
 */

#include <fstream>
#include <iostream>
#include <map>
#include <string>

struct record {
    std::string fname;  // first name
    std::string lname;  // last name
};

using hist_t = std::map<record, size_t>;

// Operator prototypes
std::istream& operator>>(std::istream& is, record& rec);
std::ostream& operator<<(std::ostream& os, record const& rec);
bool operator<(record const& rec1, record const& rec2);

int main() {
    hist_t h;

    for (record r; std::cin >> r; ) {
        auto i_ret = h.insert(std::pair<record, size_t>(r, 1));

        if (!i_ret.second) {
            i_ret.first->second++;
        }
    }

    int out_count = 0;

    std::cout << "{ ";
    for (auto const& [key, value] : h)
        std::cout << key << " : " << value << (++out_count == h.size() ? " " : ", ");
    std::cout << "}" << std::endl;

    return 0;
}

/**
 * Input operator to parse white space delimited content from
 * stream in the form fname lname
 *
 * @param   istream reference to get content from
 * @param   record reference to parse content into
 *
 * @return  istream after parsing
 */
std::istream& operator>>(std::istream& is, record& rec) {
    std::string fname_, lname_;

    is >> fname_;
    is >> lname_;

    rec.fname = fname_;
    rec.lname = lname_;

    return is;
}

/**
 * Output operator to output record content to our stream
 *
 * @param   ostream to output to
 * @param   record to get content from
 *
 * @return  ostream after parsing
 */
std::ostream& operator<<(std::ostream& os, record const& rec) {
    os << rec.fname << " " << rec.lname;

    return os;
}

/**
 * Less than operator which compares two records by lname as strings.
 * If the lnames are the same, then compares by fname.
 *
 * @param   record on the left side of the less than symbol
 * @param   record on the right side of the less than symbol
 *
 * @return  true rec1 is less than rec2
 */
bool operator<(record const& rec1, record const& rec2) {
    if (rec1.lname == rec2.lname) {
        return rec1.fname < rec2.fname;
    }
    return rec1.lname < rec2.lname;
}
