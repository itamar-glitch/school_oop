/*
Author: Itamar Azran,
*/
#pragma once
#include "Teacher.h"
#include "Class.h"
class Tutor : public  Teacher
{
public:
	Tutor() {}//default Ctor 
	~Tutor() {}//Dtor
	Tutor(vector<string> new_subjects, int& num_subject, string first_name, string last_name, int& seniority_worker, int Seniority_manneger, Class* new_kita);//custom Ctor
	Class* get_kita();//returns pointer on Class of tutor
	int get_salary();//returns salary of tutor
	bool get_excelent();//check if tutor is excelent
	void print();//print tutor's data
private:
	Class* kita;
};

