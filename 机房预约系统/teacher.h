#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"order.h"
#include<vector>
#include"order.h"
//教师类
class Teacher :public Identity
{
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(int empId, string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//查看所有预约
	void showAllOrder();
	//审核预约
	void validOrder();
	//教师编号
public:
	int m_EmpId;//教师编号
};