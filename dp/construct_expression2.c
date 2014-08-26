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

2,动态规划的非递归实现：

*/

#include <stdlib.h>
#include <stdio.h>
#define MAX 100
#include <string.h>

int ret[MAX][2]={{0}};//存储结果，第一列存结果，第二位存符号
void printarry(int ret[][2],int len){//输出二维数组
        int i=0;
        for(;i<len;i++){
                int j=0;
                for(;j<2;j++){
                        printf("ret[%d][%d]=%d,",i,j,ret[i][j]);
                }
                printf("\n");
        }
}

void FUN1(int *inp,int inplen,int ret[][2],int retlen){//非递归实现构造指定值的表达式
        int k=0;
        for(;k<inplen;k++){
                printf ( "==================\n" );
                int tmp[MAX][2]={{0}};
                int i=0;
                for(;i<retlen/2;i++){
                        tmp[2*i][0]=ret[i][0]+inp[k];
                        tmp[2*i][1]=(ret[i][1]<<1)+1;
                        tmp[2*i+1][0]=ret[i][0]-inp[k];
                        tmp[2*i+1][1]=(ret[i][1]<<1)+0;
                }
                memcpy(ret,tmp,sizeof(tmp));//把修改过的tmp重新写回ret;
                retlen = retlen*2;
                printarry(ret,retlen/2);
        }
}

void FUN(int *inp,int inpnum,int inplen,int ret[][2],int retlen){//刚开始写的，有递归有顺序，不伦不类
        printf ( "==================\n" );
        printarry(ret,retlen/2);
        if(inpnum == inplen) return;
        int tmp[MAX][2]={{0}};
        int i=0;
        for(;i<retlen/2;i++){
                tmp[2*i][0]=ret[i][0]+inp[inpnum];
                tmp[2*i][1]=(ret[i][1]<<1)+1;
                tmp[2*i+1][0]=ret[i][0]-inp[inpnum];
                tmp[2*i+1][1]=(ret[i][1]<<1)+0;
        }
        memcpy(ret,tmp,sizeof(tmp));
        FUN(inp,++inpnum,inplen,tmp,retlen*2);//这里其实用for循环可以代替，改进版如FUN1（）;
}
int main(){
        int input[] = {1,2,3,4,5};
//      FUN(input,0,4,ret,2);
        FUN1(input,4,ret,2);
        return 0;
}

/*
xu@xu-ThinkPad-X61:~/algorithm$ gcc 1234eq10.c
xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
==================
ret[0][0]=1,ret[0][1]=1,
ret[1][0]=-1,ret[1][1]=0,
==================
ret[0][0]=3,ret[0][1]=3,
ret[1][0]=-1,ret[1][1]=2,
ret[2][0]=1,ret[2][1]=1,
ret[3][0]=-3,ret[3][1]=0,
==================
ret[0][0]=6,ret[0][1]=7,
ret[1][0]=0,ret[1][1]=6,
ret[2][0]=2,ret[2][1]=5,
ret[3][0]=-4,ret[3][1]=4,
ret[4][0]=4,ret[4][1]=3,
ret[5][0]=-2,ret[5][1]=2,
ret[6][0]=0,ret[6][1]=1,
ret[7][0]=-6,ret[7][1]=0,
==================
ret[0][0]=10,ret[0][1]=15,
ret[1][0]=2,ret[1][1]=14,
ret[2][0]=4,ret[2][1]=13,
ret[3][0]=-4,ret[3][1]=12,
ret[4][0]=6,ret[4][1]=11,
ret[5][0]=-2,ret[5][1]=10,
ret[6][0]=0,ret[6][1]=9,
ret[7][0]=-8,ret[7][1]=8,
ret[8][0]=8,ret[8][1]=7,
ret[9][0]=0,ret[9][1]=6,
ret[10][0]=2,ret[10][1]=5,
ret[11][0]=-6,ret[11][1]=4,
ret[12][0]=4,ret[12][1]=3,
ret[13][0]=-4,ret[13][1]=2,
ret[14][0]=-2,ret[14][1]=1,
ret[15][0]=-10,ret[15][1]=0,
xu@xu-ThinkPad-X61:~/algorithm$

改进：

其实对于用二进制存储符号位，应该把二进制转换为符号位的代码写出来，直观些：

代码如下

*/
int biTofh(int bi,int len){//二进制转化为正负号
        int i=0;
        while(i<len){
                int tmp = 1;
                if((bi & (tmp<<(len-i-1))) != 0){//从最左位开始比较，该位是1
                        printf("+");
                }
                else{
                        printf("-");
                }
                i++;    
        }
        printf("\n");
        return 0;
}

int main(){
        int input[] = {1,2,3,4,5};
        biTofh(20,5);//20的二进制是10100共5位;
        return 0;
}
/*
输出结果：

xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
+-+--
*/

