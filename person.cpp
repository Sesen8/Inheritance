/*
 * Title:		X X X X X X X X X
 * Purpose:		P P P P P P P P P
 * Author:		Master Shifu
 * Date:		Mmm DD, YYYY
 */
#include "person.h"
#include "date.h"

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


}

void Person::Write(ostream &output) const {



}

string Person::GetName() const {
    return _name;
}

size_t Person::GetAge() const {

    return _birthday.Difference(Date::Now()) / 365;
}
