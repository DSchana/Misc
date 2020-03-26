#ifndef comp3400_2020w_project_write_image_hxx_
#define comp3400_2020w_project_write_image_hxx_

//===========================================================================

#include <string>                   // for std::string
#include <chrono>                   // for timing and clocks
#include <fstream>                  // for std::ofstream
#include <iostream>                 // for std::cerr and std::cout
#include <ctime>
#include <chrono>

//===========================================================================

using namespace std;
using namespace chrono;

template <typename Image>
void write_image(Image const& image, std::string const& fname) {
    
	//Create a variable to locate the current time at this moment
	auto start = high_resolution_clock::now();

	//Create a variable to be used for the file stream
	ofstream outputFile;
	//opne file for writing and truncating
	outputFile.open(fname, ios::out | ios::trunc);
    

	//Call function to save image to output file
    image.save(outputFile, true);

	//Create another variable to locate the secondary time after the output of the file 
	auto end = high_resolution_clock::now();


	//Print the time to console to determine how long this process has gone
	cout << "OFSTREAM_TIME: " << fname << " took " << duration_cast<seconds>(end-start).count();
	cout << " seconds to write.\n";

	//Close file
	outputFile.close();
	
}
//===========================================================================

#endif // #ifndef comp3400_2020w_project_write_image_hxx_
