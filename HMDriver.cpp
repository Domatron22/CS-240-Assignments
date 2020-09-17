/*
Name: Dominic Triano
Date: 12/5/2018
Compiler: MSVC
Description: 
Assignment 7 A.K.A. "HashMap"//Hash map is what is being created
1.) constructs a 23 element array using the hash function ((first_letter)+(last_letter))%23*
2.) queries the user for 15 words and store them using the hash function*
3.) print out the contents of each position of the array, showing vacant and showed positions*
4.) repetadely query user for a word, hash the word, check for its inclusion in the list, and report the result.*
Continue until the user wants to stop.
*/

#include <iostream>
#include <vector>
#include <string>
#include "HashMap.h"

using namespace std;

int main(void) 
{
	HashMap hash;
	int s = 0;
	string in;
	string in2;
	cout << "Enter fifteen words: \n ";
	for (int i = 0; i < 15; i++)
	{
		cin >> in;
		hash.input(in);
		cout << " ";
	}
	cout << "\nThe values of the vector are as follows: ";
	hash.display();
	do 
	{
		cout << "Enter a word to search, Press E to exit: \n";
		cin >> in2;
		s = hash.search(in2);
		if ( s == -1)
		{
			cout << "The inputted word was not found...\n";
		}
		else {
			cout << "The inputted word was found in position " << s << "\n";
		}
		
	} while (in2 != "E");
}