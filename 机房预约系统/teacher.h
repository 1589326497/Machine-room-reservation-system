#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"order.h"
#include<vector>
#include"order.h"
//��ʦ��
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int empId, string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
	//��ʦ���
public:
	int m_EmpId;//��ʦ���
};