# 3.博弈
三个棋子连在一起可以获胜。构造算法做到从不输棋，且机会出现时总能赢棋（因为能查表发现陷阱位置）
## 1）极小极大策略
使用一个赋值函数给位置的好坏定值，能获胜的位置值+1，平局为0，输为-1.通过考察盘面能确定这局棋输赢的位置叫终端位置，一个位置不是终端位置，那该位置的值通过递归假设双方最优棋步确定，叫极小极大策略，因为计算机要使值极大，下棋者使值极小。后继位置是从当前位置走一步可以达到的任意位置，在某位置计算机要走，递归求出所有后继位置的值，选有最大值的一步走。为得到任意后继位置的值，递归算出该后继位置所有后继位置的值，然后选最小的值，这个最小值是下棋人最佳的应招。
## 2）置换表：
通过散列实现的数据结构。利用表记录所有已经被计算过值的位置，程序将考察一些位置，当这些位置的值已经被存储了，出现第二次时就无需重新计算，这个位置基本变成了终端位置。
## 3）α-β裁剪
人们能取得的最重要的改进叫α-β裁剪。在假想的棋局里给某个位置求值的递归调用的迹就是博弈树。α裁减就是对一个无论如何都不能增加值的节点不进行求值。β裁减是对怎么做都不会影响结果的节点不进行求值。
对弈程序通常尽量对非终端节点应用求值函数。