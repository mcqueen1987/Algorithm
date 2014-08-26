/*
构造和为指定值的表达式：±1±2±3±4±5=3 确定符号

问题描述：

在1,2,3,4,5中任意添加正负号，使结果等于3.例如：±1±2±3±4±5=3;

解决方案：

写出递归方程：

1：f（n）表示添加数A（n）后得到结果B（n）：比如n=1时，f（1）就是添加A（0）=1后B（n）={{1,+}，{-1,-}};

2：f（n+1）表示添加数A（n+1）后得到结果B（n+1）：比如n=2时，f（2）就是添加A（1）=2后B（n+1）= 

     {{1+2=3,++}，{1-2=-1,+-}，{-1+2=1,-+}，{-1-2=-3,--}};

3：其中符号++ ;+- ;用四位二进制数表示+为1，-为0。+-+-+即10101=21;

用递归和非递归两种方法实现：

1,动态规划的递归实现：

*/


#include <stdlib.h>
#include <stdio.h>
#define MAX 100
#include <string.h>

int fuhao = 0;//符号位
//inp：输入数据，inpn：输入数据inp的正需处理的数据下标，inplen：inp的数据个数，tar：和数，即指定值;
int FUN2(int *inp,int inpn,int inplen,int tar){
        if(inpn >= inplen){
                if(tar == 0){
                return 1;
                }
                else{return 0;}
        }
        if(FUN2(inp,inpn+1,inplen,tar-inp[inpn])){//tar=10=F(234)-1
                fuhao = (fuhao<<1)+1;
                printf("--------inp[%d]=%d is + ,fuhao=%d\n",inpn,inp[inpn],fuhao);
                return 1;
        }
        if(FUN2(inp,inpn+1,inplen,tar+inp[inpn])){//tar=10=F(234)+1;
                fuhao = (fuhao<<1)+0;
                printf("--------inp[%d]=%d is - ,fuhao=%d\n",inpn,inp[inpn],fuhao);
                return 1;
        }
        return 0;
}

int main(){
        int input[] = {1,2,3,4,5};
        //      FUN(input,0,4,ret,2);
        //      FUN1(input,4,ret,2);
        FUN2(input,0,5,3);
        printf("------%d\n",fuhao);
        return 0;
}

/*xu@xu-ThinkPad-X61:~/algorithm$ gcc 1234eq10.c
xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
--------inp[4]=5 is + ,fuhao=1
--------inp[3]=4 is - ,fuhao=2
--------inp[2]=3 is + ,fuhao=5
--------inp[1]=2 is - ,fuhao=10
--------inp[0]=1 is + ,fuhao=21
------21


改进：

函数体内有个全局变量int fuhao;

现在用函数返回值来存储符号值，返回-1表示结果不对，返回0表示符号位是“-”，1表示“+”;

代码如下：
*/

int FUN2(int *inp,int inpn,int inplen,int tar){
        if(inpn >= inplen){
                if(tar == 0){
                        return 0;
                }
                else{return -1;}
        }

        int fuhao = FUN2(inp,inpn+1,inplen,tar-inp[inpn]);
        if(fuhao!=-1){//tar=10=F(234)-1
                fuhao = (fuhao<<1)+1;
                printf("--------inp[%d]=%d is + ,fuhao=%d\n",inpn,inp[inpn],fuhao);
                return fuhao;
        }
        fuhao = FUN2(inp,inpn+1,inplen,tar+inp[inpn]);
        if(fuhao!=-1){//tar=10=F(234)+1;
                fuhao = (fuhao<<1)+0;
                printf("--------inp[%d]=%d is - ,fuhao=%d\n",inpn,inp[inpn],fuhao);
                return fuhao;
        }
        return -1;
}

