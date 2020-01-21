#include <iostream>
//#include <stdlib.h>
#include <vector>
#include "boy.h"
#include "Database.h"

/*
����������
25 ��� 15000
28 ���� 8000
35 ���� 50000
0
18 С��Ů 95
25 �绨  79
26 ����  90
26 ��Ī�� 100
0
*/

/**
void autoPair(const vector<boy>&boys, const vector<Girl>&girls) {

	for (int i = 0; i < boys.size(); i++) {
		for (int j = 0; j < girls.size(); j++) {

			if (boys[i].satisfied(girls[j]) &&
				girls[j].satisfied(boys[i])) {

				cout << boys[i].description() << "\n<--ƥ��-->"
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

	data.init(); //��ʼ������
	//data.print();//��ӡ��Ϣ
	//data.autoPair(); //�Զ����
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
	 cout << "\n\n-----��ӭʹ���Զ����׽������ϵͳ-----\n\n";
		cout << "1:������Ա��Ϣ�鿴:" << endl;
		cout << "2:������Ա�����Ϣ�鿴" << endl;
		cout << "3:��������Ա��Ϣ" << endl;
		cout << "4:�����к���Ϣ:" << endl;
		cout << "5:����Ů����Ϣ:" << endl;
		cout << "0:�˳�:" << endl;
		cout << "��ѡ��:";
		cin >> n;
		if (n == 0) {
			return 0;
		}
		switch (n) {
		case 1:
			data.print();//��ӡ��Ϣ
			system("pause");
			break;
		case 2:
			data.autoPair(); //�Զ����
			system("pause");
			break;
		case 3:
			data.autoPairBest();//������
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
			cout << "��������������������\n";
			cin.clear();//	��������־
			char ch;
			while ((ch = getchar()) != '\n');
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}