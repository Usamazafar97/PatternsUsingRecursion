// Patterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<conio.h>

using namespace std;

void PrintSteric(char ch, int start)//Actually a helping function to print character (*) for all other functions
{
	if (start == 0)
	{
		return;
	}
	cout << ch;
	PrintSteric(ch, start - 1);
}

void PrintPatternNo1(int start, int end)//Pattern number one
{
	char ch = ' ';
	if (start == end)
	{
		cout << "     *" << "\n";
		start++;
		return;
	}
	PrintSteric(ch, start);
	cout << "*" << "\n";
	PrintPatternNo1(start + 1, end);//stack overroll
	PrintSteric(ch, start);
	cout << "*" << "\n";
}

void PrintPatternNo2(int size, int start, int end)//Pattern number two
{
	start = start - 1;
	if (start == end - 1)
	{
		return;
	}

	PrintSteric(' ', end - start);
	PrintSteric('*', ((2 * start) + 1));
	cout << "\n";
	PrintPatternNo2(size, start + 2, end);//stack overroll
	PrintSteric(' ', end - start);
	PrintSteric('*', ((2 * start) + 1));
	cout << "\n";
}

void PrintPatternNo3(int size, int start, int end)//Pattern number three
{
	start = start - 1;
	if (start == end)
	{

		return;
	}

	PrintSteric(' ', end - start);
	PrintSteric('*', ((2 * start) + 1));
	cout << "\n";


	PrintPatternNo3(size, start + 2, end);//stack overroll
	if (start == 0)
	{
		return;
	}
	start = start - 1;
	end = end;
	PrintSteric(' ', end - (start));
	PrintSteric('*', ((2 * (start)) + 1));
	cout << "\n";
}

void PrintPatternNo4(int size, int start, int end)//Pattern number four
{
	start = start - 1;
	//end = end + 1;
	if (start == size)
	{
		return;
	}
	PrintSteric(' ', end);
	cout << "|";

	PrintSteric(' ', end);
	PrintSteric('*', (2 * start));
	cout << "|";
	PrintSteric('*', (2 * start));
	PrintSteric(' ', end);
	cout << "|" << "\n";
	PrintPatternNo4(size, start + 2, end - 1);//stack overroll
	if (start == 0)
	{
		return;
	}
	start -= 1;
	end += 1;
	PrintSteric(' ', end);
	cout << "|";

	PrintSteric(' ', end);
	PrintSteric('*', (2 * start));
	cout << "|";
	PrintSteric('*', (2 * start));
	PrintSteric(' ', end);
	cout << "|" << "\n";
}

void PrintPatternNo5(int start, int end)//Pattern number five
{

	if (start == end)
	{
		return;
	}
	PrintSteric(' ', start);
	cout << "*";
	PrintSteric(' ', (end - start) + (end - start));
	cout << "*" << "\n";
	PrintPatternNo5(start + 1, end);//stack overroll
	if (start == end - 1)
	{
		PrintSteric(' ', start + 1);
		PrintSteric('*', 1);
		cout << "\n";
	}

	PrintSteric(' ', start);

	cout << "*";
	PrintSteric(' ', (end - start) + (end - start));
	cout << "*" << "\n";
}

void PrintPatternNo6(int start, int end)//Pattern number six
{
	start -= 1;
	if (start == end)
	{
		return;
	}
	PrintSteric(' ', end - start);
	cout << "*";
	PrintSteric(' ', 2 * (start));
	cout << "*" << "\n";
	PrintPatternNo6(start + 2, end);//stack overroll
	if (start == 0)
	{
		return;
	}
	start = start - 1;
	PrintSteric(' ', end - start);
	cout << "*";
	PrintSteric(' ', 2 * (start));
	cout << "*" << "\n";
}
int main()
{
	PrintPatternNo1(1, 5);
	PrintPatternNo2(5, 1, 5);
	PrintPatternNo3(5, 1, 5);
	PrintPatternNo4(5, 1, 5);
	PrintPatternNo5(1, 5);
	PrintPatternNo6(1, 5);
	_getch();//to pause the screen 
	return 0;
}

