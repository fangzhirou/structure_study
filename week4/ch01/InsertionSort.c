#include <stdio.h>
//插入排序实现练习7.1
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
int main()
{
    int a[9]={3,1,4,1,5,9,2,6,5};
    InsertionSort(a,9);//进行排序
    for(int i=0;i<9;i++)
        printf("%d\n",a[i]);
    return 0;
}
