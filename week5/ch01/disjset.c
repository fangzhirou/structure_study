#include "disjset.h"
#include <stdio.h>
void Initilialize(disjset s)
{
    int i;
    for(i=numsets;i>0;i--)
        s[i]=0;
}
/*void setunion(disjset s,settype root1,settype root2)
{
    s[root2]=root1;
}*/
void setunion(disjset s,settype root1,settype root2)//按高度求并
{
    if(s[root2]<s[root1])
        s[root1]=root2;
    else{
        if(s[root1]==s[root2])
            s[root1]--;
        s[root2]=root1;
    }
}
settype Find(int x,disjset s)//路径压缩
{
    if(s[x]<=0)
        return x;
    else
        return Find(s[x],s);
}
