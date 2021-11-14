# 4.k-d树
## 1）二维查找树的性质：奇数层上分支按第一个关键字进行，偶数层上分支按第二个关键字进行，根是任意选取的奇数层。没有办法能保证这棵树平衡，只能重构子树来定期对树进行平衡。
## 2）插入操作：沿树下行，保留当前层，假设基本的项是2个元素的数组，把层限制在0,1，使用递归实现。
## 2）范围查询：可以要求精准匹配或2个关键字中一个的匹配。正交范围查询给出其第一个关键字在一个特殊的值集合之间，第二个关键字在另一个集合之间的所有项。