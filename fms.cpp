#include<iostream>
#include"FMS.h"
using namespace std;
void fms()
{
	map<int, Person> m;
	int flag = 0;
	while (1)
	{
		system("cls");
		cout << "\t\t\t\t\t\t��ӭʹ�����²������ϵͳ" << endl;
		cout << "\t\t\tԱ������Ϊ�գ���ѡ��������²������ϵͳ���˳����²������ϵͳ������ѡ��ǰ��Ӧ���֣�����" << endl;
		cout << "\t\t\t1:�������²������ϵͳ" << endl << "\t\t\t2:�˳����²������ϵͳ" << endl;
		cin >> flag;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cin >> flag;
		}
		if (flag == 1) {
			ManagePerson( m );
			cout << "1:�������²���ϵͳ" << endl << "2:�˳����²������ϵͳ" << endl;
		}
		else if (flag == 2) {
			cout << "���²������ϵͳ���˳���" << endl;
			return ;
		}
		else {
			cout << "�����ʽ����,���������룬�����Ӧ���ֽ���ѡ��" << endl;
			cout << "1:�������²������ϵͳ" << endl << "2:�˳����²������ϵͳ" << endl;
		}
	}
}
int main()
{
	fms();
	system("pause");
	return 0;
}