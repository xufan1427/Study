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
	cout << "Ա����ţ�" << mit->first 
		<< "\t\t������" << mit->second.m_name
		<< "\t\t����: " << mit->second.m_department
		<< "\t\tн��: " << mit->second.m_salary << endl;

}
void Modify(map<int, Person>& m,int place)
{
	while (1) 
{
		system("cls");
		cout << "\t\t\t��ѡ����Ҫ�޸ĵ�Ա����Ϣ��" << endl
			<< "\t\t\t1:����" << endl
			<< "\t\t\t2:����" << endl
			<< "\t\t\t3:н��" << endl
			<< "\t\t\t4:���" << endl
			<<"\t\t\t0:�˳��޸Ľ���" << endl;
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
				cout << "�������޸ĺ��������" << endl;
				cin >> name;
				(*mit).second.m_name = name;
				printOne(m, place);
				break;
		case 2:
				cout << "�������޸ĺ�Ĳ��ţ�" << endl;
				cin >> depart;
				(*mit).second.m_department = depart;
				printOne(m, place);
				break;
		case 3:
				cout << "�������޸ĺ��н�ʣ�" << endl;
				cin >> salary;
				(*mit).second.m_salary = salary;
				printOne(m, place);
				break;
		case 4:
				cout << "�������޸ĺ��Ա����ţ�" << endl;
				cin >> numb;
				if (m.find(numb) != m.end())
				{
					cout << "\t\t\t��Ա������Ѵ��ڣ����������룺" << endl;
					cin >> numb;
				}
				(*mit).second.m_number = numb;
				m.insert(make_pair(numb, Person((*mit).second)));
				mit=m.end();
				m.erase(place);
				printOne(m, numb);
				break;
		default:
			cout << "�����ʽ����" << endl;
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
		cout << "Ա�����ݿ�Ϊ�գ�" << endl;
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
	cout << "��ѡ���ѯ��ʽ��" << endl
		<< "1:Ա������" << endl
		<< "2:Ա�����" << endl;
	cin >> fflag;
	switch (fflag) {
	case 1:
		system("cls");
		cout << "����Ա��������ѯϵͳ��" << endl;
		cout << "������Ա��������" << endl;
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
					cout << "�Ƿ�ɾ����Ա����Ϣ��" << endl
						<< "0:ȷ��ɾ����" << endl
						<< "1:��ɾ��" << endl;
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
					cout << "�Ƿ��޸Ĵ�Ա����Ϣ��" << endl
						<< "0:ȷ���޸ģ�" << endl
						<< "1:���޸�" << endl;
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
			cout << "δ�ҵ����ϵ�Ա����" << endl;
		if (count && nop == 1)
		{
			m.erase(nopnumber);
			cout << "ɾ���ɹ�" << endl;
		}
		else if (count && nop == 2)
		{
			Modify(m, nopnumber);
			cout << "�޸ĳɹ�" << endl;
			system("pause");
		}
		break;
	case 2:
		cout << "��������Ҫ���ҵ�Ա����ţ�" << endl;
		int fnumber;
		cin >> fnumber;
		dit = m.find(fnumber);
		if (dit != m.end())
		{
			printOne(m, dit->first);
			system("pause");
			if (nop == 2)
			{
				cout << "�Ƿ�ȷ���޸Ĵ�Ա����Ϣ" << endl
					<< "1:���޸�" << endl
					<< "0:ȷ���޸�" << endl;
				int denumber = 1;
				cin >> denumber;
				if (!denumber)
				{
					Modify(m,fnumber);
					cout << "�޸ĳɹ�!" << endl;
					system("pause");
				}
			}
		}
		break;
	default:
		cout << "�����ʽ����" << endl;
	}

	
}
void DeletePerson(map<int, Person>& m)
{
	int deflag = 0;
	map<int, Person>::iterator mit = m.end();
	while (1) {
		system("cls");
		cout << "��ѡ��ɾ����ʽ��" << endl;
		cout << "1:Ա������" << endl
			<< "2:Ա�����" << endl
			<< "3:�˳�Ա��ɾ���ӳ���" << endl;
		cin >> deflag;
		if (deflag == 1) {
			FindPerson(m, 1);
		}
		else if (deflag == 2) {
			cout << "��������Ҫɾ����Ա����ţ�" << endl;
			int denumber = -1;
			cin >> denumber;
			mit = m.find(denumber);
			if (mit != m.end()) {
				printOne(m, mit->first);
				cout << "�Ƿ�ɾ����Ա����Ϣ��" << endl
					<< "0:ȷ��ɾ����" << endl
					<< "1:��ɾ��" << endl;
				int Deflag = 1;
				cin >> Deflag;
				if (!Deflag)
				{
					m.erase(mit->first);
					cout << "ɾ���ɹ���" << endl;
					system("pause");
				}
			}
		}
		else if (deflag == 3)
		{
			cout << "�ɹ��˳�Ա��ɾ���ӳ���" << endl;
			break;
		}
		else {
			cout << "�����ʽ����,���������룬�����Ӧ���ֽ���ѡ��" << endl;
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
		cout << "������Ա�������ֱ��,Ա����Ų���Ϊ0��" << endl;
		cin >> number;
		if (number == 0)
			return;
		mit = m.find(number);
		if (mit == m.end()) {
			cout << "������Ա����������" << endl;
			cin >> name;
			cout << "������Ա���Ĳ��ű�ţ�" << endl;
			cout << "1���з���" << endl;
			cout << "2�����ڲ�" << endl;
			cout << "3�����۲�" << endl;
			cin >> idepart;
			switch (idepart)
			{
			case 1:
				department="�з���";
				break;
			case 2:
				department = "���ڲ�";
				break;
			case 3:
				department = "���۲�";
				break;
			default:
				department = "��ʱ��";
			}
			cout << "������Ա����н�ʣ�" << endl;
			cin >> salary;
			m.insert(make_pair(number, Person(name, salary, department, number)));
			cout << "��ӳɹ���" << endl;
		}
		else {
			cout << "��Ա������Ѵ��ڣ����������룡" << endl;
			system("pause");
		}
		cout << "�Ƿ�������" << endl
			<< "0:�������" << endl
			<< "1:�������" << endl;
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
		cout << "\t\t\t����Ա�����ݹ�����ϵͳ��" << endl;
		cout << "\t\t\t������ѡ��ǰ�Ķ�Ӧ����" << endl;
		cout << "\t\t\t1:���Ա����Ϣ" << endl;
		cout << "\t\t\t2:ɾ��Ա����Ϣ" << endl;
		cout << "\t\t\t3:����Ա����Ϣ" << endl;
		cout << "\t\t\t4:�޸�Ա����Ϣ" << endl;
		cout << "\t\t\t5:��ʾ����Ա����Ϣ" << endl;
		cout << "\t\t\t6:�˳����²������ϵͳ" << endl;
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
			cout << "����Ա���޸Ľ��棡" << endl;
			FindPerson(m, 2);
			break;
		case 5: 
			PrintPerson(m);
			break;
		case 6: 
			return;
		default:
			cout << "�����ʽ����,���������룬�����Ӧ���ֽ���ѡ��" << endl;
		}
	}
}

