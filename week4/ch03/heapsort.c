#define LeftChild(i)(2*(i)+1)//不知道为什么选这个
#include <stdio.h>
//堆排序解决练习7.11
void PercDown(int a[],int i,int n)//将数组按照堆序放入堆数组内
{
    int Child;
    int tmp;
    for(tmp=a[i];LeftChild(i)<n;i=Child)
    {
        Child=LeftChild(i);
        if(Child!=n-1&&a[Child+1]>a[Child])
            Child++;
        if(tmp<a[Child])
            a[i]=a[Child];
        else
            break;
    }
    a[i]=tmp;//用来互换
}
void Swap(int *left,int *right)//互换元素
{
	int tmp;
	tmp = *left;
	*left = *right;
	*right = tmp;
}
void Heapsort(int a[],int n)//将堆数组变成递增数组
{
    int i;
    for(i=n/2;i>=0;i--)//构建一个max堆
        PercDown(a,i,n);
    for(i=n-1;i>0;i--)//每次都缩小堆的大小
    {
        Swap(&a[0],&a[i]);//把最大元与堆内最后一个数互换位置
        PercDown(a,0,i);//整理数组，构建一个新max堆，此时最大元存放在堆数组最后一个单元，但已经不属于堆
    }
}


int main()
{
    int a[12]={142,543,123,65,453,879,572,434,111,242,811,102};
    Heapsort(a,12);
    for(int i=0;i<12;i++)
        printf("%d\n",a[i]);
    return 0;
}
