#include <iostream>
#include "Single.h"


using namespace std;

Single::Single()
{
	this->name = " ";
	this->age = 0;
}

Single::Single(string name, int age) {
	this->name = name;
	this->age = age;
}

Single::~Single()
{
}

int Single::getAge()const {
	return age;
}

string Single::getName()const {
	return name;
}

void Single::errorinfo()
{
	cout << "��������������������\n";
	cin.clear();//	��������־
	char ch;
	while ((ch = getchar()) != '\n');
}
