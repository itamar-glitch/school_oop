/* Assignment: 3
Author1: Itamar Azran,
ID: 307955450
Author2: Yevgeniy Gluhoy,
ID: 336423629
*/
#include "Pupil.h"
#include <string>
#include <iostream>
#include <vector>
Pupil:: Pupil(vector<int>& new_grades, string newstudent_layer, int newclass_number,string fullname,string lastname): Person(fullname,lastname) {
	grades = new_grades;
	student_layer = newstudent_layer;
	class_number= newclass_number;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float Pupil::get_avrage() {
	int number_of_subjects = grades.size();//size of grade's vector
	float avrage = 0;
	for (int i = 0; i <= number_of_subjects-1; i++) {//sum of all grades
		avrage += grades.at(i);
	}
	return avrage / number_of_subjects;//average
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Pupil::get_exellent() {
	float avrage;
	int number_of_subjects = grades.size();//size of grade's vector
	avrage = get_avrage();//average
	if (avrage > 85) {//first condition to "excelent"
		for (int i = 0; i <= number_of_subjects-1; i++) {
			if (grades.at(i) < 65) {//second condition to "excelent"
				return false;
			}
		}
		return true;//all conditions are met
	}
	return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Pupil::print() {
	int number_of_subjects = grades.size();//size of grade's vector
	int i = 0;
	Person::print();//prints full name
	if (number_of_subjects != 0) {//prints grades
		cout << "grades: ";
		for (i = 0; i < number_of_subjects-1; i++) {
			cout << grades.at(i) << ", ";
		}
		cout << grades.at(i) << endl;
	}
	bool exellent = get_exellent();//returns True if pupil is excelent, else false
	if (get_exellent()) {
		cout << "academic status: " << "exellent" << endl;
	}
	else {
		cout << "academic status: " << "not exellent" << endl;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Pupil::set_pupil_grades(vector <int>& new_grades) {
	grades = new_grades;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Pupil::set_layer(char new_layer) {
	student_layer = new_layer;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Pupil:: set_class_number(int& newclass_number) {
	class_number = newclass_number;
}
vector<int> Pupil::get_grades() {
	return grades;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string Pupil::get_names(int& choose) {
	string name;
	if (choose == 1) {
		name = this->get_names(choose);
		return name;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////