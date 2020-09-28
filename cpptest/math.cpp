#include <iostream>
#include "math.hpp"
#include <Windows.h>


int inputfromuser()
{
	int input{};
	std::cin >> input;
	return input;
}

double fractinputfromuser()
{
	double input{};
	std::cin >> input;
	return input;
}

std::string removespace(std::string& str)
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
	std::cout << "Please select a calculation type:\n1 - Algebra\n2 - Conversion\n3 - Advanced Algorithms\n";
	std::cin >> calctype;
	if (calctype == "1" || calctype == "algebra" || calctype == "Algebra")
	{
		std::cout << "Current calculation type: Algebra\n";
		std::cout << "Enter current x value: ";
		signed int x{ inputfromuser() };
		std::cout << "Your x value is: " << x << "\n";
		std::cout << "Enter current y value: ";
		signed int y{ inputfromuser() };
		std::cout << "Your y value is: " << y << "\n";
		std::string calcmode;
		std::cout << "Please select a calculation mode (add, subtract, multiply, divide)\n";
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
			std::cout << "Calculation method unknown, restarting in 5 seconds..\n";
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
			std::cout << "See you again!" << std::endl;
			Sleep(1000);
			exit(0);
		}
	}
	else if (calctype == "2" || calctype == "conversion" || calctype == "Conversion")
	{
		std::cout << "Current calculation type: Conversion\n";
		std::string convtype;
		std::cout << "Please select a conversion unit group (Length, Area, Volume, Velocity)";
		std::cin >> convtype;
		if (convtype == "length" || convtype == "Length")
		{
			
		}
		else if (convtype == "area" || convtype == "Area")
		{
			
		}
		else if (convtype == "volume" || convtype == "Volume")
		{
			
		}
		else if (convtype == "velocity" || convtype == "Velocity")
		{
			std::cout << "Please select a conversion unit (kmph>mps || mps>kmph)\n";
			std::string convunit;
			std::cin >> convunit;
			convunit.erase(std::remove(convunit.begin(), convunit.end(), ' '), convunit.end());
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
			std::cout << "Calculation method unknown, restarting in 5 seconds..\n";
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
			std::cout << "See you again!" << std::endl;
			Sleep(1000);
			exit(0);
		}
	}
	
	return 0;
}