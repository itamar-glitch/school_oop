/*
Author: Itamar Azran,
*/
#pragma once
#include "Worker.h"
#include <iostream>
class AdministrationPersonal: public virtual Worker
{
public:
	AdministrationPersonal() {}//default Ctor
	~AdministrationPersonal(){}//Dtor
	AdministrationPersonal(string new_office_place, string first_name, string last_name, int seniority_worker, int Seniority_manneger = 0);//custom Ctor
	string get_office_place();//returns office_place
	virtual void set_office_place(string new_office_place);//changes office_place
	virtual int get_salary();//returns salary
	virtual bool get_exellent();//check Admin exellent
	virtual void print_Admin();//prints Admin data
private:
	string office_place;
};

