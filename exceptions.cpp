/*

Exceptions provide a way to react to exceptional circumstances (like runtime errors) in programs by transferring control
to special functions called "handlers".

The C++ Standard library provides a base class specifically designed to declare objects to be thrown as exceptions.
It is called std::exception and is defined in the <exception> header.
This class has a virtual member function called what() that returns a null-terminated character sequence (of type char
*) and that can be overwritten in derived classes to contain some sort of description of the exception.

virtual const char* what() const throw();

*/
#include "functions.h"
#include <exception>
#include <iostream>

using std::cout;

// Extend exception base class provided by C++ Standart Library and override virtual member function what()
class MKException : public std::exception
{
  public:
    const char *what() const throw()
    {
        return "MK exception happened.";
    }
};

void exceptionBasics()
{
    try
    {
        // throwAnInt();
        // throwAChar();
        throwACustomException();
    }
    catch (int e)
    {
        cout << "Exception (type int): " << e << "\n ";
    }
    // Multiple handlers (i.e., catch expressions) can be chained; each one with a different parameter type.
    catch (char e)
    {
        cout << "Exception (type char): " << e << "\n ";
    }
    catch (std::exception &e) // MKException extends std::exception !
    {
        cout << e.what() << "\n ";
    }
    // "three dots" syntax (...) inside the catch block will handle any type of exception:
    catch (...)
    {
        cout << "General Exception!\n";
    }
}

void throwAnInt()
{
    int exceptionNum = 10;

    // The throw keyword throws an exception
    throw exceptionNum;
}

void throwAChar()
{
    // The throw keyword throws an exception
    throw 'A';
}

void throwACustomException()
{
    // 1. throw with the default constuctor
    throw MKException();

    // 2. throw an explicit object
    // MKException mke;
    // throw mke;
}