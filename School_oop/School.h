/*
Author: Itamar Azran
*/
#pragma once
#include "Teacher.h"
#include "Layer.h"
#include "Worker.h"
#include "Tutor.h"
#include "Pupil.h"
#include "Secretary.h"
#include "Manager.h"
#include "Class.h"
#include "VecAnalyser.h"
#include <iostream>
#include <vector>
#include <string>
static class School
{
public:
	School* set_school();
	~School(){}
	static School* new_school(vector <Layer*> new_list_layers, int new_num_of_layers, vector<Pupil*> new_list_pupil, vector<Worker*>new_list_worker);
	int menu();
	int check_manager(string first_name, string last_name);
	void remove_teacher(string first_name, string last_name);
	void remove_administrationpersonal(string first_name, string last_name);
	void clean_buff();
	void set_student(Pupil* new_student);
	void set_layers(Layer new_layer);
	void set_worker(vector<Worker*> new_worker);
	bool check_layer(string new_layer);
	int check_tutor(string first_name, string last_name);
private:
	School(){
		school_data = this;
		for (int i = 97; i <= 122; i++) {
		//	char* temp = (char*)i;
			string layer_name = "a";
			vector<Class*>new_class;
			vector<Pupil*> temp_pupil;
			for (int j = 1; j <= 3; j++) {
				Class* temp_class = new Class((char)i,j, 0, nullptr, temp_pupil);
				new_class.push_back(temp_class);
			}
			Layer* new_Layer = new Layer(layer_name, new_class);
			list_layers.push_back(new_Layer);

		}
	}
	vector<Layer*>list_layers;
	int num_of_layers=0;
	vector<Pupil*>list_pupil;
	vector<Worker*>list_worker;
	static School* school_data;
	char* get_char_from_user();
};
