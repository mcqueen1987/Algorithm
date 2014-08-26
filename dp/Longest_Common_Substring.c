/*

最长公共子串
想把算法描述清楚真是件费时费力费脑筋的事情啊，下面算法描述部分源自以下连接：

http://www.cnblogs.com/zhangchaoyang/articles/2012070.html

最长公共子串（LCS）

找两个字符串的最长公共子串，这个子串要求在原字符串中是连续的。其实这又是一个序贯决策问题，可以用动态规划来求解。我们采用一个二维矩阵来记录中间的结果。这个二维矩阵怎么构造呢？直接举个例子吧："bab"和"caba"(当然我们现在一眼就可以看出来最长公共子串是"ba"或"ab")

　　 b　　a　　b

c　　0　　0　　0

a　　0　　1　　0

b　　1　　0　　1

a　　0　　1　　0

我们看矩阵的斜对角线最长的那个就能找出最长公共子串。

不过在二维矩阵上找最长的由1组成的斜对角线也是件麻烦费时的事，下面改进：当要在矩阵是填1时让它等于其左上角元素加1。

　　 b　　a　　b

c　　0　　0　　0

a　　0　　1　　0

b　　1　　0　　2

a　　0　　2　　0

这样矩阵中的最大元素就是 最长公共子串的长度。

在构造这个二维矩阵的过程中由于得出矩阵的某一行后其上一行就没用了，所以实际上在程序中可以用一维数组来代替这个矩阵。

自个儿写的c的代码练手，贴出来求指正:

*/

#include <stdlib.h>
#include <stdio.h>
#define MAX 100
#include<string.h>

int ret[MAX][MAX]={{0}};
//求两串的最长公共子串;
int LCS(char stra[],int lena,char strb[],int lenb){
        int i=1,max=0,maxpt=0;//maxpt存放最大公共子串的末尾元素下标;
        for(;i<=lena;i++){
                int j=1;
                for(;j<=lenb;j++){
                        if(stra[i-1] == strb[j-1]) ret[i][j] = 1;//ret比stra，strb的下表多1;
                        ret[i][j] += ret[i-1][j-1];
                        if(ret[i][j]>max){
                                max=ret[i][j];
                                maxpt=i;
                        }
                        printf("ret[%d][%d]=%d\n",i,j,ret[i][j]);
                }
        }
        printf("max sub sequence string form %c to %c,%d numbers\n",stra[maxpt-max],stra[maxpt-1],max);
        return max;
}

int main(){
        char stra[] = "caba";
        char strb[] = "bab";
        int lena = strlen(stra)/sizeof(char);
        int lenb = strlen(strb)/sizeof(char);
        int ret = LCS(stra,lena,strb,lenb);
        printf("maxlen is:%d\n",ret);
        return 0;
}

/*

运行结果如下：

xu@xu-ThinkPad-X61:~/algorithm$ gcc LCS3.c
xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
ret[1][1]=0
ret[1][2]=0
ret[1][3]=0
ret[2][1]=0
ret[2][2]=1
ret[2][3]=0
ret[3][1]=1
ret[3][2]=0
ret[3][3]=2
ret[4][1]=0
ret[4][2]=2
ret[4][3]=0
max sub sequence string form a to b,2 numbers
maxlen is:2

*/