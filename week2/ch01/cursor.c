#include "cursor.h"
#include<stdlib.h>
#include<stdio.h>
#define SpaceSize 100
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
typedef int PtrNode;
typedef PtrNode List;
typedef PtrNode Position;
struct  Node
{
	int Element;
	Position Next;
};

struct Node CursorSpace[SpaceSize];



static Position CursorAlloc() {//设链表头结点
	Position p;
	p = CursorSpace[0].Next;
	CursorSpace[0].Next = CursorSpace[p].Next;
	return p;
}

static void CursorFree(Position p) {//删除链表
	CursorSpace[p].Next = CursorSpace[0].Next;
	CursorSpace[0].Next=p;
}


void InitializeCursorSpace(void) {//初始化链表
	for (int i = 0; i < SpaceSize - 1; i++)
		CursorSpace[i].Next = i+1;
	CursorSpace[SpaceSize - 1].Next = 0;
}

List creatList() {//创建链表
	List L;
	L = CursorAlloc();
	if (L == 0)
		FatalError("Out of memory");
	CursorSpace[L].Next = 0;
	return L;
}
Position FindPrevious(int X, List L) {//查询前驱元
	Position P;
	P = L;
	while (CursorSpace[P].Next != 0 && CursorSpace[CursorSpace[P].Next].Element != X)
		P = CursorSpace[P].Next;
	return P;
}

void DeleteList(List L) {//删除链表
	Position p;
	p = CursorSpace[L].Next;
	CursorSpace[L].Next = 0;
	while (p != 0) {
		Position tmp;
		tmp = CursorSpace[p].Next;
		CursorFree(p);
		p = tmp;
	}
}

List MakeEmpty(List L) {//置空
	if (L != 0){
		DeleteList(L);
		CursorSpace[L].Next = 0;
		return L;
	}
	else {
		L = CursorAlloc();
		if (L == 0)
			FatalError("Out of memory");
		CursorSpace[L].Next = 0;
		return L;
	}
}

int IsEmpty(List L) {//测试链表是否为空
	return CursorSpace[L].Next == 0;
}

int IsLast(Position P, List L) {//测试p是否为链表末尾
	return CursorSpace[P].Next == 0;
}

Position Find(int X, List L) {//寻找元素值为x的节点，游标实现
	Position P;
	P = CursorSpace[L].Next;
	while (P != 0 &&CursorSpace[P].Element != X)
	{
		P = CursorSpace[P].Next;
	}
	return P;
}

void Delete(int X, List L) {//删除节点
	Position P;
	P = FindPrevious(X, L);
	if (!IsLast(P, L)) {
		Position TmpCell = CursorSpace[P].Next;//暂存要删的节点
		CursorSpace[P].Next = CursorSpace[TmpCell].Next;//摘链
		CursorFree(TmpCell);
	}
}
void Insert(int X, List L, Position P) {//插入节点
	Position tmpCell;
	tmpCell = CursorAlloc();
	if (tmpCell == 0)
		FatalError("Out of space!!");
	CursorSpace[tmpCell].Element = X;//给节点赋值
	CursorSpace[tmpCell].Next = CursorSpace[P].Next;//和p的下一个节点连上
	CursorSpace[P].Next = tmpCell;//和p连上
}

Position Header(List L) {
	return L;
}

Position First(List L) {
	return CursorSpace[L].Next;
}

Position Advance(Position P) {
	return CursorSpace[P].Next;
}

int Retrieve(Position P) {
	return CursorSpace[P].Element;
}

int main() {
	InitializeCursorSpace();
	List l = creatList();
	Insert(23333, l, l);
	printf("%d", Retrieve(First(l)));
}
