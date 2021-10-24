#include <stdio.h>
#include <stdlib.h>
//归并排序解决练习7.13
int merge(int r[],int s[],int left,int mid,int right)
{
    int i,j,k;
    i=left;
    j=mid+1;
    k=left;
    while((i<=mid)&&(j<=right))
        if(r[i]<=r[j])//把正常数组r划分为前半后半，比较这2个数组的第一个元素大小
        {
            s[k] = r[i];//数组s用来存放较小的值
            i++;//此时i的值被拷贝，应该后移再继续比较
            k++;//k后移
        }
        else//同理
        {
            s[k]=r[j];
            j++;
            k++;
        }
        while(i<=mid)
            s[k++]=r[i++];//开始给s赋值,是和r一样的
        while(j<=right)
            s[k++]=r[j++];
    return 0;
}
int merge_sort(int r[],int s[],int left,int right)
{
    int mid;
    int t[20];//临时数组
    if(left==right)//只有一个元素时
        s[left]=r[right];
    else
    {
        mid=(left+right)/2;
        merge_sort(r,t,left,mid);//把临时数组传入赋前半部分值
        merge_sort(r,t,mid+1,right);//吧临时数组传入赋后半部分值
        merge(t,s,left,mid,right);
    }
    return 0;
}
int main()
{
    int a[8]={3,1,4,1,5,9,2,6};
    int i;
    merge_sort(a,a,0,7);
    for(i=0;i<8;i++)
        printf("%d ",a[i]);
    return 0;
}
