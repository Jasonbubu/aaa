#include <sstream> //stringstringͷ�ļ�
#include <iostream>
#include <iomanip> 
#include "Girl.h"

class boy;

Girl::Girl():Single("δ֪", 0) {
	//age = 0;
	//name = "";
	yanZhi = 0;
}

Girl::Girl(int age, string name, int yanZhi):Single(name, age){
	//this->age = age;
	//this->name = name;
	this->yanZhi = yanZhi; 
}


Girl::~Girl(){ 
}

/*
int Girl::getAge() const{
	return age;
}

string Girl::getName() const{
	return name;
}
*/

int Girl::getYanZhi() const{
	return yanZhi;
}

bool Girl::satisfied(const boy &boy) const{
	if (boy.getSalary() >= yanZhi * YANZHI_FACTOR) {
		return true;
	}
	else {
		return false;
	}
}

string Girl::description() const{
	stringstream ret; //ע�⣺stringstream���ݵ��÷�
                      //��Ҫ��������ݰ��Զ���ĸ�ʽ˳������뵽ret��
	                  //�ٵ���ret.str()����ת���ַ���
	//ret <<"����("<<name << ")-Ů-��ֵ(" << yanZhi << ")-����(" << age << ")";
	ret << "����:" << name << "\t\t�Ա�:Ů\t\t��ֵ:"
		<<setw(3)<<setiosflags(ios::left) //��������Ŀ�� ���Ҷ��� setw˭��ǰ�������˭
		<<yanZhi << "\t\t����:" <<age;

	return ret.str();
}

bool Girl::operator>(const Girl& girl)
{
	if (this->yanZhi > girl.yanZhi) {
		return true;
	}else{
		return false;
	}
	
}

void Girl::inputGirl(vector<Girl> &girls) {
	int age;
	int yanZhi;
	int n = 1;
	string name;

	while (1) {
		cout << "�������" << n << "��С��������[ 0 ����]: ";
		cin >> age;
		if (age == 0) {
			break;
		}
		if (cin.fail()) {
			Girl::errorinfo();
			continue;
		}
		cout << "�������" << n << "��С��������: ";
		cin >> name;
		if (cin.fail()) {
			Girl::errorinfo();
			continue;
		}
		cout << "�������" << n << "��С������ֵ: ";
		cin >> yanZhi;
		if (cin.fail()) {
			Girl::errorinfo();
			continue;
		}

		girls.push_back(Girl(age, name, yanZhi));
		n++;
	}
	return;
}

void Girl::inputGirls(Girl &girl)
{
	int age = 0;
	int yanZhi = 0;
	string name = "";
	continue1:
	cout << "������С��������[ 0 ����]: ";
	cin >> age;
	if (cin.fail()) {
		Girl::errorinfo();
		goto continue1;
	}
	continue2:
	cout << "�������С��������: ";
	cin >> name;
	if (cin.fail()) {
		Girl::errorinfo();
		goto continue2;
	}
	continue3:
	cout << "�������С������ֵ: ";
	cin >> yanZhi;
	if (cin.fail()) {
		Girl::errorinfo();
		goto continue3;
	}

   girl=Girl(age, name, yanZhi);
	//girls.push_back(Girl(age, name, yanZhi));

}

ostream& operator<<(ostream& os, const Girl& girl)
{
	// TODO: �ڴ˴����� return ���

	os<<"����:" << girl.name << "\t\t�Ա�:Ů\t\t��ֵ:"
		<< setw(3) << setiosflags(ios::left) //��������Ŀ�� ���Ҷ��� setw˭��ǰ�������˭
		<<girl.yanZhi << "\t\t����:" << girl.age;
	return os;
}
