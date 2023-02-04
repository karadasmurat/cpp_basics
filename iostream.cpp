/*

input device -> device driver -> input library -> our program -> output library -> device drivers -> output device

The details of how our characters are actually transmitted to/from the devices are dealt with by the I/O library and
the device drivers.

The buffer is a data structure that the ostream uses internally to store the data you give it while communicating with
the operating system. If you notice a “delay” between your writing to an ostream and the characters appearing at their
destination, it’s usually because they are still in the buffer. Buffering is important for performance, and performance
is important if you deal with large amounts of data.

The C++ standard library provides the type istream to deal with streams of input and the type ostream to deal with
streams of output.

To call ‘<<‘ and ‘>>’ operator, we must call it like:
    cout << obj1 ;
    cin >> obj1 ;

So if we want to make them a member method, then they must be made members of "ostream" and "istream" classes, which is
not a good option most of the time. Therefore, these operators are overloaded as global functions with two parameters,
cout and object of user defined class.


We typically have much more data than can fit in the main memory of our computer, so we store most of it on disks or
other large-capacity storage devices. “Such devices also have the desirable property that data doesn’t disappear when
the power is turned off — the data is persistent.

For a file, an ostream converts objects in main memory into streams
of bytes and writes them to disk. An istream does the opposite; that is, it takes a stream of bytes from disk and
composes objects from them. An ifstream is an istream for reading from a file, an ofstream is an ostream for writing to
a file, and an fstream is an iostream that can be used for both reading and writing.

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

// a temperature reading, for reading/writing a struct from file.
struct Reading
{
    int hour{0}; // hour after midnight [0:23]
    double temperature{0};

    Reading() = default;
    Reading(int h, double t) : hour(h), temperature(t)
    {
    }
};

// overloading '<<' operator.
std::ostream &operator<<(std::ostream &os, const Reading &r)
{
    return os << r.hour << " " << r.temperature << endl;
}

// overloading '>>' operator.
std::istream &operator>>(std::istream &is, Reading &r)
{
    // is >> r.hour >> r.temperature;

    cout << "Enter hour: ";
    is >> r.hour;
    cout << "Enter temperature: ";
    is >> r.temperature;

    return is;
}

void loadTemperaturesFromFile()
{

    // Defining an ifstream with a name string opens the file of that name for reading.
    std::ifstream ifstr{"temperatures.txt"};

    std::vector<Reading> temps;

    if (ifstr)
    {
        for (Reading r; ifstr >> r;)
        {
            temps.push_back(r);
        }

        ifstr.close();
    }

    else
        cout << "Unable to open file";

    cout << "Readings from file: \n";
    for (const auto &r : temps)
        cout << r;
}

void saveTemperaturesToFile()
{

    std::vector<Reading> temps;

    // create a vector of 3 Reading structs, and save them to file.
    // temps.reserve(3);
    // temps.emplace_back(13, 33);
    // temps.emplace_back(17, 30);
    // temps.emplace_back(23, 27);

    cout << "Please provide temperature readings." << endl;
    // get temperature readings
    for (Reading r; std::cin >> r;) // operator>> overloaded.
    {
        temps.push_back(r);
    }

    // Defining an ofstream
    // std::ofstream ofstr{"temperatures.txt"};

    // Defining an ofstream to "append"
    std::ofstream ofstr;
    // flags can be combined using the bitwise operator OR (|)
    ofstr.open("temperatures.txt", ios::out | ios::app);

    if (ofstr)
    {
        for (const auto &t : temps)
            ofstr << t; // // operator<< overloaded.
    }
    else
    {
        std::cerr << "Error opening file." << endl;
    }
}

void fileBasics()
{
    // writeFile();
    // readFile();

    // saveTemperaturesToFile();
    loadTemperaturesFromFile();
}

void writeFile()
{
    // Create and open a text file
    // Defining an ofstream with a name string opens the file with that name for writing.
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

    // Defining an ifstream with a name string opens the file of that name for reading.
    std::ifstream myfile{"out.txt"};

    // std::fstream fs;
    // fs.open("foo", ios::in);

    string line;
    // if (myfile.is_open())
    if (myfile)
    {
        while (getline(myfile, line))
            cout << line << '\n';

        myfile.close();
    }

    else
        cout << "Unable to open file";
}
