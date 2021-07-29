/*
Author: Itamar Azran,
*/
#include "Worker.h"
#include "Person.h"
#include <iostream>
int Worker:: basis = 25;

/*Worker(char* first_name, char* last_name, int seniority_worker, int Seniority_manneger);
	//this->set_new_name(2, first_name, last_name);//sets full name of worker
	seniority[0] = Seniority_manneger;
	seniority[1] = seniority_worker;
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Worker:: get_seniority(int choose) {//0 for manager seniority 1 for worker
	if (choose == 1) {
		return seniority[0];
	}
	else {
		return seniority[1];
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Worker:: set_seniority(int choose, int value) {//0 for manager seniority 1 for worker
	if (choose == 0|| choose == 2) {
		seniority[0] = value;
	}
	if(choose==1 || choose == 2) {
		seniority[1] = value;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Worker::print() {
	Person::print();
	if (seniority[0] != 0) {
		cout <<endl<< "Seniority as manager: " << seniority[0] << endl << "Seniority as worker: " << seniority[1];
	}
	else {
		cout << endl << "Seniority as worker: " << seniority[1];
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Worker::get_Manager_salary() {
	return basis;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
