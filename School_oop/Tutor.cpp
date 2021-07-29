/* Assignment: 3
Author1: Itamar Azran,
ID: 307955450
Author2: Yevgeniy Gluhoy,
ID: 336423629
*/
#include "Tutor.h"
Tutor::Tutor(vector<string> new_subjects, int& num_subject, string first_name, string last_name, int& seniority_worker, int Seniority_manneger, Class* new_kita) :Teacher(new_subjects,num_subject,first_name,last_name,seniority_worker,Seniority_manneger) {
	Person::set_new_name(2,first_name, last_name);
	kita = new_kita;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Tutor::get_salary() {
	int sal = (Teacher::get_salary());
	return 1000 + sal;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Class* Tutor::get_kita() {
	return kita;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Tutor::get_excelent() {
	int size = (kita->get_size_all_pupils());
	int counter = 0;
	Pupil check_pup;
	for (int i = 0; i < size; i++) {
		check_pup = kita->get_pupil(i);
		if (check_pup.get_exellent()) {
			counter++;
		}
		if ((float)counter >= (float)(size / 2)) {
			return true;
		}
		if ((float)counter >= (float)(size / 2)) {
			return true;
		}
		return false;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Tutor::print() {
	Worker::print();
	int num = (Teacher::get_numofsubject());
	cout << endl << "Nuber of subjects: " << num;
	print_subject_list();
	int sal = get_salary();
	cout << endl << "Salary is: " << sal;
	kita->print();
	if (get_excelent()) {
		cout <<endl<< "tutor is excelent";
	}
	else {
		cout <<endl<< "tutor is not excelent";
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////