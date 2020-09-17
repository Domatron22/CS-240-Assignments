/*
Name: Dominic Triano
Date: 11/2/2018
Language: C++
Description: This program takes the prime factorization of a number inputted by the user
*/

#include <iostream>
#include "stack.h"

using namespace std;

int main(void)
{
	Stack s;
	int a; // User input
	int n = 2; //2 will be lowest since it has to be greater than one
	int d; //

	cout << "Enter a positive integer greater than 1: ";
	cin >> a;
	d = a;

	while (d > 1)
	{
		if (d % n == 0)//n goes into d evenly
		{
			d = d / n; 
			s.push(n); //n is added to the stack
		}
		else {
			n++; //if it doesnt go into d evenly, we increase it until it does
		}
	}

	cout << "\nPrime factors for " << a << " are as follows: \n";
	while (!s.empty())
	{
		cout << s.top() << " ";//gets value from stack
		s.pop(); //pops value after being printed
	}

	cin.get();//keeps the window open, awaiting input from user
	cin.get();
}