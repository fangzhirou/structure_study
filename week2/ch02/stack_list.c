#include "stack_list.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
//栈的链表实现

Stack CreatStack()//创造空栈，并且返回头指针
{
	Stack S = malloc(sizeof(struct Node));//申请内存
	if (S == NULL)
	{
		FatalError("out of space!!!");
		return NULL;
	}

	S->Next = NULL;

	return S;
}



int IsEmpty(Stack S)//判断栈是否为空
{
	return S->Next == NULL;
}


void MakeEmpty(Stack S)//置空
{
	if (S == NULL)
	{
		FatalError("Must use Creatstack first!!");
	}

	else
	{
		while (!IsEmpty(S))
			Pop(S);
	}
}
void PrintStack(Stack  S)//打印栈
{
	PtrToNode P = S->Next;
	while (P)
	{
		printf("%d  ", P->data);
		P = P->Next;
	}
	printf("\n");
}

void Push(Stack S, Element data)//入栈
{
    PtrToNode TmpCell;
    TmpCell= malloc(sizeof(struct Node));
	if (TmpCell == NULL)
	{
		FatalError("out of space!!!");
	}

	else

	{
		TmpCell->data = data;
		TmpCell->Next = S->Next;
		S->Next =TmpCell;
	}
}

void Pop(Stack S)//出栈
{
	PtrToNode P;
	if (IsEmpty(S))
	{
		FatalError("Empty stack");
	}

	else
	{
		P = S->Next;
		S->Next = S->Next->Next;
		free(P);
	}
}

Element Top(Stack S)//返回栈顶元素
{
	if (!IsEmpty(S))
	{
		return S->Next->data;
	}

	else
	{
		FatalError("Empty stack");
	}
	return 0;
}
int main()
{
	Stack S =CreatStack();//创建空栈

	for (int i = 0; i < 10; i++)
	{
		Push(S, i);//入栈
	}

	PrintStack(S);//打印栈

	printf("栈顶元素：%d\n", Top(S));//打印栈顶元素
	for (int i = 0; i < 3; i++)
	{
		Pop(S);//出栈
	}

	PrintStack(S);

	printf("栈顶元素：%d\n", Top(S));

	return 0;
}
