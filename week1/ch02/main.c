#include<stdio.h>
#include<stdlib.h>
#define MaxDegree 100
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
//适合大部分项都有的稠密多项式,采用多项式数组,即顺序表
typedef struct
{
    //系数数组
    int CoeffArray[MaxDegree +1];
    //最高次幂
    int HighPower;

}*Polynomial;
int Max(int m, int n)
{
    if (m > n) {
        return m;
    }
    else {
        return n;
    }
}
//初始化多项式
void ZeroPolynomial(Polynomial p)
{
    int i;
    for(i=0;i<=MaxDegree;i++)
        //p指向的是系数数组，置0
        p->CoeffArray[i]=0;
    //指数为0
    p->HighPower=0;
}
//相加
void Add(const Polynomial p1,const Polynomial p2,Polynomial sum)
{
    int i;
    //给结果置零
    ZeroPolynomial(sum);
    //指数是取的两个链表中的最大指数
    sum->HighPower=Max(p1->HighPower,p2->HighPower);
    //从最大指数开始递减
    for(i=sum->HighPower;i>=0;i--)
        //系数域是系数之和
        sum->CoeffArray[i]=p1->CoeffArray[i]+p2->CoeffArray[i];

}
void Mult(const Polynomial p1,const Polynomial p2,Polynomial result)
{
    int i,j;
    ZeroPolynomial(result);
    //多项式乘法指数相加
    result->HighPower=p1->HighPower+p2->HighPower;
    if(result->HighPower>MaxDegree)
        FatalError("Exceeded array size");
    else
    {
        //多项式相乘系数相乘
        for(i=0;i<=p1->HighPower;i++)
        {
            for(j=0;j<=p2->HighPower;j++)
            {
                result->CoeffArray[i+j]+=p1->CoeffArray[i]*p2->CoeffArray[j];
            }

        }

    }
}
void PrintPoly(const Polynomial Q)
{
    int i;
    for (i = Q->HighPower; i > 0; i--)
        // CoeffArray[i]代表系数，i代表指数
        printf("%dx^%d + ", Q->CoeffArray[i], i);
    printf("%d\n", Q->CoeffArray[0]);
}
int main()
{
    Polynomial P, Q;
    P = (Polynomial) malloc(sizeof(*P));
    Q = (Polynomial) malloc(sizeof(*Q));
    //设最高次幂，此时则有0次方和1次方
    P->HighPower = 1;
    //设系数值
    P->CoeffArray[0] = 1;
    P->CoeffArray[1] = 1; // P = x + 1
    Mult(P, P, Q); // Q = P * P = x^2 + 2x + 1
    Mult(Q, Q, P); // P = Q * Q = x^4 + 4x^3 + 6x^2 + 4x + 1
    Add(P, P, Q); // Q = P + P = 2x^4 + 8x^3 + 12x^2 + 8x^1 + 2
    // 打印结果
    PrintPoly(Q);
    return 0;

}
