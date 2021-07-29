/*
Author: Itamar Azran
*/
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "AdministrationPersonal.h"
#include "Teacher.h"
static class Manager:public AdministrationPersonal, public Teacher
{
public:
	static Manager get_static() { return *Manager::manager_ptr; }
	float manager_salary();
	bool get_exellent();
	void print();
	~Manager() {}
	static Manager* assign_manager(string new_office_place,vector<string> new_subjects, int& num_subject, string first_name, string last_name, int& seniority_worker, int Seniority_manneger);
private:
	Manager(){}
	void set_admin(string first_name, string last_name,int seniority_worker,int seniority_manager);
	Manager(string new_office_place, string first_name, string last_name, int seniority_worker, vector<string> new_subjects, int& num_subject, int Seniority_manneger = 0) :AdministrationPersonal(new_office_place, first_name, last_name, seniority_worker, Seniority_manneger) {
		set_admin(first_name, last_name, seniority_worker, Seniority_manneger);
		new_set_teacher(new_subjects, num_subject);
		manager_ptr=this;
	}
	Manager(string new_office_place, string first_name, string last_name, int seniority_worker, int Seniority_manneger = 0);
	static  Manager* manager_ptr;
};
 
