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
	//���ļ��ж�ȡ��Ϣ����ʼ��"boy"��"Girl"
	initBoysFromFile();
	initGirlsFromFile();
}

void Database::print()
{
	cout << "\n--------�мα�����Ϣ--------\n";
	for (int i = 0; i < boys.size(); i++) {
		cout << boys[i].description() << endl;
	}
	cout << "\n\n--------Ů�α�����Ϣ--------\n";
	for (int i = 0; i < girls.size(); i++) {
		cout << girls[i].description() << endl;
	}
}

void Database::addOne(boy &boy1)
{
	boys.push_back(boy1);
	
	cout << "--------�Զ���Խ��--------\n";

	//line �ĳ�ʼ��Ϊ����50����-����
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
	saveBoys(); //����boys����Ϣ���ļ���
}

void Database::addOne(Girl &girl)
{
	girls.push_back(girl);

	cout << "--------�Զ���Խ��--------\n";

	//line �ĳ�ʼ��Ϊ����50����-����
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
	saveGirls();//����Girl����Ϣ���ļ���

}

void Database::autoPair()
{
	cout << "--------�Զ���Խ��--------\n";

	//line �ĳ�ʼ��Ϊ����50����-����
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
	cout << "--------------��ʿ�Զ������Ѱ���---------------\n";

	//line �ĳ�ʼ��Ϊ����50����-����
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

	cout << "--------------Ůʿ�Զ������Ѱ���---------------\n\n";
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
		//�����д�����
		//�ʼû��Ҫ�򿪵�����ļ�
		//���ù���Ա��������û�������Ϣ
		cout << "--------��������û� [�мα�] ����-------\n\n";
		boy::inputBoys(this->boys);
		saveBoys(); //����boys����Ϣ���ļ���
		stream.close();
		return;
	}
	//�ļ��򿪳ɹ���
	while (1) {
		string line;
		char name[32]="";
		int age;
		int salary;
		getline(stream, line);
		if (stream.eof()) {
			break;
		}
		//����������һ������ line
		//�ļ���ʽ << "����:" << name << "\t\t�Ա�:��\t\tн��:" << salary 
		//<< "\t\t����:" << age;
		int ret = sscanf_s(line.c_str(),"����:%s �Ա�:�� н��:%d ����:%d",
			name, sizeof(name), &salary, &age);
		if (ret <= 0) {
			cout << "�мα����ݽ���ʧ��!\n";
			system("pause");
			exit(-1);
		}
		//�Ѷ�����boys��Ϣ ����һ��boy���� �����浽boys��
		boys.push_back(boy(age, string(name), salary));
	}
	stream.close();
}

void Database::initGirlsFromFile()
{
	ifstream stream;
	stream.open(GIRL_FILE);
	if (!stream.is_open()) {
		//�����д�����
		//�ʼû��Ҫ�򿪵�����ļ�
		//���ù���Ա��������û�������Ϣ
		cout << "--------��������û� [Ů�α�] ����-------\n\n";
		Girl::inputGirl(this->girls);
		saveGirls(); //����Girl����Ϣ���ļ���
		stream.close();
		return;
	}
	//�ļ��򿪳ɹ���
	while (1) {
		string line;
		char name[32];
		int age;
		int yanzhi;
		getline(stream, line);
		if (stream.eof()) {
			break;
		}
		//����������һ������ line
		//�ļ���ʽ << "����:" << name << "\t\t�Ա�:��\t\tн��:" << salary 
		//<< "\t\t����:" << age;

		int ret = sscanf_s(line.c_str(), "����:%s �Ա�:Ů ��ֵ:%d ����:%d",
			name, sizeof(name), &yanzhi, &age);
		if (ret <= 0) {
			cout << "Ů�α����ݽ���ʧ��!\n";
			system("pause");
			exit(-1);
		}
		//�Ѷ�����boys��Ϣ ����һ��boy���� �����浽boys��
		girls.push_back(Girl(age, string(name), yanzhi));
	}

	stream.close();
}

void Database::saveBoys()
{
	ofstream stream;
	stream.open(BOYS_FILE);
	if (!stream.is_open()) {
		cout << BOYS_FILE << "д��ʧ��" << endl;
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
		cout << GIRL_FILE << "д��ʧ��" << endl;
		exit(-1);
	}
	for (int i = 0; i < girls.size(); i++) {
		stream << girls[i].description() << endl;
	}
	stream.close();
}

