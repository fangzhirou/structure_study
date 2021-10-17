#include "BinNode.h"
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<string.h>



BinHeap creatBinHeap()
{
    BinHeap heap = (BinHeap)malloc(sizeof(*heap));
    if(heap == NULL)
    {
        printf("Memory is not sufficient\n");
        exit(1);
    }
    return heap;
}
BinHeap findBinHeapMin(BinHeap heap)
{
    if(heap == NULL)
        return NULL;
    BinHeapNodelink h = heap;
    BinHeapNodelink min_node = h;
    int min_key = h->key;
    while((h = h->sibling) != NULL)
    {
        if(h->key > min_key)
        {
            min_node = h;
            min_key = h->key;
        }
    }
    return min_node;
}
//=======================两个二项队列的连接============================
BinHeap BinHeapUnion(BinHeap H1, BinHeap H2)
{
    BinHeap heap = BinHeapMerge(H1, H2);
    if(heap == NULL)
        return NULL;
    BinHeap x, x_prev, x_next;
    x_prev = NULL;
    x = heap;
    x_next = x->sibling;
    //将相同度数的二项堆合并成一个二项堆 B_k -> B_k+1
    while(x_next != NULL)
    {
        //case 1:相邻不等,不作变化指针后移
        //case 2:连续3个相等，不作变化指针后移（下一次循环处理后2个相等的节点）
        if(x->degree != x_next->degree || (x_next->sibling!=NULL && x_next->degree == x_next->sibling->degree) )
        {
            x_prev = x;
            x = x_next;
        }

        //case 3、4：相邻2个相等,和第3个不等
        else
        {
            //case 3: 将x_next连到x
            if(x->key <= x_next->key)
            {
                x->sibling = x_next->sibling;
                BinHeapPair(x_next, x);
            }

            //case 4: 将x连到x_next
            else
            {
                if(x_prev == NULL)
                    heap = x_next;
                else
                    x_prev->sibling = x_next;

                BinHeapPair(x, x_next);
                x = x_next;
            }

        }//case 3&4
        x_next = x->sibling;

    }//while
    return heap;

}

//将2个二项队列合并成度数单调递增的一个二项队列
BinHeap BinHeapMerge(BinHeap H1, BinHeap H2)
{
    BinHeap H3 = NULL, H3_prev = NULL, heap = NULL;//heap用于指向新的二项队列, H3用作heap的索引指针
    BinHeap h1, h2;
    h1 = H1, h2 = H2;
    if(H1 != NULL && H2 != NULL)
    {
        while(h1 != NULL && h2 != NULL)
        {
            if(h1->degree < h2->degree)
            {
                H3 = h1;
                h1 = h1->sibling;
            }
            else
            {
                H3 = h2;
                h2 = h2->sibling;
            }

            if(H3_prev == NULL)
            {
                H3_prev = H3;
                heap = H3;
            }
            else
            {
                H3_prev->sibling = H3;
                H3_prev = H3;
            }
        }//while

        if(h1 == NULL)
            H3_prev->sibling = h2;
        else if(h2 == NULL)
            H3_prev->sibling = h1;
    }

    if(H1 == NULL)
    {
        heap = H2;
    }
    if(H2 == NULL)
    {
        heap = H1;
    }

    return heap;
}

//连接2个度数k相同的二项树成度数为k+1的一棵树,将H1 连接到 H2上
BinHeap BinHeapPair(BinHeap H1, BinHeap H2)
{
    H1->parent = H2;
    H1->sibling = H2->leftChild;
    H2->leftChild = H1;
    H2->degree++;
    return H2;
}
//用数组元素创建二项队列
BinHeap CreatHeapWithArray(int a[], int n)
{
    BinHeap heap = NULL;
    BinHeap newheap = NULL;
    for(int i = 0; i < n; i++)
    {
        newheap = (BinHeap)malloc(sizeof(*newheap));
        if(newheap == NULL)
        {
            printf("Memory is not sufficient\n");
            exit(1);
        }
        memset(newheap, 0, sizeof(*newheap));
        newheap->key = a[i];
        if(heap == NULL)
            heap = newheap;
        else
        {
            heap = BinHeapUnion(heap, newheap);
            newheap = NULL;
        }

    }
    return heap;
}
BinHeap BinHeapDelMin(BinHeap H1)
{
    if (H1 == NULL)
        return NULL;

    BinHeap p, min, min_prev;
    p = H1;
    min_prev = NULL;
    min = H1;
    int key = min->key;

    while (p->sibling != NULL)
    {
        if(p->sibling->key < key)
        {
            min_prev = p;
            min = p->sibling;
            key = p->sibling->key;
        }
        p = p->sibling;
    }

    BinHeap heap = H1;

    if(H1 == min)
        heap = min->sibling;
    else
        min_prev->sibling = min->sibling;

    BinHeap x_prev = NULL, x = NULL; //
    BinHeap  H2 = NULL;
    p = NULL;
    x = min->leftChild;
    while (x != NULL)
    {
        p = x;
        x = x->sibling;
        p->sibling = H2;
        H2 = p;
        p->parent = NULL;
    }
    heap = BinHeapUnion(heap, H2);
    return min;
}
int main()
{
    BinHeap H1=creatBinHeap();
    BinHeap H2=creatBinHeap();
    BinHeap H=creatBinHeap();
    int a[6]={1,2,3,4,5,6};
    int b[5]={7,8,9,10,11};
    CreatHeapWithArray(a, 3);
    CreatHeapWithArray(b,4);
    H=BinHeapMerge(H1, H2);

}
