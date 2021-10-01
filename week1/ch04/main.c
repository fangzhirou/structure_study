#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define bucket 10
#define LENGTH sizeof(struct node)
//定义一个节点
typedef struct node
{
    int data;
    struct node* next;
}*List, *Node;
//判断结点是否为空
int IsEmpty(List L) {
    return L->next == NULL;
}
//判断是否为最后一个结点
int IsLast(List L) {
    return L->next == NULL;
}
//初始化结点（头结点）
List Init_List(void) {
    Node L = (Node)malloc(LENGTH);
    if (L == NULL)
        printf("out of space");
    L->next = NULL;
    return L;
}
//遍历链表
void Print_List(Node phead)
{
    Node p = phead->next;//跳过头结点进行遍历
    while (p != NULL)//尾结点为空时终止（尾结点的指针域为空）
    {
        printf("%d\t", p->data);
        p = p->next;
    }printf("\n");
}
//根据链表中最大的数决定排序趟数
int SortNum(Node L) {
    Node p = L->next;
    int x=0,count=0;
    for (; p != NULL; p = p->next) {
        if (x<p->data) {
            x = p->data;
        }
    }
    while (x) {
        x /= 10;
        count++;
    }
    return count;
}
void MoveNode(Node L1,Node L2) {
    Node temp;
    while (!IsLast(L1)) {
        L1 = L1->next;
    }
    if (L2->next ==NULL)
        exit(-1);//表或桶为空时结束
    temp = L2;
    L2 = L2->next;
    temp->next = L2->next;//相当于在链表移除结点L2，到放到桶（结构体数组）中收集
    L1->next = L2;
    L2->next = NULL;

}
//创建一个单链表(尾插法)
 List Create_List(Node L)
{
     Node p;
     Node tail = L;
    int a;
    int len;
    printf("请输入要排序的个数:");
    scanf("%d", &len);
    printf("请输入元素:\n");
    for (int i = 0; i < len; i++)
    {
        p = (Node)malloc(LENGTH);
        if (p ==NULL)
            return 0;
        scanf("%d", &a);
        tail->next = p;
        p->data = a;
        p->next = NULL;
        tail = p;
    }
     return L;//f返回头结点
}
 void RaidSort(Node L) {
     Node b[bucket];
     int i,Element,sum;
     for ( i = 0; i < bucket; i++) {
         b[i] = Init_List();
     }
     int num = SortNum(L);//num为趟数
     for (i = 0; i < num; i++) {
         while (!IsEmpty(L)) {
             Element = L->next->data;
             sum = (int)(Element / pow(10, i)) % 10;//根据num的值，按照个位十位，，，（低位到高位放入桶中）
             MoveNode(b[sum],L);

         }
         for (int j = 0; j < 10; j++) {
             while (!IsEmpty(b[j]))
             {
                 MoveNode(L,b[j]);
             }
         }
         printf("第%d轮排序:\n", i + 1);
         Print_List(L);
     }
     for (int i = 0; i < bucket; i++)
         free(b[i]);//排序完成释放桶
 }
int main()
{
    Node s;
    s=Init_List();
    Create_List(s);
    Print_List(s);
    RaidSort(s);
    return 0;
}
