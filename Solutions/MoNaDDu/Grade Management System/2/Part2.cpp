#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <memory>
#include <functional>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

class Student;
class Students;

using StudentPtr = shared_ptr<Student>;
using StudentsPtr = shared_ptr<Students>;

class Student final : public enable_shared_from_this<Student>
{
	friend class Students;

public:
	static StudentPtr MakeInstance(const string& name, const unsigned char korean_score, const unsigned char english_score, const unsigned char math_score)
	{
		return make_shared<Student>(name, korean_score, english_score, math_score);
	}

	Student(const string& name, const unsigned char korean_score, const unsigned char english_score, const unsigned char math_score)
		: name(name), scores({ korean_score, english_score, math_score }),
		sum(korean_score + english_score + math_score), average(sum / 3.0f)
	{

	}

	Student(const string& name, initializer_list<unsigned char> scores)
		: name(name), scores(scores),
		sum(accumulate(cbegin(scores), cend(scores), 0)), average(sum / static_cast<float>(this->scores.size()))
	{

	}

	Student(const string& name, const vector<unsigned char>& scores)
		: name(name), scores(scores),
		sum(accumulate(cbegin(scores), cend(scores), 0)), average(sum / static_cast<float>(this->scores.size()))
	{

	}

	Student(const string& name, vector<unsigned char>&& scores)
		: name(name), scores(move(scores)),
		sum(accumulate(cbegin(scores), cend(scores), 0)), average(sum / static_cast<float>(this->scores.size()))
	{

	}

	~Student() = default;

	void ForEachAboutScores(function<void(unsigned char)> Func) const
	{
		for_each(cbegin(scores), cend(scores), Func);
	}

private:
	const string name;
	const vector<unsigned char> scores;
	const short sum;
	const float average;
};

class Students final : public enable_shared_from_this<Students>
{
public:
	Students() = default;
	~Students() = default;

	static StudentsPtr MakeInstance(void)
	{
		return make_shared<Students>();
	}

	StudentsPtr PushBack(StudentPtr student)
	{
		if (student->scores.size() != subject_names.size())
			throw logic_error("학생 정보 등록 에러: 학생의 과목 정보 수와 과목 이름 수가 일치하지 않음.");

		students.push_back(student);

		return shared_from_this();
	}

	StudentsPtr PrintScoreTable(void)
	{
		if (students.empty())
			cout << "-= No Data =-" << endl;
		else
		{
			auto header{ MakeHeader() };

			PrintHeader(header);
			PrintLine(header.size());
			PrintStudentsInformation();
			PrintLine(header.size());
			PrintTotalSumsInformation();
			PrintTotalAveragesInformation();
		}

		return shared_from_this();
	}

private:
	vector<StudentPtr> students;
	static const string name;
	static const vector<string> subject_names;
	static const string sum;
	static const string avg;
	static const string rank;
	static const streamsize name_size{ 12ll };
	static const streamsize added_size{ 5ll };

	string MakeHeader(void) const
	{
		stringstream ss;

		ss << left << setw(name_size) << name;
		ForEach(subject_names, [&ss, this](const string& subject_name) { ss << setw(CalStreamSize(subject_name)) << subject_name; });
		ss << setw(CalStreamSize(sum)) << sum
			<< setw(CalStreamSize(avg)) << avg
			<< rank;

		return ss.str();
	}

	inline void PrintHeader(const string& header) const
	{
		cout << header << endl;
	}

	void PrintLine(const unsigned int n) const
	{
		fill_n(ostream_iterator<char>(cout), n, '=');
		cout << endl;
	}

	void PrintStudentsInformation(void) const
	{
		ForEach(students, bind(&Students::PrintStudentInformation, this, placeholders::_1));
	}

	void PrintStudentInformation(const StudentPtr& student) const
	{
		cout << left << setw(name_size) << student->name;
		PrintStudentScores(student);
		cout << setw(CalStreamSize(sum)) << student->sum
			<< setw(CalStreamSize(avg)) << fixed << setprecision(1ll) << student->average
			<< setw(CalStreamSize(rank)) << GetRank(student) << endl;
	}

