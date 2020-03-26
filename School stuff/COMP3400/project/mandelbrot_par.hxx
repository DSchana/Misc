#ifndef comp3400_2020w_project_mandelbrot_par_hxx_
#define comp3400_2020w_project_mandelbrot_par_hxx_

//===========================================================================

#include <cmath>                    // for std::abs
#include <complex>                  // for std::complex

#include <string>                   // for std::string
#include <vector>                   // for std::vector

#include <algorithm>                // for various algorithms
#include <numeric>                  // e.g., for std::iota

#include <chrono>                   // for timing and clocks
#include <execution>                // for std::execution::par
#include <thread>                   // e.g., for std::thread::get_id()

#include <iostream>                 // for std::cerr and std::cout

#include "ppm.hxx"
#include "hsv.hxx"
#include "utils.hxx"
#include "program_cli_args.hxx"
#include "mandelbrot.hxx"

//===========================================================================

template <typename Image, typename Real, typename MandelToColourFunc>
void draw_mandelbrot_set_par(
  //Variable declarations
  Image& image,
  std::complex<Real> const& min_point,
  std::complex<Real> const& max_point,
  MandelToColourFunc&& m2c,
  std::size_t const& max_iter,
  std::size_t chunks_per_x_axis
)
{
  using namespace std;

  //find the width, height and point width of th image
  auto const image_width = image.width();
  auto const image_height = image.height();
  auto const point_width = max_point - min_point;

  //This will be sued to assign the colors and values of each pixel and image
  auto const compute_cell = [&](size_t const& ilow, size_t const& ihigh,
      size_t const& jlow, size_t const& jhigh)
  {
      //write the cell infromation concurrently given the parameters
      write_cell_info_concurrently(ilow, jlow, ihigh, jhigh);
        
      //for each of the length...
      for (size_t i = ilow; i != ihigh; ++i)
      {
          //calculate the image index and size as a real number
          Real const x =
              image_index_to_real(i, image_width,
                  point_width.real(), min_point.real());
          ;

          //for the secondary set of sizes
          for (size_t j = jlow; j != jhigh; ++j)
          {
              //calcuate a secondary real number
              Real const y =
                  image_index_to_real(j, image_height,
                      point_width.imag(), min_point.imag());
              ;

              //calcuate the complex pair and assign it to the image values at i and j to write the image
              complex<Real> const c(x, y);
              image(i, j) = m2c(compute_mandelbrot_at(c, max_iter), max_iter);
          }
      }
  };
 
  //This is used to inclusively and exclusively sum the operations in arbirary order
  std::vector<std::size_t> idivs_lo, idivs_hi;
  evenly_divide_n(back_inserter(idivs_lo), image_width, chunks_per_x_axis);
  std::inclusive_scan(begin(idivs_lo), end(idivs_lo), back_inserter(idivs_hi));
  std::exclusive_scan(begin(idivs_lo), end(idivs_lo), begin(idivs_lo), 0);

  //Similar to above this is used to sum the operations of the vector in arbitrary order
  std::vector<std::size_t> jdivs_lo, jdivs_hi;
  evenly_divide_n(back_inserter(jdivs_lo), image_height, chunks_per_x_axis);
  std::inclusive_scan(begin(jdivs_lo), end(jdivs_lo), back_inserter(jdivs_hi));
  std::exclusive_scan(begin(jdivs_lo), end(jdivs_lo), begin(jdivs_lo), 0);

  //This creates a vector and uses iota to fill the vector will values that are increasing from the beginning to the end
  std::vector<std::size_t> indicE_vector (idivs_lo.size()); 
  std::iota(indicE_vector.begin(), indicE_vector.end(), 0);

  //determine start time
  auto startTime = std::chrono::high_resolution_clock::now();

  for (auto i = 0; i < indicE_vector.size(); ++i) {
    std::for_each(std::execution::par, indicE_vector.begin(), indicE_vector.end(), [&](std::size_t const& j) {
      compute_cell(*(idivs_lo.begin() + i), *(idivs_hi.begin() + i), *(jdivs_lo.begin() + j), *(jdivs_hi.begin() + i));
    });
  }

  //determine the amount of time it takes at teh very end
  auto endTime = std::chrono::high_resolution_clock::now();
  auto secs = endTime - startTime;

  cout << "MANDELBROT_TIME: " << image_width << " by " << image_height 
  << " Mandelbrot set took " << secs.count() << " seconds.\n";
}

//===========================================================================

#endif // #ifndef comp3400_2020w_project_mandelbrot_par_hxx_
