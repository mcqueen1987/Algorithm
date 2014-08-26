/*
http://www.cnblogs.com/McQueen1987/p/3552021.html

求一串数字中——和最大的连续子序列； 

问题描述 ：
从一组数字中，找出其所有连续子序列中，和数（子序列所有数字求和）最大的连续子序列：

如：数组 int A[ ] = {-4 , 3 , 5 , -1};找出某几个连续的子序列其和最大。比如A0+A1 = -1 。A1+A2+A3+A4 = 3。而A2+A3=8;则A2 A3组成的数组即是所求。

 

求解方法1：

先写我自己的方法，不是动态规划，复杂度大概是O（n*n);

1,二维数组ret[ ][ ];用上面的例子中数组A[ ]= {-4 , 3 , 5 , -1}为例：

        ～  -4   3   5   1

0        0   0   0   0   0     //为了方便计算，第0行第0列均设为0

1        0  -4   3   5   1     //第1行表示子串长度为1时，包含该位置元素的子序列和数

2        0       -1   8   6     //第2行表示子串长度为2时，包含该位置元素的子序列和数

3        0             4   9

4        0                  5

其中，ret[i][j]位置的值为ret[i-1][j-1] + inp[j-1];

原理是，包含某个数x的子串长度为k的最大和数，等于x加上x之前的子串长度为k-1的最大和数;

即：上表中ret[4][5]=4,它是子序列长度为3，包含j=5处元素（即inp[4])的最大和数，是第5列以前的所有子序列长度为3-1=2的序列中，最大和数+该位的值：ret[3][4] + inp[4]=-1+5=4;

也就是说子序列长度为i的包含第j个位置的最大和数，是基于子序列长度为i-1的j前面的最大和数来求得的;

*/

#include<stdlib.h>
#include<stdio.h>
#define MAX 100 

int ret[MAX][MAX] = {{0}};//len+1行len+1列
int maxSubSeqSum(int inp[],int len){
        int maxret = 0;//最大的顺序子串和的值
        int i = 1;//第0行和第0列都为0
        for(;i<len+1;i++){
                int j=i;
                for(;j<len+1;j++){
                        ret[i][j] = ret[i-1][j-1] + inp[j-1];
                        //ret由于第0行第0列值都为0,所以inp需要j-1
                        if(ret[i][j] > maxret) maxret = ret[i][j];
                        printf("ret[%d][%d]=%d\n",i,j,ret[i][j]);
                }
        }
        return maxret;
}

int main(){
        int input[] = {1,-1,4,-3,2};
        int len = sizeof(input)/sizeof(int);
        int ret = maxSubSeqSum(input,len);
        printf("max sub sequence sum is:%d\n",ret);
        return 0;
}
/*
运行结果：

xu@xu-ThinkPad-X61:~/algorithm$ gcc maxSubSeqSum.c 
xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
ret[1][1]=1
ret[1][2]=-1
ret[1][3]=4
ret[1][4]=-3
ret[1][5]=2
ret[2][2]=0
ret[2][3]=3
ret[2][4]=1
ret[2][5]=-1
ret[3][3]=4
ret[3][4]=0
ret[3][5]=3
ret[4][4]=1
ret[4][5]=2
ret[5][5]=3
max sub sequence sum is:4

*/