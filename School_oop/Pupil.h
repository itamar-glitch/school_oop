/*
Author: Itamar Azran
*/
#pragma once
#include "Person.h"
#include <string>
#include <iostream>
#include <vector>//students
using namespace std;
class Pupil: public Person//Person is Inheritance of Pupil
{
public:
	Pupil() {};//Default Ctor
	Pupil(vector<int>& new_grades,string newstudent_layer,int newclass_number,string fullname,string lastname);//custom Ctor
	~Pupil() {};//Dtor
	float get_avrage();//returns average of pupil
	bool get_exellent();//returns True if pupil is excelent, else false
	void print();//prints pupil's data
	void set_pupil_grades(vector<int>& new_grads);//sets the grades
	void set_layer(char new_layer);//sets char of pupils classroom
	void set_class_number(int& newclass_number);//sets number of classroom
	vector<int> get_grades();//returns vector of grades
	string get_names(int& choose);//return name
private:
	vector<int> grades;
	string student_layer;
	int class_number;

};

