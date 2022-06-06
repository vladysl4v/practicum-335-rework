#include <iostream>
#include "header.h"

using namespace std;


int main()
{
	char filename[22];
	int n;
	do {
		cout << "Menu:\n"
			<< "1 - Write to file\n"
			<< "2 - Read File\n"
			<< "0 - Quit\n\n=>";
		cin >> n;
		cin.ignore();
		switch (n)
		{
		case 1:
			cout << "Input a file name, please\n";
			cin.getline(filename, 22);
			WriteFile(filename);
			break;
		case 2:
			cout << "Input a file name, please\n";
			cin.getline(filename, 22);
			ReadFile(filename);
			break;
		default: n = 0;
		}
	} while (n);
}

