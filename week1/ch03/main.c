//单链表求解多项式
#include<stdio.h>
#include<stdlib.h>


typedef struct PNode{
	int coef;	//系数
	int expn;	//指数
	struct PNode *next;	//指针域
}PNode,*Polynomial;


void CreatPolyn(Polynomial P,int n){
	P=(Polynomial)malloc(sizeof(PNode));
	P->next=NULL;
	for(int i=0;i<n;i++){
		int j=i+1;
		int k=i+1;
		Polynomial S=(Polynomial)malloc(sizeof(PNode));
		printf("请输入第%d个指数",j);
		scanf("%d",&S->expn);
		printf("请输入第%d个系数",k);
		scanf("%d",&S->coef);
		Polynomial pre=P;	//用于保存游标指针q的前驱，初值为头节点
		Polynomial q=P->next;	//初始化游标指针q，指向首元节点
		while(q&&q->expn<S->expn){	//游标指针向后移动，寻找第一个比待插入节点S的指数大的节点P
			pre=q;		//前驱紧随其后
			q=q->next;	//游标指针向后移动
		}
		S->next=q;
		pre->next=S;
	}
};
void PrintfPolyn(Polynomial P){
	Polynomial q=P->next;
	int count=0;	//不是用来计数的，单纯用于判断当前项是否为第一项
	while(q){
		if(count==0){
			printf("%dX^%d",q->coef,q->expn);
		}
		else{
			printf("+%dX^%d",q->coef,q->expn);
		}
		count++;
		q=q->next;
	}
	printf("\n");
};
void AddPolyn(Polynomial Pa,Polynomial Pb){
	Polynomial p1=Pa->next;	//Pa和Pb的游标指针初始化，分别指向各自首元节点
	Polynomial p2=Pb->next;
	Polynomial p3=Pa;		//初始化“和多项式”的游标指针
	int sum=0;
	Polynomial r;			//用于储存被淘汰的游标指针地址，方便之后释放内存
	while(p1&&p2){
		if(p1->expn==p2->expn){	//当p1和p2指数相同
			sum=p1->coef+p2->coef;
			if(sum!=0){
				p1->coef=sum;
				p3->next=p1;	//将修改系数后的p1添加在p3之后
				p3=p1;			//p3后移一位
				p1=p1->next;	//p1后移一位
				r=p2;
				p2=p2->next;
				free(r);
			}
			else{				//系数相加为零时
				r=p1;
				p1=p1->next;
				free(r);
				r=p2;
				p2=p2->next;
				free(r);
			}
		}
		else if(p1->expn<p2->expn){	//Pa当前节点指数较小
			p3->next=p1;	//p1添加在p3之后
			p3=p1;			//p3后移一位
			p1=p1->next;	//p1后移一位
		}
		else{						//Pb当前节点指数较小
			p3->next=p2;
			p3=p2;
			p2=p2->next;
		}
	}
	p3->next=p1?p1:p2;				//插入非空多项式的剩余项
	free(Pb);						//释放Pb的头节点（Pa已然成为新的多项式“和多项式”）
};
int main(){
	Polynomial Pa;	//初始化多项式Pa和Pb
	Polynomial Pb;
	int n1=0;
	int n2=0;
	printf("创建第一个多项式Pa：\n");
	printf("请输入Pa的项数：\n");
	scanf("%d",&n1);
	CreatPolyn(Pa,n1);
	printf("创建第二个多项式Pb：\n");
	printf("请输入Pb的项数：\n");
	scanf("%d",&n2);
	CreatPolyn(Pb,n2);
	printf("展示Pa：\n");
	PrintfPolyn(Pa);
	printf("展示Pb：\n");
	PrintfPolyn(Pb);
	printf("开始相加~\n");
	AddPolyn(Pa,Pb);
	printf("展示和多项式：\n");
	PrintfPolyn(Pa);
	return 0;
}
