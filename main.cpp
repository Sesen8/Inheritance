#include "date.h"
#include "person.h"
#include "student.h"
#include "professor.h"


#include <iostream>
#include <vector>

using std::cin;
using std::cerr;
using std::cout;
using std::getline;
using std::endl;
using std::vector;

size_t Menu();

int main(int argc, char* argv[]) {
	vector<Person*> people; // This is the only vector you need, remember to release the memory
	int userOption;
	while ( (userOption = Menu()) != 15){

        if (userOption == 1){			// Add Person
            string empty;
            getline(cin, empty);

            cout << "Name: ";
            string name;
            //cin >> name;
            getline(cin,name);


            cout << "Birthday yyyy mm d: ";
            string year;
            string month;
            string day;
            getline(cin,year, ' ');
            getline(cin,month, ' ');
            getline(cin,day);


            Person* newPerson = new Person(name,stoul(year),stoul(month),stoul(day));
            people.push_back(newPerson);
            cout << "Person inserted in position: " << people.size()-1<< endl;

		}



        else if (userOption == 2){		// Add Student
            string empty;
            getline(cin, empty);

            cout << "Name: ";
            string name;
            //cin >> name;
            getline(cin,name);


            cout << "Birthday yyyy mm d: ";
            string year;
            string month;
            string day;
            getline(cin,year, ' ');
            getline(cin,month, ' ');
            getline(cin,day);

            cout << "Major: ";
            string major;
            getline(cin,major);

            Date birthday(stoul(year),stoul(month),stoul(day));

            Student* newStudent = new Student(name,birthday,major);
            people.push_back(newStudent);
            cout << "Student inserted in position: " << people.size()-1<< endl;


		}

        else if (userOption == 3){		// Add Professor
            string empty;
            getline(cin, empty);

            cout << "Name: ";
            string name;
            //cin >> name;
            getline(cin,name);


            cout << "Birthday yyyy mm d: ";
            string year;
            string month;
            string day;
            getline(cin,year, ' ');
            getline(cin,month, ' ');
            getline(cin,day);

            cout << "Department: ";
            string department;
            getline(cin,department);

            cout << "Hire Date yyyy mm d: ";
            string year1;
            string month1;
            string day1;
            getline(cin,year1, ' ');
            getline(cin,month1, ' ');
            getline(cin,day1);

            Date birthday(stoul(year),stoul(month),stoul(day));
            Date hiredate(stoul(year1),stoul(month1),stoul(day1));

            Professor* newProfessor = new Professor(name,birthday,department,hiredate);
            people.push_back(newProfessor);
            cout << "Professor inserted in position: " << people.size()-1<< endl;


        }
        else if (userOption == 4){		// List All People
            if(people.size() == 0){
                cout << "No People added" << endl;
                continue;
            }
            for(int i = 0; i<people.size(); i++){

                if(dynamic_cast<Student*>(people.at(i)) != nullptr){
                    Student* foundStudent=(dynamic_cast<Student*>(people.at(i)));
                    cout << foundStudent->ToString() << endl;
                }
                else if(dynamic_cast<Professor*>(people.at(i)) != nullptr){
                    Professor* foundProfessor=(dynamic_cast<Professor*>(people.at(i)));
                    cout << foundProfessor->ToString() << endl;
                }
                else {
                    cout << people.at(i)->ToString() << endl;
                }

            }


		}


        else if (userOption == 5){		// Show Students Report
            if(people.size() == 0){
                cout << "No People added" << endl;
                continue;
            }
            bool check = false;


            for(int i = 0; i<people.size(); i++) {
                if((dynamic_cast<Student*>(people.at(i))) != nullptr){
                    Student* foundStudent=(dynamic_cast<Student*>(people.at(i)));
                    cout << foundStudent->ToString() << endl;
                    check = true;
                }
            }
            if(check == false){
                cout << "No Student added" << endl;
                continue;
            }
		}



        else if (userOption == 6){		// Show Professor Report
            if(people.size() == 0){
                cout << "No People added" << endl;
                continue;
            }
            bool check = false;

            for(int i = 0; i<people.size(); i++) {
                if(dynamic_cast<Professor*>(people.at(i)) != nullptr){
                    Professor* foundProfessor=(dynamic_cast<Professor*>(people.at(i)));
                    cout << foundProfessor->ToString() << endl;
                    check = true;
                }
            }
            if(check == false){
                cout << "No Student added" << endl;
                continue;
            }
		}



        else if (userOption == 7) {        // Show !Professor !Student
            if(people.size() == 0){
                cout << "No People added" << endl;
                continue;
            }

            for (int i = 0; i < people.size(); i++) {

                if ((dynamic_cast<Student *>(people.at(i)) == nullptr) &&
                    (dynamic_cast<Professor *>(people.at(i)) == nullptr)) {
                    cout << people.at(i)->ToString() << endl;
                }

            }
        }





        else if (userOption == 8){		// Calculate Average GPA
            int numofStudents = 0;
            float totalGPA;
            for(int i = 0; i<people.size(); i++) {
                if(dynamic_cast<Student*>(people.at(i)) != nullptr){
                    Student* foundStudent=dynamic_cast<Student*>(people.at(i));
                    float gpa = foundStudent->GetGPA();
                    totalGPA += gpa;
                    numofStudents++;
                }

            }

            float avgGPA = (totalGPA)/static_cast<float>(numofStudents);
            cout << "The average GPA of the students is: " << avgGPA << endl;

		}





        else if (userOption == 9){		// Calculate Average Salary
            float numofProfessors = 0;
            float totalSalary;
            for(int i = 0; i<people.size(); i++) {
                if(dynamic_cast<Professor*>(people.at(i)) != nullptr){
                    Professor* foundProfessor=dynamic_cast<Professor*>(people.at(i));
                    float salary = foundProfessor->GetSalary();
                    totalSalary += salary;
                    numofProfessors++;
                }

            }

            float avgSal = (totalSalary)/numofProfessors;
            cout << "The average salary of the professors is: " << avgSal << endl;

		}





        else if (userOption == 10){	// Input Grades to Student
            for(int i = 0; i<people.size(); i++) {
                if(dynamic_cast<Student*>(people.at(i)) != nullptr){
                    Student* foundStudent=dynamic_cast<Student*>(people.at(i));
                    cout << i << " " << foundStudent->ToString() << endl;
                }
            }

            int index =0;
            cout << "Number of student to input grades to: ";
            cin >>index;
            while(index>people.size()-1){
                cout <<"Position Out of Range!" << endl;
                cout << "Number of student to input grades to: ";
                cin >>index;
            }
            cout << "Grade of the student [0.0 to 4.0 scale]: ";
            float grade;
            string strGrade;
            cin >> strGrade;
            while(!isdigit(strGrade.at(0))){
                cout <<"Incorrect input!" << endl;
                cout << "Grade of the student [0.0 to 4.0 scale]: ";
                cin >> strGrade;

            }
            grade = stof(strGrade);
            while(grade>4.0 || grade<0.0){
                cout <<"Invalid grade value, make sure to use the scale [0.0 to 4.0]" << endl;
                cout << "Grade of the student [0.0 to 4.0 scale]: ";
                cin >> grade;

            }
            cout << "Credits {1,2,3,4,5}: ";
            size_t credits;
            cin >> credits;
            while(credits>5 || credits<1){
                cout <<"Invalid grade value, make sure to use the scale {1,2,3,4,5}" << endl;
                cout << "Credits {1,2,3,4,5}: ";
                cin >> credits;
            }

            dynamic_cast<Student*>(people.at(index))->AddGrade(grade,credits);

		}





        else if (userOption == 11){	// Promote Professor
            for (int i = 0; i < people.size(); i++) {

                if(dynamic_cast<Professor*>(people.at(i)) != nullptr){
                    Professor* foundProfessor=dynamic_cast<Professor*>(people.at(i));
                    cout << i << " " << foundProfessor->ToString() << endl;
                }

            }
            cout << "Number of Professor to Promote: ";
            size_t index;
            cin >>index;
            while(index>people.size()-1){
                cout <<"Position Out of Range!" << endl;
                cout << "Number of professor to give raise: ";
                cin >>index;
            }
            (dynamic_cast<Professor*>(people.at(index)))->Promote();


		}
        else if (userOption == 12){	// Give Raise to Professor
            for (int i = 0; i < people.size(); i++) {

                if(dynamic_cast<Professor*>(people.at(i)) != nullptr){
                    Professor* foundProfessor=dynamic_cast<Professor*>(people.at(i));
                    cout << i << " " << foundProfessor->ToString() << endl;
                }

            }

            int index =0;
            cout << "Number of professor to give raise: ";
            cin >>index;
            while(index>people.size()-1){
                cout <<"Position Out of Range!" << endl;
                cout << "Number of professor to give raise: ";
                cin >>index;
            }

            cout << "Raise to the professor [0.0, 50.0]: ";
            float raise;
            string strRaise;
            cin >> strRaise;
            while(!isdigit(strRaise.at(0))){
                cout <<"Incorrect input!" << endl;
                cout << "Raise to the professor [0.0, 50.0]: ";
                cin >> strRaise;

            }
            raise = stof(strRaise);
            while(raise>50.0 || raise<0.0){
                cout <<"Invalid raise value, make sure to use the scale [0.0, 50.0]" << endl;
                cout << "Raise to the professor [0.0, 50.0]: ";
                cin >> raise;

            }

            float newRaise = raise/100.0;
            (dynamic_cast<Professor*>(people.at(index)))->Raise(newRaise);





		}
        else if (userOption == 13){	// Load from File

		}
        else if (userOption == 14){	// Write to File

		}
	}
	return 0;
}

size_t Menu(){
	int option = 0;
	while(true){
		cout << "-------------------------------------------" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Add a Student" << endl;
		cout << "3. Add a Professor" << endl;
		cout << "4. List all People" << endl;
		cout << "5. Show Students Report" << endl;
		cout << "6. Show Professors Report" << endl;
		cout << "7. Show People (not Professors or Students)" << endl;
		cout << "8. Calculate all Students Average GPA" << endl;
		cout << "9. Calculate all Professors Average Salary" << endl;
		cout << "10. Input Grades to Student" << endl;
		cout << "11. Promote Professor" << endl;
		cout << "12. Give Raise to Professor" << endl;
		cout << "13. Load Data from File" << endl;
		cout << "14. Write Data to File" << endl;
		cout << "15. Exit" << endl;

		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Incorrect input!" << endl;
			continue;
		}
		if (option < 1 || option > 15){
			cerr << "Incorrect menu option!" << endl;
			continue;
		}
		break;
	}
	cout << endl;
	return static_cast<size_t>(option);
}
