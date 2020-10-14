#include "math.hpp"
#include "console.hpp"
#include <iostream>

// define this so the console returns your input
//#define RETURN_UVALUE

//define this to use untested functions
#define ALLOW_UNTESTED

//@DEPRECATED: no longer required, type check already implemented
//#define USE_ADVANCED_ALGEBRA

/*
* @TODO: clean up code, use a different .cpp file and a header for user input
* @UNFINISHED: conversion (length, area, volume), more advanced algorithms
*/

int inputfromuser() // code to return user input for braces without having to use std::cin every single time
{
	int input{};
	std::cin >> input;
	if (!std::cin) // crash ( i don't know how to properly restart the application ) when input is non-numeric
	{
		std::cin.clear();
		std::cout << clred << "[ERROR] Non-numeric character detected, stopping in 2 seconds..\n" << cl_white;
		Sleep(2000);
		system("CLS");
		exit(EXIT_FAILURE);
	}
	return input;
}

double fractinputfromuser() // double input implementation for fractional numbers
{
	double input{};
	std::cin >> input;
	if (!std::cin) // same as above
	{
		std::cin.clear();
		std::cout << clred << "[ERROR] Non-numeric character detected, stopping in 2 seconds..\n" << cl_white;
		Sleep(2000);
		system("CLS");
		exit(EXIT_FAILURE);
	}
	return input;
}

std::string removespace(std::string& str) // quick implementation for removing whitespace
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

