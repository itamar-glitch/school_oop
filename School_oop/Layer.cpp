/* Assignment: 3
Author1: Itamar Azran,
ID: 307955450
Author2: Yevgeniy Gluhoy,
ID: 336423629
*/
#include "Layer.h"
Layer::Layer(string new_layer_name, vector<Class*>new_class_ptr) {
	layer_name = new_layer_name;
	class_ptr = new_class_ptr;
}
Layer::Layer(const Layer& new_layer)
{
	layer_name = new_layer.layer_name;
	class_ptr = new_layer.class_ptr;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Class* Layer::get_class(int index) {
	return class_ptr[index];
}
string Layer::get_layer_string()
{
	return layer_name;
}

void Layer::add_class(Class* new_class)
{
	class_ptr.push_back(new_class);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////