#ifndef MULPOLY_H
#define MULPOLY_H
#include <stdio.h>
#include <stdlib.h>
typedef struct Node *polynomial;

typedef struct Node *position;
struct Node
{
    int coefficient;
    int power;
    position next;
};

typedef struct hashTbl *hashTable;
struct hashTbl
{
    int tableSize;
    polynomial *theList; //一个数组
};
polynomial Insert(int coefficient, int power, polynomial p); //插入元素到一个多项式
hashTable initialize(hashTable h);
int hash(int power);
polynomial sortAndInsertToC(hashTable h, polynomial C);

#endif // MULPOLY_H
