#include <stdio.h>
#include <stdlib.h>
//快速排序解决练习7.17
void Swap(int *left,int *right)
{
	int tmp;
	tmp = *left;
	*left = *right;
	*right = tmp;
}
void InsertionSort(int a[],int n)
{
    int i,p;
    int tmp;//存放扫描到的元素值
    for(p=0;p<n;p++)
    {
        tmp=a[p];
        for(i=p;i>0&&a[i-1]>tmp;i--)//遍历数组，前一个元素比当前元素大时，令当前元素为较大值,然后继续往前判断，看前面有没有比当前元素还大的,没有就跳出循环。
        {
            a[i]=a[i-1];
        }
        a[i]=tmp;//此时的i是自减后的，相当于让前面的元素替换为一开始存放的扫描值，其实就是2值互换。
    }
}
int median(int a[], int left, int right) {//三数中值分割
    int center=(left+right)/2;
    if(a[left]>a[center])
        Swap(&a[left],&a[center]);
    if(a[left]>a[right])
        Swap(&a[left],&a[right]);
    if(a[center]>a[right])
        Swap(&a[center],&a[right]);
    Swap(&a[center],&a[right-1]);
    return a[right-1];//枢纽元，是左中右3个位置元素的中值
}

void QSort(int a[], int left, int right) {
    int i,j;
    int pivot;
    if(left+3<=right)
    {
        //pivot=median(a,left,right);//三数中值分割法选出来的枢纽元
        pivot=3;//题目给的枢纽元，这两个选一个，另一个就要注释掉
        i=left;
        j=right-1;
        for( ; ; )//分成大于枢纽元和小于枢纽元2个不相交集合
        {
            while(a[++i]<pivot){}
            while(a[--j]>pivot){}
            if(i<j)
                Swap(&a[i],&a[j]);
            else
                break;
        }
        Swap(&a[i],&a[right-1]);
        QSort(a,left,i-1);//对前一个集合快排
        QSort(a,i+1,right);//对后一个集合快排
    }
    else
        InsertionSort(a+left,right-left+1);

}

void QuickSort(int a[],int n)//驱动程序
{
    QSort(a,0,n-1);
}




int main() {
    int a[11]={3,1,4,1,5,9,2,6,5,3,5};
    int i;
    QuickSort(a,11);
    for(i=0;i<11;i++)
        printf("%d ",a[i]);
    return 0;
}
