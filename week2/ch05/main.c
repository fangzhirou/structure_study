//树的节点声明
typedef struct TreNode *PtrToNode;
struct TreeNode
{
    ElementType Element;
    PtrToNode FirstChild;
    PtrToNode NextSibling;
};
//二叉树节点声明
typedef struct BinaryTreeNode *PtrNode;
typedef struct PtrNode Tree;
struct BinaryTreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
};
