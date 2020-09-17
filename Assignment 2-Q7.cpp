/*
Name: Dominic Triano
Date Written:9/25/2018
Language: C++
Compiler: msvc
Description: Assignment 2, Question 7:
This code adds two matricies and adds them and outputs the result.
*/

#include <iostream>
#include <time.h>
using namespace std;

int main(void)
{
	int a[5][5];
	int b[5][5];//two five by five matricies
	srand((unsigned)time(0));//seed the random number method
	//population of a
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			a[r][c] = (rand() % 20) + 1; //call the method specifying the parameters you want it to generate in
		}
	}
	//population of b
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			b[r][c] = (rand() % 30) + 1;
		}
	}
	//output of a
	cout << "The generated matrix for a is as follows:\n";
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			cout << a[r][c] << " ";
		}
		//if the matrix is finished with the first row, output a new line and flush the buffer
		cout << endl;
	}
	cout << "The generated matrix for b is as follows:\n";
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			cout << b[r][c] << " ";
		}
		cout << endl;
	}
	//add the two matricies
	cout << "The sum of the matricies a and b is as follows:\n";
	for (int r = 0; r < 5; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			cout << a[r][c] + b[r][c] << " ";
			//Question 7 said to calculate the sum, but didn't say to assign it to a new matrix
		}
		cout << endl;
	}
	cout << "Press Enter to exit";
	cin.get();//keeps the window open, awaiting input from user
}