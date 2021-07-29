/* Assignment: 3
Author1: Itamar Azran,
ID: 307955450
Author2: Yevgeniy Gluhoy,
ID: 336423629
*/
#pragma once
#include <vector>
#include <iostream>
#include "Person.h"
#include "Class.h"
class Worker: public Person
{
public:
	Worker() {}
	~Worker() {} 
	Worker(string first_name,string last_name, int seniority_worker,int Seniority_manneger ):Person::Person(first_name, last_name) {
		seniority[0] = Seniority_manneger;
		seniority[1] = seniority_worker;
	}
	//Worker(char* first_name, char* last_name,int seniority_worker, int Seniority_manneger);
	virtual int get_seniority(int choose);//0 for manager seniority 1 for worker
	virtual void set_seniority(int choose, int value);//0 for manager seniority 1 for worker
	virtual int get_Manager_salary();
	virtual void print();
	static int get_base() { return Worker::basis; }
	virtual Class*  get_kita() { return nullptr; }
private:
	static int basis;
	int seniority[2];//first for manager seniority secoond for regular worker seniority
};
//class not finish!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
