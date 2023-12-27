/*
	����ԤԼϵͳ ��ϰ��Ŀ 2023/5/1��ʼ����2023/5/3���
*/
#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
void managerMenu(Identity*& manager);
void studentMenu(Identity*& student);
void teacherMenu(Identity*& teacher);
//��¼
void LoginIn(string fileName, int type)
{
	//�����ָ��
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);
	//�ļ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)//ѧ����¼
	{
		cout << "����������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;
	
	//��¼��֤
	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				//��¼�ɹ� �����������ϵͳ
				system("pause");
				system("cls");
				//����ѧ������
				person = new Student(id, name, pwd);
				//����ѧ���˵�
				studentMenu(person);
				return;
			}
		}	
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				//������ʦ����
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd)
		{
			if ( name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				//��������Ա����
				person = new Manager( name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��¼��֤ʧ�ܣ�" << endl;

	system("pause");
	system("cls");
	return;
}

//����Ա�˵� ����
void managerMenu(Identity* &manager)//ָ�������ô��ݣ���ֹ����һ����ָ��
{
	//����Ա�˵�
	manager->operMenu();
	
	Manager* man = (Manager*)manager;	//�Ѹ���ָ��ǿתΪ����
	int select = 0;
	cin >> select;
	if (select == 1)	//����˺�
	{
		cout << "����˺�" << endl;
		man->addPerson();
	}
	else if (select == 2)	//�鿴�˺�
	{
		cout << "�鿴�˺�" << endl;
		man->showPerson();
	}
	else if (select == 3)	//�鿴������Ϣ
	{
		cout << "�鿴������Ϣ" << endl;
		man->showComputer();
	}
	else if (select == 4)	//���ԤԼ��¼
	{
		cout << "���ԤԼ��¼" << endl;
		man->cleanFile();
	}
	else //ע����¼
	{
		delete manager; //���ٵ������Ķ���
		manager = NULL;
		cout << "ע���ɹ�" << endl;
		system("pause");
		system("cls");
		return;

	}

}
//ѧ������ ѡ�����
void studentMenu(Identity*& student)
{
	while (true)
	{
		//ѧ���˵�
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)	//����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2)	//�鿴�ҵ�ԤԼ
		{
			stu->showOrder();
		}
		else if (select == 3)	//�鿴����ԤԼ
		{
			stu->shoeAllOrder();
		}
		else if (select == 4)	//ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete student; //���ٵ������Ķ���
			student = NULL;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//��ʦ�˵� ѡ�����
void teacherMenu(Identity*& teacher)
{
	
	while (true)
	{
		//��ʦ�˵�
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select;
		cin >> select;
		if (select == 1)	
		{
			//�鿴����ԤԼ
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validOrder();
		}
		else
		{
			delete teacher; //���ٵ������Ķ���
			teacher = NULL;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
		

	}
}
int main()
{
	int select = 0;//���ڽ����û���ѡ��
	while (true)
	{
		cout << "======================  ��ӭ�����ͻ���ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		//system("pause");
		cin >> select;	//�����û���ѡ��
		switch (select)
		{
		case 1:	//ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:	//��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:	//����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:	//�˳�ϵͳ
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			break;
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	return 0;
}