#pragma once

struct Students
{
	char surname[12];
	int group;
	int mark1;
	int mark2;
	int mark3;
};

void ReadFile(char*);
void WriteFile(char*);
