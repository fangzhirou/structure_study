#include "List.h"
#include<stdio.h>
#include<stdlib.h>
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
//链表的基本操作
typedef struct Node *PtrNode;
//给结点重命名
typedef PtrNode List;
typedef PtrNode Position;
struct Node{
    //数据域
    int data;
    //指针域
    Position Next;
};

//头插法建立单链表

void createlist(Position p, int a[], int n)
{
	Node *s;
	int i;
	p = (Node*)malloc(sizeof(Node));
	p ->Next = NULL;
	for(i=0;i<n;++i)
	{
		s = (Node*)malloc(sizeof(Node));
		s ->data = a[i];
		//下面两句为头插法的关键步骤
		s ->Next = p ->Next;	//s所指新结点的指针域next指向L中的开始结点
		p ->Next = s;			//头结点的指针域next指向s结点，使得s成为新的开始结点

	}
 }

int IsEmpty(List l)
{
    return l->Next==NULL;
}
//当p为尾节点时
int IsLast(Position p,List l)
{
    return p->Next==NULL;
}
//返回某个元素在表中的位置.l是链表表头
Position Find(int x,List l)
{
    Position p;
    p=l->Next;
    while(p!=NULL&&p->data!=x)
        p=p->Next;
    return p;
}
Position FindPrevious(int x,List l)
{
    Position p;
    //p为表头
    p=l;
    //p一直后移，直到p的后继结点的元素为x
    while(p->Next!=NULL&&p->Next->data!=x)
        p=p->Next;
    return p;
}
void Delete(int x,List l)
{
    Position p,t;
    //p是要删除的节点的前驱元
    p=FindPrevious(x,l);
    //要删除的节点不是尾节点
    if (t->Next!=NULL)
    {
        //令t为要删除的节点
        t=p->Next;
        //t的后继元就是p的后继元，t摘链
        p->Next=t->Next;
        //删除t,t指向的地址不变，但数据已经无定义
        free(t);
    }
}
//把节点插入到p的后面
void Insert(int x,List l,Position p)
{
    Position t;
    t=(Node*)malloc(sizeof(struct Node));//是c中给指针动态分配内存空间的函数，size为分配的空间大小
    if(t==NULL)
    //抛出错误函数FatalError
        FatalError("Out of Space");
    //给t赋值x
    t->data=x;
    //让t后继是原来p的后继
    t->Next=p->Next;
    //让p的后继变成t
    p->Next=t;

}
void DeleteList(List l)
{
    Position p,t;
    //p是表头的后继元
    p=l->Next;
    //把表头的后继置空，令表与后面断链成为空表
    l->Next=NULL;
    //表本身不为空时
    while(p!=NULL)
    {
        //用t表示p的后继
        t=p->Next;
        //把p删除，所指数据无定义
        free(p);
        //p指向原来的后继，但此时已不是表内
        p=t;
    }
}
//打印链表数据
 void printfList(Position p)
 {
 	Node *t=p;
	int count = 0;
	printf("表中的元素为:\n");
	while(t->Next)
	{
		t = t->Next;
		printf("%d\t",t->data);
		count++;
		if(count%5==0)
		{
			printf("\n");
		}
	}
	printf("\n");

 }

int main()
{
    Position p;
    int n;
    printf("请输入数组的个数：");
 	scanf("%d",&n);
 	int a[n];
 	printf("请输入数组中的数(用空格分开)：\n");
 	for(int i=0;i<n;++i)
 	{
 		scanf("%d",&a[i]);
	}
	//测试头插法建立链表
	createlist(p,a,n);
	//查看建立后的链表
	printfList(p);
	return 0;
}
