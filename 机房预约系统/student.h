#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<vector>
#include"computerRoom.h"
#include"globalFile.h"
#include<fstream>
#include"order.h"
//ѧ����
class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id,string name,string pwd);
	//�˵�����
	virtual void operMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴�ҵ�ԤԼ
	void showOrder();
	//�鿴����ԤԼ
	void shoeAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
public:
	//ѧ��ѧ��
	int m_Id;
	vector<ComputerRoom> vCom;
};
