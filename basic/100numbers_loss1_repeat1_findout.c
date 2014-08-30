/*
 1-100的连续整数，乱序，重复一个数，丢失一个数，原地找出这两个数

问题描述：

1.比如inp={3,1,2,5,3}丢失了4，有两个3，原地找出这两个数。

2.为了方便起见这个连续数组从1开始；

 

解决：

1.元素3放在数组inp[3-1]的位置，该位置原来存的是2，再把2存入inp[2-1]……

状态栏：     {0   -1     }     {0-1-1    }     {-1-1-1    }    {-1-1-1  -1}   {-1-1-1   -1}   

                {3,1,2,5,3}     {3,1,2,5,3}     {3,1,2,5,3}     {3,1,2,5,3}     {3,1,2,5,3}     

结果栏：     {      3     }     {   2 3     }     { 1 2 3     }     { 1 2 3   5}     { 1 2 3   5}    

以上过程某个位置元素有两种状态，分别标识为0和1：比如第一个元素3，跳转到inp[3-1]后，它原来的位置inp[1-1]被访问过，却没有被跳转过（跳转到该位置），标识状态为0，inp[3-1]被跳转过，标识状态为-1；

 

1.input：int inp[]={3,1,2,5,3}；

2.output：重复元素int  cf，丢失元素int  loss；

3.有个问题，比如{3，6，5，4，1}，3跳到5跳到1，最后又跳回3。这是一个虚幻过程，中间6和4没有访问过。如何保证每个元素都被遍历？我们用两层循环嵌套；

4.下一跳元素可能有三种状态：
           0：被访问过，却没有被跳转过
          -1：被跳转过
    >0的数：既没被访问过，又没有被跳转过

如果下一跳是0，表示以前该元素跳出去过，但是没有跳到这里过，现在跳过来了，就改为-1；

如果下一跳是-1，表示该元素以前被访问过，又访问一次，可见是重复元素；

如果下一跳非0非-1，表示是新元素，跳到该元素，执行下一次循环；

 

思路大致如上，但是代码写起来费了老大力气了，看来还是底子薄，想提速还要多写啊！！
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int cf=-1,loss=-1;  //cf：重复的元素  loss：丢失的元素
int input[] = {2,3,6,4,2,1,7};

void fun(int inp[], int size)
{
  assert(inp!=NULL && size>1);
  int pre=inp[0],aft=inp[pre-1],i=0,j=pre-1;  //pre：当前元素值   aft：下一跳元素的值
  inp[0]=0;
  while(j<size){        //外层循环保证每个元素都被遍历到
   i=j;
   printf("outside loop : j = %d\n",j);
   while(inp[i]!=-1)    //内层循环是根据元素和数组下标的关系进行跳转循环
   {
     printf("inp[%d] = %d\n",i,inp[i]);
     if(inp[i]==0){     //0表示该位置i跳转到其他位置过，但其他位置从未跳转到此位置；-1表示其他元素跳转到该位置i过
         printf("inp[%d] == 0 is changed -1\n",i);
         inp[i]=-1;break;
     }
     else{
         pre=inp[i];    aft=inp[pre-1];
         printf("pre=%d ; aft = %d\n",pre,aft);
         if(aft==-1){    //下一跳为-1表示下一跳元素被访问过，表明inp[i]是重复元素
           cf=inp[i];
           inp[i]=0;     //该位置状态改变
           printf("doubled element = , %d\n",cf);
           break;
         }
         else{           //下一跳不为0，-1表示下一跳元素未被访问，循环到下一跳；
           inp[i]=-1;
           i=pre-1;
         }
     }
   }
   j++;
  }
  i=0;
  while(inp[i]==-1) i++;
  loss = i+1;
  printf("loss element is =  %d\n",loss);
}

int main(){
  fun(input,7);
  return 0;
}

/*
看看结果：
复制代码

[root@admin Desktop]# ./a.out
outside loop : j = 1
inp[1] = 3
pre=3 ; aft = 6
inp[2] = 6
pre=6 ; aft = 1
inp[5] = 1
pre=1 ; aft = 0
inp[0] = 0
inp[0] == 0 is changed -1
outside loop : j = 2
outside loop : j = 3
inp[3] = 4
pre=4 ; aft = 4
outside loop : j = 4
inp[4] = 2
pre=2 ; aft = -1
doubled element = , 2
outside loop : j = 5
outside loop : j = 6
inp[6] = 7
pre=7 ; aft = 7
loss element is =  5
[root@admin Desktop]

复制代码

输入是：input[] = {2,3,6,4,2,1,7};

doubled element =  2

loss element is =  5

恩  目前为止没问题！
*/