/*
* Grade Management System - part 1
* data : 2017.06.14
* auth : han3l
*/
#include "stdafx.h"
#include "Student.h"

void printLine(Student* Students[5]);

int main()
{
	/*
	* Students : Student's grade info variable
	* name : Student's name
	* scores : Student's subject scores
	* { korean, english, mathematics }
	* rank : Student's rank
	*/
	Student* students[5];
	std::string name;
	short scores[3];
	short rank;

	// Enter the information of the students.
	for (int i = 0; i < 5; i++)
	{
		std::cin >> name >> scores[0] >> scores[1] >> scores[2];
		students[i] = new Student(name, scores);
	}
	
	// Set Up a rank
	for (int i = 0; i < 5; i++)
	{
		rank = 1;    
		for (int j = 0; j < 5; j++)
		{
			if (students[i]->getAverage() < students[j]->getAverage())
			{
				rank++;
			}
			students[i]->setRank(rank);
		}
	}

	// Print Information
	printLine(students);

	delete[] &students;

	return 0;
}

void printLine(Student* students[5])
{
	std::cout << "Name\t" << "Kor\t" << "Eng\t" << "Math\t" << "Sum\t" << "Avg\t" << "Rank\t" << std::endl;
	std::cout << "====================================================" << std::endl;
	for each(auto s in students)
	{
		s->printInfo();
	}
	std::cout << "====================================================" << std::endl;
}
