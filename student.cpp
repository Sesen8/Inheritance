/*
 * Title:		X X X X X X X X X
 * Purpose:		P P P P P P P P P
 * Author:		Master Shifu
 * Date:		Mmm DD, YYYY
 */

#include "date.h"
#include "person.h"
#include "student.h"
#include <sstream>

using std::stringstream;

Student::Student(const string &name, const Date &birthday)
        : Person(name, birthday) {

}

Student::Student(const string &name, const Date &birthday, const string &major)
        : Person(name, birthday), _major(major), _credits(0), _gpa(0){

}

Student::Student(const string &name, const Date &birthday, const string &major, size_t credits)
        : Person(name, birthday), _major(major), _credits(credits), _gpa(0){

}

Student::Student(const string &name, const Date &birthday, const string &major, size_t credits, float gpa)
        : Person(name, birthday), _major(major), _credits(credits), _gpa(gpa){

}

Student::~Student() {

}

string Student::ToString() const {

    stringstream ss;
    ss << "{Person: " <<  Person::ToString() << ", major: " << _major << ", credits:" << std::to_string(GetCredits()) << ", gpa: " << std::to_string(GetGPA()) << "}";



    return ss.str();
}

void Student::Read(istream &input) {

    string line;
    getline(input,line);
    stringstream cutUp(line);

    string major1;
    size_t credits1;
    float gpa1;

    Person::Read(input);
    cutUp >> major1 >> credits1 >> gpa1;

    _major=major1;
    _credits=credits1;
    _gpa=gpa1;

}

void Student::Write(ostream &output) const {

    string major1 =_major;
    size_t credits1 = GetCredits();
    float gpa1 = GetGPA();

    Person::Write(output);
    output << major1 << " " << credits1 << " " << gpa1;


}

void Student::AddGrade(float grade, size_t credits) {
    size_t totalGrade = _gpa * _credits;

    size_t newCredits = _credits + credits;
    _credits = newCredits;

    totalGrade+=grade;

    size_t newGPA = totalGrade/newCredits;
    _gpa = newGPA;

}

float Student::GetGPA() const {
    return _gpa;
}

size_t Student::GetCredits() const {
    return _credits;
}
