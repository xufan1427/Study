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
		cout << "\t\t\t\t\t\t欢迎使用人事财务管理系统" << endl;
		cout << "\t\t\t员工数据为空！请选择进入人事财务管理系统或退出人事财务管理系统（输入选项前对应数字！）：" << endl;
		cout << "\t\t\t1:进入人事财务管理系统" << endl << "\t\t\t2:退出人事财务管理系统" << endl;
		cin >> flag;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cin >> flag;
		}
		if (flag == 1) {
			ManagePerson( m );
			cout << "1:进入人事财务系统" << endl << "2:退出人事财务管理系统" << endl;
		}
		else if (flag == 2) {
			cout << "人事财务管理系统已退出！" << endl;
			return ;
		}
		else {
			cout << "输入格式错误,请重新输入，输入对应数字进行选择！" << endl;
			cout << "1:进入人事财务管理系统" << endl << "2:退出人事财务管理系统" << endl;
		}
	}
}
int main()
{
	fms();
	system("pause");
	return 0;
}