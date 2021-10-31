#include <stdio.h>
double Eval(int n)//使用一个表来递归
{
    int i,j;
    double sum,answer;
    double *c;
    c=malloc(sizeof(double)*(n+1));
    if(c==null)
        printf("out of space");
    c[0]=1.0;
    for(i=1;i<=n;i++)
    {
        sum=0.0;
        for(j=0;j<i;j++)
            sum+=c[j];
        c[i]=2.0*sum/i+1;
    }
    answer=c[n];
    free(c);
    return answer;
}
