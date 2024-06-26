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

class Person {
private:
	std::string name, sec_name, dad_name, date, phone;
	int day, month, year;
public:

	// Initialize the person
	Person(const std::string& middle, const std::string& first, const std::string& last, const std::string& dob, const std::string& number) :
		sec_name(middle), name(first), dad_name(last), date(dob), phone(number) {};

	// Adding a date in a separate format
	void set_date(std::vector <int> p1) {
		day = p1[0];
		month = p1[1];
		year = p1[2];
	}

	// Functions for obtaining information
	std::string GetName() const {
		return name;
	}
	std::string GetSec_Name() const {
		return sec_name;
	}
	std::string GetDad_Name() const {
		return dad_name;
	}
	std::string GetDate() const {
		return date;
	}
	std::string GetPhone() const {
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

	// Checking for other characters when entering
	std::string check_input() {
		std::string result = "";
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

	// Splitting date str into vector: day, month, year
	std::vector <int> add_date() {
		try {
			std::vector <int> dmy;
			int cnt = 0;
			std::string s = "";
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
		} catch (const std::exception& e) {
			return {};
		}
	}

	// Checking that the date is not future
	bool isDateBeforeNow(int day, int month, int year) {
		time_t now = time(nullptr);
		tm* localTime = localtime(&now);

		// System date
		tm currentDate = {0, 0, 0, localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900 };

		// Input date
		tm inputDate = {0, 0, 0, day, month, year };
		
		return ((year * 10000 + month * 100 + day) - (currentDate.tm_year * 10000 + currentDate.tm_mon * 100 + currentDate.tm_mday)) <= 0;
	}

	// Checking the number of days in a month
	bool CheckDate(int day, int month, int year)
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
			if (day >= 1 and day <= 31) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day >= 1 and day <= 30) {
				return true;
			}
			else {
				return false;
			}
		}
		else if (month == 2) {
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
				if (day >= 1 and day <= 29) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				if (day >= 1 and day <= 28) {
					return true;
				}
				else {
					return false;
				}
			}
		}
		else {
			return false;
		}
	}

	// Existence date check
	bool right_date() {
		bool f = isDateBeforeNow(day, month, year);
		bool f1 = CheckDate(day, month, year);
		if (day == -1 or month == -1 or year == -1) {
			return false;
		}
		else if (not(1 <= month and month <= 12)) {
			return false;
		}
		else {
			tm time_info = {0,0,0, day, month, year};
			tm time_info_mk = {0,0,0, day, month-1, year-1900};
			time_t time = mktime(&time_info_mk);
			return f && f1 && time != -1 &&
				time_info.tm_year == year &&
				time_info.tm_mon == month &&
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
	int size;

public:
	List() : head(nullptr), tail(nullptr), size(0) {}

	// Checking an integer
	std::string true_int() {
		int i;
		if ((std::cin >> i).good()) {
			return std::to_string(i);
		}
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			return "er";
		}
		else {
			return "er";
		}
	}

	// Get Person by index
	Person* getByIndex(int index) {
		Node* current = head;
		int currentIndex = 1;
		while (current && currentIndex < index) {
			current = current->next;
			currentIndex++;
		}
		if (current && currentIndex == index) {
			return current->data;
		}
		return nullptr;
	}

	// Adding a person
	void append(Person* p) {
		std::string res = p->check_input();
		if (res == "0") {
			std::vector <int> full_date = p->add_date();
			if (!full_date.empty() and full_date.size() == 3) {
				p->set_date(full_date);
				bool f = p->right_date();
				if (f) {
					Node* newNode = new Node(p);
					if (!head)
					{
						head = tail = newNode;
					}
					else
					{
						tail->next = newNode;
						newNode->prev = tail;
						tail = newNode;
					}
					size++;
				}
				else
				{
					std::cerr << "Error in date" << std::endl;
				}
			}
			else {
				std::cerr << "Error in date" << std::endl;
			}
		}
		else {
			std::cout << res << std::endl;
		}
	}

	// Removing a person
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

	// List Output
	void printList() {
		Node* current = head;
		int index = 1;
		while (current) {
			std::cout << index << ". ";
			std::cout << "Name: " << current->data->GetSec_Name() << " " << current->data->GetName() << " " << current->data->GetDad_Name() << ", ";
			std::cout << "Date of Birth: " << current->data->GetDate() << ", ";
			std::cout << "Phone Number: " << current->data->GetPhone() << std::endl;
			current = current->next;
			index++;
		}
	}

	// Adding all Persons from a file
	void addFromFile(const std::string& filename) {
		std::string name, sec_name, dad_name, date, phone;
		std::ifstream file(filename);
		if (!file.is_open()) {
			std::cerr << "Failed to open file: " << filename << std::endl;
			return;
		}

		while (file >> sec_name >> name >> dad_name >> date >> phone) {
			Person* p = new Person(sec_name, name, dad_name, date, phone);
			std::string res = p->check_input();
			if (res == "0") {
				std::vector <int> full_date = p->add_date();
				p->set_date(full_date);
				bool f = p->right_date();
				if (f) {
					append(p);
				}
				else {
					std::cerr << "Error in date" << std::endl;
				}
			}
			else {
				std::cout << res << std::endl;
			}
		}

		file.close();
	}

	// Comparison of two Persons
	bool compare(Person* person1, Person* person2) {
		std::string ans = "";
		// Surname
		if (person1->GetSec_Name() > person2->GetSec_Name()) { ans += "1"; }
		else if (person1->GetSec_Name() < person2->GetSec_Name()) { ans += "0"; }
		else if (person1->GetSec_Name() == person2->GetSec_Name()) { ans += "2"; }

		// Name
		if (person1->GetName() > person2->GetName()) { ans += "1"; }
		else if (person1->GetName() == person2->GetName()) { ans += "0"; }
		else if (person1->GetName() < person2->GetName()) { ans += "2"; }

		// Dad name
		if (person1->GetDad_Name() > person2->GetDad_Name()) { ans += "1"; }
		else if (person1->GetDad_Name() == person2->GetDad_Name()) { ans += "0"; }
		else if (person1->GetDad_Name() < person2->GetDad_Name()) { ans += "2"; }

		//Date
		int date_1 = person1->GetYear() * 10000 + person1->GetMonth() * 100 + person1->GetDay();
		int date_2 = person2->GetYear() * 10000 + person2->GetMonth() * 100 + person2->GetDay();
		if (date_1 < date_2) { ans += "1"; }
		else if (date_1 == date_2) { ans += "0"; }
		else if (date_1 > date_2) { ans += "2"; }

		//Phone
		if (person1->GetPhone() > person2->GetPhone()) { ans += "1"; }
		else if (person1->GetPhone() == person2->GetPhone()) { ans += "0"; }
		else if (person1->GetPhone() < person2->GetPhone()) { ans += "2"; }

		bool f = false;
		for (auto c : ans) {
			if (c == '1') {
				f = true;
				break;
			}
			else if (c == '0') {
				f = false;
				break;
			}
		}
		return f;
	}

	// Checking one Person
	void check_person(List& list, bool del) {
		std::vector <Node*> for_del;
		std::string sec_name, name, dad_name, date, phone;
		std::cout << "Write FIO, date of birth and phone('*' if no need to check): ";
		std::cin >> sec_name >> name >> dad_name >> date >> phone; std::cout << std::endl;
		Node* current = head;
		while (current) {
			bool answer = false;
			if (sec_name != "*") {
				if (sec_name == current->data->GetSec_Name()) {
					answer = true;
				}
				else {
					answer = false;
				}
			}
			else if (name != "*") {
				if (name == current->data->GetName()) {
					answer = true;
				}
				else {
					answer = false;
				}
			}
			else if (dad_name != "*") {
				if (dad_name == current->data->GetDad_Name()) {
					answer = true;
				}
				else {
					answer = false;
				}
			}
			else if (date == "*") {
				if (date == current->data->GetDate()) {
					answer = true;
				}
				else {
					answer = false;
				}
			}
			else if (phone == "*") {
				if (phone == current->data->GetPhone()) {
					answer = true;
				}
				else {
					answer = false;
				}
			}
			if (answer == true or (phone == "*" and date == "*" and sec_name == "*" and name == "*" and dad_name == "*")) {
				for_del.push_back(current);
			}
			current = current->next;
		}
		if (not del) {
			for (int i = 0; i < for_del.size(); i++) {
				std::cout << i + 1 << ". ";
				std::cout << "Name: " << for_del[i]->data->GetSec_Name() << " " << for_del[i]->data->GetName() << " " << for_del[i]->data->GetDad_Name() << ", ";
				std::cout << "Date of Birth: " << for_del[i]->data->GetDate() << ", ";
				std::cout << "Phone Number: " << for_del[i]->data->GetPhone() << std::endl;
			}
		}
		else {
			for (int i = 0; i < for_del.size(); i++) {
				remove(for_del[i]->data);
			}
		}
	}

	// Person with the closest birthday
	void close_bd() {
		std::vector <Node*> ind;
		Node* current = head;
		int max_d = 366;
		Node* close = nullptr;

		while (current) {
			tm bd = { 0,0,0,
						current->data->GetDay(),
						current->data->GetMonth() - 1,
						current->data->GetYear() - 1900 };

			auto now = std::chrono::system_clock::now();
			time_t now_c = std::chrono::system_clock::to_time_t(now);
			tm* local = localtime(&now_c);
			bd.tm_year = local->tm_year;
			if (mktime(&bd) < mktime(local)) { bd.tm_year++; }
			std::chrono::system_clock::time_point birthday_time = std::chrono::system_clock::from_time_t(std::mktime(&bd));
			std::chrono::duration<double> diff = birthday_time - now;
			int days = static_cast<int>(diff.count() / (60 * 60 * 24)) + 1;
			if (days < max_d) {
				max_d = days;
				close = current;
			}
			current = current->next;
		}
		if (close != nullptr) {
			std::cout << "Name: " << close->data->GetSec_Name() << " " << close->data->GetName() << " " << close->data->GetDad_Name() << ", ";
			std::cout << "Date of Birth: " << close->data->GetDate() << ", ";
			std::cout << "Phone Number: " << close->data->GetPhone() << ", Days: " << max_d << std::endl;
		}
		else {
			return;
		}
		
	}

	// Clearing List
	void clearList() {
		Node* current = head;
		while (current) {
			Node* next = current->next;
			delete current->data; // Deleting the Person object stored in the node
			delete current; // Delete the node itself
			current = next;
		}
		head = tail = nullptr; // The head and tail pointers point to nullptr, i.e. the list is empty
		size = 0; // Resetting the list size to zero
	}

	// Export List to file "output.txt"
	void writeToFile(const std::string& filename) {
		std::ofstream outFile(filename);
		if (!outFile.is_open()) {
			std::cerr << "Failed to open file: " << filename << std::endl;
			return;
		}

		Node* current = head;
		while (current) {
			outFile << current->data->GetSec_Name() << " "
				<< current->data->GetName() << " "
				<< current->data->GetDad_Name() << " "
				<< current->data->GetDate() << " "
				<< current->data->GetPhone() << std::endl;
			current = current->next;
		}

		outFile.close();
	}

	// List bubble sort
	void bubbleSort() {
		if (!head || !head->next) {
			// If the list is empty or contains only one element, then it is already sorted
			return;
		}
		bool swapped;
		Node* last = nullptr;
		do {
			swapped = false;
			Node* current = head;
			while (current->next != last) {
				bool f = compare(current->data, current->next->data);
				if (f) {
					// If the current element is larger than the next one, swap them
					Person* temp = current->data;
					current->data = current->next->data;
					current->next->data = temp;
					swapped = true;
				}
				current = current->next;
			}
			last = current;
		} while (swapped);
	}

	// Destructor
	~List() {
		Node* current = head;
		while (current) {
			Node* next = current->next;
			delete current->data;
			delete current;
			current = next;
		}
	}
};