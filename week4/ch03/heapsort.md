# 堆排序
## 1.构建max堆，更改堆序特性，让所有节点的孩子都小于节点本身，根一定是最大元。
## 2.写出互换元素的函数
## 3.把堆中最大元删掉，然后重新按堆序构建新堆。最大元存放在原来的堆数组的最后一个单元（利用交换元素的函数），但已经不在堆的范围内了，因为此时堆已经缩小了。
## 4.经过n-1次删除最大元，最后堆数组就是按递增顺序排列的数组了。
