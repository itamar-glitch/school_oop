/*
Author: Itamar Azran
*/
#include "Manager.h"
using namespace std;
Manager* Manager::manager_ptr = 0;
float Manager:: manager_salary() {
	int Teacher_salary = Manager::Teacher::get_salary();
	int base = AdministrationPersonal::Worker::get_base();
	int seniority = Worker::get_seniority(0);
	float salary = base * 2 + 500 * seniority;
	if (typeid(this) == typeid(Teacher)) {
		salary += Teacher::get_salary();
	}
	return salary;
}
bool Manager::get_exellent() {
	int seniority = Worker::get_seniority(0);
	if (seniority>=3) {
		return true;
	}
	return false;
}
 Manager* Manager::assign_manager(string new_office_place, vector<string> new_subjects, int& num_subject, string first_name, string last_name, int& seniority_worker, int Seniority_manneger=0)
 {
		
	if (manager_ptr != NULL) {
		cout << "you are a loser so you cant be a manager yevgeni we need to chage it!!!!!!@!@!@!@" << endl;
		return NULL;
	}
	else if (num_subject != 0) {//if teacher has subject
		Manager* manager_ptr=new Manager(new_office_place, first_name, last_name, seniority_worker, new_subjects, num_subject, Seniority_manneger);
		return manager_ptr;

	}
	else {
		Manager* manager_ptr= new Manager(new_office_place, first_name, last_name, seniority_worker, Seniority_manneger = 0);
		return manager_ptr;
	}
}
 Manager::Manager(string new_office_place, string first_name, string last_name, int seniority_worker, int Seniority_manneger) :AdministrationPersonal(new_office_place, first_name, last_name, seniority_worker, Seniority_manneger) {
	 set_admin(first_name,last_name,seniority_worker, Seniority_manneger);
	 manager_ptr=this;
	// Teacher::new_set_teacher;

 }
 void Manager::set_admin(string first_name, string last_name, int seniority_worker, int seniority_manager) {
	 set_new_name(2, first_name, last_name);
	 set_seniority(1, seniority_worker);
	 set_seniority(0, seniority_manager);
 }
void Manager::print() {
	if (Teacher::get_numofsubject() != 0) {
		Worker::print();
		cout << endl << "Nuber of subjects: " << get_numofsubject();
		print_subject_list();
		cout << endl << "Salary is: " << this->manager_salary();
		if (Manager::get_exellent()) {
				cout << endl<<"Manager is excelent";
			}
		else {
			cout <<endl<<"Manager is not excelent";
		}
	}
}
