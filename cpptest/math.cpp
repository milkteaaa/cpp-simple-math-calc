#include "math.hpp"
#include "console.hpp"
#include <iostream>

// define this so the console returns your input
//#define RETURN_UVALUE

int main();

int inputfromuser() // code to return user input for braces without having to use std::cin every single time
{
	int input{};
	std::cin >> input;
	if (!std::cin)
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
	if (!std::cin)
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
	std::string calctype;
	std::cout << cl_icyan << "Please select a calculation type:" << cl_white << "\n1 - Algebra\n2 - Conversion\n3 - Advanced Algorithms\n";
	std::cin >> calctype;
	if (calctype == "1" || calctype == "algebra" || calctype == "Algebra")
	{
		std::cout << cl_iyellow << "Current calculation type: Algebra\n";
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
			std::cout << clred << "Calculation method unknown, restarting in 5 seconds..\n" << cl_white;
			Sleep(5000);
			system("CLS");
			main();
		}
		std::string aftermath;
		std::cout << "Do you want to start again? (Y/N)\n";
		std::cin >> aftermath;
		if (aftermath == "Y" || aftermath == "y")
		{
			system("CLS");
			main();
		}
		else if (aftermath == "N" || aftermath == "n")
		{
			std::cout << clred << "[SYSTEM] See you again!" << std::endl;
			Sleep(1000);
			exit(0);
		}
	}
	else if (calctype == "2" || calctype == "conversion" || calctype == "Conversion") /* i do this for a reason ok */
	{
		std::cout << "Current calculation type: Conversion\n";
		std::string convtype;
		std::cout << "Please select a conversion unit group (Length, Area, Volume, Velocity)";
		std::cin >> convtype;
		if (convtype == "length" || convtype == "Length")
		{
			/* not implemented */
		}
		else if (convtype == "area" || convtype == "Area")
		{
			/* not implemented */
		}
		else if (convtype == "volume" || convtype == "Volume")
		{
			/* not implemented */
		}
		else if (convtype == "velocity" || convtype == "Velocity")
		{
			std::cout << "Please select a conversion unit (kmph>mps || mps>kmph)\n";
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
			std::cout << "Do you want to start again? (Y/N)\n";
			std::cin >> aftermath;
			if (aftermath == "Y" || aftermath == "y")
			{
				system("CLS");
				main();
			}
			else if (aftermath == "N" || aftermath == "n")
			{
				std::cout << "See you again!" << std::endl;
				Sleep(1000);
				exit(0);
			}
		}
		else
		{
			std::cout << "Conversion type unknown, restarting in 5 seconds..\n";
			Sleep(5000);
			system("CLS");
			main();
		}
		/* simple restart approach instead of filling up the console making it hard to read */
		std::string aftermath;
		std::cout << "Do you want to start again? (Y/N)\n";
		std::cin >> aftermath;
		if (aftermath == "Y" || aftermath == "y")
		{
			system("CLS");
			main();
		}
		else if (aftermath == "N" || aftermath == "n")
		{
			std::cout << "See you again!" << std::endl;
			Sleep(1000);
			exit(0);
		}
	}
	else if (calctype == "3" || calctype == "advanced algorithms" || calctype == "Advanced Algorithms" || calctype == "algorithms")
	{
		std::cout << "Current calculation type: Algorithms\n";
		std::cout << "Input an array to sort:";
		
	}
	return 0;
}