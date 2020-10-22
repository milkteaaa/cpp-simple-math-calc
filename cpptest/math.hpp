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
#include <complex>
#include <wtypes.h>
#include "console.hpp"

//#define ALLOW_UNTESTED

namespace mathlibrary
{
	namespace algebra 
	{
		int add(int x, int y)
		{
			return x + y;			
		}

		int subtract(int x, int y)
		{
			return x - y;
		}

		int multiply(int x, int y)
		{
			return x * y;			
		}

		int divide(int x, int y)
		{
			if (y == 0)
			{
				std::cout << clred << "[MATH ERROR] Division by 0 is undefined\n" << cl_white;
				return NULL;
			}
			else
			{
				return x / y;				
			}
		}

		namespace advanced_algebra
		{
			double squarert(double x)
			{
				if (x < 0)
				{
					std::cout << clred << "[MATH ERROR] Cannot sqrt a value of negative.\n" << cl_white;
					return NULL;
				}
				else
				{
					return sqrt(x);
				}
			}

			std::complex<double> imaginarysqrt(std::complex<double> x)
			{
				std::complex<double> i = std::sqrt(std::complex<double>(x));
				return i;
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
				return kmph * 3.6;				
			}

			double mpstokmph(double mps)
			{
				return mps / 3.6;				
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
			if (n == 1)
				return FALSE;
			if (n < 0)
				return FALSE;
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