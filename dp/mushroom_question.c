/*

采蘑菇问题

http://www.cnblogs.com/McQueen1987/p/3544875.html

查了下采蘑菇问题，用c写的相当困难，把自己绕进去了。

最后发现问题出在：采蘑菇的小姑娘起始位置是在数组之外的，而非数组的起始位置。所以在数组下标上折腾了好久。

 

采蘑菇问题描述引用以下博客：

http://blog.chinaunix.net/uid-26456800-id-3194477.html

【描述】

萌萌走出山路后，来到一片草地，发现过了草地有巨型蘑菇，于是他准备采摘一些。但是他对保护花草却很重视，他不忍心踩死花草，但为了蘑菇，他只能尽量少踩死几株。现在，草地上也像一条路，上面有n个点，第N个点就是巨型蘑菇所在地（上面没草），每个点上都有i株小草或j株蘑菇（也就是说有蘑菇就没有草），他每次最多跨越k步。

现在请为他选择一条路，在踩死尽量少的小草下，去采蘑菇。

P.S：默认出发点为：1，结束点为：N；

【输入格式】

第一行2个数：

n（表示这条路的长度），k（每次最多跨越数）

接下来第二行，n个数：

a[0],a[1],a[2],a[3]…a[n-1]（就是相应株数的小草，例如：

0 0 1 2 0【这是说第3个点有1株草，第4个点有2株草】)

（注意，如果小姑娘第一跳跨数为1,说明跳到了位置a[0]，

小姑娘的起始位置位于数组外） 

 

【输出格式】

一个数，最少踩到的小草株数：m

【输入样例】

5 2

0 1 1 2 0

【输出样例】

1

（只踩到了第3株）

【数据范围】

N,k<=10000;

A[i]<=100;

*/

#include<stdlib.h>
#include<stdio.h>

int step=2;
int inplen=5;

int FUN(int inp[],int start){
        if(start > (inplen -1))
                return 0;
        int tmp=0;
        int min=0xffff;
        int k=1;
        for(;k<=step;k++){
                tmp=FUN(inp,start+k);
                if(tmp<min) min=tmp;
                printf("start %d  = %d\n",start, tmp);
        }
        return min+inp[start];
}

int main(){
        int input[]={1,2,0,3,2};
        int ret=FUN(input,0);
        printf("-------%d\n",ret);
        return 0;
}

/*

输出：

xu@xu-ThinkPad-X61:~$ gcc caimogu.c
xu@xu-ThinkPad-X61:~$ ./a.out
start 4 = 0
start 4 = 0
start 3 = 2
start 3 = 0
start 2 = 3
start 4 = 0
start 4 = 0
start 2 = 2
start 1 = 2
start 4 = 0
start 4 = 0
start 3 = 2
start 3 = 0
start 1 = 3
start 0 = 4
start 4 = 0
start 4 = 0
start 3 = 2
start 3 = 0
start 2 = 3
start 4 = 0
start 4 = 0
start 2 = 2
start 0 = 2
-------3
xu@xu-ThinkPad-X61:~$

*/

