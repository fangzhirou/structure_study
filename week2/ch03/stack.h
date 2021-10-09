#ifndef STACK_H
#define STACK_H
struct StackRecord;
struct StackRecord
{
    int Capacity;
    int TopOfStack;
    int *Array;
};
typedef struct StackRecord *Stack;
Stack CreatStack(int MaxElements);
int IsEmpty(Stack S);//判断栈是否为空
void DisposeStack(Stack S);
void MakeEmpty(Stack S);//置空
void Push(Stack S, int data);//入栈
void Pop(Stack S);//出栈
int Top(Stack S);//返回栈顶元素
int TopAndPop(Stack S);
#endif // STACK_H
