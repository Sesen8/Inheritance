/*
 * Title:		X X X X X X X X X
 * Purpose:		P P P P P P P P P
 * Author:		Master Shifu
 * Date:		Mmm DD, YYYY
 */
#include "person.h"
#include "date.h"
#include <sstream>
#include <string>
#include <iostream>
#include <ctime>
#include <cmath>

using std::string;
using std::stringstream;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;



Person::Person(const string &name, const Date &birthday) :_name(name), _birthday(birthday){


}

Person::Person(const string &name, size_t year, size_t month, size_t day) : _name(name), _birthday(Date(year,month,day)){

}

Person::~Person() {

}

string Person::ToString() const {

    string convert = "{name: " + _name + ", birthday: " + _birthday.ToString() + "}}";

    return convert;
}

void Person::Read(istream &input) {

    string line;
    getline(input,line);
    stringstream cutUp(line);


    string name;
    size_t year;
    size_t month;
    size_t day;

    cutUp >> name >> year >> month >> day;

    _name=name;
    Date newDate(year,month,day);
    _birthday = newDate;

}

void Person::Write(ostream &output) const {

    string name1 = _name;
    size_t year1 = _birthday.GetYear();
    size_t month1 = _birthday.GetMonth();
    size_t day1 = _birthday.GetDay();

    output << name1 << " " << year1 << " " << month1 << " " << day1;


}

string Person::GetName() const {
    return _name;
}

size_t Person::GetAge() const {

    return _birthday.Difference(Date::Now()) / 365;
}
