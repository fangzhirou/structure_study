# 随机化算法
## 1）随机数发生器：
产生伪随机数最简单是线性同余发生器，必须先给出种子x0，选择A,M，得到随机数x=AXi mod M.
## 2）跳跃表：
以期望时间支持查找和插入的数据结构，期望基于随机数发生器。能够添加删除和所有涉及排序的操作并得到与二叉查找树的平均时间界匹配的期望时间界。最简单的支持查找的可能的数据结构是链表。将有K个指针的节点定义为k阶节点，任意k阶节点上第i阶指针指向的下一个节点至少具有i阶，需要插入新元素时，按照概率分布随机选择新节点的阶数。执行Find时，在头结点从最高阶指针开始，沿阶一直走，直到找到正在寻找的节点的下一二节点前停下，再转到低一阶继续。进行到一阶停止时，为执行插入，始终监视每个使我们转到下一阶的节点，最后将新节点拼接到表中。
