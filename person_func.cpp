#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "person.h"
#include <vector>

using namespace std;

// Initialize the person
Person::Person(const std::string& middle, const std::string& first, const std::string& last, const std::string& dob, const std::string& number) :
	sec_name(middle), name(first), dad_name(last), date(dob), phone(number) {};

// Splitting date str into vector: day, month, year
std::vector <int> Person::add_date() {
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
	}
	catch (const std::exception& e) {
		return {};
	}
}

// Adding a date in a separate format
void Person::set_date(std::vector <int> p1) {
	day = p1[0];
	month = p1[1];
	year = p1[2];
}

// Functions for obtaining information
std::string Person::GetName() const {
	return name;
}
std::string Person::GetSec_Name() const {
	return sec_name;
}
std::string Person::GetDad_Name() const {
	return dad_name;
}
std::string Person::GetDate() const {
	return date;
}
std::string Person::GetPhone() const {
	return phone;
}
int Person::GetDay() const {
	return day;
}
int Person::GetMonth() const {
	return month;
}
int Person::GetYear() const {
	return year;
}

// Checking for other characters when entering
std::string Person::check_input() {
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

// Checking that the date is not future
bool Person::isDateBeforeNow(int day, int month, int year) {
	time_t now = time(nullptr);
	tm* localTime = localtime(&now);

	// System date
	tm currentDate = { 0, 0, 0, localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900 };

	// Input date
	tm inputDate = { 0, 0, 0, day, month, year };

	return ((year * 10000 + month * 100 + day) - (currentDate.tm_year * 10000 + currentDate.tm_mon * 100 + currentDate.tm_mday)) <= 0;
}

// Checking the number of days in a month
bool Person::CheckDate(int day, int month, int year)
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
bool Person::right_date() {
	bool f = isDateBeforeNow(day, month, year);
	bool f1 = CheckDate(day, month, year);
	if (day == -1 or month == -1 or year == -1) {
		return false;
	}
	else if (not(1 <= month and month <= 12)) {
		return false;
	}
	else {
		tm time_info = { 0,0,0, day, month, year };
		tm time_info_mk = { 0,0,0, day, month - 1, year - 1900 };
		time_t time = mktime(&time_info_mk);
		return f && f1 && time != -1 &&
			time_info.tm_year == year &&
			time_info.tm_mon == month &&
			time_info.tm_mday == day;
	}
}