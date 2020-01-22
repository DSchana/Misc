/**
 * @file        a2.cpp
 * @author      Dilpreet Chana 104570850
 *
 * @section DESCRIPTION
 *
 * Find the nearest standard web colour
 * to given rgb colour from user
 */

#include <cmath>
#include <array>
#include <vector>
#include <limits>
#include <string>
#include <istream>
#include <ostream>
#include <iostream>
#include <algorithm>

struct rgb {
    unsigned char red, green, blue;    
};

/**
 * Input operator to parse white space delimited content
 * from stream in the form of r g b
 *
 * @param   istream reference to get content from
 * @param   rgb reference to parse content into
 *
 * @return  istream after parsing
 */
std::istream& operator>>(std::istream& is, rgb& colour) {
    unsigned int r, g, b;
    is >> r;
    is >> g;
    is >> b;

    // Failbit if colour channel values exceed what can be stored in a byte
    if (r > 255 || g > 255 || b > 255) {
        is.setstate(std::ios_base::failbit);
    }

    colour.red = r;
    colour.green = g;
    colour.blue = b;

    return is;
}

/**
 * Output oprtator to output rgb colour content to out stream
 *
 * @param   ostream reference to output to
 * @param   rgb reference to get content from
 *
 * @return  ostream after parsing
 */
std::ostream& operator<<(std::ostream& os, rgb const& colour) {
    os << static_cast<unsigned int>(colour.red) << ", ";
    os << static_cast<unsigned int>(colour.green) << ", ";
    os << static_cast<unsigned int>(colour.blue);

    return os;
}

/**
 * Find euclidian distance between two colours
 *
 * @param   First colour
 * @param   Second colour
 *
 * @return  Double euclidian distance between the two colours
 */
double distance(rgb const& c1, rgb const& c2) {
    return sqrt(pow(c1.red - c2.red, 2) + pow(c1.green - c2.green, 2) + pow(c1.blue - c2.blue, 2));
}

int main() {
    std::array<rgb,16> const colours{{
        { 0x00, 0x00, 0x00 },  // 0: black
        { 0x80, 0x00, 0x00 },  // 1: maroon
        { 0x00, 0x80, 0x00 },  // 2: green
        { 0x80, 0x80, 0x00 },  // 3: olive
        { 0x00, 0x00, 0x80 },  // 4: navy
        { 0x80, 0x00, 0x80 },  // 5: purple
        { 0x00, 0x80, 0x80 },  // 6: teal
        { 0xC0, 0xC0, 0xC0 },  // 7: silver
        { 0x80, 0x80, 0x80 },  // 8: grey
        { 0xFF, 0x00, 0x00 },  // 9: red
        { 0x00, 0xFF, 0x00 },  // 10: lime
        { 0xFF, 0xFF, 0x00 },  // 11: yellow
        { 0x00, 0x00, 0xFF },  // 12: blue
        { 0xFF, 0x00, 0xFF },  // 13: fushsia
        { 0x00, 0xFF, 0xFF },  // 14: aqua
        { 0xFF, 0xFF, 0xFF }   // 15: white
    }};

    std::array<std::string,16> const colour_names{
        "black", "maroon", "green", "olive", "navy", "purple", "teal", "silver",
        "gray", "red", "lime", "yellow", "blue", "fushsia", "aqua", "white"
    };

    rgb col;
    std::vector<double> distances;
    while (std::cin >> col) {
        // Fill distances vector with distances from the input colour and
        // the 16 standard colours.
        distances.clear();
        std::transform(colours.begin(), colours.end(), std::back_inserter(distances), [&col](rgb const& c2){ return distance(col, c2); });

        // Find the closest colour
        double max_index = 0;
        for (size_t i = 0; i < distances.size(); i++) {
            if (distances[i] < distances[max_index]) {
                max_index = i;
            }
        }

        std::cout << colour_names[max_index] << std::endl;
    }

    return 0;
}
