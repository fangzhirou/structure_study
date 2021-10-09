#ifndef CURSOR_H
#define CURSOR_H
#define SpaceSize 100
typedef int PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void InitializeCursorSpace(void);

List creatList();
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(int X, List L);
void Delete(int X, List L);
Position FindPrevious(int X, List L);
void Insert(int X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
struct  Node
{
	int Element;
	Position Next;
};

struct Node CursorSpace[SpaceSize];

#endif // CURSOR_H
