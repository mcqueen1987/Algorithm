/*
http://www.cnblogs.com/McQueen1987/p/3552021.html

求一串数字中——和最大的连续子序列； 

问题描述 ：
从一组数字中，找出其所有连续子序列中，和数（子序列所有数字求和）最大的连续子序列：

如：数组 int A[ ] = {-4 , 3 , 5 , -1};找出某几个连续的子序列其和最大。比如A0+A1 = -1 。A1+A2+A3+A4 = 3。而A2+A3=8;则A2 A3组成的数组即是所求。

方法4：

分治算法解决方案：解决规模为n的问题，可以递归地解决规模近似为n/2的子问题，然后对答案进行合并，得到整个问题的答案；

把int A[] = {31,-41,59,26,-53,58,97,-93,-23,84};

分为：31,-41,59,26,-53,

         58,97,-93,-23,84

两个子问题Sa，Sb；

现在，最大子向量必定在Sa，Sb或者跨越Sa和Sb之间边界的部位Sc；

我们分治递归Sa，Sb，并通过类似方法3的遍历的方式计算Sc；

代码如下：

*/

#define Max(a,b,c) ((a>b?a:b)>c?(a>b?a:b):c)


int A[] = {31,-41,59,26,-53,58,97,-93,-23,84};

//divide-and-conquer algorithm
int fun(int A[], int low, int high){
   int mid=(low+high)/2;
   int tmp=0,lret=0,rret=0,i=mid,j=mid+1;
   if(low>high) return 0;
   if(low == high) return Max(A[low],0,0);
   for(;i>=low;i--){
      tmp+=A[i];
      lret=Max(tmp,lret,0);
   } 
   tmp=0;
   for(;j<=high;j++){
      tmp+=A[j];
      rret=Max(tmp,rret,0);
   }
   return Max(lret+rret,fun(A,low,mid),fun(A,mid+1,high));
}

int main(){
   int ret = fun(A,0,9);
   printf("%d",ret);
}

/*
运行结果：

Output:
187

*/