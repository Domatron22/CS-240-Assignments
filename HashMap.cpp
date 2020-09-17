/*
Name: Dominic Triano
Date: 12/6/2018
Compiler: MSVC
Description: Implimentation file for HashMap(Assignment 7)*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "HashMap.h"


HashMap::HashMap()
	: store(23)//saved constructor call by using initializing list
{

}


HashMap::~HashMap()
{

}

void HashMap::display()
{
	for (int i = 0; i < 23; i++)
	{
		if (store[i] != "\n")
		{
			std::cout << i << ": " << store[i];//outputs vector
		}
		else
		{
			std::cout << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void HashMap::input(std::string input)
{
	int f = 0;
	int b = 0;
	int p = 0;
	bool placed = false;
	placed = false;
	f = static_cast<int>(input[0]);//creates int value of the character
	b = static_cast<int>(input[input.length() - 1]);
	p = (f + b) % 23;//hash equation given
	while (!placed)
	{
		if (store[p] == "\0")//"\0" is null
		{
			store[p] = input;//inserts inputted word at said position
			placed = true;
		}
		else if (store[p] != "\0")
		{
			p++;
		}
		if (p == input.length() - 1)//if it reaches the end set it back to the front place
		{
			p = 0;
		}
	}
}

int HashMap::search(std::string search)
{
	int f = 0;
	int b = 0;
	int p = 0;
	int v = 0;
	f = static_cast<int>(search[0]);
	b = static_cast<int>(search[search.length() - 1]);
	p = (f + b) % 23;
	while (v == 0)//ne stands for non existant
	{
		if (store[p] == search)
		{
			v = p;
		}
		else if (store[p] != "\0")
		{
			p++;
		}
		else if (p == 22)
		{
			p = 0;
		}
		else {
			v = -1;
		}
	}
	return v;
}
