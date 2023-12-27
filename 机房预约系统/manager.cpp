#include"manager.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	//��ʼ��
	this->initVector();
}

//ѡ��˵�����
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1,���ѧ��" << endl;
	cout << "2,�����ʦ" << endl;
	string fileName;	//�ļ���
	string tip;			//������ʾ
	ofstream ofs;

	int select = 0;
	cin >> select;

	string errorTip;//�ظ�������ʾ

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ������ظ�������������";
	}

	ofs.open(fileName, ios::out | ios::app); //д�ļ���׷�ӵķ�ʽ

	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true)
	{
		cin >> id;
		//�������
		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			//û���ظ�����ѭ��
			break;
		}
	}
	cout << "���������֣�" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	//������д���ļ�
	ofs << endl;
	ofs << id << " " << name << " " << pwd << endl;
	//�����ݼӵ�������
	if (select == 1)
	{
		Student s;
		s.m_Id = id;
		s.m_Name = name;
		s.m_Pwd = pwd;
		this->vStu.push_back(s);
	}
	else
	{
		Teacher t;
		t.m_EmpId = id;
		t.m_Name = name;
		t.m_Pwd = pwd;
		this->vTea.push_back(t);

	}
	
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");
	
	ofs.close();
}

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "��ţ�" << t.m_EmpId<< " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}
//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��Ҫ�鿴������" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ����" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "���н�ʦ��Ϣ����" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ����" << endl;
	for (auto com : vCom)
	{
		cout << "������ţ�" << com.m_ComId << " �����������" << com.m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector()
{
	//��ȡѧ���ļ�����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//�������
	vStu.clear();
	vTea.clear();

	//ѧ��������ʼ��
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰ��ѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ʦ������ʼ��
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ�Ľ�ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();

	//��ȡ������Ϣ
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}
//����ظ�
bool Manager::checkRepeat(int id, int type)
{
	//���ѧ��
	if (type == 1)
	{
		for (auto stu : this->vStu)
		{
			if (id == stu.m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (auto tea : this->vTea)
		{
			if (id == tea.m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}