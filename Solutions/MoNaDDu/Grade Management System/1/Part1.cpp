#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <memory>
#include <functional>
#include <algorithm>

using namespace std;

class Student;
class Students;

using StudentPtr = shared_ptr<Student>;
using StudentsPtr = shared_ptr<Students>;

class Student
{
	friend class Students;
	friend ostream& operator<<(ostream& os, Student student)
	{
		return os << left << setw(12) << student.name
			<< setw(5) << +student.korean_score
			<< setw(5) << +student.english_score
			<< setw(6) << +student.math_score
			<< setw(5) << student.sum
			<< setw(5) << fixed << setprecision(1) << student.average;
	}

	friend ostream& operator<<(ostream& os, Student* student)
	{
		return os << *student;
	}

public:
	Student(const string& name, const unsigned char korean_score, const unsigned char english_score, const unsigned char math_score)
		: name(name), korean_score(korean_score), english_score(english_score), math_score(math_score),
		sum(korean_score + english_score + math_score), average(sum / 3.0f)
	{

	}

private:
	const string name;
	const unsigned char korean_score;
	const unsigned char english_score;
	const unsigned char math_score;
	const short sum;
	const float average;
};

class Students : public enable_shared_from_this<Students>
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
		students.push_back(student);

		return shared_from_this();
	}

	StudentsPtr PrintScoreTable(void)
	{
		auto header{ MakeHeader() };
		
		cout << header << endl;
		PrintLine(header.size());

		auto rank_list{ MakeRankList() };

		for (auto i = 0u; i < students.size(); ++i)
		{
			PrintStudentInformation(students[i]);
			cout << setw(CalStreamSize(rank)) << rank_list[i] << endl;
		}
	
		PrintLine(header.size());
		PrintTotalSums();
		PrintTotalAverages();

		return shared_from_this();
	}

private:
	vector<StudentPtr> students;
	static const string name;
	static const string kor;
	static const string eng;
	static const string math;
	static const string sum;
	static const string avg;
	static const string rank;
	static const streamsize name_size = 12ll;

	string MakeHeader(void) const
	{
		stringstream ss;
		ss << left << setw(name_size) << name
			<< setw(CalStreamSize(kor)) << kor
			<< setw(CalStreamSize(eng)) << eng
			<< setw(CalStreamSize(math)) << math
			<< setw(CalStreamSize(sum)) << sum
			<< setw(CalStreamSize(avg)) << avg
			<< rank;

		return ss.str();
	}

	void PrintLine(const unsigned int n) const
	{
		for (auto i = 0u; i < n; ++i)
			cout << "=";
		cout << endl;
	}

	void PrintStudentInformation(const StudentPtr& student) const
	{
		cout << left << setw(name_size) << student->name
			<< setw(CalStreamSize(kor)) << +student->korean_score
			<< setw(CalStreamSize(eng)) << +student->english_score
			<< setw(CalStreamSize(math)) << +student->math_score
			<< setw(CalStreamSize(sum)) << student->sum
			<< setw(CalStreamSize(avg)) << fixed << setprecision(1ll) << student->average;
	}

	void PrintTotalSums(void) const
	{
		cout << left << setw(name_size) << sum
			<< setw(CalStreamSize(kor)) << SumOfKoreanScores()
			<< setw(CalStreamSize(eng)) << SumOfEnglishScores()
			<< setw(CalStreamSize(math)) << SumOfMathScores()
			<< setw(CalStreamSize(sum)) << SumOfTotalScores()
			<< endl;
	}

	void PrintTotalAverages(void) const
	{
		cout << left << setw(name_size) << avg
			<< setw(CalStreamSize(kor)) << AverageOfKoreanScores()
			<< setw(CalStreamSize(eng)) << AverageOfEnglishScores()
			<< setw(CalStreamSize(math)) << AverageOfMathScores()
			<< setw(CalStreamSize(sum)) << AverageOfTotalScores()
			<< endl;
	}

	float AverageOfKoreanScores(void) const
	{
		return static_cast<float>(SumOfKoreanScores()) / students.size();
	}

	float AverageOfEnglishScores(void) const
	{
		return static_cast<float>(SumOfEnglishScores()) / students.size();
	}

	float AverageOfMathScores(void) const
	{
		return static_cast<float>(SumOfMathScores()) / students.size();
	}

	float AverageOfTotalScores(void) const
	{
		return static_cast<float>(SumOfTotalScores()) / students.size() / 3.0f;
	}

	int SumOfKoreanScores(void) const
	{
		return ForEachForSum([](const auto& student) { return student->korean_score; });
	}

	int SumOfEnglishScores(void) const
	{
		return ForEachForSum([](const auto& student) { return student->english_score; });
	}

	int SumOfMathScores(void) const
	{
		return ForEachForSum([](const auto& student) { return student->math_score; });
	}
	
	int SumOfTotalScores(void) const
	{
		return ForEachForSum([](const auto& student) { return student->sum; });
	}

	int ForEachForSum(function<int(const StudentPtr&)> Func) const
	{
		auto sum{ 0 };

		for (const auto& student : students)
			sum += Func(student);

		return sum;
	}

	vector<unsigned int> MakeRankList(void) const
	{
		vector<unsigned int> ranks;

		for (const auto& student : students)
		{
			ranks.emplace_back(1u + count_if(cbegin(students), cend(students), [&student](const auto& e) {
				return student->sum < e->sum;
			}));
		}

		return ranks;
	}

	streamsize CalStreamSize(const string& title) const
	{
		return title.size() + 5u;
	}
};

const string Students::name = "Name";
const string Students::kor = "Kor";
const string Students::eng = "Eng";
const string Students::math = "Math";
const string Students::sum = "Sum";
const string Students::avg = "Avg";
const string Students::rank = "Rank";

int main()
{
	Students::MakeInstance()
		->PushBack(make_shared<Student>("John"s, 96, 92, 98))
		->PushBack(make_shared<Student>("Chris"s, 88, 90, 68))
		->PushBack(make_shared<Student>("James"s, 98, 80, 75))
		->PushBack(make_shared<Student>("Tom"s, 64, 70, 72))
		->PushBack(make_shared<Student>("Jane"s, 80, 88, 94))
		->PrintScoreTable();

	return 0;
}