# 开放定址散列表
## 1.头文件声明
声明了开放定址散列表的操作函数，主要是利用平方探测法进行相应操作。使用线性探测方法实现再散列
## 2.函数实现
与分离链接散列算法需要指针不同，开放定址散列算法中，若有冲突发生就选择另外的单元，直到找出空单元为止。线性探测法逐步探测每个单元以查找出一个空单元，平方探测是消除线性探测中一次聚集问题的冲突解决方案，再散列建立另外一个约2倍大的表，扫描整个原始散列表，计算每个元素的新散列值并将其插入新表。

