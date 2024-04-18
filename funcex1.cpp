#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>
#include <cctype>
#include <chrono>
#include <algorithm>

#include "person.h"

using namespace std;

//// Функция сравнения двух человек
//void compare(vector <Person>& data_base) {
//	printing(data_base);
//	int i1, i2;
//	cout << "Write 2 index of people to compare: ";
//	cin >> i1 >> i2; cout << endl;
//	Person p1 = data_base[i1 - 1]; Person p2 = data_base[i2 - 1];
//
//	//Name
//	if (p1.GetName().size() > p2.GetName().size()) {
//		cout << "Name: + , ";
//	}
//	else if (p1.GetName().size() == p2.GetName().size()) {
//		cout << "Name: 0 , ";
//	}
//	else if (p1.GetName().size() < p2.GetName().size()) {
//		cout << "Name: - , ";
//	}
//
//	//Second name
//	if (p1.GetSec_Name().size() > p2.GetSec_Name().size()) {
//		cout << "Surname: + , ";
//	}
//	else if (p1.GetSec_Name().size() == p2.GetSec_Name().size()) {
//		cout << "Surname: 0 , ";
//	}
//	else if (p1.GetSec_Name().size() < p2.GetSec_Name().size()) {
//		cout << "Surname: - , ";
//	}
//
//	//Dad name
//	if (p1.GetDad_Name().size() > p2.GetDad_Name().size()) {
//		cout << "Otchestvo: + , ";
//	}
//	else if (p1.GetDad_Name().size() == p2.GetDad_Name().size()) {
//		cout << "Otchestvo: 0 , ";
//	}
//	else if (p1.GetDad_Name().size() < p2.GetDad_Name().size()) {
//		cout << "Otchestvo: - , ";
//	}
//
//	//Date
//	int date_1 = p1.GetYear() * 10000 + p1.GetMonth() * 100 + p1.GetDay();
//	int date_2 = p2.GetYear() * 10000 + p2.GetMonth() * 100 + p2.GetDay();
//	if (date_1 < date_2) {
//		cout << "Date: + , ";
//	}
//	else if (date_1 == date_2) {
//		cout << "Date: 0 , ";
//	}
//	else if (date_1 > date_2) {
//		cout << "Date: - , ";
//	}
//
//	//Phone
//	if (p1.GetPhone() > p2.GetPhone()) {
//		cout << "Phone: +";
//	}
//	else if (p1.GetPhone() == p2.GetPhone()) {
//		cout << "Phone: 0";
//	}
//	else if (p1.GetPhone() < p2.GetPhone()) {
//		cout << "Phone: -";
//	}
//	cout << endl;
//}
//
//// Функция удаления человека из базы
//void eliminate(vector <Person>& data_base) {
//	int i;
//	printing(data_base);
//	cout << "Choose an index of person to delete: ";
//	cin >> i;
//	if (1 <= i and i <= data_base.size()) {
//		data_base.erase(data_base.begin() + i - 1);
//	}
//	else {
//		cerr << "Invalid index" << endl;
//	}
//	cout << endl;
//}
//
//
//// Функция проверки человека на соответствие условию
//bool check(vector <Person>& data_base) { // arg in func
//	printing(data_base);
//	int i;
//	string sec_name, name, dad_name, date, phone;
//	bool answer = true;
//	cout << "Choose an index of person to check: ";
//	cin >> i; cout << endl;
//	Person checker = data_base[i - 1];
//	cout << "Write options to check: last name, first name, otchestvo, date of birth, phone number: ";
//	cin >> sec_name >> name >> dad_name >> date >> phone;
//	if (name != "*") {
//		if (name != checker.GetName()) {
//			answer = false;
//		}
//	}
//	else if (sec_name != "*") {
//		if (sec_name != checker.GetSec_Name()) {
//			answer = false;
//		}
//	}
//	else if (dad_name != "*") {
//		if (dad_name != checker.GetDad_Name()) {
//			answer = false;
//		}
//	}
//	else if (date != "*") {
//		if (date != checker.GetDate()) {
//			answer = false;
//		}
//	}
//	else if (phone != "*") {
//		if (phone != checker.GetPhone()) {
//			answer = false;
//		}
//	}
//	return answer;
//}
//
//// Кол-во дней до ДР
//void birthday(vector <Person>& data_base) {
//	printing(data_base);
//	int i = 0;
//	cout << "Choose an index of person to count days until birthday: ";
//	cin >> i; cout << endl;
//	tm bd = { 0,0,0,
//			data_base[i - 1].GetDay(),
//			data_base[i - 1].GetMonth() - 1,
//			data_base[i - 1].GetYear() - 1900 };
//
//	auto now = chrono::system_clock::now();
//	time_t now_c = chrono::system_clock::to_time_t(now);
//	tm* current = localtime(&now_c);
//
//	bd.tm_year = current->tm_year;
//
//	if (mktime(&bd) < mktime(current)) {
//		bd.tm_year++;
//	}
//	chrono::system_clock::time_point birthday_time = chrono::system_clock::from_time_t(std::mktime(&bd));
//	chrono::duration<double> diff = birthday_time - now;
//
//	int days = static_cast<int>(diff.count() / (60 * 60 * 24)) + 1;
//
//	cout << "Day(s) until birthday: " << days << endl;
//}
//
//// Запись базы данных в файл
//void write(vector <Person>& data_base) {
//	ofstream outputFile("output.txt");
//	if (!outputFile.is_open()) {
//		cerr << "Error openning file!" << endl;
//	}
//	else {
//		for (Person per : data_base) {
//			outputFile << per.GetSec_Name() << " " << per.GetName() << " " << per.GetDad_Name() << " " << per.GetDate() << " " << per.GetPhone() << endl;
//		}
//
//		outputFile.close();
//	}
//
//}
//
//// Функция сортировки
//bool elemsort(const Person& per1, const Person& per2) {
//	const string& surname1 = per1.GetSec_Name();
//	const string& surname2 = per2.GetSec_Name();
//
//	const string& name1 = per1.GetName();
//	const string& name2 = per2.GetName();
//
//	const string& dad_name1 = per1.GetDad_Name();
//	const string& dad_name2 = per2.GetDad_Name();
//
//	const string& date1 = per1.GetDate();
//	const string& date2 = per2.GetDate();
//
//	const string& phone1 = per1.GetPhone();
//	const string& phone2 = per2.GetPhone();
//
//	size_t min_name = min(name1.length(), name2.length());
//	size_t min_surname = min(surname1.length(), surname2.length());
//	size_t min_dad_name = min(dad_name1.length(), dad_name2.length());
//	size_t min_date = min(date1.length(), date2.length());
//	size_t min_phone = min(phone1.length(), phone2.length());
//
//	if (surname1 != surname2) {
//		for (size_t i = 0; i < min_surname; i++) {
//			if (surname1[i] != surname2[i]) {
//				return surname1[i] < surname2[i];
//			}
//		}
//		return surname1.length() < surname2.length();
//	}
//	else if (name1 != name2) {
//		for (size_t i = 0; i < min_name; i++) {
//			if (name1[i] != name2[i]) {
//				return name1[i] < name2[i];
//			}
//		}
//		return name1.length() < name2.length();
//	}
//	else if (dad_name1 != dad_name2) {
//		for (size_t i = 0; i < min_dad_name; i++) {
//			if (dad_name1[i] != dad_name2[i]) {
//				return dad_name1[i] < dad_name2[i];
//			}
//		}
//		return dad_name1.length() < dad_name2.length();
//	}
//	else if (date1 != date2) {
//		for (size_t i = 0; i < min_date; i++) {
//			if (date1[i] != date2[i]) {
//				return date1[i] < date2[i];
//			}
//		}
//		return date1.length() < date2.length();
//	}
//	else if (phone1 != phone2) {
//		for (size_t i = 0; i < min_phone; i++) {
//			if (phone1[i] != phone2[i]) {
//				return phone1[i] < phone2[i];
//			}
//		}
//		return phone1.length() < phone2.length();
//	}
//	else {
//		return 0;
//	}
//}
//
//// Фукнция вызова сортировки
//void sortVector(vector <Person>& vec) {
//	sort(vec.begin(), vec.end(), elemsort);
//	printing(vec);
//}
