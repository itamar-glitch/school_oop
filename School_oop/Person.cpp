/* Assignment: 3
Author1: Itamar Azran,
ID: 307955450
Author2: Yevgeniy Gluhoy,
ID: 336423629
*/
#include "Person.h"
using namespace std;
bool Person::set_new_name(int choose, string newname, string new_lastname) {//0 change first name, 1 choose change last_name ,2 change evrything 
	if (choose ==0||choose==2) {//changing first name
		first_name = newname;
		if (choose == 0) {
			return true;
		}
	}
	if (choose == 1 || choose == 2) {//changing last_name
		last_name = new_lastname;
		if (choose == 1) {
		return true;
	}
	}
	if (choose == 2) {
		return true;
	}
	return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
string Person::get_names(int choose) {//0->return first name, 'else'->return last name
	if (choose == 0) {//get firstname
		return first_name;
	}
	else {//get last_name
		return last_name;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Person::print() {
	cout << "first name: " << first_name << endl<<"last name: "<<last_name<<endl;
}
