#include <stdio.h>
void allpairs(twodimarray a,twodimarray d,twodimarray path,int n)//所有点对最短路径
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            d[i][j]=a[i][j];
            path[i][j]=notavertex;
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(d[i][k]+d[k][j]<d[i][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                    path[i][k]=k;
                }
            }
        }
    }
}
