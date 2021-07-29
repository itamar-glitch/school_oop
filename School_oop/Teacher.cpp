/*
Author: Itamar Azran
*/
#include "Teacher.h"
#include "Worker.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
Teacher::Teacher(vector<string> new_subjects, int& num_subject, string first_name, string last_name, int& seniority_worker, int Seniority_manneger ): Worker(first_name, last_name,  seniority_worker,  Seniority_manneger){
	num_of_subject = num_subject;
	subject_list = new_subjects;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<string>Teacher::get_subject_list() {
	return subject_list;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Teacher:: get_numofsubject() {
	return num_of_subject;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Teacher::get_salary() {
	int x=0,y=0,bs=0;
	bs = Worker::get_base();
	x = get_numofsubject();
	y = this->get_seniority(1);//wich seniority need to return?????????????????????????? ? ? ? ? ? ? ? ? ? ? ? ? ????????????????????????????????????????????? ?? ?? ? ??  ?????  ????? ?  ?
	return bs * (1 + x / 10) + 300 * y;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Teacher::print_subject_list() {
	cout << endl << "Subjects: ";
	for (int i = 0; i < subject_list.size(); i++) {
		cout << subject_list[i];
		if (i < subject_list.size() - 1) {
			cout << ", ";
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Teacher::print() {
	Worker::print();
	cout << endl << "Nuber of subjects: " << num_of_subject;
	print_subject_list();
	int sal = get_salary();
	cout << endl << "Salary is: " << sal;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Teacher:: new_set_teacher(vector<string> new_subject_list, int new_num_of_subject) {
	this->subject_list= new_subject_list;
	this->num_of_subject = new_num_of_subject;
}
