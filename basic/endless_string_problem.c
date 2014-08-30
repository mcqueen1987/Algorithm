/*
无穷字符串问题--CSDN上的面试题（原创）

网上看到一道奇怪的题，分享一下：http://hero.csdn.net/Question/Details?ID=307&ExamID=302

    发布公司：CSDN
    有 效 期：2014-02-26至2014-03-28

    难 度 等 级：
    答 题 时 长：120分钟
    编程语言要求：C C++ Java C#

题目详情

假设字符串A=“^__^" (4个字符），B="T.T"（3个字符）,我们进行如下步骤：

(1) 把A接到B的后面得到字符串C (按样例C="T.T^__^")

(2) 令A=B,B=C

不断重复步骤（1）（2）得到的字符串是无穷的。

求这个串的第n个字符。（0<n<2^63)

 

分析：

1.不断重复步骤（1）（2）得到的字符串是无穷的！！现在要求的是这个无穷串的第n个字符！

2.（0<n<2^63)不是个小数，要记录整个过程，考虑到节省空间，最好用二进制来记录;

3.简单举例：n=8时

   字符串为：

    1：                                A=“^__^"                B="T.T"   

    2：C="T.T^__^"            A="T.T"                  B="T.T^__^"  

    3：C="T.T^__^T.T"      A=="T.T^__^"         B="T.T^__^T.T"  

     …………

     上式中B="T.T^__^T.T"  ，第n=8位是符号”T“;

 

算法分析：

1.借鉴计算机网络通信的编码思想，我们用四位二进制数1100表示A,三位二进制数100表示B;

2.用二进制位来记录这个长字符串，原来是 B="T.T^__^T.T" ，现在存为B=”1001100“;

3.如何通过B=”1001100“判断B的第n位是那个字符呢？

   当n=6时

    B=”1001100“的第6位是0,则往前走k位遇到第一个”1“，然后判断1前面是1还是0,如果两个1则表明第n个字符是属于串A的（A=1100），如果前面是0,只有一个1则在B内（B=100）;然后通过移动的位数k来判断n是A或B串的第几个字符;

还有另外一个思路：

就是用两个二进制数，一个用来判断n位字符属于A还是属于B，另一个二进制数判断n位字符属于A或B的第几个符号;

比如A=1111,B=000,当n位是1就知道是A，0就表示该符号在B内;

然后用A=1000,B=100表示在A或B的第几位，

比如  10001001000

                      |     （左侧符号指向0,我们就向前读取，由几个0就是串的第几位）                              

 

基本思路不是很难，但代码一写陷阱多多！下面就献上代码把：

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char FUN(const char *A,char *B,int N){
        int lenA = strlen(A);
        int lenB = strlen(B);
        if(lenA<3 || lenB<3) return '\0';//长度小于3时候retA，retB的编码不支持
        int retA = 1<<(lenA-1);//用三位二进制100表示A，四位二进制1100表示B.
        int retB = 3<<(lenB-2);
//      printf("reta=%d,retb=%d",retA,retB);
        while(lenB < N){
                int retC = ((retB<<(lenA)) | retA);//C=BA;
                int lenC = lenA + lenB;
                retA = retB;lenA = lenB;
                retB = retC;lenB = lenC;
        }
        int k = lenB - N;
        if((retB & (1<<k))){//该位bit==1
                if((retB & (1<<(k+1)))) return B[1];//左侧bit==11,B,N=2
                else{//左侧bit==0
                        if((retB & (1<<(k-1)))) return B[0];//右侧bit=1,011,B,N=1
                        else return A[0];//右侧bit=0,010,A,N=1
                }
        }
        else{//该位==0
                int count = 0;
                while(!(retB & (1<<k))){
                        count++; k++;
                }
                if((retB & (1<<(k+1)))) return B[count+1];
                else  return A[count];
        }
        return 'x';
}

int main(){
        char *A = "^__^";
        char *B = "T.T";
        int N = 20;
        int i=1;
        for(;i<=N;i++){
                char ret = FUN(A,B,i);
                printf("i=%d,ret=%c\n",i,ret);
        }
        return 0;
}

/*

输出结果

xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
i=1,ret=T
i=2,ret=.
i=3,ret=T
i=4,ret=^
i=5,ret=_
i=6,ret=_
i=7,ret=^
i=8,ret=T
i=9,ret=.
i=10,ret=T
i=11,ret=T
i=12,ret=.
i=13,ret=T
i=14,ret=^
i=15,ret=_
i=16,ret=_
i=17,ret=^
i=18,ret=T
i=19,ret=.
i=20,ret=T

恩 welldone！！

*/



