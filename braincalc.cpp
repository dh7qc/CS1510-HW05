// Dennis Hahn CS1510 1B Homework #5
// braincalc.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "abstractstack.h"
#include "LLStack.h"

using namespace std;

int main()
{
	LLStack<int> brain;
	int a, b;
	string x;
	bool valid = false;

	cin >> x;
	do 
	{ 
		if ((x == "+" || x == "-" || x == "*" || x == "/") && brain.isEmpty() == false)
		{
			valid = true;
			a = brain.top();
			brain.pop();
			
			if (brain.isEmpty() == false)
			{
				b = brain.top();
				brain.pop();
			}
			else
			{
				brain.push(a);
				valid = false;
			}
		}

		if (x == "+")
		{
			if (valid)
				brain.push(b + a);
		}
		else if (x == "-")
		{
			if (valid)
				brain.push(b - a);
		}
		else if (x == "/")
		{
			if (valid && a != 0)
				brain.push(b / a);
		}
		else if (x == "*")
		{
			if (valid)
				brain.push(b * a);
		}
		else if (x == "!")
		{
			if (brain.isEmpty() == false)
			{
				a = brain.top();
				brain.pop();
				brain.push(-1*a);
			}
		}
		else if (x == "S")
		{
			if (brain.isEmpty() == false)
			{
				int total = 0;
				while (brain.isEmpty() == false)
				{
					total = total + brain.top();
					brain.pop();
				}

				brain.push(total);
			}
		}
		else if (x == "P")
		{
			if (brain.isEmpty() == false)
			{
				int total = 1;
				while (brain.isEmpty() == false)
				{
					total = total * brain.top();
					brain.pop();
				}
				brain.push(total);
			}
		}
		else if (x == "X")
		{
			brain.output();
		}
		else if (x == "C")
		{
			brain.clear();
		}
		else 
		{
			 brain.push(atoi(x.c_str()));
		}

		cin >> x;
	} while (x != "$");
	
	brain.clear();

	return 0;
}	
