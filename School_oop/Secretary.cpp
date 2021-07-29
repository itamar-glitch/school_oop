/* Assignment: 3
Author1: Itamar Azran,
ID: 307955450
Author2: Yevgeniy Gluhoy,
ID: 336423629
*/
#include "Secretary.h"
#include <iostream>
Secretary::Secretary(int child_pupil_num, string first_name, string last_name, int seniority_worker, int Seniority_manneger):Worker( first_name, last_name,  seniority_worker,  Seniority_manneger) {
	child_pupil = child_pupil_num;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Secretary::get_salary() {
	int base = get_base();
	return base + child_pupil * 200;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Secretary::get_exellent() {
	int i = get_seniority(1);
	if (i > 10) {
		return true;
	}
	else {
		return false;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Secretary::print() {
	Worker::print();
	cout << endl << "Number of children that are learning in school: " << child_pupil;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////