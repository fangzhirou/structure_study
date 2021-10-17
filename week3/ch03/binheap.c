#include "binheap.h"
#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
#define MinPQSize 10
#define MinData 0
PriorityQueue Initialize(int maxElements)
{
    PriorityQueue H;
    if (maxElements <MinPQSize)
    {
        FatalError("Priority queue size is toosmall");
    }

    H= malloc(sizeof(struct HeapStruct));
    if (H == NULL)
        FatalError("Out of space");

    // 数组的第0个元素是个sentinel标记节点，计入数组容量中，但不计入capcaity或size中
    H->Elements = malloc((maxElements+1)*sizeof(int));
    if (H->Elements == NULL)
        FatalError("Out of space");
    H->Size = 0;
    H->Capacity = maxElements;
    H->Elements[0] = MinData;

    return H;
}
void Insert(int x,PriorityQueue H)
{
    int i;
    if(isFull(H))
    {
        FatalError("Priority queue is full");
        return ;
    }
    for(i= ++H->Size;H->Elements[i/2]>x;i/=2)
        H->Elements[i]=H->Elements[i/2];
    H->Elements[i]=x;
}
int deleteMin(PriorityQueue H)
{
    int i,Child;
    int MinElement,LastElement;
    if(isEmpty(H))
    {
        FatalError("Priority queue is empty");
        return H->Elements[0];
    }
    MinElement=H->Elements[1];
    LastElement=H->Elements[H->Size--];
    for(i=1;i*2<=H->Size;i=Child)
    {
        Child=i*2;
        if(Child!=H->Size&&H->Elements[Child+1]<H->Elements[Child])
            Child++;
        if(LastElement>H->Elements[Child])
            H->Elements[i]=H->Elements[Child];
        else
            break;
    }
    H->Elements[i]=LastElement;
    return MinElement;
}
void printHeap(PriorityQueue H){
	int i;
	if(!isEmpty(H)){
		for(i=1;i<=H->Size;i++)
		  printf("%d\t",H->Elements[i]);
		printf("\n");
	}
}
int isEmpty(PriorityQueue H){//判空

	return H->Size==0;
}

int isFull(PriorityQueue H){//判满
	return H->Size==H->Capacity;
}
int main(){
	PriorityQueue H=Initialize(10);
	if(isEmpty(H))
	  printf("H empty\n");

	Insert(4,H);
	Insert(42,H);
	Insert(14,H);
	Insert(456,H);
	Insert(74,H);

	printHeap(H);
	deleteMin(H);
	printHeap(H);

}
