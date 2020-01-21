#include <iostream>
//#include <stdlib.h>
#include <vector>
#include "boy.h"
#include "Database.h"

/*
输入用例：
25 杨过 15000
28 郭靖 8000
35 段誉 50000
0
18 小龙女 95
25 如花  79
26 秋香  90
26 李莫愁 100
0
*/

/**
void autoPair(const vector<boy>&boys, const vector<Girl>&girls) {

	for (int i = 0; i < boys.size(); i++) {
		for (int j = 0; j < girls.size(); j++) {

			if (boys[i].satisfied(girls[j]) &&
				girls[j].satisfied(boys[i])) {

				cout << boys[i].description() << "\n<--匹配-->"
					<< girls[j].description() << endl;
				cout << endl;
			}
		}
	}

}*/

int main(void) {	
	/*
	vector<boy>boys;
	vector<Girl>girls;

	boy::inputBoys(boys);
	Girl::inputGirl(girls);

	autoPair(boys, girls);
	*/
	Database data;

	data.init(); //初始化数据
	//data.print();//打印信息
	//data.autoPair(); //自动配对
	boy boy1;
	//boy::inputBoy(boy1);
	//data.addOne(boy1);

	Girl girl;
	//girl.inputGirls(girl);
	//data.addOne(girl);
	int n;
	while (true)
	{
		system("cls");
	 cout << "\n\n-----欢迎使用自动相亲交友配对系统-----\n\n";
		cout << "1:所有人员信息查看:" << endl;
		cout << "2:所有人员配对信息查看" << endl;
		cout << "3:最佳配对人员信息" << endl;
		cout << "4:输入男孩信息:" << endl;
		cout << "5:输入女孩信息:" << endl;
		cout << "0:退出:" << endl;
		cout << "请选择:";
		cin >> n;
		if (n == 0) {
			return 0;
		}
		switch (n) {
		case 1:
			data.print();//打印信息
			system("pause");
			break;
		case 2:
			data.autoPair(); //自动配对
			system("pause");
			break;
		case 3:
			data.autoPairBest();//最佳配对
			system("pause");
			break;
		case 4:
			boy::inputBoy(boy1);
			data.addOne(boy1);
			system("pause");
			break;
		case 5:
			girl.inputGirls(girl);
			data.addOne(girl);
			system("pause");
			break;
		default:
			cout << "你输入有误请重新输入\n";
			cin.clear();//	清除错误标志
			char ch;
			while ((ch = getchar()) != '\n');
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}