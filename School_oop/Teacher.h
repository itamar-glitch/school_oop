/* Assignment: 3
Author1: Itamar Azran,
ID: 307955450
Author2: Yevgeniy Gluhoy,
ID: 336423629
*/
#pragma once
#include "Worker.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Teacher : public virtual Worker
{
public:
	Teacher() {}//default Ctor
	~Teacher(){}//Dtor
	Teacher(vector<string> new_subjects, int& num_subject, string first_name, string last_name, int& seniority_worker, int Seniority_manneger );//custom Ctor
	vector<string> get_subject_list();
	int get_numofsubject();
	int get_salary();
	void print_subject_list();
	void print();
	void new_set_teacher(vector<string> new_subject_list, int new_num_of_subject);
private:
	vector<string> subject_list;
	int num_of_subject=0;
};

