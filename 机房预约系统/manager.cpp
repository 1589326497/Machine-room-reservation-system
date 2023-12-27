#include"manager.h"

//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	//初始化
	this->initVector();
}

//选择菜单界面
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1,添加学生" << endl;
	cout << "2,添加老师" << endl;
	string fileName;	//文件名
	string tip;			//操作提示
	ofstream ofs;

	int select = 0;
	cin >> select;

	string errorTip;//重复错误提示

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工编号重复，请重新输入";
	}

	ofs.open(fileName, ios::out | ios::app); //写文件以追加的方式

	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true)
	{
		cin >> id;
		//容器检测
		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			//没有重复跳出循环
			break;
		}
	}
	cout << "请输入名字：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	//将数据写到文件
	ofs << endl;
	ofs << id << " " << name << " " << pwd << endl;
	//将数据加到容器中
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
	
	cout << "添加成功" << endl;

	system("pause");
	system("cls");
	
	ofs.close();
}

void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "编号：" << t.m_EmpId<< " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}
//查看账号
void Manager::showPerson()
{
	cout << "请选择要查看的内容" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有教师信息如下" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下" << endl;
	for (auto com : vCom)
	{
		cout << "机房编号：" << com.m_ComId << " 机房最大容量" << com.m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initVector()
{
	//读取学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//清空容器
	vStu.clear();
	vTea.clear();

	//学生容器初始化
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前的学生人数为：" << vStu.size() << endl;
	ifs.close();

	//教师容器初始化
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前的教师人数为：" << vTea.size() << endl;
	ifs.close();

	//获取机房信息
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}
//检查重复
bool Manager::checkRepeat(int id, int type)
{
	//检查学生
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