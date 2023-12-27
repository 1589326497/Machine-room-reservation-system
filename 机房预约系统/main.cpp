/*
	机房预约系统 练习项目 2023/5/1开始——2023/5/3完成
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
//登录
void LoginIn(string fileName, int type)
{
	//基类的指针
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);
	//文件检查
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)//学生登录
	{
		cout << "请输入您的学号" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;
	
	//登录验证
	if (type == 1)
	{
		//学生登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "学生验证登录成功！" << endl;
				//登录成功 按任意键进入系统
				system("pause");
				system("cls");
				//创建学生对象
				person = new Student(id, name, pwd);
				//进入学生菜单
				studentMenu(person);
				return;
			}
		}	
	}
	else if (type == 2)
	{
		//教师登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				//创建教师对象
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while ( ifs >> fName && ifs >> fPwd)
		{
			if ( name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager( name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "登录验证失败！" << endl;

	system("pause");
	system("cls");
	return;
}

//管理员菜单 控制
void managerMenu(Identity* &manager)//指针用引用传递，防止拷贝一个新指针
{
	//管理员菜单
	manager->operMenu();
	
	Manager* man = (Manager*)manager;	//把父类指针强转为子类
	int select = 0;
	cin >> select;
	if (select == 1)	//添加账号
	{
		cout << "添加账号" << endl;
		man->addPerson();
	}
	else if (select == 2)	//查看账号
	{
		cout << "查看账号" << endl;
		man->showPerson();
	}
	else if (select == 3)	//查看机房信息
	{
		cout << "查看机房信息" << endl;
		man->showComputer();
	}
	else if (select == 4)	//清空预约记录
	{
		cout << "清空预约记录" << endl;
		man->cleanFile();
	}
	else //注销登录
	{
		delete manager; //销毁掉堆区的对象
		manager = NULL;
		cout << "注销成功" << endl;
		system("pause");
		system("cls");
		return;

	}

}
//学生对象 选择控制
void studentMenu(Identity*& student)
{
	while (true)
	{
		//学生菜单
		student->operMenu();

		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		if (select == 1)	//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)	//查看我的预约
		{
			stu->showOrder();
		}
		else if (select == 3)	//查看所有预约
		{
			stu->shoeAllOrder();
		}
		else if (select == 4)	//取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete student; //销毁掉堆区的对象
			student = NULL;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//教师菜单 选择控制
void teacherMenu(Identity*& teacher)
{
	
	while (true)
	{
		//教师菜单
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select;
		cin >> select;
		if (select == 1)	
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			delete teacher; //销毁掉堆区的对象
			teacher = NULL;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
		

	}
}
int main()
{
	int select = 0;//用于接收用户的选择
	while (true)
	{
		cout << "======================  欢迎来到客机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		//system("pause");
		cin >> select;	//接收用户的选择
		switch (select)
		{
		case 1:	//学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:	//老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:	//管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:	//退出系统
			cout << "欢迎下次使用" << endl;
			system("pause");
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	return 0;
}