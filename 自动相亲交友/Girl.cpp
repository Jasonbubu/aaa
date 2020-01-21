#include <sstream> //stringstring头文件
#include <iostream>
#include <iomanip> 
#include "Girl.h"

class boy;

Girl::Girl():Single("未知", 0) {
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
	stringstream ret; //注意：stringstream数据的用法
                      //把要输入的数据按自定义的格式顺序的输入到ret中
	                  //再调用ret.str()方法转成字符串
	//ret <<"姓名("<<name << ")-女-颜值(" << yanZhi << ")-年龄(" << age << ")";
	ret << "姓名:" << name << "\t\t性别:女\t\t颜值:"
		<<setw(3)<<setiosflags(ios::left) //设置输出的宽度 及右对齐 setw谁的前面就设置谁
		<<yanZhi << "\t\t年龄:" <<age;

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
		cout << "请输入第" << n << "个小姐姐的年龄[ 0 结束]: ";
		cin >> age;
		if (age == 0) {
			break;
		}
		if (cin.fail()) {
			Girl::errorinfo();
			continue;
		}
		cout << "请输入第" << n << "个小姐姐的姓名: ";
		cin >> name;
		if (cin.fail()) {
			Girl::errorinfo();
			continue;
		}
		cout << "请输入第" << n << "个小姐姐的颜值: ";
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
	cout << "请输入小姐姐的年龄[ 0 结束]: ";
	cin >> age;
	if (cin.fail()) {
		Girl::errorinfo();
		goto continue1;
	}
	continue2:
	cout << "请输入个小姐姐的姓名: ";
	cin >> name;
	if (cin.fail()) {
		Girl::errorinfo();
		goto continue2;
	}
	continue3:
	cout << "请输入个小姐姐的颜值: ";
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
	// TODO: 在此处插入 return 语句

	os<<"姓名:" << girl.name << "\t\t性别:女\t\t颜值:"
		<< setw(3) << setiosflags(ios::left) //设置输出的宽度 及右对齐 setw谁的前面就设置谁
		<<girl.yanZhi << "\t\t年龄:" << girl.age;
	return os;
}
