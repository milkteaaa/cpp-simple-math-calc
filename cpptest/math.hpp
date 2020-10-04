#pragma once

/*
* C++ mathematic library
* won't crash when user attempts to divide a number by zero (undefined)
*/

///
// Including libs
///
#include <algorithm>

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
				std::cout << "Division by 0 is undefined\n";
				return NULL;
			}
			signed int a = x / y;
			return a;
		}
	}
	
	namespace conversion
	{
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
		int sortnum(int array[])
		{
			int n = sizeof(array) / sizeof(array[0]);
			std::sort(array, array + n);
			for (int i = 0; i < n; ++i)
				return array[i];
		}
	}
}