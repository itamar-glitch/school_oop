/*
Author: Itamar Azran
*/
#pragma once
#include "Pupil.h"
#include <vector>
using namespace std;
class Tutor;
class Class
{
public:
	Class(){}//defaulr Ctor
	~Class(){}
	void set_tutor(Tutor* new_tutor);
	//Dtor
	Class(char new_name_layer, int new_num_class, int new_num_of_pupils, Tutor* new_mentor, vector<Pupil*>new_all_pupils);
	Class(const Class &new_class) {//CCtor
		name_layer = new_class.name_layer;
		num_class = new_class.num_class;
		num_of_pupils = new_class.num_of_pupils;
		mentor = new_class.mentor;
		all_pupils = new_class.all_pupils;
	}
	void operator= (const Class& new_class);
	void add_new_pupil(Pupil* new_pupil);//adds new pupils to Class
	Pupil get_pupil(int index);//returns pupil on index
	int get_size_all_pupils();
	void print();
	int get_class_name();
	void set_class_number(int class_number);
private:
	char name_layer;
	int num_class;
	int num_of_pupils;
	Tutor* mentor;
	vector<Pupil*>all_pupils;
};

