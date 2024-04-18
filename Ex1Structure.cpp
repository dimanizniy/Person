#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <list>

#include "person.h"
#include "headex1.h"
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	List list;

	cout << "1 - Adding from keyboard" << endl;
	cout << "2 - Adding from file" << endl;
	cout << "3 - Compare two people" << endl;
	cout << "4 - Output" << endl;
	cout << "5 - Delete person" << endl;
	cout << "6 - Copy person" << endl;
	cout << "7 - Check one person" << endl;
	cout << "8 - Days until birthday" << endl;
	cout << "9 - Export the database to the file" << endl;
	cout << "10 - Sort the database" << endl;
	cout << "-1 - Clear the database" << endl;
	cout << "0 - Exit" << endl;
	int flag = -10;
	while (flag != 0) {
		cout << "Choose action: ";
		cin >> flag; cout << endl;
		if (flag == 0) {
			cout << "The end...";
			break;
		}
		else if (flag == 1) {
			string name, sec_name, dad_name, date, phone;
			cout << "Write a FIO, date and phone: ";
			cin >> sec_name >> name >> dad_name >> date >> phone; cout << endl;
			Person* p = new Person(sec_name, name, dad_name, date, phone);
			list.append(p);

		}
		else if (flag == 2) 
		{
			string adress;
			cout << "Write an adress to file: ";
			cin >> adress; cout << endl;
			list.addFromFile(adress);
		}
		else if (flag == 3) {
			list.compare(list);
		}
		else if (flag == 4) {
			list.printList();
		}
		else if (flag == 5) {
			//eliminate(data_base);
		}
		else if (flag == 6) {
			//copy(data_base);
		}
		else if (flag == 7) {
			//bool f = check(data_base);
			//if (f) {
			//	cout << "Equally" << endl;
			//}
			//else {
			//	cout << "Not equally" << endl;
			//}
		}
		else if (flag == 8) {
			//birthday(data_base);
		}
		else if (flag == 9) {
			//write(data_base);
		}
		else if (flag == 10) {
			//sortVector(data_base);
		}
		else if (flag == -1) {
			//data_base.clear();
			//cout << "Database was cleared" << endl;
		}
	}
	if (not flag) {
		exit;
	}
}