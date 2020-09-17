/*
Name: Dominic Triano
Date Written: 10/10/2018
Date Modified: 11/13/2018
Language: c++
Compiler: msvc
Description: Adapted from my assignement 3, instead of searching for d words, it now sees if the file is a palendrome*/

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <sstream>


using namespace std;

int main(void)
{
	int c = 0;
	string fileName;
	string line;
	ifstream file;

	cout << "Enter File Name\n";
	cin >> fileName;
	file.open(fileName.data()); // takes what fileName is pointing to
	assert(file.is_open()); //test to see if file is open


	cout << "\nSearching file for d words... \n";

	while(getline(file,line))//get line of file
	{
		//cout << line << "\n"; //added this and line 44 when trying to find the problem with the reoccuring count

		stringstream stream(line); //streaming over a line from file
		while (!stream.eof())//while not at end of line
		{
			string word;//had to move string word inside while because it was recounting some words because the memory was preserved through the loop iterations
			stream >> word;// get next word in line
			//cout << word << "\n";
			if (word[0] == 'd' || word[0] == 'D')
			{
				c++; //count the amount of d words
			}
		}
	}

	cout << c << " words starting with 'd' \n";

	cout << "\nPress Enter to exit";
	cin.get();//keeps the window open, awaiting input from user
	cin.get();
}