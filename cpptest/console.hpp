#pragma once
#include <Windows.h>
#include <iostream>

inline std::ostream& clblue(std::ostream& s)
{
	HANDLE hstdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hstdOut, FOREGROUND_BLUE);
	return s;
}

inline std::ostream& clred(std::ostream& s)
{
	HANDLE hstdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hstdOut, FOREGROUND_RED);
	return s;
}

inline std::ostream& clcyan(std::ostream& s)
{
	HANDLE hstdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hstdOut, FOREGROUND_BLUE | FOREGROUND_GREEN);
	return s;
}

inline std::ostream& cl_igreen(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& cl_iyellow(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& cl_iaqua(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& cl_ipurple(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& cl_icyan(std::ostream& s)
{
	HANDLE hstdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hstdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& clgreen(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN);
	return s;
}

inline std::ostream& clyellow(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_RED);
	return s;
}

inline std::ostream& claqua(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_GREEN | FOREGROUND_BLUE);
	return s;
}

inline std::ostream& clpurple(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_BLUE);
	return s;
}


inline std::ostream& cl_iblue(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& cl_ired(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& cl_white(std::ostream& s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	return s;
}


