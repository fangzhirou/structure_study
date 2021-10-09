#ifndef STACK_LIST_H
#define STACK_LIST_H

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode  Stack;
typedef int Element;

struct Node
{
	Element data;
	PtrToNode Next;
};

Stack CreatStack();//创造空栈，并且返回头指针

PtrToNode CreatNode(Element data);//创造结点

int IsEmpty(Stack S);//判断栈是否为空

void MakeEmpty(Stack S);//置空

void PrintStack(Stack  S);//打印栈

void Push(Stack S, Element data);//入栈

void Pop(Stack S);//出栈

Element Top(Stack S);//返回栈顶元素




#endif // !STACK_LIST_H

