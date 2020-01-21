#include <fstream>
#include <iostream>
#include "Database.h"

#define BOYS_FILE "boys.txt"
#define GIRL_FILE "girl.txt"

Database::Database()
{
}

Database::~Database()
{
}

void Database::init()
{
	//从文件中读取信息来初始化"boy"和"Girl"
	initBoysFromFile();
	initGirlsFromFile();
}

void Database::print()
{
	cout << "\n--------男嘉宾的信息--------\n";
	for (int i = 0; i < boys.size(); i++) {
		cout << boys[i].description() << endl;
	}
	cout << "\n\n--------女嘉宾的信息--------\n";
	for (int i = 0; i < girls.size(); i++) {
		cout << girls[i].description() << endl;
	}
}

void Database::addOne(boy &boy1)
{
	boys.push_back(boy1);
	
	cout << "--------自动配对结果--------\n";

	//line 的初始化为（有50个‘-’）
	string line(50, '-');
	cout << line << endl;
	
	for (int j = 0; j < girls.size(); j++) {

		if (boy1.satisfied(girls[j]) &&
			girls[j].satisfied(boy1)) {

			cout << boy1.description() << endl;
			cout << girls[j].description() << endl;
			cout << endl << line << endl;
		}
	}
	saveBoys(); //保存boys的信息到文件中
}

void Database::addOne(Girl &girl)
{
	girls.push_back(girl);

	cout << "--------自动配对结果--------\n";

	//line 的初始化为（有50个‘-’）
	string line(50, '-');
	cout << line << endl;

	for (int j = 0; j < boys.size(); j++) {

		if (girl.satisfied(boys[j]) &&
			boys[j].satisfied(girl)) {

			cout << girl.description() << endl;
			cout << boys[j].description() << endl;
			cout << endl << line << endl;
		}
	}
	saveGirls();//保存Girl的信息到文件中

}

void Database::autoPair()
{
	cout << "--------自动配对结果--------\n";

	//line 的初始化为（有50个‘-’）
	string line(50, '-');
	cout << line << endl;
	for (int i = 0; i < boys.size(); i++) {
		for (int j = 0; j < girls.size(); j++) {

			if (boys[i].satisfied(girls[j]) &&
				girls[j].satisfied(boys[i])) {

				cout << boys[i].description() << endl;
				cout<< girls[j].description() << endl;
				cout << endl<<line << endl;
			}
		}
	}

	cout << line << endl;
	for (int i = 0; i < girls.size(); i++) {
		for (int j = 0; j < boys.size(); j++) {

			if (boys[j].satisfied(girls[i]) &&
				girls[i].satisfied(boys[j])) {

				cout << girls[i].description() << endl;
				cout << boys[j].description() << endl;
				cout << endl << line << endl;
			}
		}
	}
}

void Database::autoPairBest()
{
	cout << "--------------男士自动配对最佳伴侣---------------\n";

	//line 的初始化为（有50个‘-’）
	string line(50, '-');
	cout << line << endl;

	for (int i = 0; i < boys.size(); i++) {
		Girl* girlBest = NULL;

		for (int j = 0; j < girls.size(); j++) {

			if (girls[j].satisfied(boys[i]) &&
				boys[i].satisfied(girls[j])) {

				//cout << girls[j].description() << endl;
				//cout << boys[i].description() << endl;
				//cout << endl << line << endl;
				if (!girlBest) {
					girlBest = &girls[j];
				}
				else if (girls[j] > * girlBest) {
					girlBest = &girls[j];
				}

			}
		}
		if (girlBest) {
			cout << boys[i] << endl;
			cout << *girlBest<< endl;
			cout << endl << line << endl;
		}
	}

	cout << "--------------女士自动配对最佳伴侣---------------\n\n";
	for (int i = 0; i< girls.size(); i++) {
		boy* boyBest = NULL;

		for (int j = 0; j < boys.size(); j++) {

			if (girls[i].satisfied(boys[j]) &&
				boys[j].satisfied(girls[i])) {

				//cout << girls[j].description() << endl;
				//cout << boys[i].description() << endl;
				//cout << endl << line << endl;
				if (!boyBest) {
					boyBest = &boys[j];
				}
				else if (boys[j] > * boyBest) {
					boyBest = &boys[j];
				}

			}
		}
		if (boyBest) {
			cout << girls[i] << endl;
			cout << *boyBest << endl;
			cout << endl << line << endl;
		}
	}
}

void Database::initBoysFromFile()
{
	ifstream stream;
	stream.open(BOYS_FILE);
	if (!stream.is_open()) {
		//假设有此需求
		//最开始没有要打开的这个文件
		//就让管理员输入基础用户数据信息
		cout << "--------输入基础用户 [男嘉宾] 数据-------\n\n";
		boy::inputBoys(this->boys);
		saveBoys(); //保存boys的信息到文件中
		stream.close();
		return;
	}
	//文件打开成功；
	while (1) {
		string line;
		char name[32]="";
		int age;
		int salary;
		getline(stream, line);
		if (stream.eof()) {
			break;
		}
		//解析读到的一行数据 line
		//文件格式 << "姓名:" << name << "\t\t性别:男\t\t薪资:" << salary 
		//<< "\t\t年龄:" << age;
		int ret = sscanf_s(line.c_str(),"姓名:%s 性别:男 薪资:%d 年龄:%d",
			name, sizeof(name), &salary, &age);
		if (ret <= 0) {
			cout << "男嘉宾数据解析失败!\n";
			system("pause");
			exit(-1);
		}
		//把读到的boys信息 构建一个boy对象 并保存到boys里
		boys.push_back(boy(age, string(name), salary));
	}
	stream.close();
}

void Database::initGirlsFromFile()
{
	ifstream stream;
	stream.open(GIRL_FILE);
	if (!stream.is_open()) {
		//假设有此需求
		//最开始没有要打开的这个文件
		//就让管理员输入基础用户数据信息
		cout << "--------输入基础用户 [女嘉宾] 数据-------\n\n";
		Girl::inputGirl(this->girls);
		saveGirls(); //保存Girl的信息到文件中
		stream.close();
		return;
	}
	//文件打开成功；
	while (1) {
		string line;
		char name[32];
		int age;
		int yanzhi;
		getline(stream, line);
		if (stream.eof()) {
			break;
		}
		//解析读到的一行数据 line
		//文件格式 << "姓名:" << name << "\t\t性别:男\t\t薪资:" << salary 
		//<< "\t\t年龄:" << age;

		int ret = sscanf_s(line.c_str(), "姓名:%s 性别:女 颜值:%d 年龄:%d",
			name, sizeof(name), &yanzhi, &age);
		if (ret <= 0) {
			cout << "女嘉宾数据解析失败!\n";
			system("pause");
			exit(-1);
		}
		//把读到的boys信息 构建一个boy对象 并保存到boys里
		girls.push_back(Girl(age, string(name), yanzhi));
	}

	stream.close();
}

void Database::saveBoys()
{
	ofstream stream;
	stream.open(BOYS_FILE);
	if (!stream.is_open()) {
		cout << BOYS_FILE << "写入失败" << endl;
		exit(-1);
	}
	for (int i = 0; i < boys.size(); i++) {
		stream << boys[i].description() << endl;
	}
	stream.close();
}

void Database::saveGirls()
{
	ofstream stream;
	stream.open(GIRL_FILE);
	if (!stream.is_open()) {
		cout << GIRL_FILE << "写入失败" << endl;
		exit(-1);
	}
	for (int i = 0; i < girls.size(); i++) {
		stream << girls[i].description() << endl;
	}
	stream.close();
}

