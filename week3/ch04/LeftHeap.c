#include "LeftHeap.h"
#include<stdlib.h>
#include<stdio.h>
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )

PriorityQueue Initialize()
{
    PriorityQueue H=malloc(sizeof(struct TreeNode));
    if (H == NULL)
    {
        printf("FAILURE!\n");
        exit(EXIT_FAILURE);
    }
    H->Left = H->Right = NULL;
    H->Npl = 0;
    H->Element = 0;
    return H;
}
int FindMin(PriorityQueue H)
{
    if(!H)
        return H->Element;
    return 0;
}
int IsEmpty(PriorityQueue H)
{
    return H->Left == NULL && H->Right == NULL;
}
void SwapChildren(PriorityQueue H)
{
    PriorityQueue Temp;
    Temp = H->Left;
    H->Left = H->Right;
    H->Right = Temp;
}
static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)//合并左式堆
{
    if (H1->Left == NULL)
        H1->Left = H2;
    else
    {
        H1->Right = Merge(H1->Right, H2);
        if (H1->Left->Npl < H2->Right->Npl)
            SwapChildren(H1);
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)//驱动合并左式堆
{
    if (H1 == NULL)
        return H2;
    if (H2 == NULL)
        return H1;
    if (H1->Element < H2->Element)
        return Merge1(H1, H2);
    else
        return Merge1(H2, H1);
}
PriorityQueue Insert1(int X, PriorityQueue H)//插入
{
    PriorityQueue SingleNode;
    SingleNode = malloc(sizeof(struct TreeNode));
    if(SingleNode==NULL)
        FatalError("Out of space");
    else
    {
        SingleNode->Element = X;
        SingleNode->Npl=0;
        H = Merge(SingleNode, H);
    }
    return H;
}
PriorityQueue DeleteMin1(PriorityQueue H)
{
    PriorityQueue LeftHeap, RightHeap;
    if (IsEmpty(H))
    {
        FatalError("Priority queue is empty");
        return H;
    }
    LeftHeap = H->Left;
    RightHeap = H->Right;
    free(H);
    return Merge(LeftHeap, RightHeap);
}

void PreTrv(PriorityQueue H)//  前序遍历
	{
		if(H != NULL){
			printf("%d ",H->Element);
			PreTrv(H->Left);
			PreTrv(H->Right);
		}
	}
PriorityQueue CreateHeap()  //递归建堆
	{
		PriorityQueue H;
		int X;
		scanf("%d",&X);
		if(X == 0)
			H = NULL;
		else{
			H =malloc(sizeof(struct TreeNode));
			H->Element = X;
			H->Left = CreateHeap();
			H->Right = CreateHeap();
		}

		return H;
	}

int main()
	{
		PriorityQueue H1, H2;
		PriorityQueue H;

		printf("递归建树:\n\n");
		H1 = CreateHeap();
		H2 = CreateHeap();
		H = Merge(H1, H2);

		printf("\n左式堆合并后:\n\n");
		PreTrv(H);
		printf("\n\n");

		printf("插入数据后:\n\n");
		H = Insert1(1, H);
		PreTrv(H);

		H = DeleteMin1(H);
		printf("\n\n删除最小元素后: \n\n");
		PreTrv(H);

		return 0;
	}
