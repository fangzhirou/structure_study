# 桶式排序
条件：输入数据是小于M的正整数。
1.留一个计数数组，初始化为全0，有M个单元（桶）。当数组元素A[i]被读入时Count[A[i]]增1。最后看哪些桶不为0，输出这些不为0的桶的位置，就是排好序的表。