int main()
{
	SetConsoleTitle(L"C++ Math Calculator"); // changes calculator name
	HWND console = GetConsoleWindow();  /* this code changes the calculator window size */
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 600, 400, TRUE);
	std::string calctype; //setting a string to get calculation type from user
	std::cout << cl_icyan << "Please select a calculation type:" << cl_white << "\n1 - Algebra\n2 - Conversion\n3 - Advanced Algorithms\n";
	std::cin >> calctype;
	if (calctype == "1" || calctype == "algebra" || calctype == "Algebra")
	{
		std::string albtype;
		std::cout << "Please select Algebra type (Basic || Advanced)\n";
		std::cin >> albtype;
		if (albtype == "basic" || albtype == "Basic")
		{
			std::cout << cl_iyellow << "[ INFORMATION ] Current calculation type: Algebra\n";
			std::cout << "Enter current x value: ";
			signed int x{ inputfromuser() };
#ifdef RETURN_UVALUE
			std::cout << "Your x value is: " << x << "\n";
#endif
			std::cout << "Enter current y value: ";
			signed int y{ inputfromuser() };
#ifdef RETURN_UVALUE
			std::cout << "Your y value is: " << y << "\n";
#endif
			std::string calcmode;
			std::cout << cl_iaqua << "Please select a calculation mode (add, subtract, multiply, divide)\n" << cl_white;
			std::cin >> calcmode;
			if (calcmode == "add" || calcmode == "Add" || calcmode == "+")
			{
				std::cout << "The answer is: " << mathlibrary::algebra::add(x, y) << std::endl;
			}
			else if (calcmode == "subtract" || calcmode == "Subtract" || calcmode == "-")
			{
				std::cout << "The answer is: " << mathlibrary::algebra::subtract(x, y) << std::endl;
			}
			else if (calcmode == "multiply" || calcmode == "Multiply" || calcmode == "*")
			{
				std::cout << "The answer is: " << mathlibrary::algebra::multiply(x, y) << std::endl;
			}
			else if (calcmode == "divide" || calcmode == "Divide" || calcmode == "/")
			{
				std::cout << "The answer is: " << mathlibrary::algebra::divide(x, y) << std::endl;
			}
			else
			{
				std::cout << clred << "[ALGORITHM] Calculation method unknown, restarting in 5 seconds..\n" << cl_white;
				Sleep(5000);
				system("CLS");
				main();
			}
			std::string aftermath;
			std::cout << cl_iaqua << "[SYSTEM] Do you want to start again? (Y/N)\n" << cl_white;
			std::cin >> aftermath;
			if (aftermath == "Y" || aftermath == "y")
			{
				system("CLS");
				main();
			}
			else if (aftermath == "N" || aftermath == "n")
			{
				std::cout << clred << "[SYSTEM] See you again!\n";
				Sleep(1000);
				exit(0);
			}
		}
		else if (albtype == "advanced" || albtype == "Advanced")
		{
			std::cout << "Current calculation type: Advanced Algebra\n";
			std::cout << "Enter a number: ";
			double x = { fractinputfromuser() };
			std::cout << cl_igreen << "Square root of given number is: " << mathlibrary::algebra::advanced_algebra::squarert(x) << "\n" << cl_white;
			std::string aftermath;
			std::cout << cl_iaqua << "[SYSTEM] Do you want to start again? (Y/N)\n" << cl_white;
			std::cin >> aftermath;
			if (aftermath == "Y" || aftermath == "y")
			{
				system("CLS");
				main();
			}
			else if (aftermath == "N" || aftermath == "n")
			{
				std::cout << clred << "[SYSTEM] See you again!\n";
				Sleep(1000);
				exit(0);
			}
		}
	}
	else if (calctype == "2" || calctype == "conversion" || calctype == "Conversion") /* i do this for a reason ok */
	{
		std::cout << "Current calculation type: Conversion\n";
		std::string convtype;
		std::cout << "Please select a conversion unit group (Length, Area, Volume, Velocity)\n";
		std::cin >> convtype;
		if (convtype == "length" || convtype == "Length")
		{
			/* placeholder code */
			std::cout << clred << "[ALGORITHM] Calculation type unfinished, restarting program in 2 seconds...\n";
			Sleep(2000);
			system("CLS");
			main();
			/* untested */
#ifdef ALLOW_UNTESTED
			std::cout << cl_iaqua << "Please select a conversion unit type (Imperial || Metric)";
			std::string convutype;
			std::cin >> convutype;
			if (convutype == "imperial" || convutype == "Imperial")
			{
				// im not familiar with imperial stuff
			}
			else if (convutype == "metric" || convutype == "Metric")
			{
				std::cout << "Please select a conversion unit (mm || cm || m || km)";
					// this is actually time-consuming
				std::string convunit;
				if (convunit == "mm")
				{
					// @TODO: finish this
				}
				else if (convunit == "cm")
				{
					// @TODO: finish this
				}
				else if (convunit == "m")
				{
					// @TODO: finish this
				}
				else if (convunit == "km")
				{
					// @TODO: finish this
				}
			}

#endif
		}
		else if (convtype == "area" || convtype == "Area")
		{
			/* placeholder code */
			std::cout << clred << "[ALGORITHM] Calculation type unfinished, restarting program in 2 seconds...\n";
			Sleep(2000);
			system("CLS");
			main();
			/* not implemented */
		}
		else if (convtype == "volume" || convtype == "Volume")
		{
			/* placeholder code */
			std::cout << clred << "[ALGORITHM] Calculation type unfinished, restarting program in 2 seconds...\n";
			Sleep(2000);
			system("CLS");
			main();
			/* not implemented */
		}
		else if (convtype == "velocity" || convtype == "Velocity")
		{
			std::cout << cl_iaqua << "Please select a conversion unit (kmph>mps || mps>kmph)\n" << cl_white;
			std::string convunit;
			std::cin >> convunit;
			convunit.erase(std::remove(convunit.begin(), convunit.end(), ' '), convunit.end()); // doesn't work ;(
			//removespace(convunit);
			if (convunit == "km/h>m/s" || convunit == "kmph>mps")
			{
				std::cout << "Enter km/h value: ";
				double x{ fractinputfromuser() };
				std::cout << "Conversion result: " << mathlibrary::conversion::velocity::kmphtomps(x) << " m/s\n";
			}
			else if (convunit == "m/s>km/h" || convunit == "mps>kmph")
			{
				std::cout << "Enter m/s value: ";
				double x{ fractinputfromuser() };
				std::cout << "Conversion result: " << mathlibrary::conversion::velocity::mpstokmph(x) << " km/h\n";
			}
			std::string aftermath;
			std::cout << cl_iaqua << "[SYSTEM] Do you want to start again? (Y/N)\n" << cl_white;
			std::cin >> aftermath;
			if (aftermath == "Y" || aftermath == "y")
			{
				system("CLS");
				main();
			}
			else if (aftermath == "N" || aftermath == "n")
			{
				std::cout << clred << "[SYSTEM] See you again!\n";
				Sleep(1000);
				exit(0);
			}
		}
		else
		{
			std::cout << clred << "[ALGORITHM] Conversion type unknown / unfinished, restarting in 5 seconds..\n";
			Sleep(5000);
			system("CLS");
			main();
		}
		/* simple restart approach instead of filling up the console making it hard to read */
		std::string aftermath;
		std::cout << cl_iaqua << "[SYSTEM] Do you want to start again? (Y/N)\n" << cl_white;
		std::cin >> aftermath;
		if (aftermath == "Y" || aftermath == "y")
		{
			system("CLS");
			main();
		}
		else if (aftermath == "N" || aftermath == "n")
		{
			std::cout << clred << "[SYSTEM] See you again!\n";
			Sleep(1000);
			exit(0);
		}
	}
	else if (calctype == "3" || calctype == "advanced algorithms" || calctype == "Advanced Algorithms" || calctype == "algorithms")
	{		
#ifdef ALLOW_UNTESTED
		std::cout << cl_white << "[" << cl_iblue << " INFORMATION " << cl_white << "] " << "Current calculation type: Algorithms\n";
		std::cout << "Please select an algorithm (isPrime || isEven)\n";
		std::string algotype;
		std::cin >> algotype;
		if (algotype == "isprime" || algotype == "isPrime")
		{
			// check if a number is prime
			std::cout << "Enter a number: ";
			int num = { inputfromuser() };
			int fl = mathlibrary::algorithm::isPrime(num);
			if (fl == 1)
			{
				std::cout << cl_igreen << "Given number is a prime number.\n" << cl_white;
			}
			else if (fl == 0)
			{
				std::cout << cl_igreen << "Given number is not a prime number.\n" << cl_white;
			}
			std::string aftermath;
			std::cout << cl_iaqua << "[SYSTEM] Do you want to start again? (Y/N)\n" << cl_white;
			std::cin >> aftermath;
			if (aftermath == "Y" || aftermath == "y")
			{
				system("CLS");
				main();
			}
			else if (aftermath == "N" || aftermath == "n")
			{
				std::cout << clred << "[SYSTEM] See you again!\n";
				Sleep(1000);
				exit(0);
			}
		}
		else if (algotype == "iseven" || algotype == "isEven")
		{
			std::cout << "Enter a number: ";
			int num{ inputfromuser() };
			int flag = mathlibrary::algorithm::isEvenorOdd(num);
			if (flag == 1)
			{
				std::cout << cl_igreen << "Given number is even.\n";
			}
			else if (flag == 0)
			{
				std::cout << cl_igreen << "Given number is odd.\n";
			}
			// i might put this aftermath thing into a seperate function, i'm tired of copy + pasting the same code over and over
			std::string aftermath;
			std::cout << cl_iaqua << "[SYSTEM] Do you want to start again? (Y/N)\n" << cl_white;
			std::cin >> aftermath;
			if (aftermath == "Y" || aftermath == "y")
			{
				system("CLS");
				main();
			}
			else if (aftermath == "N" || aftermath == "n")
			{
				std::cout << clred << "[SYSTEM] See you again!\n";
				Sleep(1000);
				exit(0);
			}
		}
#endif

#ifndef ALLOW_UNTESTED
		std::cout << clred << "[ALGORITHM] Calculation type unfinished, restarting program in 2 seconds...\n";
		Sleep(2000);
		system("CLS");
		main();
#endif
		/* not implemented */
	}
	return 0;
}