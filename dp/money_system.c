/*

货币系统：如何用不同面值货币来构造一个确定的钱数？

http://www.cnblogs.com/McQueen1987/p/3537621.html

问题描述：

如何用货币系统中的货币来构造一个确定的面值，有多少种不同的方法？ 
举例来说, 使用一个货币系统 {2,3,5}产生 10元单位面值的一些可能的方法是:

5x2;

5x1+2x1+3x1;

3x2+2x2;

2x5……等等 

写一个程序来计算有多少种方法用给定的货币系统来构造一个确定的面值？最少需要多少张货币？

 

先写一个简单的程序：

1、货币系统面值为3元，5元和7元；

2、能否用上述面值组成总值为19的钱数？

写两种方法：

1.递归方法：用总值19递归减去面值{3,5,7};结果恰好=0则true，<0则19不能由{3,5,7}组成;

2.非递归方法：新建数组ret[ ],从第1位开始计算各位值，如果ret[i]==1，表示i可以由{3,5,7}构成，否则ret[i]=0;

C代码如下：
*/

#include<stdlib.h>
#include<stdio.h>

int cash(int sum,int v1,int v2,int v3)//递归，sum可以由v1,v2,v3组成,则返回1,
{
if(sum==0){return 1;}
if(sum<0) return 0;
return cash(sum-v1,v1,v2,v3)||
cash(sum-v2,v1,v2,v3)||
cash(sum-v3,v1,v2,v3);
}

int cash1(int sum,int v1,int v2,int v3)//非递归，数组result第i位1表示result[i]可以由v1v2v3组成

{
int result[50] = {1};
int i=1;
for(;i<=sum;i++)
{
if(i>=v1 && result[i-v1]==1) result[i]=1;
if(i>=v2 && result[i-v2]==1) result[i]=1;
if(i>=v3 && result[i-v3]==1) result[i]=1;

}
return result[sum];
}

 

int main(int argc, char* argv[])
{
int result = cash(4,3,5,7);
int result1 = cash1(19,3,5,7);
printf("ret=%d------ret1=%d\n",result,result1);
return 0;
}

/*

进一步的，如果能组成相应数值的钱数，那有多少种可能的组合情况？

FUN和FUN1一样，只是FUN1省去了一个累加器count更灵巧一切，供大家参考;
*/

#include <stdlib.h>
#include <stdio.h>

int count = 0;

void FUN(int sum, int mon[], int len){//mon数组组成sum的种类数
if(sum == 0) count ++;
if(sum <0 ) return;
int i =0;
for(;i<len;i++){
FUN(sum-mon[i], mon, len);
}
}
int FUN1(int sum, int mon[], int len){
int tmp = 0;
if(sum == 0) return 1;
if(sum <0 ) return 0;
int i =0;
for(;i<len;i++){
tmp +=FUN1(sum-mon[i], mon, len);
}
return tmp;
}
/*
int main(){
int mon[] = {2,3,5};
int sum = 20;
FUN(sum,mon,3);
printf("FUN!!!!%d\n", count);
printf("FUN1!!!!%d\n", FUN1(sum,mon,3));
return 0;
}

进一步的，在所有可能的组合情况中，所含元素个数最少的组合，其元素个数是几？

1.递归方式：把递归过程想象成一个n叉树，遍历n棵子树，返回其中最小的深度值;
*/

#include <stdio.h>
#define ERROR 0xffff //indicate error

int  sum = 10;//total money
int money[] = {3,1,2};
//求money[]能组成sum的所有可能组合，元素最少的，返回元素个数;
int FUN(int sum,int mony[],int lenth)
{
        if(sum==0){return 0;}
        if(sum<0)return ERROR;
        int tmp=ERROR;//元素最少的组合的元素个数
        int i=0;
        for(;i<lenth;i++){//找出树的最小深度
          if(tmp>FUN(sum-mony[i],mony,lenth))
          {
             tmp=FUN(sum-mony[i],mony,lenth);
          }
        }
       return tmp==ERROR?ERROR:(tmp+1);//子树向上返回需+1;
}


/*

int main()
{ 
        int arryLenth=sizeof(money)/sizeof(int);
        int result = FUN(sum,money,arryLenth);
        printf("%d\n",result);
        return 0; 
}

2.非递归方式：

1.二维数组result[ ][ ]有SUM+1行，2列;

2.第一列存放标志位。从第1行开始，如果i可以由mony[2,3,5]构成，则第i行的第一列==1;否则result[i][1]=0;

3.第二列存放最小元素个数：在所有可能的组合情况中，所含元素个数最少的组合，将其元素个数填入result[i][2]中;

*/

#include<stdio.h>
#include<stdlib.h>
#define SUM 10

int mony[]={3,5,2};
int result[SUM+1][2]={{1,0}};
int FUN(int SUM1,int mony1[],int mlen){//mlen length of mony[]
        int i=1,j=0;
        for(;i<=SUM1;i++){//i行j列
                int k=0;
                int minNum=0xffff;
                for(;k<mlen;k++){
                        if(i>=mony1[k] && result[i-mony1[k]][0]==1){
                                result[i][0]=1;
                                int tmp= result[i-mony1[k]][1]+1;
                                minNum=(minNum>tmp?tmp:minNum);
                        }
                }
                result[i][1]= minNum;
                printf("%d,%d\n",result[i][0],result[i][1]);
        }
        return result[SUM][1];
}

/*
int main()
{
        int len=sizeof(mony)/sizeof(int);
        int tmp=FUN(SUM,mony,len);
        printf("%d\n",tmp);
        return 0;
}
*/

