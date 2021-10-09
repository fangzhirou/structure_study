#include "stack.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
Stack CreateStack(int MaxElements)//创建
{
    Stack S;
    if(MaxElements<5)
        FatalError("Stack size is too small");
    S=(Stack)malloc(sizeof(struct StackRecord));
    if(S==NULL)
        FatalError("Out of space");

    S->Array=malloc(sizeof(int) *MaxElements);
    if(S->Array==NULL)
        FatalError("Out of space!!");
    S->Capacity=MaxElements;
    MakeEmpty(S);
    return S;
}

void DisposeStack(Stack S)//销毁
{
    if(S!=NULL)
    {
        free(S->Array);
        free(S);
    }
}

int IsEmpty(Stack S)//判空
{
    return S->TopOfStack==-1;
}

void MakeEmpty(Stack S)//置空
{
    S->TopOfStack=-1;
}
void Push(Stack S,int x)//入栈
{
    if(IsFull(S))
        FatalError("Full stack");
    else
        S->Array[++S->TopOfStack]=x;
}
int Top(Stack S)//返回栈顶
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack];
    FatalError("Empty stack");
    return 0;
}
void Pop(Stack S)//弹出元素
{
    if(IsEmpty(S))
        FatalError("Empty stack");
    else
        S->TopOfStack--;
}

int TopAndPop(Stack S)//给出栈顶并弹出
{
    if(!IsEmpty(S))
        return S->Array[S->TopOfStack--];
    FatalError(("Empty stack"));
    return 0;
}
int main()
{
	Stack S=CreatStack(10);//创建空栈

	for (int i = 0; i < 10; i++)
	{
		Push(S, i);//入栈
	}

	//PrintStack(S);//打印栈

	printf("栈顶元素：%d\n", Top(S));//打印栈顶元素
	for (int i = 0; i < 3; i++)
	{
		Pop(S);//出栈
	}

	//PrintStack(S);

	printf("栈顶元素：%d\n", TopAndPop(S));

	return 0;
}
