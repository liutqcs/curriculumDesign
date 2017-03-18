//文件名MaunTest.cpp
#include"ALGraph.h"
#include"MGraph.h"
#include<iostream>
using namespace std;
int visited[MaxSize]={0};
int mainMG();//无向图菜单显示声明，及功能的调用（界面已足够友好）
int mainALG();//有向图菜单显示声明，及功能的调用
int menu()//图的遍历的菜单
{
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------图的遍历--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------0.退  出--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------1.无向图--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------2.有向图--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------3.菜  单--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	int n;
	cout<<"请输入服务选项(0-3)："<<endl;
	cin>>n;
	char ch;
	switch(n)
	{
	case 0:break;
	case 1:
		{
			mainMG();
			cout<<"是否返回/退出？(Y/N)"<<endl;
			cin>>ch;
			if(ch=='Y' || ch=='y')
				menu();
			else
				break;
		}break;
	case 2:
		{
			mainALG();
			cout<<"是否返回/退出？(Y/N)"<<endl;
			cin>>ch;
			if(ch=='Y' || ch=='y')
				menu();
			else
				break;
		}break;
	case 3:menu();break;
	}
	return 0;
}
int menuM()
{
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------*无向图*--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------0.非递归--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------1.递  归--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------2.退  出--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------3.菜  单--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	return 0;
}
int menuA()
{
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------*有向图*--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------0.非递归--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------1.递  归--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------2.退  出--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	cout<<"|--------------------------3.菜  单--------------------------|"<<endl;
	cout<<"|------------------------------------------------------------|"<<endl;
	return 0;
}
int mainMG()
{
	int m,n,i=0;
	cout<<"请输入结点个数：（节点个数不得大于10）"<<endl;
	cin>>m;
	cout<<"请输入结点信息（即结点值,以#结尾）"<<endl;
	char a,b[10];
	cin>>a;
	while(a!='#')
	{
		b[i]=a;
		i++;
		cin>>a;
	}
	cout<<"请输入边的条数："<<endl;
	cin>>n;
	MGraph<char> MG(b,m,n);
	menuM();
	int t;
	cout<<"请输入服务选项(0-3)："<<endl;
	cin>>t;
	switch(t)
	{
	case 0:
		{
			for(int i=0;i<MaxSize;i++)
			visited[i]=0;
			cout<<"非递归深度优先遍历序列是："<<endl;
			MG.DFSTraverse0(0);
			cout<<endl;
			for(int i=0;i<MaxSize;i++)
			visited[i]=0;
			cout<<"广度优先遍历序列是："<<endl;
			MG.BFSTraverse(0);
			cout<<endl;
		}break;
	case 1:
		{
			for(int i=0;i<MaxSize;i++)
				visited[i]=0;
			cout<<"递归深度优先遍历序列是："<<endl;
			MG.DFSTraverse1(0);
			cout<<endl;
			for(int i=0;i<MaxSize;i++)
			visited[i]=0;
			cout<<"广度优先遍历序列是："<<endl;
			MG.BFSTraverse(0);
			cout<<endl;
		}break;
	case 2:break;
	case 3:menuM();break;
	}
	return 0;
}
int mainALG()
{
	int m,n,i=0;
	cout<<"请输入结点个数：（节点个数不得大于10）"<<endl;
	cin>>m;
	cout<<"请输入结点信息（即结点值,以#结尾）"<<endl;
	char a,b[10];
	cin>>a;
	while(a!='#')
	{
		b[i]=a;
		i++;
		cin>>a;
	}
	cout<<"请输入边的条数："<<endl;
	cin>>n;
	ALGraph<char> ALG(b,m,n);
	menuA();
	int t;
	cout<<"请输入服务选项(0-3)："<<endl;
	cin>>t;
	switch(t)
	{
	case 0:
		{
			for(int i=0;i<MaxSize;i++)
			visited[i]=0;
			cout<<"非递归深度优先遍历序列是："<<endl;
			ALG.DFSTraverse0(0);
			cout<<endl;
			for(int i=0;i<MaxSize;i++)
			visited[i]=0;
			cout<<"广度优先遍历序列是："<<endl;
			ALG.BFSTraverse(0);
			cout<<endl;
			int c;
			cout<<"请输入查询入度与出度的点的序列："<<endl;
			cin>>c;
			cout<<"入度为："<<ALG.GetVertex(c).InDegree<<endl;
			cout<<"出度为："<<ALG.GetVertex(c).OutDegree<<endl;
			ALG.TopSort(ALG);
			//ALG.Link(ALG);
		}break;
	case 1:
		{
			for(int i=0;i<MaxSize;i++)
				visited[i]=0;
			cout<<"递归深度优先遍历序列是："<<endl;
			ALG.DFSTraverse1(0);
			cout<<endl;
			for(int i=0;i<MaxSize;i++)
			visited[i]=0;
			cout<<"广度优先遍历序列是："<<endl;
			ALG.BFSTraverse(0);
			cout<<endl;
			int c;
			cout<<"请输入查询入度与出度的点的序列："<<endl;
			cin>>c;
			cout<<"入度为："<<ALG.GetVertex(c).InDegree<<endl;
			cout<<"出度为："<<ALG.GetVertex(c).OutDegree<<endl;
			ALG.TopSort(ALG);
			//ALG.Link(ALG);
		}break;
	case 2:break;
	case 3:menuA();break;
	}
	return 0;
}
void main()
{
	menu();
}