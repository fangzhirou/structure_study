#include <stdio.h>
//希尔排序解决练习7.4
void Shellsort(int a[],int n)
{
    int i,j,increment;
    int tmp;
    //increment=1,3,7.1*2+1=3,3*2+1=7，increment代表增量
    for(increment=1;increment>0;increment=increment*2+1)
    {
        for(i=increment;i<n;i++)
        {
            tmp=a[i];//存放开始值
            for(j=i;j>=increment;j-=increment)
            {
                if(tmp<a[j-increment])//比较相隔increment的元素的大小
                a[j]=a[j-increment];//较大位置存放较大值
                else
                    break;
            }
            a[j]=tmp;//互换位置
        }
    }
}
int main()
{
    int a[9]={9,8,7,6,5,4,3,2,1};
    Shellsort(a,9);
    for(int i=0;i<9;i++)
        printf("%d\n",a[i]);
    return 0;
}