	void PrintStudentScores(const StudentPtr& student, const unsigned int index = 0u) const
	{
		if (index == subject_names.size())
			return;

		cout << setw(CalStreamSize(subject_names[index])) << +student->scores[index];

		PrintStudentScores(student, index + 1);
	}

	unsigned int GetRank(const StudentPtr& student) const
	{
		return 1u + count_if(cbegin(students), cend(students), [&student](const auto& e) { return student->sum < e->sum; });
	}

	void PrintTotalSumsInformation(void) const
	{
		cout << left << setw(name_size) << sum;
		PrintTotalSums();
		cout << setw(CalStreamSize(sum)) << SumOfTotalScores() << endl;
	}

	void PrintTotalSums(const unsigned int index = 0u) const
	{
		if (index == subject_names.size())
			return;

		cout << setw(CalStreamSize(subject_names[index]))
			<< ForEachAboutSum([index](const auto& student) { return student->scores[index]; });

		PrintTotalSums(index + 1);
	}

	int SumOfTotalScores(void) const
	{
		return ForEachAboutSum([](const auto& student) { return student->sum; });
	}

	void PrintTotalAveragesInformation(void) const
	{
		cout << left << setw(name_size) << avg;
		PrintTotalAverages();
		cout << setw(CalStreamSize(sum)) << AverageOfTotalScores()
			<< endl;
	}

	void PrintTotalAverages(const unsigned int number_of_subjects = 0u) const
	{
		if (number_of_subjects == subject_names.size())
			return;

		cout << setw(CalStreamSize(subject_names[number_of_subjects]))
			<< ForEachAboutSum([number_of_subjects](const auto& student) { return student->scores[number_of_subjects]; }) / static_cast<float>(students.size());

		PrintTotalAverages(number_of_subjects + 1);
	}

	float AverageOfTotalScores(void) const
	{
		return static_cast<float>(SumOfTotalScores()) / students.size() / subject_names.size();
	}

	template<typename T>
	void ForEach(const T& list, function<void(const typename T::value_type&)> Func) const
	{
		for_each(cbegin(list), cend(list), Func);
	}

	int ForEachAboutSum(function<int(const StudentPtr&)> Func) const
	{
		return accumulate(cbegin(students), cend(students), 0, [&Func](const int acc, const auto& student) { return acc + Func(student); });
	}

	streamsize CalStreamSize(const string& title) const
	{
		return title.size() + added_size;
	}
};

const string Students::name{ "Name"s };
const vector<string> Students::subject_names{ "Kor"s, "Eng"s, "Math"s };
const string Students::sum{ "Sum"s };
const string Students::avg{ "Avg"s };
const string Students::rank{ "Rank"s };

void PrintMenu(void)
{
	cout << "\n- Menu Select -\n";
	cout << "   1. Input Student's grade\n";
	cout << "   2. Print Student's grade\n";
	cout << "   3. Exit\n\n";
	cout << "Select : ";
}

size_t Input(void)
{
	size_t selected_number;

	cin >> selected_number;

	return selected_number;
}

template<typename T>
void Read(T& input, const string& header = "")
{
	cout << header;
	cin >> input;
}

StudentPtr ReadStudentInformation(void)
{
	string name;
	int korean_score;
	int english_score;
	int math_score;

	Read(name, "> Name : ");
	Read(korean_score, "> Korean : ");
	Read(english_score, "> English : ");
	Read(math_score, "> Math : ");

	return Student::MakeInstance(name, korean_score, english_score, math_score);
}

void ReadStudentsInformation(StudentsPtr& students)
{
	students->PushBack(ReadStudentInformation());

	char answer;

	Read(answer, "> Do you continue to input (Y/N)? ");

	if (toupper(answer) == 'Y')
		ReadStudentsInformation(students);
}

void PrintSocreTable(const StudentsPtr& students)
{
	students->PrintScoreTable();
	cout << endl;
}


void Play(StudentsPtr& students)
{
	PrintMenu();

	switch (Input())
	{
	case 1:
		ReadStudentsInformation(students);
		break;

	case 2:
		PrintSocreTable(students);
		break;

	case 3:
		return;

	default:
		cout << "Invalid number! Try again." << endl;
		break;
	}

	Play(students);
}

int main()
{
	Play(Students::MakeInstance());

	return 0;
}