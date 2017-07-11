#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class Student
{
public:
	Student();
	virtual ~Student();
	Student(std::string name, short scores[3]);
	void printInfo();
	float getAverage();
	void setRank(short rank);
private:
	std::string name;
	short scores[3];
	short sum;
	float average;
	short rank;
};

