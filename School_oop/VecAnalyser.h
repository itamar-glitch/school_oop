/* Assignment: 3
Author1: Itamar Azran,
ID: 01234567
Author2: Yevgeniy Gluhoy,
ID: 336423629
*/
#pragma once
#include <iostream>
#include <vector>
#include "Worker.h"
#include "Class.h"
#include "Pupil.h"
#include "Manager.h"
using namespace std;
template <typename T>
class VecAnalyser
{
private:
	vector<T> my_vector;
public:
	VecAnalyser() {}
	VecAnalyser(vector<T> new_vector) {
		my_vector = new_vector;
	}
	~VecAnalyser(){}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	T get_object(int index) {
		if (index >= my_vector.size()) {
			if (my_vector.size() != 0) {
				cout << endl << "Index " << index << " is out of range. The possible range is from 0 to " << my_vector.size() << ".";
				return nullptr;
			}
			else {
				cout << endl << "Index " << index << " is out of range. List is empty!";
				return nullptr;
			}
		}
		else {
			return my_vector[index];
		}
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void swap(int index1, int index2) {
		T first_index, second_index;
		if (my_vector.size() == 0) {
			cout << endl << "Indexes " << index1 <<","<<index2<< " is out of range. List is empty!";
		}
		else if (index1 >= my_vector.size() || index2 >= my_vector.size()) {
			if (index1 >= my_vector.size() && index2 < my_vector.size()) {
				cout << endl << "Index " << index1 << " is out of range. The possible range is from 0 to " << my_vector.size() << ".";
			}
			else if (index1 < my_vector.size() && index2 >= my_vector.size()) {
				cout << endl << "Index " << index2 << " is out of range. The possible range is from 0 to " << my_vector.size() << ".";
			}
			else if (index1 >= my_vector.size() && index2 >= my_vector.size()) {
				cout << endl << "Indexes " << index1 <<","<<index2<< " is out of range. The possible range is from 0 to " << my_vector.size() << ".";
			}
		}
		else {
			first_index = my_vector[index1];
			second_index = my_vector[index2];
			my_vector[index1] = second_index;
			my_vector[index2] = first_index;
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void printElement(int index) {
		if (index >= my_vector.size()) {
			if (my_vector.size() != 0) {
				cout << endl << "Index " << index << " is out of range. The possible range is from 0 to " << my_vector.size() << ".";
			}
			else {
				cout << endl << "Index " << index << " is out of range. List is empty!";
			}
		}
		else {
			my_vector[index].print();
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void printAll() {
		for (int i = 0; i < my_vector.size(); i++) {
			my_vector[i]->print();//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!need to change all print function to name print!!!!
		}
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void printMax() {
		if (typeid(Worker*) == typeid(T)) {
			int index =NULL;
			int max_salary = 0,check_salary=0;
			for (int i = 0; i < my_vector.size(); i++) {
				//max_salary = my_vector[i]->get_salary();////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!need to change all salary function to name get_salary!!!!
				if (max_salary < check_salary) {
					max_salary = check_salary;
					index = i;
				}
			}
			my_vector[index]->print();
		}
		else if (typeid(Pupil*) == typeid(T)) {
			float avarage = 0,check_value=0;
			int index = NULL;
			for (int i = 0; i < my_vector.size(); i++) {
				//check_value = my_vector[i]->get_avrage();
					if (avarage < check_value) {
						avarage = check_value;
						index = i;
				}
			}
			my_vector[index]->print();
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool RTTI(int index) {
		if (typeid(*(my_vector[index])) == typeid(Manager)) {
			return true;
		}
		else {
			return false;
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void printtutor(int index) {
		if (typeid(my_vector) == typeid(Worker*)) {
			Class* kita;
			kita = (my_vector[index])->get_kita();
			kita->print();
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

};

