#ifndef HASHQUAD_H
#define HASHQUAD_H
#include <stdio.h>
#include <stdlib.h>
typedef unsigned int Index;
typedef Index Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);//³õÊ¼»¯
void DestroyTable(HashTable H);
Position Find(int key,HashTable H);//²éÕÒ
int Retrieve(Position P,HashTable H);
void Insert(int Key, HashTable H);//²åÈë
HashTable Rehash(HashTable H);
int NextPrime(int TableSize);
int isPrime(int x);
enum KindOfEntry{Legitimate,Empty,Deleted};

struct HashEntry
{
    int Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;
struct HashTbl
{
    int TableSize;
    Cell *TheCells;
};
#endif // HASHQUAD_H
