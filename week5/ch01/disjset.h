#ifndef DISJSET_H
#define DISJSET_H
#include <stdio.h>
typedef int disjset[numsets+1];
typedef int settype;
void Initilialize(disjset s);
void setunion(disjset s,settype root1,settype root2);
settype Find(int x,disjset s);

#endif // DISJSET_H
