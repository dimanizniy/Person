#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

#include "person.h"
#include <Windows.h>


int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	List list;

	std::cout << "1 - Adding from keyboard" << std::endl;
	std::cout << "2 - Adding from file" << std::endl;
	std::cout << "3 - Compare two people" << std::endl;
	std::cout << "4 - Output" << std::endl;
	std::cout << "5 - Check one person" << std::endl;
	std::cout << "6 - Days until birthday" << std::endl;
	std::cout << "7 - Export the database to the file" << std::endl;
	std::cout << "8 - Sort the database" << std::endl;
	std::cout << "-1 - Clear the database" << std::endl;
	std::cout << "0 - Exit" << std::endl;
	std::string flag = "10";
	while (flag != "0") {
		std::cout << "Choose action: ";
		std::cin >> flag; std::cout << std::endl;
		if (flag == "0") {
			std::cout << "The end...";
			break;
		}
		else if (flag == "1") {
			std::string name, sec_name, dad_name, date, phone;
			std::cout << "Write a FIO, date and phone: ";
			std::cin >> sec_name >> name >> dad_name >> date >> phone; std::cout << std::endl;
			Person* p = new Person(sec_name, name, dad_name, date, phone);
			list.append(p);

		}
		else if (flag == "2")
		{
			std::string adress;
			std::cout << "Write an adress to file: ";
			std::cin >> adress; std::cout << std::endl;
			list.addFromFile(adress);
		}
		else if (flag == "3") {
			list.compare(list);
		}
		else if (flag == "4") {
			list.printList();
		}
		else if (flag == "5") {
			list.check_person();
		}
		else if (flag == "6") {
			list.birthday();
		}
		else if (flag == "7") {
			list.writeToFile("output.txt");
			std::cout << "Exported!" << std::endl;
		}
		else if (flag == "8") {
			list.bubbleSort();
			std::cout << "Sorted!" << std::endl;
		}
		else if (flag == "-1") {
			list.clearList();
			std::cout << "Database is cleared" << std::endl;
		}
	}
	if (flag == "0") {
		exit;
	}
}