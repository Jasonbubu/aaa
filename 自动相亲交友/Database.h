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
	
	//初始化文件
	void init();
	//自动配对
	void autoPair();

	//自动配对最佳伴侣信息
	void autoPairBest();

	// 信息打印
	void print();  

	//配对信息处理
	void addOne(boy &boy);
	//配对信息处理
	void addOne(Girl& girl);


;
private:
	//用文件数据来初始化boy
	void initBoysFromFile();
	//用文件数据来初始化girl
	void initGirlsFromFile();
	//保存boys的信息到文件中
	void saveBoys();
	//保存Girl的信息到文件中
	void saveGirls();

	vector<boy>boys;  //所有单身男孩的信息
	vector<Girl>girls;//所有单身女孩的信息

};

 