/* Assignment: 3
Author1: Itamar Azran,
ID: 307955450
Author2: Yevgeniy Gluhoy,
ID: 336423629
*/
#include "Class.h"
#include "Tutor.h"
void Class:: set_tutor(Tutor* new_tutor) {
	mentor = new_tutor;
}
Class::Class(char new_name_layer, int new_num_class, int new_num_of_pupils, Tutor* new_mentor, vector<Pupil*>new_all_pupils) {
	name_layer = new_name_layer;
	num_class = new_num_class;
	num_of_pupils = new_num_of_pupils;
	mentor = new_mentor;
	all_pupils = new_all_pupils;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Class::add_new_pupil(Pupil* new_pupil) {
	all_pupils.push_back(new_pupil);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Pupil Class::get_pupil(int index) {
	return *all_pupils[index];
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Class::get_size_all_pupils() {
	return all_pupils.size();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Class::print() {
	cout << endl << "Layer: " << name_layer;
	cout << endl << "Class number: " << num_class;
	for (int i = 0; i < all_pupils.size(); i++) {
		if (i < (all_pupils.size() - 1)) {
			cout << all_pupils[i]<<", ";
		}
		cout << all_pupils[i];
	}
}
int Class::get_class_name()
{
	return num_class;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Class:: set_class_number(int class_number) {
	Class::num_class = class_number;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Class::operator= (const Class& new_class) {
	name_layer = new_class.name_layer;
	num_class = new_class.num_class;
	num_of_pupils = new_class.num_of_pupils;
	mentor = new_class.mentor;
	all_pupils = new_class.all_pupils;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////