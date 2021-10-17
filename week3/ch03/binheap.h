#ifndef BINHEAP_H
#define BINHEAP_H
#include <stdio.h>
#include <stdlib.h>
struct HeapStruct;
typedef struct HeapStruct * PriorityQueue;
// 初始化堆
PriorityQueue Initialize(int maxElements);

// 销毁堆
void Destroy(PriorityQueue H);

// 清空堆中的元素
void MakeEmpty(PriorityQueue H);

// 插入操作
void Insert(int x, PriorityQueue H);

// 删除最小者操作，返回被删除的堆顶元素
int deleteMin(PriorityQueue H);

// 查找最小者（堆顶）
int findMin(PriorityQueue H);

// 判断堆是否为空
int isEmpty(PriorityQueue H);

// 判断堆是否满
int isFull(PriorityQueue pqueue);
struct HeapStruct
{
    int Capacity;
    int Size;
    int *Elements;
};
#endif // BINHEAP_H
