/*
Author: Itamar Azran
*/
#include "AdministrationPersonal.h"
AdministrationPersonal::AdministrationPersonal(string new_office_place, string first_name, string last_name, int seniority_worker, int Seniority_manneger) :Worker(first_name, last_name, seniority_worker, Seniority_manneger){
	office_place = new_office_place;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string AdministrationPersonal::get_office_place() {//returns office_place
	return office_place;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AdministrationPersonal::set_office_place(string new_office_place) {
	office_place = new_office_place;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int AdministrationPersonal::get_salary() {//returns salary
	return Worker::get_Manager_salary();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool AdministrationPersonal:: get_exellent() {//check Admin exellent
	return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AdministrationPersonal::print_Admin() {//prints Admin data]
	Worker::print();
	int sal = get_salary();
	cout << endl << "Salary is: " << sal;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
