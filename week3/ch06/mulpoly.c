#include "mulpoly.h"
#include <stdio.h>
#include <stdlib.h>
#define HASHMODULUS 11 //散列函數的模數
/*多项式的例程*/
polynomial Insert(int coefficient, int power, polynomial p)
//插入元素到一个多项式
{
    position pos;
    position beforePos;
    position tmpCell; //如果該多項式沒有對應的冪，就插入

    tmpCell = malloc(sizeof(struct Node));
    if (tmpCell == NULL)
    {
        printf("Out of space!!!");
        exit(0);
    }
    else
    {
        tmpCell->coefficient = coefficient;
        tmpCell->power = power;
        tmpCell->next = NULL;
    }

    if (p == NULL)
    {
        p = malloc(sizeof(struct Node));
        if (p == NULL)
        {
            printf("Out of space!!!\n");
            exit(0);
        }
        else
            p->next = tmpCell;
    }
    else
    {
        beforePos = p;
        pos = p->next;
        if (pos == NULL)
            beforePos->next = tmpCell;
        else
        {
            while (pos != NULL)
            {
                if (pos->power == power)
                {
                    pos->coefficient += coefficient;
                    free(tmpCell);
                    break;
                }
                else if (pos->power > power)
                {
                    if (pos->next == NULL)
                    {
                        pos->next = tmpCell;
                        break;
                    }
                    beforePos = pos;
                    pos = pos->next;
                }
                else if (pos->power < power)
                {
                    beforePos->next = tmpCell;
                    tmpCell->next = pos;
                    break;
                }
            }
        }
    }
    return p;
}

hashTable initialize(hashTable h)
{
    /*散列表的大小默認為11，即模數*/
    int i;
    h = malloc(sizeof(struct hashTbl));

    if (h == NULL)
    {
        printf("Out of space!!!\n");
        exit(0);
    }
    else
    {
        h->tableSize = HASHMODULUS;
        h->theList = malloc(sizeof(polynomial) * HASHMODULUS);
        if (h->theList == NULL)
        {
            printf("Out of space!!!\n");
            exit(0);
        }
        else
        {
            for (i = 0; i < HASHMODULUS; i++)
            {
                h->theList[i] = malloc(sizeof(struct Node));
                if (h->theList[i] == NULL)
                {
                    printf("Out of space!!!\n");
                    exit(0);
                }
                else
                    h->theList[i]->next = NULL;
            }
        }
    }

    return h;
}

int hash(int power)
{
    unsigned int hashValue = power % HASHMODULUS;

    return hashValue;
}

polynomial sortAndInsertToC(hashTable h, polynomial C)
{
    position pos;

    int i;
    int tmpCoefficient;
    int tmpPower;

    if (C == NULL)
    {
        C = malloc(sizeof(struct Node));
        if (C == NULL)
        {
            printf("Out of space!!!");
            exit(0);
        }
        C->next = NULL;
    }

    for (i = 0; i < HASHMODULUS; i++)
    {
        pos = h->theList[i]->next;

        while (pos != NULL)
        {
            tmpCoefficient = pos->coefficient;
            tmpPower = pos->power;
            C = Insert(tmpCoefficient, tmpPower, C);
            pos = pos->next;
        }
    }

    return C;
}

int main()
{
    polynomial A = NULL;
    polynomial B = NULL;
    polynomial C = NULL;   //这个多项式是A和B的乘积结果
    position firstOfA;     //A的第一个节点
    position firstOfB;     //B的第一个节点
    int tmpMulCoefficient; //多项式节点乘积的系数
    int tmpMulPower;       //多项式节点乘积的幂
    int hashValue;       //乘积结果的散列值
    hashTable h = NULL;
    /*建立多项式A*/
    A = Insert(8, 4, A);
    A = Insert(8, 3, A);
    A = Insert(4, 2, A);
    A = Insert(3, 1, A);
    A = Insert(8, 5, A);

    /*建立多项式B*/
    B = Insert(8, 5, B);
    B = Insert(1, 4, B);
    B = Insert(4, 3, B);
    B = Insert(2, 2, B);
    B = Insert(8, 6, B);
    B = Insert(8, 1, B);

    /*建立散列表h*/
    h = initialize(h);

    /*多项式相乘放进散列表*/
    firstOfA = A->next;
    while (firstOfA != NULL)
    {
        firstOfB = B->next;
        while (firstOfB != NULL)
        {
            tmpMulCoefficient = firstOfA->coefficient * firstOfB->coefficient;
            tmpMulPower = firstOfA->power + firstOfB->power;
            /*放进散列表*/
            hashValue = hash(tmpMulPower);
            h->theList[hashValue] = Insert(tmpMulCoefficient, tmpMulPower, h->theList[hashValue]);
            firstOfB = firstOfB->next;
        }
        firstOfA = firstOfA->next;
    }
    /*将结果排序*/
    C = sortAndInsertToC(h, C);

    position posC = C->next;
    while (posC != NULL)
    {
        printf("系数： %d : 次数： %d \n", posC->coefficient, posC->power);
        posC = posC->next;
    }
    return 0;
}
