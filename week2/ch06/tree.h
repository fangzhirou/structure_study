#ifndef TREE_H
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
SearchTree MakeEmpty(SearchTree T);
Position Find(int x,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int x,SearchTree T);
SearchTree Del(int x,SearchTree T);
int Retrieve(Position p);
void InorderTraversal(SearchTree T);
void PreorderTraversal(SearchTree T);
#endif // TREE_H
