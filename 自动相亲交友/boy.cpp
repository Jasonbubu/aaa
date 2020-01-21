#include <sstream>
#include <iostream>
#include "Girl.h"



boy::boy() :Single("δ֪", 0) {
	//age = 0;
	//name = "";
	salary = 0;
}

boy::boy(int age, string name, int salary):Single(name,age) {
	//this->age = age;
	//this->name = name;
	this->salary = salary;
}

boy::boy(const boy &other) :Single(other.getName(), other.getAge()) {

	salary = other.salary;
}

boy::~boy()
{
}


/*
int Girl::getAge() const{
return age;
}

string Girl::getName() const{
return name;
}
*/

int boy::getSalary()const {
	return salary;
}

string boy::description()const {
	stringstream ret;
	//ret <<"���� ("<< name << ")-��-н(" << salary << ")-����(" << age << ")";
	//ret << "���� (" << getName() << ")-��-н(" << salary << ")-����(" << getAge() << ")";
	ret << "����:" << name << "\t\t�Ա�:��\t\tн��:" << salary 
		<< "\t\t����:" << age;

	return ret.str();
}

bool boy::satisfied(const Girl &girl)const {
	int yanzhi = salary * SALARY_FACTOR;
	if (yanzhi > 100) {
		yanzhi = 95;
	}
	if (girl.getYanZhi() >= yanzhi) {
		return true;
	}
	else {
		return false;
	}
}

void boy::inputBoys(vector<boy> &boys) {
	int n = 1;
	int age;
	string name;
	int salary;

	while (1) {
		cout << "�������" << n << "��С�������[ 0 ������]��";
		cin >> age;
		if (age == 0 ) {	
			break;
		}
		if (cin.fail()) {
			boy::errorinfo();
			continue;
		}
		cout << "�������" << n << "��С���������";
		cin >> name;
		if (cin.fail()) {
			boy::errorinfo();
			continue;
		}
		cout << "�������" << n << "��С���н�ʣ�";
		cin >> salary;
		if (cin.fail()) {
			boy::errorinfo();
			continue;
		}

		boys.push_back(boy(age, name, salary));
		n++;
	}

	return;
}

void boy::inputBoy(boy& boy1)
{
	int age = 0;
	string name = "";
	int salary = 0;
	continue1:
	cout << "������С��������[ 0 ������]��";
	cin >> age;
	if (cin.fail()) {
		boy::errorinfo();
		goto continue1;
	}
	continue2:
	cout << "������С����������";
	cin >> name;
	if (cin.fail()) {
		boy::errorinfo();
		goto continue2;
	}
	continue3:
	cout << "������С����н�ʣ�";
	cin >> salary;
	if (cin.fail()) {
		boy::errorinfo();
		goto continue3;
	}

	boy1=boy(age, name, salary);
}

bool boy::operator>(boy& boys)
{
	if (this->salary > boys.salary) {
		return true;
	}
	else {
		return false;
	}

}

ostream& operator<<(ostream& os, const boy& boys)
{
	// TODO: �ڴ˴����� return ���
	os << "����:" << boys.name 
		<< "\t\t�Ա�:��\t\tн��:" <<boys.salary
		<< "\t\t����:" << boys.age;
	return os;
}
