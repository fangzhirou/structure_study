#include "AvlTree.h"//有平衡条件的二叉树：左右高度最多差1
#include<stdio.h>
#include<stdlib.h>
struct AvlNode
{
    int Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};
static int Height(Position P)
{
    if(P==NULL)
        return -1;
    else
        return P->Height;
}

AvlTree MakeEmpty(AvlTree T)
{
    if(T!=NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(int X,AvlTree T)
{
    if(T==NULL)
    {
        printf("Element not found\n");
        return NULL;
    }
    if(X<T->Element)
        return Find(X,T->Left);
    else if(X>T->Element)
        return Find(X,T->Right);
    else
        return T;
}

Position FindMin(AvlTree T)
{
    if(T==NULL)
    {
        printf("Element not found\n");
        return NULL;
    }
    if(T->Left)
        return FindMin(T->Left);
    else
        return T;
}

Position FindMax(AvlTree T)
{
    if(T==NULL)
    {
        printf("Element not found\n");
        return NULL;
    }
    if(T->Right)
        return FindMax(T->Right);
    else
        return T;
}

static int Max(int Lhs,int Rhs)
{
    return Lhs > Rhs ? Lhs : Rhs;
}

static Position SingleRotateWithLeft(Position K2)//单旋转，调整左左
{
    //K2是不满足平衡特性的点
    Position K1;

    K1 = K2->Left;//赋值为需要平衡的点的左儿子
    K2->Left = K1->Right;//让K2的左儿子移动变为K1的右儿子
    K1->Right = K2;//K1的右儿子为K2，K1成为新的根

    K2->Height = Max(Height(K2->Left),Height(K2->Right))+1;
    K1->Height = Max(Height(K1->Left),K2->Height)+1;

    return K1;
}

static Position SingleRotateWithRight(Position K1)//单旋转调整右右
{
    Position K2;

    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;

    K1->Height = Max(Height(K1->Left),Height(K1->Right))+1;
    K2->Height = Max(K1->Height,Height(K2->Right))+1;
}

static Position DoubleRotateWithLeft(Position K3)//双旋转调整左右
{
    K3->Left = SingleRotateWithRight(K3->Left);//K3的左儿子是其左儿子单旋转后的新根
    return SingleRotateWithLeft(K3);//再对K3进行单旋转，得到最后的真正根
}

static Position DoubleRotateWithRight(Position K1)//双旋转调整右左
{
    K1->Right = SingleRotateWithLeft(K1->Right);
    return SingleRotateWithRight(K1);
}

AvlTree Insert(int X,AvlTree T)
{
	if(T==NULL)
	{
		T = malloc(sizeof(struct AvlNode));
		if(T==NULL)
		{
			printf("Malloc Error\n");
			exit(1);
		}
		T->Element = X;
		T->Height = 0;
		T->Left = T->Right = NULL;
	}
	else if(X<T->Element)
	{
		T->Left = Insert(X,T->Left);
		if(Height(T->Left) - Height(T->Right)==2)
		{
			if(X<T->Left->Element)
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}
	else if(X>T->Element)
	{
		T->Right = Insert(X,T->Right);
		if(Height(T->Right) - Height(T->Left)==2)
		{
			if(X>T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
	}
	T->Height = Max(Height(T->Left),Height(T->Right))+1;
	return T;
}

AvlTree Delete(int X,AvlTree T)
{
    Position temp;
    if(T==NULL)
    {
        printf("Element not found\n");
        return NULL;
    }
    else if(X<T->Element)
    {
        T->Left = Delete(X,T->Left);
    }
    else if(X>T->Element)
    {
        T->Right = Delete(X,T->Right);
    }
    else if(T->Left && T->Right)
    {
        temp = FindMin(T->Right);
        T->Element = temp->Element;
        T->Right = Delete(T->Element,T->Right);
    }
    else
    {
        temp = T;
        if(T->Left==NULL)
            T = T->Right;
        else if(T->Right==NULL)
            T = T->Left;
        free(temp);
    }

    if(T!=NULL)
    {
        int balance = Height(T->Left)-Height(T->Right);
        if(balance==2)
        {
            int balance2 = Height(T->Left->Left)-Height(T->Left->Right);
            if(balance2==-1)
            {
                T = DoubleRotateWithLeft(T);
            }
            else
            {
                T = SingleRotateWithLeft(T);
            }
        }
        else if(balance==-2)
        {
            int balance2 = Height(T->Right->Left)-Height(T->Right->Right);
            if(balance2==-1)
            {
                T = DoubleRotateWithRight(T);
            }
            else
            {
                T = SingleRotateWithRight(T);
            }
        }
        T->Height = Max(Height(T->Left),Height(T->Right))+1;
    }
    return T;
}

int Retrieve(Position P)
{
    return P->Element;
}
int Depth(AvlTree T)
{
    int Ldepth,Rdepth;
    if(T==NULL)
        return 0;
    if(T->Left)
        Ldepth = Depth(T->Left);
    else
        Ldepth = 0;
    if(T->Right)
        Rdepth = Depth(T->Right);
    else
        Rdepth = 0;
    return Ldepth>Rdepth ? Ldepth+1:Rdepth+1;
}

void PreOrderTraversal(AvlTree T)
{
    if(T==NULL)
        return ;
    printf("%d ",T->Element);
    PreOrderTraversal(T->Left);
    PreOrderTraversal(T->Right);
}

void InOrderTraversal(AvlTree T)
{
    if(T==NULL)
        return ;
    InOrderTraversal(T->Left);
    printf("%d ",T->Element);
    InOrderTraversal(T->Right);
}

void PostOrderTraversal(AvlTree T)
{
    if(T==NULL)
        return ;
    PostOrderTraversal(T->Left);
    PostOrderTraversal(T->Right);
    printf("%d ",T->Element);
}

int main()
{
    AvlTree T=NULL;
    T = MakeEmpty(T);

    int depth = Depth(T);
    printf("树的深度：%d\n",depth);

    while(1)
    {
        int Element;
        printf("输入加入树中的元素（到0结束输入）");
        scanf("%d",&Element);
        if(Element==0)
            break;
        else
            T = Insert(Element,T);
    }

    depth = Depth(T);
    printf("树的深度:%d\n",depth);

    printf("先序遍历: ");
    PreOrderTraversal(T);
    printf("\n");
    printf("中序遍历:: ");
    InOrderTraversal(T);
    printf("\n");
    printf("后序遍历: ");
    PostOrderTraversal(T);
    printf("\n");

    while(1)
    {
        int Element;
        printf("输入想删除的树中的元素（到0结束输入）");
        scanf("%d",&Element);
        if(Element==0)
            break;
        else
            T = Delete(Element,T);
    }
    printf("删除后：\n");
    depth = Depth(T);
    printf("树的深度:%d\n",depth);

    printf("先序遍历: ");
    PreOrderTraversal(T);
    printf("\n");
    printf("中序遍历: ");
    InOrderTraversal(T);
    printf("\n");
    printf("后序遍历: ");
    PostOrderTraversal(T);
    printf("\n");



    return 0;
}
