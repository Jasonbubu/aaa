#pragma once
#include <vector>
#include "boy.h"
#include "Girl.h"

using namespace std;

class Database
{
public:
	Database();
	~Database();
	
	//��ʼ���ļ�
	void init();
	//�Զ����
	void autoPair();

	//�Զ������Ѱ�����Ϣ
	void autoPairBest();

	// ��Ϣ��ӡ
	void print();  

	//�����Ϣ����
	void addOne(boy &boy);
	//�����Ϣ����
	void addOne(Girl& girl);


;
private:
	//���ļ���������ʼ��boy
	void initBoysFromFile();
	//���ļ���������ʼ��girl
	void initGirlsFromFile();
	//����boys����Ϣ���ļ���
	void saveBoys();
	//����Girl����Ϣ���ļ���
	void saveGirls();

	vector<boy>boys;  //���е����к�����Ϣ
	vector<Girl>girls;//���е���Ů������Ϣ

};

 