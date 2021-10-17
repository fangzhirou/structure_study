#ifndef HASHSEP_H
#define HASHSEP_H
#include <stdio.h>
#include <stdlib.h>
struct ListNode;
typedef struct ListNode *Position;

struct HashTb1;
typedef struct HashTbl *HashTable;
HashTable InitializeTable(int TableSize);//³õÊ¼»¯
void DestroyTable(HashTable H);
Position Find(int key,HashTable H);//²éÕÒ
int Retrieve(Position P);
void Insert(int Key, HashTable H);//²åÈë
int NextPrime( int N );
struct ListNode
{
	int Element;
	struct ListNode *Next;
};
typedef Position List;
struct HashTb1
{
	int TableSize;
	List *TheLists;
};
#endif // HASHSEP_H
