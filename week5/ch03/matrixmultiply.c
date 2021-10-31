#include <stdio.h>
void matrixmultiply(matrix a,matrix b,matrix c,int n)//简单的矩阵乘法
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(j=0;j<n;j++)
            {
                c[i][j]=0.0;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
                c[i][j]+=a[i][k]*b[k][j];
        }
    }
}
