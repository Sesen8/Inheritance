/*
 * Title:		X X X X X X X X X
 * Purpose:		P P P P P P P P P
 * Author:		Master Shifu
 * Date:		Mmm DD, YYYY
 */

#include "date.h"
#include "person.h"
#include "professor.h"
#include <sstream>

using std::stringstream;

Professor::Professor(const string &name, const Date &birthday, const string &department)
        : Person(name, birthday) , _department(department), _hireDate(Date::Now()), _rank(ASSISTANT_PROFESSOR), _salary(60000){

}

Professor::Professor(const string &name, const Date &birthday, const string &department, const Date &hireDate)
        : Person(name, birthday) , _department(department), _hireDate(hireDate), _rank(ASSISTANT_PROFESSOR), _salary(60000){

}

Professor::Professor(const string &name, const Date &birthday, const string &department, const Date &hireDate, Rank rank)
        : Person(name, birthday) , _department(department), _hireDate(hireDate), _rank(rank), _salary(60000) {

}

Professor::Professor(const string &name, const Date &birthday, const string &department, const Date &hireDate, Rank rank, float salary)
        : Person(name, birthday) , _department(department), _hireDate(hireDate), _rank(rank), _salary(salary) {

}

Professor::~Professor() {

}

string Professor::ToString() const {
    stringstream ss;
    ss << "{Person: " <<  Person::ToString() << ", department: " << _department << ", rank: " << GetRank()
            << ", hire-date: " << _hireDate <<", salary: " << std::to_string(GetSalary()) << "}";

    return ss.str();
}

void Professor::Read(istream &input) {
    string line;
    getline(input,line);
    stringstream cutUp(line);

    string department1;
    size_t hireYear,hireMonth,hireDay;
    float salary1;

    Person::Read(input);
    cutUp >> department1 >> hireYear >> hireMonth >> hireDay >> salary1;

    _department=department1;
    Date newDate(hireYear,hireMonth,hireDay);
    _hireDate = newDate;
    _salary=salary1;
}

void Professor::Write(ostream &output) const {
    string department1 =_department;
    size_t hireYear1 = _hireDate.GetYear();
    size_t hireMonth1 = _hireDate.GetMonth();
    size_t hireDay1 = _hireDate.GetDay();
    float salary1 = GetSalary();
    Person::Write(output);
    output << department1 << " " << hireYear1 << " " << hireMonth1 << " " << hireDay1 << " " << salary1;

}

void Professor::Raise(float percentage) {
    float increase = _salary * percentage;

    float newSalary = _salary +increase;

    _salary = newSalary;


}

void Professor::Promote() {
    if (_rank == ASSISTANT_PROFESSOR ){
        _rank = ASSOCIATE_PROFESSOR;
        if(_salary <70000){
            _salary = 70000;
        }
    }
    else if(_rank == ASSOCIATE_PROFESSOR){
        _rank = PROFESSOR;
        if(_salary <75000){
            _salary = 75000;
        }
    }
}

Rank Professor::GetRank() const {
    return _rank;
}

float Professor::GetSalary() const {
    return _salary;
}
