/*
The fstream and stringstream classes are related by inheritance to the iostream
classes. The input classes inherit from istream and the output classes from ostream. Thus, operations that can be
performed on an istream object can also be performed on either an ifstream or an istringstream. Similarly for the output
classes, which inherit from ostream.
*/

#include "functions.h"
#include <chrono>
#include <fstream> // work with files
#include <iostream>

using std::cout;
using std::endl;
using std::ios;
using std::string;

void fileBasics()
{

    writeFile();
    readFile();
}

void writeFile()
{

    // Create and open a text file
    std::ofstream ofstr;

    // flags can be combined using the bitwise operator OR (|)
    ofstr.open("out.txt", ios::out | ios::app);

    // Write to the file
    if (ofstr.is_open())
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

        ofstr << ctime(&timenow) << "\n";

        // close it so that the operating system is notified and its resources become available again.
        ofstr.close();
    }
    else
        cout << "Unable to open file";
}

void readFile()
{

    string line;
    std::ifstream myfile("out.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else
        cout << "Unable to open file";
}