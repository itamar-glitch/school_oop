/*
Author: Itamar Azran
*/

#include "School.h"
using namespace std;
School* School::school_data = 0;
School* School::set_school() {
	School* school_data = new School();
	return school_data;
}
void School::set_student(Pupil* new_student) {
	list_pupil.push_back(new_student);
}
void School::set_layers(Layer new_layer)
{
	list_layers.push_back(&new_layer);
	num_of_layers++;
}
void School::set_worker(vector<Worker*> new_worker)	
{
	list_worker.push_back(new_worker[0]);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*void School::menu() {
	vector <Layer*> new_list_layers;
	int new_num_of_layers;
	vector<Pupil*> new_list_pupil;
	vector<Worker*>new_list_worker;
	cout << "School managenent menu" << endl << "============================================================================================";
	cout <<endl<< "Choose one of the following options:";
	cout << endl << "[1] Add pupil" << endl << "[2] " << endl << "[3] " << endl << "[4] " << endl << "[5] " << endl << "[6] ";
}*/
void School::clean_buff() {
	if (char(cin.peek()) == '\n')
		cin.ignore();

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
	}
}
bool School::check_layer(string new_layer) {
	for (int i = 0; i < list_layers.size(); i++) {
		if (list_layers[i]->get_layer_string() == new_layer) {
			return true;
		}
		return false;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char* School::get_char_from_user()
{
	clean_buff();
	cin >> noskipws;//cin will not skip the spaces
	int size_of_char=1;
	char newname;
	vector<char> vechar;
	while (cin >> newname) {//take char by char and saving them into vector until input '0' 'Enter' 
		if ((int)newname == '\n') {
			break;
		}
		vechar.push_back(newname);
		size_of_char++;
	}
	char* new_layer = new char[size_of_char + 1];
	new_layer[size_of_char + 1] = 0;
	for (int i=0; i <= size_of_char-1; i++) {
		if (i == size_of_char-1) {
			new_layer[i] = 0;
			break;
		}
		new_layer[i] = vechar[i];
	}
	if (size_of_char == 0) {
		cout << "please enter again";
		get_char_from_user();
	}
	return new_layer;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int School::menu() {
	Class* kita;
	Tutor* temp_tutor;
	Teacher* new_teacher;
	int j = 0;
	int department_choise;
	Layer* new_layer;
	int registered_teacher_index, num__of_subject,index;
	int size_of_char=1;
	vector<int> new_grades;
	vector<string> new_subjects;
	int singel_grades;
	int num_of_grades;
	string layer,temp, new_office_place;
	char newname;
	char* temp_char;
	vector <Layer*> new_list_layers;
	int new_num_of_layers;
	vector<Pupil*> new_list_pupil;
	vector<Worker*>new_list_worker;
	int num_of_subjects_layer;
	vector<int>pupil_grades;
	Pupil* new_student;
	string first_name, last_name;
	do {
		cout << "School managenent menu" << endl << "============================================================================================";
		cout << endl << "Please choose one of the following options:" << endl;
		cout << "============================================================================================" << endl;
		cout << "1) Add pupil." << endl << "2) Add teacher." << endl;
		cout << "3) Add tutor." << endl << "4) Add Manager." << endl << "5) Add secretary." << endl;
		cout << "6) Print person details." << endl << "7) Print outstanding pepole" << endl << "8) Print tutor class" << endl << "9) Highest paid worker" << endl << "10) Exit"<<endl;
		cout << "============================================================================================" << endl;
		clean_buff();
		cin >> department_choise;
		switch (department_choise) {
		case 1: {
			cout << endl << "Please enter pupil's first name: ";
			string first_name = get_char_from_user();
			cout << endl << "Please enter pupil's last name:  ";
			 last_name = get_char_from_user();


			cout << endl << "How many grades has pupil: ";
			clean_buff();
			cin >> num_of_grades;
			cin >> noskipws;//cin will not skip the spaces
			//int j = 1;
			for(int j=1; j <= num_of_grades; j++) {
				cout << endl << "Please, enter a valid grade(between 0 to 100): ";
				clean_buff();
				while (cin >> singel_grades) {//take char by char and saving them into vector until input '0' 'Enter' 
					if ((int)singel_grades == '\n') {
						break;
					}
					if (singel_grades < 0 || singel_grades>100) {
						cout << endl << singel_grades << "is ilegal grade!"  ;
						cout << endl << "Please try again" ;
					}
					else {
						new_grades.push_back(singel_grades);//grades for student object@!#!@$!
					}
				}
			}
			cout << endl << "Enter layer: ";
			do {
				layer = get_char_from_user();
				if ((int)layer[0] < 97 || (int)layer[0]>122|| layer[1]!=0) {
					cout << endl << "Layer is not exist, please enter a valid layer: ";
				}
			} while (!School::check_layer(layer));
			int class_number;
			cout << endl << "Please, enter pupil's class number(from 1 to 3): ";
			clean_buff();
			do {
				cin >> class_number;
				if ((int)class_number < 97 || (int)class_number>122){ //|| class_number[1] != 0) {
					cout << endl << "Class is not exist, please enter a valid class(from 1 to 3): ";
				}
				} while (class_number < 1 || class_number > 3);
			new_student=new Pupil(new_grades, layer, class_number, first_name, last_name);
			set_student(new_student);
		}
			break;
		case 2: {
			clean_buff();
			cout << endl << "please eneter teacher first name: ";
			first_name = get_char_from_user();
			cout << endl << "please eneter teacher last name:  ";
			 last_name = get_char_from_user();
			//clean_buff();
			cin >> noskipws;//cin will not skip the spaces
			cout << endl<<"please enter number of sunject: ";//char* last_name, int& seniority_worker, int Seniority_manneger = 0
			cin >> num_of_grades;
			for (int j = 0; j < num_of_grades; j++) {
				cout << endl<<"please enter subject name: ";
				string temp = get_char_from_user();
				new_subjects.push_back(temp);;
			}
			//clean_buff();
			cout << endl << "what is your worker siniiority?: ";
			int worker_seniority=0;
			cin >> worker_seniority;
			clean_buff();
			cout << endl << "what is your manager siniiority?: ";
			int manager_seniority = 0;
			cin >> manager_seniority;
			if(worker_seniority==0 &&manager_seniority==0){
				break;
			}
			new_teacher=new Teacher(new_subjects, num_of_grades,first_name,last_name,worker_seniority,manager_seniority);
			new_list_worker.push_back(new_teacher);
			School::set_worker(new_list_worker);
			new_list_worker.clear();
			break;
		}
		case 3: {
			new_subjects.clear();
			int num__of_subject;
			cout << endl << "please eneter tutor first name: ";
			 first_name = get_char_from_user();
			cout << endl << "please eneter tutor last name:  ";
			 last_name = get_char_from_user();
			 registered_teacher_index =check_manager(first_name, last_name);//check if he is a mannager
			if (registered_teacher_index == 0) {//its a mannager!!
				cout << endl << "tutor can't be a manager";
				break;
			}
			else if (registered_teacher_index == 1) {
				remove_teacher(first_name, last_name);//if its a manager we need to remove him
			}
			cout << endl << "please enter the number of subjects: ";
			cin >> num__of_subject;//number of tutor subjects
			for (int i = 0; i < num__of_subject; i++) {
				cout << endl << "please enter subject name: ";//crate a vector type list of subjects names
				string temp = get_char_from_user();
				new_subjects.push_back(temp);
			}
			int seniority_worker, Seniority_manneger;//from 212-218 we take the class number and layeer name
			cout << endl << "what layer is the class that " << first_name << " " << last_name << " intendet to teach? ";
			layer = get_char_from_user();
			do {
				layer = get_char_from_user();
				if ((int)layer[0] < 97 || (int)layer[0]>122 || layer[1] != 0) {
					cout << endl << "Layer is not exist, please enter a valid layer: ";
				}
			} while (!School::check_layer(layer));
			cout << endl << "which class number " << first_name << " " << last_name << " intendet to teach? ";
			int clas;

			clean_buff();
			do {
				cin >> clas;
				if (clas < 1 || clas>3) { //|| class_number[1] != 0) {
					cout << endl << "Class is not exist, please enter a valid class(from 1 to 3): ";
				}
			} while (clas < 0 || clas > 3);

			cout << endl << "what is your worker siniiority?: ";//tutor have seniorty
			clean_buff();
			cin >> seniority_worker;
			cout << endl << "what is your manager siniiority?: ";
			clean_buff();
			cin >> Seniority_manneger;
			//kita=list_layers[(int)layer[0] - 97]->get_class(clas-1);
			temp_tutor = new Tutor(new_subjects, clas, first_name, last_name, seniority_worker, Seniority_manneger, list_layers[(int)layer[0] - 97]->get_class(clas - 1));
			//kita->set_tutor(temp_tutor);
			list_worker.push_back(temp_tutor);
			break;
		}//Tutor(vector<string> new_subjects, int& num_subject, string first_name, string last_name, int& seniority_worker, int Seniority_manneger, Class* new_kita)
		case 4: {
			cout << endl << "Please enter manager first name: ";
			 first_name = get_char_from_user();
			cout << endl << "Please enter manager last name:  ";
			 last_name = get_char_from_user();
			index = check_manager(first_name, last_name);
			if (index == 1) {
				remove_teacher(first_name, last_name);
			}
			else if (index == 2) {
				remove_administrationpersonal(first_name, last_name);
			}
			else if (index == 0) {
				cout << "Sorry, this person is already manager";
				break;
			}
			cout << endl << "Please enter the number of subjects: ";
			clean_buff();
			cin >> num__of_subject;
			if (num__of_subject != 0) {
				for (int i = 0; i <= num__of_subject; i++) {
					cout << endl << "Please enter subject name: ";
					temp = get_char_from_user();
					new_subjects.push_back(temp);
				}
			}
			int seniority_worker, Seniority_manneger;
			cout << endl << "what is your worker siniority?: ";
			clean_buff();
			cin >> seniority_worker;
			cout << endl << "what is your manager siniority?: ";
			clean_buff();
			cin >> Seniority_manneger;
			cout << endl << "Please enter number of office: ";
			clean_buff();
			new_office_place = get_char_from_user();
			Manager* new_manager = Manager::assign_manager(new_office_place, new_subjects, num__of_subject, first_name, last_name, seniority_worker, Seniority_manneger);
			new_list_worker.push_back(new_manager);
			School::set_worker(new_list_worker);
			new_list_worker.clear();
			
			break;

		}
		case 5: {
			clean_buff();
			int child_pupil_num, seniority_worker, Seniority_manneger;
			cout << endl << "please enter the number of pupil in school: ";
			cin >> child_pupil_num;
			cout << endl << "please eneter teacher first name: ";
			 first_name = get_char_from_user();
			cout << endl << "please eneter teacher last name:  ";
			 last_name = get_char_from_user();
			cout << endl << "what is your worker siniiority?: ";
			cin >> seniority_worker;
			cout << endl << "what is your manager siniiority?: ";
				clean_buff();
			cin >> Seniority_manneger;
			Secretary new_secretary(child_pupil_num, first_name, last_name, seniority_worker, Seniority_manneger);
			//Worker* new_worker = dynamic_cast<Worker*>(&new_secretary);
			new_list_worker.push_back(&new_secretary);
			School::set_worker(new_list_worker);
			new_list_worker.clear();
			break;
		}
		case 6: {
			VecAnalyser<Pupil*> ppl(list_pupil);
			VecAnalyser<Worker*> wrk(list_worker);
			ppl.printAll();
			wrk.printAll();
			break;
		}
		case 7: {

		}
		case 8: {
			cout << endl << "Please enter first name of tutor:";
			 first_name = get_char_from_user();
			cout << endl << "Please enter last name of tutor:  ";
			 last_name = get_char_from_user();
			index = check_tutor(first_name, last_name);
			if (index == 0) {
				cout << endl << "There are no tutors registered in school with that name.";
			}
			else {
				VecAnalyser<Worker*> wrk(list_worker);
				wrk.printtutor(index - 1);
			}
			break;
		}
		case 9: {
			VecAnalyser<Worker*> wrk(list_worker);
			wrk.printMax();
			break;
		}
		case 10: {
			break;
		}
		}
		if (department_choise != 10) {
			printf("\n");
		}
	} while (department_choise != 10);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int School::check_manager(string first_name, string last_name) {
	//typeid(object);
	string check_first_name;
	string check_last_name;
	for (int i = 0; i < list_worker.size(); i++) {
		if (typeid(Teacher) == typeid(list_worker[i])) {
			check_first_name = list_worker[i]->get_names(0);
			check_last_name = list_worker[i]->get_names(1);
			if (check_first_name == first_name && check_last_name == last_name) {
				if (typeid(Manager) == typeid(list_worker[i])) {
					return 0;//new manager is already manager
				}
				return 1;//new manager is already teacher in school
			}
		}
		else if (typeid(AdministrationPersonal) == typeid(list_worker[i])) {
			check_first_name = list_worker[i]->get_names(0);
			check_last_name = list_worker[i]->get_names(1);
			if (check_first_name == first_name && check_last_name == last_name) {
				if (typeid(Manager) == typeid(list_worker[i])) {
					return 0;//new manager is already manager
				}
				return 2;//new manager is some AdministrationPersonal in school
			}
		}
	}
	return 3;//there no such person
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void School::remove_teacher(string first_name, string last_name) {
	for (int i = 0; i < list_worker.size(); i++) {
		if (typeid(Teacher) == typeid(list_worker[i])) {
			list_worker.erase(list_worker.begin() + i);
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void School::remove_administrationpersonal(string first_name, string last_name) {
	for (int i = 0; i < list_worker.size(); i++) {
		if (typeid(AdministrationPersonal) == typeid(list_worker[i])) {
			list_worker.erase(list_worker.begin() + i);
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int School::check_tutor(string first_name, string last_name) {
	string check_first_name;
	string check_last_name;
	for (int i = 0; i < list_worker.size(); i++) {
		if (typeid(Tutor) == typeid(list_worker[i])) {
			check_first_name = list_worker[i]->get_names(0);
			check_last_name = list_worker[i]->get_names(1);
			if (check_first_name == first_name && check_last_name == last_name) {
				return i + 1;//tutor is already in school
			}
		}
	}
	return 0;//there no such person
}
