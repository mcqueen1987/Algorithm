/*
http://www.cnblogs.com/McQueen1987/p/3552021.html

求一串数字中——和最大的连续子序列； 

问题描述 ：
从一组数字中，找出其所有连续子序列中，和数（子序列所有数字求和）最大的连续子序列：

如：数组 int A[ ] = {-4 , 3 , 5 , -1};找出某几个连续的子序列其和最大。比如A0+A1 = -1 。A1+A2+A3+A4 = 3。而A2+A3=8;则A2 A3组成的数组即是所求。

 

方法3：

最简单的思路，遍历所有子序列，找出其中最大的；

下面看看代码：

*/

int A[] = {31,-41,59,26,-53,58,97,-93,-23,84}; 

int fun(int A[], int n){
   int max = 0,i = 0;
   for(i=0;i<n;i++){
      int tmpsum = 0, j = 0;
      for(j=i;j<n;j++){
         tmpsum += A[j];
         if(tmpsum>max) max=tmpsum;
      }
   }
   return max;
}

void main(){
   int ret = fun(A,10);
   printf("%d",ret);
}

/*
运行结果：

Output:
187

*/