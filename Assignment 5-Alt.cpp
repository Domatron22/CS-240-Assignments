/*
Name: Dominic Triano
Date Written: 11/13/2018
Date Modified: 12/3/2018
Language: c++
Compiler: msvc
Description:Searches File for Pallendrome*/

#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cassert>
#include <sstream>
#include <stack>



using namespace std;

int main(void)
{
	int n = 0;
	string fileName;
	string line;
	ifstream file;
	stack <string> pal;
	int pals = 0;
	int count = 0;

	cout << "Enter File Name\n";
	cin >> fileName;
	file.open(fileName.data()); // takes what fileName is pointing to
	assert(file.is_open()); //test to see if file is open


	cout << "\nSearching file for pallendromes... \n";

	while (getline(file, line))//get line of file
	{
		stringstream stream(line); //streaming over a line from file
		while (!stream.eof())//while not at end of line
		{
			string word;
			stream >> word;// get next word in line
			stack <char> sword;//changed from string to char
			queue <char> qword;
			int c = 0;
			int l = word.length();
			for (int i = 0; i < l; i++)
			{
				qword.push(tolower(word[i]));//push on the word to the stack and the queue
				sword.push(tolower(word[i]));//added to lower to turn to lowercase in case it is uppercase

			}
			for (int j = 0; j < l; j++)
			{
				if (sword.top() == qword.front())
				{
					c++;//if the front letter is that same as the back letter, increment by 1
				}
				qword.pop();//pop that letter so it compare the next
				sword.pop();
			}
			if (l == c)//if the length is the same as amount of letters that were both front and back
			{
				pals++;
				pal.push(word);//add it to a stack of palendromes
			}

		}
		count++;
	}

	cout << pals << " palendromes in the selected file \n";
	cout << "They are as follows: \n";

	while(!pal.empty())
	{
		cout << pal.top() << " ";
		pal.pop();
	}

	cout << "\n" << count << " words in file.";

	cout << "\nPress Enter to exit";
	cin.get();//keeps the window open, awaiting input from user
	cin.get();
}