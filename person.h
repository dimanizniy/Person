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

	Person(const std::string& middle, const std::string& first, const std::string& last, const std::string& dob, const std::string& number);

	void set_date(std::vector <int> p1);

	std::string GetName() const;
	std::string GetSec_Name() const;
	std::string GetDad_Name() const;
	std::string GetDate() const;
	std::string GetPhone() const;
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;

	// Checking for other characters when entering
	std::string check_input();

	// Splitting date str into vector: day, month, year
	std::vector <int> add_date();

	// Checking that the date is not future
	bool isDateBeforeNow(int day, int month, int year);

	// Checking the number of days in a month
	bool CheckDate(int day, int month, int year);

	// Existence date check
	bool right_date();

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
	List();

	// Checking an integer
	std::string true_int();

	// Get Person by index
	Person* getByIndex(int index);

	// Adding a person
	void append(Person* p);

	// Removing a person
	void remove(Person* p);

	// List Output
	void printList();

	// Adding all Persons from a file
	void addFromFile(const std::string& filename);

	// Comparison of two Persons
	bool compare(Person* person1, Person* person2);

	// Checking one Person
	void check_person(List& list, bool del);

	// Person with the closest birthday
	void close_bd();

	// Clearing List
	void clearList();

	// Export List to file "output.txt"
	void writeToFile(const std::string& filename);

	// List bubble sort
	void bubbleSort();

	// Destructor
	~List();
};