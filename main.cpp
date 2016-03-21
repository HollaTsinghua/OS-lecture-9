/*
	工作集页置换算法
	input格式：
	T N 分别为窗口大小和总页数
	e1 t1 e2 t2 ... en tn 分别表示每个页是否存在及初始时间
	n1 n2 ... 为每次访问的页编号，不能超过100，-1表示停止 
*/

#include <iostream>
#include <cstring>
#include <fstream> 
using namespace std;

struct member
{
	int access_time;
	bool if_exist;
}members[100];

int main()
{
	ifstream fin;
	fin.open("input.txt");
	memset(members,0,sizeof(members));
	
	int time = 0;
	int T;
	fin>>T;//窗口大小 
	int N;
	fin>>N;//总页数 

	//页初始化 
	for (int i = 0; i < N; i++)
	{
		fin>>members[i].if_exist;
		fin>>members[i].access_time;
	}

	int visit_num;
	while (1)
	{
		cout<<"exist pages(time):";
		for (int i = 0; i < N; i++)
			if (members[i].if_exist) cout<<i<<'('<<members[i].access_time<<')'<<' ';
		cout<<endl;
		fin>>visit_num;
		if (visit_num == -1)
		{
			cout<<"quit"<<endl;
			break;
		}
		cout<<"visit:"<<visit_num<<endl;
		if (members[visit_num].if_exist) cout<<"Hit!"<<endl;
		else cout<<"Miss! Add to pages."<<endl; 
		time++;
		members[visit_num].access_time = time;
		members[visit_num].if_exist = 1;
		for (int i = 0; i < N; i++)
		{
			if (time - members[i].access_time >= T)
			{
				members[i].if_exist = 0;
			}
		}
	}
	fin.close();
	return 0;
}
