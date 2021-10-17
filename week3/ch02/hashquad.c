#include "hashquad.h"
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
#define MinTableSize 10
//开放定址散列表

int NextPrime(int TableSize)
{
	while(1)
	{
		if(isPrime(TableSize))
			return TableSize;
		else
			TableSize++;
	}
}

int isPrime(int x)
{
	int i;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}
int Hash(int key,int TableSize)
{
	return key%TableSize;
}
HashTable InitializeTable(int TableSize) {//初始化开放定址散列表
	HashTable H;
	int i;

	if (TableSize < MinTableSize)
	{
		FatalError("Table size is too small.\n");
		return NULL;
	}

	//给散列表结构分配内存
	H = malloc(sizeof(struct HashTbl));
	if (H == NULL)
	{
		FatalError("out of space!!!");
	}
	H->TableSize = NextPrime(TableSize);
	//指定Cells的一个数组
	H->TheCells=malloc(sizeof(Cell)*H->TableSize);
	if(H->TheCells==NULL)
        FatalError(("Out of space"));
    for(i=0;i<H->TableSize;i++)
        H->TheCells[i].Info=Empty;
    return H;

}
Position Find(int key,HashTable H)//返回key在散列表中的位置
{
	Position currentPos;
	int collisionNum;

	collisionNum=0;
	currentPos=Hash(key,H->TableSize);
	while(H->TheCells[currentPos].Info!=Empty&&
		H->TheCells[currentPos].Element!=key)
	{
		//平方探测法
		currentPos+=2*collisionNum-1;
		if(currentPos>=H->TableSize)
			currentPos-=H->TableSize;
	}
	return currentPos;
}

void Insert(int key,HashTable H)//插入
{
	Position pos;
	pos=Find(key,H);
	if(H->TheCells[pos].Info!=Legitimate)
	{
		H->TheCells[pos].Info=Legitimate;
		H->TheCells[pos].Element=key;
	}
}
HashTable Rehash(HashTable H)	//再散列
{
	int i,oldSize;
	Cell *oldCells;

	oldCells=H->TheCells;
	oldSize=H->TableSize;

	H=InitializeTable(2*oldSize);
	for(i=0;i<oldSize;i++)
	{
		if(oldCells[i].Info==Legitimate)
			Insert(oldCells[i].Element,H);
	}
	free(oldCells);
	return H;
}

int main()
{
    HashTable Hash;
    Position p;
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
	p=Find(10,Hash);
    printf("%d \n",Hash->TheCells[p].Element);

}
