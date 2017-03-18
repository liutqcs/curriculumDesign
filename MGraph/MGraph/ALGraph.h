//文件名ALGraph.h
#ifndef ALGRAPH_H//有向图
#define ALGRAPH_H
#include<iostream>
#include"Queue.h"
using namespace std;
const int A_MaxSize=10;
//以下定义边表结点和顶点表结点
//以下定义边表结点
struct ArcNode
{
	int adjvex;//邻接点域
	ArcNode * next;
};
//定义顶点表结点
template<class T>
struct VertexNode
{
	T vertex;
	int InDegree,OutDegree;
	ArcNode *firstedge;
};
//以下为ALGraph的声明
template<class T>
class ALGraph
{
private:
	VertexNode<T> adjlist[A_MaxSize];
	int vertexNum,arcNum;
public:
	ALGraph(T a[],int n,int e);//有向图构造函数，用邻接表存储
	~ALGraph();//析构函数
	VertexNode<T> GetVertex(int n){return adjlist[n];}//获取顶点结点信息
	void DFSTraverse1(int v);//递归深度遍历图
	void DFSTraverse0(int v);//非递归深度遍历图
	void BFSTraverse(int v);//广度遍历图
	void TopSort(ALGraph<T> &G);//拓扑排序，判断有无回路
	//void Link(ALGraph<T> &G);
};
template<class T>
ALGraph<T>::ALGraph(T a[],int n,int e)
{
	ArcNode *s;
	int i,j,k;
	vertexNum=n;
	arcNum=e;
	for(i=0;i<vertexNum;i++)//存储顶点信息，初始化顶点表
	{
		adjlist[i].vertex=a[i];
		adjlist[i].firstedge=NULL;
		adjlist[i].InDegree=0;
		adjlist[i].OutDegree=0;
	}
	for(k=0;k<arcNum;k++)//依次输入每一条边
	{
	cout<<"请输入边的两个顶点的序号："<<endl;
	cin>>i>>j;//接收边所依附的两个顶点的编号
	s=new ArcNode;//生成一个边表结点S
	s->adjvex=j;
	s->next=adjlist[i].firstedge;//将结点S插入到第i个边表的表头
	adjlist[i].firstedge=s;
	adjlist[i].OutDegree++;
	adjlist[j].InDegree++;
	}
}
template<class T>
ALGraph<T>::~ALGraph()
{
	ArcNode *p=NULL;
	for(int i=0;i<vertexNum;i++)
	{
		p=adjlist[i].firstedge;
		while(p!=NULL)//删除第i个边表
		{
			adjlist[i].firstedge=p->next;
			delete p;//释放结点空间
			p=adjlist[i].firstedge;
		}
	}
}
template<class T>
void ALGraph<T>::DFSTraverse1(int v)//递归深度优先遍历图
{
	ArcNode *p=NULL;
	int j;
	cout<<adjlist[v].vertex;
	visited[v]=1;
	p=adjlist[v].firstedge;//工作指针p指向顶点v的边表
	while(p!=NULL)//依次搜索顶点v的邻接点j
	{
		j=p->adjvex;
		if(visited[j]==0)
			DFSTraverse1(j);
		p=p->next;
	}
}
template<class T>
void ALGraph<T>::DFSTraverse0(int v)
{
	int Q[MaxSize];
	int front,rear,j;
	front=rear=-1;
	cout<<adjlist[v].vertex;
	visited[v]=1;
	Q[++rear]=v;
	while(front!=rear)
	{
		v=Q[++front];
		ArcNode *p=adjlist[v].firstedge;
		while(p!=NULL)
		{
			j=p->adjvex;
			if(visited[j]==0)
			{
				cout<<adjlist[j].vertex;
				visited[j]=1;
				Q[++rear]=j;
			}
			p=p->next;
		}
	}
}
template<class T>
void ALGraph<T>::BFSTraverse(int v)
{
	int Q[MaxSize];//假设队列采用顺序存储
	int front=-1,rear=-1;//初始化队列
	ArcNode *p=NULL;
	cout<<adjlist[v].vertex;//被访问顶点入队
	visited[v]=1;
	Q[++rear]=v;
	while(front!=rear)//当队列非空时 
	{
		v=Q[++front];
		p=adjlist[v].firstedge;//工作指针p指向顶点v的边表
		while(p!=NULL)
		{
			int j=p->adjvex;//j是顶点v的邻接点
			if(visited[j]==0)
			{
				cout<<adjlist[j].vertex;
				visited[j]=1;
				Q[++rear]=j;
			}
			p=p->next;
		}
	}
}
template<class T>
void ALGraph<T>::TopSort(ALGraph<T> &G)
{
	ArcNode *p;
	int top=-1,count=0,i,j,S[MaxSize],k;
	for(i=0;i<G.vertexNum;i++)
	{
		if(G.adjlist[i].InDegree==0)
			S[++top]=i;
	}
	while(top!=-1)
	{
		j=S[top--];
		cout<<G.adjlist[j].vertex;
		count++;
		p=G.adjlist[j].firstedge;
		while(p!=NULL)
		{
			k=p->adjvex;
			G.adjlist[k].InDegree--;
			if(G.adjlist[k].InDegree==0)
				S[++top]=k;
			p=p->next;
		}
	}
	if(count<G.vertexNum) 
		cout<<"有回路！"<<endl;
	else
		cout<<"无回路！"<<endl;
}
//template<class T>
//void ALGraph<T>::Link(ALGraph<T> &G)
//{
//	int count=0;
//	for(int i=0;i<G.vertexNum;i++)
//	{
//	if(visited>1)cout<<"有回路"<<endl;
//	else if(visited<1)cout<<"不连通"<<endl;
//	else
//	cout<<"无回路且连通"<<endl;
//
//	}
//}
#endif