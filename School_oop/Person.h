/*
Author: Itamar Azran
*/
#pragma once
#include <string>
#include <iostream>
using namespace std;
class Person
{
public:
	Person() {};//Default Ctor
	Person(string newname,string new_lastname) {//custom Ctor
		first_name = newname;
		last_name = new_lastname;
	}
	~Person() {};//Dtor
	virtual bool set_new_name(int choose, string newname, string new_lastname);//function change/set name of person
	virtual string get_names(int choose);//returns first name or last name
	virtual void print();//prints full name
	virtual bool get_exellent() { return false; }//check if "excellent" person
private:
	string first_name;
	string last_name;
};

