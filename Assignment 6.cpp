/*
Name: Dominic Triano
Date: 11/27/2018
Language: C++
Description:
Finding the lowest, highest and average production levels, 
the difference in production on a day to day difference, 
and the total number of productions up to that day*/

#include <iostream>;
#include <numeric>;
#include <algorithm>;
#include <vector>;

using namespace std;

int main(void)
{
	vector <int> Doof;
	vector <int>::iterator p1, p2, maxRes, minRes;
	int diff[20];
	int pSum[20];
	int iDoof = 0;
	int sum = 0;
	double avg = 0; 
	cout << "Input Doofling production for the past 20 days: \n";
	for (int i = 0; i < 20; i++)
	{
		cin >> iDoof;
		Doof.push_back(iDoof); //pushing your values to Doof
	}
	cout << "Your production levels were as follows: \n";
	for (int i = 0; i < 20; i++)
	{
		cout << Doof[i] << " "; //Reads back values inputted
	}
	cout << "\n";
	p1 = Doof.begin(); //beggining value
	p2 = Doof.end();  //1 past end value
	maxRes = max_element(p1, p2); //finds max element
	minRes = min_element(p1, p2); //Finds min element
	cout << "The max production was: " << *maxRes << "\n";
	cout << "The min production was: " << *minRes << "\n";
	sum = accumulate(p1, p2, 0); //finds sum of the productin levels
	avg = sum / 20;
	cout << "The average production was: " << avg << "\n";
	adjacent_difference(p1, p2, diff); //finds the difference between each number
	cout << "The production level difference on a day to day basis was: \n";
	for (int i = 0; i < 20; i++)
	{
		cout << diff[i] << " "; //outputs those differences
	}
	cout << "\n";
	partial_sum(p1, p2, pSum); //finds the sum up to each number
	cout << "The accumulation of production on a day to day basis was: \n";
	for (int i = 0; i < 20; i++)
	{
		cout << pSum[i] << " "; //outputs that sum
	}
	cout << "\nPress enter to exit...";
	cin.get();
	cin.get();
}