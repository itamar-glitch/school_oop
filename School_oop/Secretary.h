/*
Author: Itamar Azran,
*/
#pragma once
#include"Worker.h"
class Secretary :public Worker
{
public:
	Secretary(){}//default Ctor
	Secretary(int child_pupil_num,string first_name, string last_name, int seniority_worker, int Seniority_manneger = 0);//custom Ctor
	~Secretary(){}//Dtor
	int get_salary();//returns salary of Secretary
	bool get_exellent();//check if secretary is excelent
	void print();//prints secretary's data
private:
	int child_pupil = 0;//childs  of secretary that are pupils in this school
};

