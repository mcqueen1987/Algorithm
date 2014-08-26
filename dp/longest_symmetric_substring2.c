/*
http://www.cnblogs.com/McQueen1987/p/3552021.html

求一串数字中——和最大的连续子序列； 

问题描述 ：
从一组数字中，找出其所有连续子序列中，和数（子序列所有数字求和）最大的连续子序列：

如：数组 int A[ ] = {-4 , 3 , 5 , -1};找出某几个连续的子序列其和最大。比如A0+A1 = -1 。A1+A2+A3+A4 = 3。而A2+A3=8;则A2 A3组成的数组即是所求。

 

求解方法2：

扫描算法（O（n））

1，递归公式：f(n)表示包含元素A(n)的规模为x[0…n]的问题。如何扩展为包含A(n+1)的规模为x[0…n+1]的问题f(n+1)？

2，我们用类似分治算法的原理：前i个元素中，最大总和子数组要么在前i个元素中，要么其结束位置为i+1；

    举个例子：

  int A[ ] = {-4 , 3 , 5 , -1};

      tmp = {  0 , 3 , 8 ,  7} 其中tmp = Max( tmp + A[i] , 0)

      max = {  0 , 3 , 8 ,  8} 其中max = Max(max, tmp);

tmp：从左往右扫描，第i位存的是包含第i位的最大子数组的和，如果和数小于0则存0；

max：从左往右扫描，第i位之前最大子数组的和，这个子数组可以不包含i；说白了就是第i位存i左侧所有tmp的最大值；

最终，max的最后一位8，即为和最大的连续子序列

下面看看代码：

*/

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a>b?a:b

int fun(int A[],int n){
  int i=1,maxret=0,tmp=max(A[0],0);
  for(;i<n;i++){
    tmp=max(0,tmp+A[i]);
    maxret=max(maxret,tmp);
    printf("tmp=%d,    maxret=%d\n",tmp,maxret);
  }
  return maxret;
}

int main(){
   int A[] = {-2,7,1,-6,-2,9,2,-1};
   int ret = fun(A,8);
   printf("%d\n",ret);
   return 0;
}

/*
运行结果：

[root@admin Desktop]# ./a.out
tmp=7,    maxret=7
tmp=8,    maxret=8
tmp=2,    maxret=8
tmp=0,    maxret=8
tmp=9,    maxret=9
tmp=11,    maxret=11
tmp=10,    maxret=11

*/