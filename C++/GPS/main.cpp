#include <iostream>
#include "GPSParser.h"
#include "InputReader.h"
/*!
 * \file main.cpp
 *
 * \author Ryan Gouldsmih
 * \date 28th March
 *
 * This runs the main application.
 */
using namespace std;
/**
* \brief Used to run the main application
* Creates a new Reader object and runs the program from this.
*/
int main()
{
    cout << "FILE ONE AND TWO IS LODING" << endl;
    //creates a pointer to the InputReader Object
    InputReader* reader = new InputReader("file1.dat", "file2.dat");
    //delete the object when it goes out of memory.
    delete(reader);
    cout << "All data has been read in succesfully annd outputted to a GPSX file" << endl;
    return 0;
}
