#ifndef LEFTHEAP_H
#define LEFTHEAP_H
#include<stdlib.h>
#include<stdio.h>
#define Insert(X,H) (H=Insert1((X),H))
#define DeleteMin(H)(H=DeleteMin1(H))

struct TreeNode;
typedef struct TreeNode *PriorityQueue;
PriorityQueue Initialize();
int FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
PriorityQueue Insert1(int X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);
struct TreeNode
{
    int Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};


#endif // LEFTHEAP_H
