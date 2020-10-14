#pragma once

/*
* C++ mathematic library
* won't crash when user attempts to divide a number by zero (undefined)
*/

///
// Including libs
///
#include <algorithm>
#include <iostream>
#include <wtypes.h>
#include "console.hpp"

//#define ALLOW_UNTESTED

namespace mathlibrary
{
	namespace algebra 
	{
		int add(signed int x, signed int y)
		{
			signed int a = x + y;
			return a;
		}

		int subtract(signed int x, signed int y)
		{
			signed int a = x - y;
			return a;
		}

		int multiply(signed int x, signed int y)
		{
			signed int a = x * y;
			return a;
		}

		int divide(signed int x, signed int y)
		{
			if (y == 0)
			{
				std::cout << clred << "[MATH ERROR] Division by 0 is undefined\n" << cl_white;
				return NULL;
			}
			else
			{
				signed int a = x / y;
				return a;
			}
		}

		namespace advanced_algebra
		{
			double squarert(double x)
			{
				if (x < 0)
				{
					std::cout << clred << "[MATH ERROR] Cannot sqrt a value of negative.\n" << cl_white;

				}
				else
				{
					double n = sqrt(x);
					return n;
				}
			}
		}

	}
	
	namespace conversion
	{
		namespace length
		{
			// @TODO: add conversion for lengths
		}

		namespace velocity
		{
			double kmphtomps(double kmph)
			{
				double a = kmph * 3.6;
				return a;
			}

			double mpstokmph(double mps)
			{
				double a = mps / 3.6;
				return a;
			}
		}
	}

	namespace algorithm
	{
#ifdef ALLOW_UNTESTED
		int sortnum(int array[])
		{
			int n = sizeof(array) / sizeof(array[0]);
			std::sort(array, array + n);
			for (int i = 0; i < n; ++i)
				return array[i];
		}
#endif
		int isPrime(int n)
		{
			int m = 0;
			int i = 0;
			int flag = 0;
			m = n / 2;
			for (i = 2; i <= m; i++)
			{
				if (n % i == 0)
				{
					flag = 1;
					return FALSE;
					break;
				}
			}
			if (flag == 0)
				return TRUE;			
		}

		int isEvenorOdd(int n)
		{			
			if (n % 2 == 0)
				return TRUE;
			else
				return FALSE;
		}
	}
}