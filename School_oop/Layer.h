/* Assignment: 3
Author1: Itamar Azran,
ID: 307955450
Author2: Yevgeniy Gluhoy,
ID: 336423629
*/
#pragma once
#include "Class.h"
class Layer
{
public:
	Layer(){}//default Ctor
	virtual ~Layer(){}//Dtor
	Layer(string new_layer_name, vector<Class*>new_class_ptr);//Ctor
	Layer(const Layer& new_layer);//Ctor
	Class* get_class(int index);//returns Class by index
	string get_layer_string();
	void add_class(Class* new_class);
private:
	string layer_name;
	vector<Class*>class_ptr;
};

