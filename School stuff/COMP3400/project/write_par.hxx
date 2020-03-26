#ifndef comp3400_2020w_project_write_par_hxx_
#define comp3400_2020w_project_write_par_hxx_

//===========================================================================

#include <cstddef>                  // for std::size_t
#include <mutex>                    // for std::mutex
#include <thread>                   // for std::thread
#include <iostream>                 // for std::cerr

//===========================================================================

inline void write_cell_info_concurrently(
//Assign values to mediate the size of  each x and y value
  size_t const& xlow, size_t const& ylow,
  size_t const& xhigh, size_t const& yhigh
)
{   //declare a static std::mutex
	std::mutex mut;
	{   
        //declare a lock_guard variable to manage the output and it's timing
		std::lock_guard<std::mutex> lock(mut);

        //Write a standard error when the lock malfunctions
		std::cerr << "PROCESSING: (" << xlow << ',' << ylow
			<< ")-(" << xhigh << ',' << yhigh << ") on thread "
			<< std::this_thread::get_id() << '\n';
	}
 
  //
  // NOTE: Look up std::mutex and std::lock_guard on cppreference.com.
  //
  //       Look at the example code associated with each.
  //
  //       Since this is the only code that will be outputting to
  //       an IOStream in parallel, it is acceptable to declare
  //       the std::mutex variable in this function (instead as a
  //       global variable).
  //
}

//===========================================================================

#endif // #ifndef comp3400_2020w_project_write_par_hxx_
