#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalFile.h"
#include<fstream>

//预约类
class OrderFile
{
public:
	//构造
	OrderFile();
	//更新预约记录
	void updateOrder();
	//记录容器
	map<int, map<string, string>> m_orderData;
	//预约记录条件
	int m_Size;
};