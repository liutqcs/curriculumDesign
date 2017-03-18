//文件名Stack.h
#ifndef QUEUE_H//避免重复包含Stack.h头文件
#define QUEUE_H
#include<iostream>
using namespace std;
const int StackSize=10;//栈最多有10个元素
template<class T>
class Stack
{
private:
	T data[StackSize];
	int top;
public:
	Stack();//构造函数，栈的初始化
	~Stack(){}//析构函数
	void Push(T x);//将元素X入栈
	T Pop();//将栈顶元素弹出
	T GetTop();//取栈顶元素（并不删除）
	int Empty();//判断栈是否为空
};
template<class T>
Stack<T>::Stack()
{
	top=-1;
}
template<class T>
void Stack<T>::Push(T x)
{
	if(top==StackSize-1)
		throw "上溢";
	top++;
	data[top]=x;
}
template<class T>
T Stack<T>::Pop()
{
	T x;
	if(top==-1)
		throw "下溢";
	x=data[top--];
	return x;
}
template<class T>
T Stack<T>::GetTop()
{
	if(top!=-1)
		return data[top];
}
template<class T>
int Stack<T>::Empty()
{
	if(top==-1) return 1;
	else return 0;
}
#endif;