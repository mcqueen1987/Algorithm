/*

最长递增子序列(Longest Increase Subsequence)

问题
给定一个长度为N的数组，找出一个最长的单调自增子序列（不一定连续，但是顺序不能乱）。例如：给定一个长度为6的数组A{5， 6， 7， 1， 2， 8}，则其最长的单调递增子序列为{5，6，7，8}，长度为4.

 

解决方案：

1,新建一个二维数组ret[ ][ ];以数组A[ ]= {2 , 1 , 5 , 9}为例：

        ～   2   1   5   9

0        0   0   0   0   0     //为了方便计算，第0行第0列均设为0

1        0   2   1   1   1    

2        0        E   5   5     //第2行表示子串长度为2，该位置及前面元素的长度为2的最长递增子序列

3        0             E   9     //E表示该位置往前都没有产度为3的递增子序列

4        0                  E

 

原理是：

1.长度为k的子串是否是递增子串与长度为k-1的子串是否是递增子串有关;

2.ret[2][3]=5  

   2表示：行号为2表示子串长度为2;

   3表示：位于第3列的数字5=A[2];

   5表示：位于第3列的数字5和其前面的各数，如果能组成长度为2的递增子序列，则在该位写                     min（所有可行序列的最大值）比如  123 和 125两个序列最大值分别为3和5,写入3;如                   果不能组成长度为2的递增序列，则写入ret[i][j]左侧数字，如果左侧为0或E则输入E;

3.如果第k行全都是E，表示改行起没有满足条件的递增子序列，则k-1为最长递增子序列的长度;

*/

#include<stdlib.h>
#include<stdio.h>
#define MAX 100 

int ret[MAX][MAX]={{0}};
int FUN(int inp[],int len){
        int i=1;//第0行全0
        int maxlen=0;
        int ERROR=0xfff;
        int isfinished;
        for(;i<=len;i++){
                int j=i;
                for(;j<=len;j++){
                        isfinished=1;//结束标志位
                        if(ret[i-1][j-1] != ERROR){
                                if(inp[j-1]>ret[i-1][j-1])  ret[i][j]=inp[j-1];
                                else{
                                        ret[i][j]=ERROR;
                                }
                        }//与左上角数比较，大于填inp，小于时不能组成递增序列填ERROR
                        else ret[i][j] = ERROR;//左上角数为ERROR时不可组成递增序列
                        if(ret[i][j-1] !=ERROR && ret[i][j-1] != 0){
                                if(ret[i][j-1]<ret[i][j]) ret[i][j]=ret[i][j-1];
                        }//左侧数不为0或ERROR时，填入左侧数和该数较小者
                        printf("ret[%d][%d]=%d\n",i,j,ret[i][j]);
                        if(ret[i][j] != ERROR) isfinished = 0;//如果还非ERROR数字表示未结束
                }
                if(isfinished == 1){//结束后保存结束时数组行数
                        maxlen = i-1;
                        break;
                }
        }
        return maxlen;
}

int main(){
        int input[]={5,6,7,1,2,8,3,4};
        int result = FUN(input, sizeof(input)/sizeof(int));
        printf("result is:%d\n",result);
        return 0;
}

/*

输出结果：

xu@xu-ThinkPad-X61:~/algorithm$ gcc maxascent1.c
xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
ret[1][1]=5
ret[1][2]=5
ret[1][3]=5
ret[1][4]=1
ret[1][5]=1
ret[1][6]=1
ret[1][7]=1
ret[1][8]=1
ret[2][2]=6
ret[2][3]=6
ret[2][4]=6
ret[2][5]=2
ret[2][6]=2
ret[2][7]=2
ret[2][8]=2
ret[3][3]=7
ret[3][4]=7
ret[3][5]=7
ret[3][6]=7
ret[3][7]=3
ret[3][8]=3
ret[4][4]=4095
ret[4][5]=4095
ret[4][6]=8
ret[4][7]=8
ret[4][8]=4
ret[5][5]=4095
ret[5][6]=4095
ret[5][7]=4095
ret[5][8]=4095
result is:4

*/