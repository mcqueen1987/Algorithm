/*

最长公共子序列：非递归实现

http://www.cnblogs.com/McQueen1987/p/3556148.html

想把算法描述清楚真是件费时费力费脑筋的事情啊，下面的算法描述部分源自以下连接：

http://www.cnblogs.com/zhangchaoyang/articles/2012070.html

感谢哥么写的文字描述的很清晰;

我用两种方式实现“最长公共子序列”算法：

1.动态规划的顺序实现;

2.动态规划的递归实现;

3.都用c实现，linux平台编译，代码附在文章末尾;

 

                                         最长公共子序列

最长公共子序列与最长公共子串的区别在于最长公共子序列不要求在原字符串中是连续的，比如ADE和ABCDE的最长公共子序列是ADE。

我们用动态规划的方法来思考这个问题如是求解。首先要找到状态转移方程：

符号约定，C1是S1的最右侧字符，C2是S2的最右侧字符，S1‘是从S1中去除C1的部分，S2'是从S2中去除C2的部分。

LCS(S1,S2)等于下列3项的最大者：

（1）LCS（S1，S2’）

（2）LCS（S1’，S2）

（3）LCS（S1’，S2’）--如果C1不等于C2； LCS（S1'，S2'）+C1--如果C1等于C2；

边界终止条件：如果S1和S2都是空串，则结果也是空串。

下面我们同样要构建一个矩阵来存储动态规划过程中子问题的解。这个矩阵中的每个数字代表了该行和该列之前的LCS的长度。与上面刚刚分析出的状态转移议程相对应，矩阵中每个格子里的数字应该这么填，它等于以下3项的最大值：

（1）上面一个格子里的数字

（2）左边一个格子里的数字

（3）左上角那个格子里的数字（如果 C1不等于C2）； 左上角那个格子里的数字+1（ 如果C1等于C2）

举个例子：

 　　　　  G　　C　　T　　A

　　 0　　0　　0　　0　　0

G　 0　　1　　1　　1　　1

B　 0　　1　　1　　1　　1

T　 0　　1　　1　　2　　2

A    0　　1　　1　　2　　3

填写最后一个数字时，它应该是下面三个的最大者：

（1）上边的数字2

（2）左边的数字2

（3）左上角的数字2+1=3,因为此时C1==C2

所以最终结果是3。

在填写过程中我们还是记录下当前单元格的数字来自于哪个单元格，以方便最后我们回溯找出最长公共子串。有时候左上、左、上三者中有多个同时达到最大，那么任取其中之一，但是在整个过程中你必须遵循固定的优先标准。在我的代码中优先级别是左上>左>上。

2.下面是非递归方式实现的代码：

*/

#include <stdlib.h>
#include <stdio.h>
#define MAX 100
#define max(a,b) (a>b)?a:b
#include<string.h>

int ret[MAX][MAX]={{0}};
int LCS(char stra[],int lena,char strb[],int lenb){
        int i=1;
        for(;i<=lena;i++){
                int j=1;
                for(;j<=lenb;j++){
                        int same = 0;
                        if(stra[i-1] == strb[j-1]) same = 1;
                        //ret比stra，strb的下标多1;
                        int tmp = max(ret[i-1][j],ret[i][j-1]);
                        ret[i][j] = max(tmp,(ret[i-1][j-1] + same));
                        printf("ret[%d][%d] = %d same=%d ,tmp=%d\n",i,j,ret[i][j],same,tmp);
                }
        }
        return ret[lena][lenb];
}

int main(){
        char stra[] = "gccct";
        char strb[] = "gcgc";
        int lena = strlen(stra)/sizeof(char);
        int lenb = strlen(strb)/sizeof(char);
        int ret = LCS(stra,lena,strb,lenb);
        printf("ret is:%d,lena=%d,lenb=%d\n",ret,lena,lenb);
        return 0;
}
/*

运行结果：

xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
ret[1][1] = 1 same=1 ,tmp=0
ret[1][2] = 1 same=0 ,tmp=1
ret[1][3] = 1 same=1 ,tmp=1
ret[1][4] = 1 same=0 ,tmp=1
ret[2][1] = 1 same=0 ,tmp=1
ret[2][2] = 2 same=1 ,tmp=1
ret[2][3] = 2 same=0 ,tmp=2
ret[2][4] = 2 same=1 ,tmp=2
ret[3][1] = 1 same=0 ,tmp=1
ret[3][2] = 2 same=1 ,tmp=2
ret[3][3] = 2 same=0 ,tmp=2
ret[3][4] = 3 same=1 ,tmp=2
ret[4][1] = 1 same=0 ,tmp=1
ret[4][2] = 2 same=1 ,tmp=2
ret[4][3] = 2 same=0 ,tmp=2
ret[4][4] = 3 same=1 ,tmp=3
ret[5][1] = 1 same=0 ,tmp=1
ret[5][2] = 2 same=0 ,tmp=2
ret[5][3] = 2 same=0 ,tmp=2
ret[5][4] = 3 same=0 ,tmp=3
ret is:3,lena=5,lenb=4



*/