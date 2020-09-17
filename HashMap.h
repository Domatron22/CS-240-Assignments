/*
Name: Dominic Triano
Date: 12/6/2018
Compiler: MSVC
Description: Header file for HashMap(Assignment 7)*/

#pragma once
#include <vector>
#include <iostream>
class HashMap
{
private:
	std::vector<std::string> store;

	
public:
	HashMap();//constructor
	~HashMap();//destructor
	void input(std::string input);//inserts strings into the HashMap
	void display();//displays the HashMap
	int search(std::string search);//searches for a string in the HashMap

};

