#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<vector>
#include"computerRoom.h"
#include"globalFile.h"
#include<fstream>
#include"order.h"
//学生类
class Student :public Identity
{
public:
	//默认构造
	Student();
	//有参构造
	Student(int id,string name,string pwd);
	//菜单界面
	virtual void operMenu();
	//申请预约
	void applyOrder();
	//查看我的预约
	void showOrder();
	//查看所有预约
	void shoeAllOrder();
	//取消预约
	void cancelOrder();
public:
	//学生学号
	int m_Id;
	vector<ComputerRoom> vCom;
};
