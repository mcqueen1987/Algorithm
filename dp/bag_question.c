/*

http://www.cnblogs.com/McQueen1987/p/3538123.html

装书包问题：从不同重量书中选任意本装入书包，刚好达到书包限重

装书包问题：

从不同重量书中选任意本装入书包，刚好达到书包限重;

1,mony[ ]存放多种不同重量的书;

2,书包限重sum;

3,从mony[ ]中选取任意组合，使总重恰好等于sum;

4,输出所有可能组合;

*/

#include<stdlib.h>
#include<stdio.h>

int sum=10;
//计算mony中所有能组成sum的元素组合，元素不得重复，输出所有组合情况
//start为遍历数组mony[]的起始位置：
void FUN(int mony[],int len,int ret[],int start){//len是mony长度
        if(ret[len]>sum) return;
        if(ret[len]==sum){//ret[]最后一位存和数
                int i=0;
                for(;i<=len;i++){
                        if(ret[i]!=0){
                                printf("----%d",ret[i]);
                        }
                }
                printf("\n");
                return;
        }
        int i=start;
        for(;i<len;i++){
                ret[i]=mony[i];//保存路径
                ret[len]+=mony[i];//ret最后一位存和数
                FUN(mony,len,ret,i+1);
                ret[i]=0;//返回上一步恢复路径
                ret[len]-=mony[i];//返回上一步恢复和数
        }
}

int main()
{
        int money[]={1,3,5,2,4};
        int ret[5+1]={0};
        FUN(money,5,ret,0);
        return 0;
}       

/*

输出结果如下：

xu@xu-ThinkPad-X61:~/algorithm$ ./exe beibaobuchfu.c

----1----3----2----4----10
----1----5----4----10
----3----5----2----10

*/