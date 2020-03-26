#ifndef comp3400_2020w_project_ppm_pixel_save_hxx_
#define comp3400_2020w_project_ppm_pixel_save_hxx_

//This will be used to create a saving feature that will overwrite the streaming of the output so that it can work with Image
std::ostream& save(std::ostream& os, bool binary = false) const {
    
    //As long as there is a valid sreaming output...
    if (os) {
        //If there is a true binary value...
        if (binary) {
            //output the different rgb values into the output stream
            os.put(r).put(g).put(b);
        }
        else {
            //If it is a false binary value, let each value be separated in a different formate
            os << r << ' ' << g << ' ' << b << ' ';
        }
    }

    //return the output
    return os;
}

#endif // #ifndef comp3400_2020w_project_ppm_pixel_save_hxx_
