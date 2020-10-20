#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
struct student
{
	string name;
	float score;
	struct student *next;
};
int main()
{
	int choose;
	std *headnode=NULL;
	//node=malloc()
	student std1;
	std1=(struct student*)malloc(sizeof(struct student));
	std1.next=headnode;
	headnode=std1;
	cin>>std1.name;
	cin>>std1.score;
	//cout<<std1.name<<endl;
	//cout<<std1.score<<endl;
choose:	cout<<"添加或者删减结点请输入1；查找请输入2!"<<endl;
	cin>>choose;
	if(choose==1)
	{
		cout<<"输入增加的节点数！"
		int num=0;
		cin>>num;
	/*	for(int i=0;i<num;i++)
		{
			student std
		}
	*/
	}
	else if(choose==2)
	{
	cout<<"haha"<<endl;
	}
	else
	{	
		cout<<"ERR：输入错误，请选择继续输入或者退出：1 继续输入；输入其他退出"<<endl;
		int choose1;
		cin<<choose1;
		if(choose1==1)
			goto choose;
		else
			return 0
	}

		return 0;
}
