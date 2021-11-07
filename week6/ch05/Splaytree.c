#include "Splaytree.h"
#include<stdio.h>
struct Splaynode
{
    int element;
    Splaytree Left;
    Splaytree Right;
};
typedef struct Splaynode *Position;
static Position Nullnode=NULL;

Splaytree Initialize()//初始化伸展树
{
    if (Nullnode==NULL)
    {
        Nullnode=malloc(sizeof(struct Splaynode));
        if(Nullnode==NULL)
            printf("Out of space");
        Nullnode->Left=Nullnode->Right=Nullnode;//初始化左指针和右指针为空
    }
    return Nullnode;
}

Splaytree Splay(int item,Position x)//展开
{
    static struct Splaynode Header;
    Position LeftMax,RightMin;
    Header.Left=Header.Right=Nullnode;//使用头分别对应初始左右树的最小或最大节点
    LeftMax=RightMin=&Header;
    Nullnode->element=Item;
    while(item!=x->element)
    {
        if(item<x->element)
        {
            if(item<x->Left->element)
                x=SingleRotateWithLeft(x);//单旋转
            if(x->Left==Nullnode)
                break;
            RightMin->Left=x;
            RightMin=x;
            x=x->Left；
        }
        else{
            if (item>x->Right->element)
                x=SingleRotateWithRight(x);//单旋转
            if(x->Right==Nullnode)
                break;
            LeftMax->Right=x;
            LeftMax=x;
            x=x->Right;
        }
        LeftMax->Right=x->Left;
        RightMin->Left=x->Right;
        x->Right=Header.Left;
        x->Left=Header.Right;
    }
}
Splaytree Insert(int item,Splaytree t)//插入
{
    static Position Newnode =NULL;
    if(Newnode==null)
    {
        Newnode=malloc(sizeof(struct SplayNode));//建立单节点树
        if(Newnode==NULL)
            printf("Out of space");
    }
    Newnode->element=item;
    if(t==Nullnode)
    {
        Newnode->Left=Newnode->Right=Nullnode;
        t=Newnode;
    }
    else//围绕item展开t
    {
        t=Splay(item,t);
        if(item<t->element)//t的新根含有大于item的值
        {
            Newnode->Left=t->Left;//t的左子树变Newnode的左子树
            Newnode->Right=t;//t的新根和右子树变成Newnode的右子树
            t->Left=Nullnode;
            t=Newnode;//Newnode成为新根
        }
        else if(t->element<item)
        {
            Newnode->Right=t->Right;
            Newnode->Left=t;
            t->Right=Nullnode;
            t=Newnode;
        }
        else
            return t;//复制拷贝
    }
    Newnode=NULL;
    return t;
}
Splaytree Remove(int item,Splaytree t)//自顶向下删除
{
    Position Newtree;
    if(t!=Nullnode)
    {
        t=Splay(item,t);//依次展开把删除目标放在根处
        if(item==t->element)
        {
            if(t->Left==Nullnode)
                Newtree=t->Right;
            else
            {
                Newtree=t->Left;
                Newtree=Splay(item,Newtree);
                Newtree->Right=t->Right;
            }
            free(t);
            t=Newtree;
        }
    }
    return t;
}
