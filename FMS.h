#pragma once
#include<iostream>
#include<string>
#include<map>
using namespace std;
class Person {
public:
	Person(string name,int salary,string department,int number)
	{
		this->m_name = name;
		this->m_salary = salary;
		this->m_department = department;
		this->m_number = number;
	}
	string m_name;
	int m_salary;
	string m_department;
	int m_number;
};
void printOne(map<int, Person> m, int place)
{
	map<int, Person>::iterator mit = m.find(place);
	cout << "员工编号：" << mit->first 
		<< "\t\t姓名：" << mit->second.m_name
		<< "\t\t部门: " << mit->second.m_department
		<< "\t\t薪资: " << mit->second.m_salary << endl;

}
void Modify(map<int, Person>& m,int place)
{
	while (1) 
{
		system("cls");
		cout << "\t\t\t请选择需要修改的员工信息：" << endl
			<< "\t\t\t1:姓名" << endl
			<< "\t\t\t2:部门" << endl
			<< "\t\t\t3:薪资" << endl
			<< "\t\t\t4:编号" << endl
			<<"\t\t\t0:退出修改界面" << endl;
		map<int, Person>::iterator mit = m.find(place);
		int mflag;
		cin>>mflag;
		string name;
		int depart;
		int salary;
		int numb;
		switch (mflag) {
		case 0:
			return ;
		case 1:
				cout << "请输入修改后的姓名：" << endl;
				cin >> name;
				(*mit).second.m_name = name;
				printOne(m, place);
				break;
		case 2:
				cout << "请输入修改后的部门：" << endl;
				cin >> depart;
				(*mit).second.m_department = depart;
				printOne(m, place);
				break;
		case 3:
				cout << "请输入修改后的薪资：" << endl;
				cin >> salary;
				(*mit).second.m_salary = salary;
				printOne(m, place);
				break;
		case 4:
				cout << "请输入修改后的员工编号：" << endl;
				cin >> numb;
				if (m.find(numb) != m.end())
				{
					cout << "\t\t\t该员工编号已存在，请重新输入：" << endl;
					cin >> numb;
				}
				(*mit).second.m_number = numb;
				m.insert(make_pair(numb, Person((*mit).second)));
				mit=m.end();
				m.erase(place);
				printOne(m, numb);
				break;
		default:
			cout << "输入格式错误" << endl;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cin >> mflag;
			}
		}
		system("pause");
	}
}
void PrintPerson(map<int,Person> m)
{
	if (m.empty())
	{
		cout << "员工数据库为空！" << endl;
	}
	else
	{
		for (map<int, Person>::iterator mit = m.begin(); mit != m.end(); mit++)
		{
			printOne(m, mit->first);
		}
	}
	system("pause");
}
void FindPerson(map<int,Person> &m,int nop)
{
	int fflag;
	int count = 0;
	string name;
	int nopnumber;
	map<int, Person>::iterator dit = m.begin();
	cout << "请选择查询方式：" << endl
		<< "1:员工姓名" << endl
		<< "2:员工编号" << endl;
	cin >> fflag;
	switch (fflag) {
	case 1:
		system("cls");
		cout << "进入员工姓名查询系统！" << endl;
		cout << "请输入员工姓名：" << endl;
		cin >> name;
		for (map<int, Person>::iterator mit = m.begin(); mit != m.end(); mit++)
		{
			if ((*mit).second.m_name == name)
			{
				printOne(m, mit->first);
				system("pause");
				count++;
				if (nop == 1)
				{
					cout << "是否删除此员工信息？" << endl
						<< "0:确认删除！" << endl
						<< "1:不删除" << endl;
					int denumber = 1;
					cin >> denumber;
					if (!denumber)
					{
						nopnumber = mit->first;
						break;
					}
				}
				else if (nop == 2)
				{
					cout << "是否修改此员工信息？" << endl
						<< "0:确认修改！" << endl
						<< "1:不修改" << endl;
					int denumber = 1;
					cin >> denumber;
					if (!denumber)
					{
						nopnumber = mit->first;
						break;
					}
				}
			}
		}
		if (!count)
			cout << "未找到符合的员工！" << endl;
		if (count && nop == 1)
		{
			m.erase(nopnumber);
			cout << "删除成功" << endl;
		}
		else if (count && nop == 2)
		{
			Modify(m, nopnumber);
			cout << "修改成功" << endl;
			system("pause");
		}
		break;
	case 2:
		cout << "请输入需要查找的员工编号：" << endl;
		int fnumber;
		cin >> fnumber;
		dit = m.find(fnumber);
		if (dit != m.end())
		{
			printOne(m, dit->first);
			system("pause");
			if (nop == 2)
			{
				cout << "是否确认修改此员工信息" << endl
					<< "1:不修改" << endl
					<< "0:确认修改" << endl;
				int denumber = 1;
				cin >> denumber;
				if (!denumber)
				{
					Modify(m,fnumber);
					cout << "修改成功!" << endl;
					system("pause");
				}
			}
		}
		break;
	default:
		cout << "输入格式错误" << endl;
	}

	
}
void DeletePerson(map<int, Person>& m)
{
	int deflag = 0;
	map<int, Person>::iterator mit = m.end();
	while (1) {
		system("cls");
		cout << "请选择删除方式：" << endl;
		cout << "1:员工姓名" << endl
			<< "2:员工编号" << endl
			<< "3:退出员工删除子程序" << endl;
		cin >> deflag;
		if (deflag == 1) {
			FindPerson(m, 1);
		}
		else if (deflag == 2) {
			cout << "请输入需要删除的员工编号：" << endl;
			int denumber = -1;
			cin >> denumber;
			mit = m.find(denumber);
			if (mit != m.end()) {
				printOne(m, mit->first);
				cout << "是否删除此员工信息？" << endl
					<< "0:确认删除！" << endl
					<< "1:不删除" << endl;
				int Deflag = 1;
				cin >> Deflag;
				if (!Deflag)
				{
					m.erase(mit->first);
					cout << "删除成功！" << endl;
					system("pause");
				}
			}
		}
		else if (deflag == 3)
		{
			cout << "成功退出员工删除子程序！" << endl;
			break;
		}
		else {
			cout << "输入格式错误,请重新输入，输入对应数字进行选择！" << endl;
			system("cls");
		}
	}
}
void AddPerson(map<int,Person> &m)
{
	string name;
	string department;
	int idepart;
	int salary;
	int number;
	int flag = 1;
	map<int, Person>::iterator mit = m.begin();
	while ( 1 ) 
	{
		system("cls");
		cout << "请输入员工纯数字编号,员工编号不能为0：" << endl;
		cin >> number;
		if (number == 0)
			return;
		mit = m.find(number);
		if (mit == m.end()) {
			cout << "请输入员工的姓名：" << endl;
			cin >> name;
			cout << "请输入员工的部门编号：" << endl;
			cout << "1：研发部" << endl;
			cout << "2：后勤部" << endl;
			cout << "3：销售部" << endl;
			cin >> idepart;
			switch (idepart)
			{
			case 1:
				department="研发部";
				break;
			case 2:
				department = "后勤部";
				break;
			case 3:
				department = "销售部";
				break;
			default:
				department = "临时工";
			}
			cout << "请输入员工的薪资：" << endl;
			cin >> salary;
			m.insert(make_pair(number, Person(name, salary, department, number)));
			cout << "添加成功！" << endl;
		}
		else {
			cout << "该员工编号已存在，请重新输入！" << endl;
			system("pause");
		}
		cout << "是否继续添加" << endl
			<< "0:继续添加" << endl
			<< "1:结束添加" << endl;
		cin >> flag;
		if (flag)
		{
			break;
		}
	}
}
void ManagePerson(map<int,Person> &m)
{
	map<int, Person>::iterator mit=m.end();
	int flag = 0;
	while (1)
	{
		system("cls");
		cout << "\t\t\t进入员工数据管理子系统！" << endl;
		cout << "\t\t\t请输入选项前的对应数字" << endl;
		cout << "\t\t\t1:添加员工信息" << endl;
		cout << "\t\t\t2:删除员工信息" << endl;
		cout << "\t\t\t3:查找员工信息" << endl;
		cout << "\t\t\t4:修改员工信息" << endl;
		cout << "\t\t\t5:显示所有员工信息" << endl;
		cout << "\t\t\t6:退出人事财务管理系统" << endl;
		cin >> flag;
		switch (flag)
		{
		case 1:
			AddPerson(m);
			break;
		case 2:
			DeletePerson(m);
			break;
		case 3: 
			FindPerson(m,0);
			break;
		case 4:
			cout << "进入员工修改界面！" << endl;
			FindPerson(m, 2);
			break;
		case 5: 
			PrintPerson(m);
			break;
		case 6: 
			return;
		default:
			cout << "输入格式错误,请重新输入，输入对应数字进行选择！" << endl;
		}
	}
}

