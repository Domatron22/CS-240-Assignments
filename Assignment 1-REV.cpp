/*
Name: Dominic Triano
Date Written:9/5/2018
Date Revised: 9/13/2020
Language: C++
Compiler: msvc and g++
Description:  fills a 5 x 5 matrix of integers. 
The matrix must be a static matrix; its size must be fixed at compile-time. 
Display the contents of the matrix. Query the user for an integer.
Pass the matrix and the integer to a bool function that searches for the first occurrence, 
and only the first occurrence, of the integer in the
matrix. If the integer is found, the function returns true 
(and passes back the row and column coordinates of the first occurrence of the integer);
 if not, the function returns false. 
 Main then displays whether the integer was found in the matrix and if so, 
 the coordinates of the first occurrence.
*/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

bool finder(int matrix[5][5], int num, pair<int, int> & f);

int main(void)
{
	//Instance the variables in the method instead of globally
	int m[5][5] = { {0, 1, 2, 3, 4},
					{5, 6, 7, 8, 9},
					{10, 11, 12, 13, 14},
					{15, 16, 17, 18, 19},
					{20, 21, 22, 23, 24}
					}; //Five-by-Five Matrix
	pair <int, int> found;
	int n; //input number variable

	//output the matrix
	cout << "The matrix is as follows:\n";
	for (int r = 0; r < 5; r++)//rows 
	{
		for (int c = 0; c < 5; c++)//columns
		{
			cout << m[r][c] << " ";
		}
		cout << endl;
	}

	//Finding the integer the user wants
	cout << "Enter a positive integer and press enter:\n" ;
	cin >> n; //inputted number
	

	if (finder(m, n, found))
	{
		cout << "Item Found! at row: " << found.first << " and column: " << found.second << "\n";
	}
	else {
		cout << "Item not Found!\n";
	}

	cin.get(); //wait for enter to close the program
	cout << "Press Enter to exit";
	cin.get();

	return 0;
}

bool finder(int matrix[5][5], int num, pair<int, int> & f)
{
	for (int r = 0; r < 5; r++) 
	{
		for (int c = 0; c < 5; c++)
		{
			if (matrix[r][c] == num)
			{
				f = make_pair(r, c);
				return true;
			}
		}
	}
	return false;
}