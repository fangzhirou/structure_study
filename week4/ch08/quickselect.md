# 快速选择
改写快速排序，同样选取枢纽元，分成2个集合，如果k<前一个集合的元素个数，那么第k个最小元一定在第一个集合里。如果k正好是前一个集合元素个数加1，那枢纽元就是第k个最小元，否则在第二个集合里，再在第二个集合递归调用寻找要找的最小元。