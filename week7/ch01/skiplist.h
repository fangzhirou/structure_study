#include<stdio.h>
#ifndef SKIP_LIST_H
#define SKIP_LIST_H
class SkipNode {
public:
        template <typename T>  friend class DeterminSkipList;
        SkipNode();
        SkipNode(const ElemType &key_input, SkipNode *right_input = NULL,
                 SkipNode *down_input = NULL);
private:
        DISALLOW_COPY_AND_ASSIGN(SkipNode); 
        int key;
        SkipNode *right;    
        SkipNode *down;  
};
class SkipList {
public:

        DeterminSkipList(const ElemType &max,const ElemType &max_1);
        ~DeterminSkipList();
     
        void Clear();
        bool Search(const ElemType &value) const;

        bool Insert(const ElemType &value);
     
        bool Remove(const ElemType &value);
    
        void Print() const;
   
        bool IsValid() const;

private:
  
        DISALLOW_COPY_AND_ASSIGN(DeterminSkipList);
        void Init();
        void ClearHelp(SkipNode<ElemType> *current);

        SkipNode<ElemType> * SearchHelp(const ElemType &value) const;
        
        void LowerHeadRemoveHelp();
        SkipNode<ElemType> *head;   
        SkipNode<ElemType> *bottom;
        SkipNode<ElemType> *tail;   

        const ElemType Max;    
        const ElemType Max_1;   
};

#endif
