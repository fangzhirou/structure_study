#include "hashsep.h"
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
//分离链接散列表
#define MinTableSize 10

int NextPrime( int N )
{

	if( N % 2 == 0 )
		N++;
	return N;
}
int Hash(int key, int TableSize)
{
	return key % TableSize;
}
HashTable InitializeTable(int TableSize)//初始化分离链接散列表
{
	HashTable H;
	int i;

	if (TableSize < MinTableSize)
	{
		FatalError("Table size is too small.\n");
		return NULL;
	}

	//给散列表结构分配内存
	H = malloc(sizeof(struct HashTb1));
	if (H == NULL)
	{
		FatalError("out of space!!!");
	}
	//H->TableSize= NextPrime(TableSize);

	//指定List的一个数组
	H->TheLists =malloc(sizeof(List) * H->TableSize);
	if (H->TheLists == NULL)
	{
		FatalError("out of space!!!\n");
	}

	//给每个表分配表头
	for (i = 0; i < H->TableSize; i++)
	{
		H->TheLists[i] =malloc(sizeof(struct ListNode));
		if (H->TheLists[i] == NULL)
		{
			FatalError("out of space!!!\n");
		}
		else
		{
			H->TheLists[i]->Next = NULL;
		}
	}
	return H;

}

Position Find(int key, HashTable H)//返回一个指向包含key的单元的指针
{
	Position P;
	List L;

	L = H->TheLists[Hash(key, H->TableSize)];
	P = L->Next;
	while (P != NULL && P->Element != key)
	{
		P = P->Next;
	}

	return P;
}

void Insert(int Key, HashTable H)//插入key到散列表中
{
	Position Pos, NewCell;
	List L;

	Pos = Find(Key, H);
	if (Pos == NULL)
	{
		NewCell = (Position)malloc(sizeof(struct ListNode));
		if (NewCell == NULL)
		{
			FatalError("out of space!!!\n");
		}
		else
		{
			L = H->TheLists[(Hash(Key, H->TableSize))];
			NewCell->Next = L->Next;
			NewCell->Element = Key;
			L->Next = NewCell;
		}
	}
}


void PrintHash(HashTable H)
{
	List L1,L2;
	int i;
	for (i = 0; i< H->TableSize; i++)
	{
		L1 = H->TheLists[i]->Next;
		L2 = L1;
		while (L2 != NULL)
		{
			if (L2->Next != NULL)
			{
				printf("%d, ", L2->Element);
			}
			else
			{
				printf("%d ", L2->Element);
			}

			L2 = L2->Next;
		}
		printf("\n");
	}

}
int main()
{
    HashTable Hash;
	Hash = InitializeTable(11);

	Insert(5, Hash);
	Insert(6, Hash);
	Insert(7, Hash);
	Insert(8, Hash);
	Insert(9, Hash);
	Insert(10, Hash);
	Insert(11, Hash);
	Insert(12, Hash);
	Insert(16, Hash);
	PrintHash(Hash);

}
