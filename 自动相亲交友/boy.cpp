#include <sstream>
#include <iostream>
#include "Girl.h"



boy::boy() :Single("未知", 0) {
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
	//ret <<"姓名 ("<< name << ")-男-薪(" << salary << ")-年龄(" << age << ")";
	//ret << "姓名 (" << getName() << ")-男-薪(" << salary << ")-年龄(" << getAge() << ")";
	ret << "姓名:" << name << "\t\t性别:男\t\t薪资:" << salary 
		<< "\t\t年龄:" << age;

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
		cout << "请输入第" << n << "个小哥的年龄[ 0 键结束]：";
		cin >> age;
		if (age == 0 ) {	
			break;
		}
		if (cin.fail()) {
			boy::errorinfo();
			continue;
		}
		cout << "请输入第" << n << "个小哥的姓名：";
		cin >> name;
		if (cin.fail()) {
			boy::errorinfo();
			continue;
		}
		cout << "请输入第" << n << "个小哥的薪资：";
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
	cout << "请输入小哥哥的年龄[ 0 键结束]：";
	cin >> age;
	if (cin.fail()) {
		boy::errorinfo();
		goto continue1;
	}
	continue2:
	cout << "请输入小哥哥的姓名：";
	cin >> name;
	if (cin.fail()) {
		boy::errorinfo();
		goto continue2;
	}
	continue3:
	cout << "请输入小哥哥的薪资：";
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
	// TODO: 在此处插入 return 语句
	os << "姓名:" << boys.name 
		<< "\t\t性别:男\t\t薪资:" <<boys.salary
		<< "\t\t年龄:" << boys.age;
	return os;
}
