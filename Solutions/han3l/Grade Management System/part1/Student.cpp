#include "stdafx.h"
#include "Student.h"


Student::Student()
{
}

Student::~Student()
{
}

Student::Student(std::string name, short scores[3])
	: name(name), scores{scores[0], scores[1], scores[2]},
	sum(scores[0] + scores[1] + scores[2]), average(sum / 3.0f)
{
}

void Student::printInfo()
{
	std::cout << name << "\t";
	for (int i = 0; i < 3; i++)
	{
		std::cout << scores[i] << "\t";
	}
	std::cout << sum << "\t";
	std::cout << std::fixed << std::setprecision(1) << average << "\t";
	std::cout << rank << std::endl;
}

float Student::getAverage()
{
	return this->average;
}

void Student::setRank(short rank)
{
	this->rank = rank;
}