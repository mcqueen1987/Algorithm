/*

http://www.cnblogs.com/McQueen1987/p/3538123.html

装书包问题：从不同重量书中选任意本装入书包，刚好达到书包限重

装书包问题：

从不同重量书中选任意本装入书包，刚好达到书包限重;

1,mony[ ]存放多种不同重量的书;

2,书包限重sum;

3,从mony[ ]中选取任意组合，使总重恰好等于sum;

4,输出所有可能组合;


算法非递归实现方法：

1.举个栗子：inp[ ]={1,2,3,4}，sum=6,计算组成sum所有可能不重复元素组合，输出最小个数值;

2,ret[sum+1]存放结果：当{1,2,3,4}中任意k个元素可以组成i时（比如2和4能组成6，此时k=2），ret[i]存放元素个数k;

3,ret[sum+1]存放的值就是可以组成sum的组合中元素个数最小的个数值;



*/

#include<stdlib.h>
#include<stdio.h>

void FUN(int inp[],int len, int*ret, int lenret){
        int i=0;
        for(;i<len;i++){
                int tmp=inp[i];
                int j=0;
                for(;j<lenret;j++){
                        if(ret[j]!=0 && (j+tmp)<lenret){
                                if(ret[j+tmp]==0){
                                        ret[j+tmp]=(ret[j]+1);
                                        continue;
                                }
                                ret[j+tmp]=((ret[j]+1)>ret[j+tmp]?
                                                ret[j+tmp]:(ret[j]+1));
                        }
                }
        }
}

int main(){
        int input[]={1,2,3,4};
        int sum=6;
        int result[6+1]={1};
        FUN(input,4, result, sum+1);
        int k=0;
        for(;k<7;k++){
                printf("%d++",result[k]);
        }
        return 0;
}

/*

输出结果：

xu@xu-ThinkPad-X61:~/algorithm$ ./exe suibian.c

1++2++2++2++2++3++3++

说明最少3个元素组成6;

*/