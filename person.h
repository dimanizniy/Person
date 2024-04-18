#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>
#include <cctype>
#include <chrono>
#include <algorithm>

#include "headex1.h"

using namespace std;

class Person {
private:
	string name, sec_name, dad_name, date, phone;
	int day, month, year;
public:

	// Объявление человека
	Person(const string& middle, const string& first, const string& last, const string& dob, const string& number) :
		sec_name(middle), name(first), dad_name(last), date(dob), phone(number) {};

	// Добавление даты в раздельном формате
	void set_date(vector <int> p1) {
		day = p1[0];
		month = p1[1];
		year = p1[2];
	}

	// Добавление основных переменных
	void set_info(string sn, string n, string dn, string date_full, string phone_nubmer) {
		sec_name = sn;
		name = n;
		dad_name = dn;
		date = date_full;
		phone = phone_nubmer;
	}

	// Функции получения информации
	string GetName() const {
		return name;
	}
	string GetSec_Name() const {
		return sec_name;
	}
	string GetDad_Name() const {
		return dad_name;
	}
	string GetDate() const {
		return date;
	}
	string GetPhone() const {
		return phone;
	}
	int GetDay() const {
		return day;
	}
	int GetMonth() const {
		return month;
	}
	int GetYear() const {
		return year;
	}

	// Проверка на иные символы
	string check_input() {
		string result = "";
		bool f = true;
		for (int i = 0; i < name.size(); i++) {
			if ('0' <= name[i] and name[i] <= '9') {
				result += "There is a digit in the name. ";
				f = false;
				break;
			}
		}
		for (int i = 0; i < sec_name.size(); i++) {
			if ('0' <= sec_name[i] and sec_name[i] <= '9') {
				result += "There is a digit in the second name. ";
				f = false;
				break;
			}
		}
		for (int i = 0; i < dad_name.size(); i++) {
			if ('0' <= dad_name[i] and dad_name[i] <= '9') {
				result += "There is a digit in the dad name. ";
				f = false;
				break;
			}
		}
		for (int i = 0; i < date.size(); i++) {
			if (not ('0' <= date[i] and date[i] <= '9') and date[i] != '.') {
				result += "There is an alpha in the date. ";
				f = false;
				break;
			}
		}
		for (int i = 0; i < phone.size(); i++) {
			if (not ('0' <= phone[i] and phone[i] <= '9') and phone[0] != '+') {
				result += "There is an alpha in the phone number. ";
				f = false;
				break;
			}
		}
		if (not f) {
			return result;
		}
		else {
			return "0";
		}
	}

	// Разбиение даты
	vector <int> add_date() {
		vector <int> dmy;
		int cnt = 0;
		string s = "";
		for (char c : date) {
			for (auto now : dmy) {
			}
			if (c != '.') {
				s += c;
			}
			else {
				if (cnt == 0) {
					dmy.push_back(stoi(s));
					s = "";
				}
				else if (cnt == 1) {
					dmy.push_back(stoi(s));
					s = "";
				}
			}
		}
		dmy.push_back(stoi(s));
		s = "";
		return dmy;
	}

	// Проверка даты 
	bool right_date() {
		if (day == -1 or month == -1 or year == -1) {
			return false;
		}
		else if (not(1 <= month and month <= 12)) {
			return false;
		}
		else {
			tm time_info = {};
			time_info.tm_year = year-1900; // год с 1900
			time_info.tm_mon = month - 1; // месяцы с 0
			time_info.tm_mday = day;

			time_t time = mktime(&time_info);

			return time != -1 &&
				time_info.tm_year == year - 1900 &&
				time_info.tm_mon == month - 1 &&
				time_info.tm_mday == day;
		}
	}
};

class Node {
public:
	Person* data;
	Node* prev;
	Node* next;

	Node(Person* p) : data(p), prev(nullptr), next(nullptr) {}
};

class List {
private:
	Node* head;
	Node* tail;

public:
	List() : head(nullptr), tail(nullptr) {}

	// Добавление человека
	void append(Person* p) {

		string res = p->check_input();
		if (res == "0") {
			vector <int> full_date = p->add_date();
			p->set_date(full_date);
			bool f = p->right_date();
			if (f) {
				Node* newNode = new Node(p);
				if (!head) {
					head = tail = newNode;
				}
				else {
					tail->next = newNode;
					newNode->prev = tail;
					tail = newNode;
				}
			}
			else {
				cerr << "Error in date" << endl;
			}
		}
		else {
			cout << res << endl;
		}
	}

	// Удаление человека
	void remove(Person* p) {
		Node* current = head;
		while (current) {
			if (current->data == p) {
				if (current == head && current == tail) {
					head = tail = nullptr;
				}
				else if (current == head) {
					head = head->next;
					head->prev = nullptr;
				}
				else if (current == tail) {
					tail = tail->prev;
					tail->next = nullptr;
				}
				else {
					current->prev->next = current->next;
					current->next->prev = current->prev;
				}
				delete current;
				return;
			}
			current = current->next;
		}
	}

	// Вывод базы
	void printList() {
		Node* current = head;
		int index = 1;
		while (current) {
			cout << index << ". ";
			cout << "Name: " << current->data->GetSec_Name() << " " << current->data->GetName() << " " << current->data->GetDad_Name() << ", ";
			cout << "Date of Birth: " << current->data->GetDate() << ", ";
			cout << "Phone Number: " << current->data->GetPhone() << endl;
			current = current->next;
			index++;
		}
	}

	// Добавление человека из файла
	void addFromFile(const string& filename) {
		string name, sec_name, dad_name, date, phone;
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "Failed to open file: " << filename << endl;
			return;
		}

		while (file >> sec_name >> name >> dad_name >> date >> phone) {
			Person* p = new Person(sec_name, name, dad_name, date, phone); 
			string res = p->check_input();
			if (res == "0") {
				vector <int> full_date = p->add_date();
				p->set_date(full_date);
				bool f = p->right_date();
				if (f) {
					append(p);
				}
				else {
					cerr << "Error in date" << endl;
				}
			}
			else {
				cout << res << endl;
			}
		}

		file.close();
	}
};