#pragma once
#include<iostream>
using namespace std;
#include"teacher.h"
#include"student.h"
#include"identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include<vector>
#include<algorithm>
#include"computerRoom.h"
//����Ա��
class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//ѡ��˵�
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//��ʼ������
	void initVector();
	
	//����ظ�
	bool checkRepeat(int id, int type);

public:
	//ѧ������
	vector<Student> vStu;
	//��ʦ����
	vector<Teacher> vTea;
	//��������
	vector<ComputerRoom> vCom;
};