//文件名Queue.h
#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;
//以下定义链队列的结点
template<class T>
struct Node
{
	T data;
	Node<T> *next;
};
//以下是链队列类Queue的声明
template<class T>
class Queue
{
private:
	Node<T> *front,*rear;//队头和队尾指针
public:
	Queue();//构造函数，初始化一个空的链队列
	~Queue();//析构函数，释放链队列中各结点的存储空间
	void EnQueue(T x);//将元素X入队
	T DeQueue();//将队头元素出队
	T GetQueue();//取链队列的队头元素
	int Empty();//判断链队列是否为空
};
template<class T>
Queue<T>::Queue()
{
	Node<T> *s=NULL;
	s=new Node<T>;
	s->next=NULL;
	front=rear=s;
}
template<class T> 
Queue<T>::~Queue()
{
	Node<T> *p=NULL:
	while(front!=NULL)
	{
		p=front->next;
		delete front;
		front=p;
	}
}
template<class T>
void Queue<T>::EnQueue(T x)
{
	Node<T> *s=NULL;
	s=new Node<T>;
	s->data=x;//申请一个数据域为X的结点S 
	s->next=NULL;
	rear->next=s;
	rear=s;//将结点S插入到队尾
}
template<class T>
T Queue<T>::DeQueue()
{
	Node<T> *p=NULL;
	int x;
	if(rear==front) throw"上溢";
	p=front->next;
	x=p->data;//暂存队头元素
	front->next=p->next;//将队头元素所在结点摘链
	if(p->next==NULL) rear=front;// 判断出队前队列长度是否为1
	delete p;
	return x;
}
template<class T>
T Queue<T>::GetQueue()
{
	if(front!=rear)
		return front->next->data;
}
template<class T>
int Queue<T>::Empty()
{
	if(front==rear)
		return 1;
	else
		return 0;
}
#endif;