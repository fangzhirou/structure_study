#ifndef QUEUE_H
#define QUEUE_H
#define NumOfQueue   20

typedef int ElementType;

struct queue
{
	int Capacity;
	int size;
	int front;
	int rear;
	ElementType* Array;
};

typedef struct queue* Queue;

Queue CreatQueue();//创建空队列；

int IsEmpty(Queue Q);//判断队列是否为空；

int IsFull(Queue Q);//判断队列是否为满；

void MakeEmpty(Queue Q);//置空

//int LengthOfQueue(Queue Q);//计算队列长度

void EnQueue(Queue Q, ElementType data);//入队

void DeQueue(Queue Q);//出队

void PrintQueue(Q);//打印队列
ElementType Front(Queue Q);
ElementType FrontAndDequeue(Queue Q);


#endif // QUEUE_H
