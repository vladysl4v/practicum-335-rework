#include <iostream>
#include <iomanip>
#include <fstream>
#include "header.h"

using namespace std;

void ReadFile(char* filename)
{
	double excellent = 0;
	int size;
	ifstream fin(filename);
	if (!fin)
	{
		cout << "ERROR" << endl;
		return;
	}

	fin >> size;
	Students* list = new Students[size];

	for (int i = 0; i < size; i++)
	{
		fin >> list[i].surname >> list[i].group;
		fin >> list[i].mark1 >> list[i].mark2 >> list[i].mark3;

		cout << setw(12) << list[i].surname
			<< setw(6) << list[i].group
			<< setw(8) << list[i].mark1
			<< setw(4) << list[i].mark2
			<< setw(4) << list[i].mark3
			<< endl;

		if (list[i].mark1 > 3 && list[i].mark2 > 3 && list[i].mark3 > 3)
			excellent++;
	}
	int success = (excellent / size) * 100;
	cout << "Quality of student success: " << success << "%" << endl << endl;
	fin.close();
}

void WriteFile(char* filename)
{
	int group, mark1, mark2, mark3;
	char surname[12];
	int size = 0;

	ofstream fout(filename);

	if (!fout)
	{
		cout << "ERROR" << endl;
		return;
	}

	fout << 0 << endl;

	do {
		cout << "Surname -> ";
		cin.getline(surname, 12);

		if (strcmp(surname, "*"))
		{
			size++;
			fout << surname << endl;
			cout << "group -> ";	cin >> group;	fout << group << endl;
			cout << "mark1 -> ";	cin >> mark1;	fout << mark1 << endl;
			cout << "mark2 -> ";	cin >> mark2;	fout << mark2 << endl;
			cout << "mark3 -> ";	cin >> mark3;	fout << mark3 << endl;
			cin.ignore();
		}
	} while (strcmp(surname, "*"));
	fout.seekp(0, ios::beg);
	fout << size;
	fout.close();
}