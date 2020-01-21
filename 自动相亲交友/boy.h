#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Girl.h"
#include "Single.h"


#define SALARY_FACTOR  0.006//薪资对应的颜值系数

class Girl;

using namespace std;

class boy : public Single{
public:
	boy();
	boy(int age,string name,int salary);
	boy(const boy &other);
	~boy();

	//int getAge()const;
	//string getName()const;
	int getSalary()const;
	string description()const;

	//设置相亲对象的要求系数
	bool satisfied(const Girl &girl)const;
	//输入多个男孩的信息
	static void inputBoys(vector<boy> &boys); 
	//输入一个男孩的信息
	static void inputBoy(boy& boy1); 


	//男孩类的比较运算符重载
	bool operator>(boy& boys);

	//友元 函数 输出运输符重载
	friend ostream& operator<<(ostream& os, const boy& boys);

private:
	//int age;
	//string name;
	int salary;  //薪资

};


ostream& operator<<(ostream& os, const boy &boys);