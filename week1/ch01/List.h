#ifndef LIST_H
#define LIST_H
//声明List,Position
struct Node;
typedef struct Node *PtrNode;
//给结点重命名
typedef PtrNode List;
typedef PtrNode Position;
//让链表为空
List MakeEmpty(List l);
//测试链表是否为空
int IsEmpty(List &l);
//测试该节点是否为尾节点
int IsLast(Position p,List &l);
//查找存放元素x的节点
Position Find(int x,List l);
//删除节点
void Delete(int x,List l);
//查找前驱元
Position FindPrevious(int x,List l);
//插入节点
void Insert(int x,List &l,Position p);
//输出链表
void printfList(Position p);
//创建链表
void createlist(Position p, int a[], int n);
#endif // LIST_H
