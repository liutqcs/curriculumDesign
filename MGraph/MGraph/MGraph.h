//文件名MGraph.h
//无向图实现递归、非递归遍历
//判断是否有回路																
#ifndef MGRAPH_H
#define MGRAPH_H
#include<iostream>
#include"Stack.h"
using namespace std;
const int MaxSize=10;//图的最大顶点数
template<class T>
class MGraph
{
private:
	T vertex[MaxSize];
	int arc[MaxSize][MaxSize];
	int vertexNum,arcNum;
public:
	MGraph(T a[],int n,int e);//邻接矩阵存储，建立具有n个顶点e条边的图
	~MGraph(){}//析构函数为空
	void DFSTraverse1(int v);//递归深度遍历
	void DFSTraverse0(int v);//非递归
	void BFSTraverse(int v);
};
template<class T>
MGraph<T>::MGraph(T a[],int n,int e)
{
	int i,j,k;
	vertexNum=n;
	arcNum=e;
	for(i=0;i<vertexNum;i++)//存储图的顶点信息
		vertex[i]=a[i];
	for(i=0;i<vertexNum;i++)//初始化图的邻接矩阵
		for(j=0;j<vertexNum;j++)
			arc[i][j]=0;
	for(k=0;k<arcNum;k++)//存储图的边信息
	{
		cout<<"请输入边的两个顶点的序号："<<endl;
		cin>>i>>j;
		arc[i][j]=1;
		arc[j][i]=1;
	}
}
template<class T>
void MGraph<T>::DFSTraverse1(int v)
{
	cout<<vertex[v];
	visited[v]=1;
	for(int j=0;j<vertexNum;j++)
		if(arc[v][j]==1 && visited[j]==0)
			DFSTraverse1(j);
}
template<class T>
void MGraph<T>::DFSTraverse0(int v)
{
	int S[MaxSize];
	int top=-1,j;
	cout<<vertex[v];
	visited[v]=1;
	S[++top]=v;//S.Push(v);
	while(top!=-1)
	{
		v=S[top];
		for(j=0;j<vertexNum;j++)
			if(arc[v][j]==1 && visited[j]==0)
			{
				cout<<vertex[j];
				visited[j]=1;
				S[++top]=j;//S.Push(j);
				break;
			}
		if(j==vertexNum) top--;
	}
}
template<class T>
void MGraph<T>::BFSTraverse(int v)
{
	int Q[MaxSize];//假设队列采用顺序存储且不会发生溢出
	int front=-1,rear=-1;//初始化队列
	cout<<vertex[v];//被访问顶点入队
	visited[v]=1;
	Q[++rear]=v;
	while(front!=rear)//当队列非空时
	{
		v=Q[++front];//将队头元素出队并送到v中
		for(int j=0;j<vertexNum;j++)
			if(arc[v][j]==1 && visited[j]==0)
			{
				cout<<vertex[j];
				visited[j]=1;
				Q[++rear]=j;
			}
	}
}
#endif