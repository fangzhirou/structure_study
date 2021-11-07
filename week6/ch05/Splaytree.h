#ifndef SPLAYTREE_H
#define SPLAYTREE_H

struct Splaynode;
typedef struct Splaynode *Splaytree;
Splaytree MakeEmpty(Splaytree t);
Splaytree Find(int x,Splaytree t);
Splaytree FindMin(Splaytree t);
Splaytree FindMax(Splaytree t);
Splaytree Initialize();
Splaytree Insert(int x,Splaytree t);
Splaytree Remove(int x,Splaytree t);
int Retrieve(Splaytree t);//获取根节点
Splaytree Splay(int item,Position x);
#endif // SPLAYTREE_H
