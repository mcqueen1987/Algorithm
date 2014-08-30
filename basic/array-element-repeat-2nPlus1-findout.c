/*
长度为n的数组，有一个数重复出现了n/2+1次，找出（三种方法）

问题:
长度为n的数组，有一个数重复出现了n/2+1次，找出这个数；
 
解决：
比较直接的思路是遍历每个元素，让其与剩下其他元素比较，相等一次计数器sum++，直到sum=n/2+1为止；
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int fun(int inp[],int size)
{
  assert(inp!=NULL && size>1);
  int i=0,j=0;
  for(;i<size-1;i++){
     int sum = 1;
     for(j=i+1;j<size;j++){
        if(inp[i]==inp[j]) sum++;
     }
     if(size/2+1 == sum) return inp[i];
  }
  return -1;
}

int main(){
  int input[]={1,2,5,2,1,8,2,2,2,2};
  int ret = fun(input,10);
  printf("result = %d\n",ret);
  return 0;
}

/*

结果如下：

[root@admin Desktop]# ./a.out
result = 2
[root@admin Desktop]# 

 
方法2：
有n/2+1个重复的，那我们每次从数组中提取出来一对不同的数，到最后数组中剩余的，就只能是重复的数了；
比如{1,3,1,2,1};
依次提取出1/3 ， 1/2，剩余的就是1；
 
方案：
1.扫描一遍数组，找到不相同两个数，都置为-1；
2.最后剩下的，全都是重复数字；
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int fun(int inp[],int size)
{
  assert(inp != NULL && size>2);
  int i=0,j=0;
  for(;i<size-1;i++){//外循环，保证每个数都被遍历到
    printf("i==:%d\n",i);
    if(-1 == inp[i]) continue;//外循环遇到-1时，证明该数被选中并剔除过
    else{
      printf("in else ==:\n");
      for(j=i+1;j<size;j++){ //内循环，从i往后寻找与inp[i]不同的且不为-1的元素；
         if(inp[i] != inp[j] && -1 != inp[j]){
           printf("j==:%d\n",j);
           inp[i]=inp[j]=-1;//找到后都置为-1
           break;
         }
         if(size-1 == j) return inp[i];//如果j走到头都没找到，证明剩下的都与inp[i]重复
      }
    }
  }
  return -1;//失败，返回-1
}

/*
int main()
{
  int input[] = {1,2,3,1,2,1,1,6,1,1};
  int ret = fun(input,10);
  printf("the number is:%d\n",ret);
  return 0;
}

结果：
复制代码

[root@admin Desktop]# ./a.out
i==:0
in else ==:
j==:1
i==:1
i==:2
in else ==:
j==:3
i==:3
i==:4
in else ==:
j==:5
i==:5
i==:6
in else ==:
j==:7
i==:7
i==:8
in else ==:
the number is:1
[root@admin Desktop]# 

复制代码

 
方法3：
这个方法不是我想到的，感觉思路极其巧妙，扫描一遍即可，且复杂度只有0(n)，上面两个算法复杂度都为O(n2);
 
方案：充分利用出现次数超过一半这个特点，使用两个变量candidate和vote，分别代表候选人和票数，遍历数组按如下方式投票和更换候选人：

1.若当前数的值与候选人candidate一样，则把候选人的票数加1；

2.若当前数与候选人不一样,则把它的票数减1，如果减掉后票数小于0，则把候选人踢掉，用当前数作为新的候选人；

3.最后剩下的候选人就是出现次数超过一半的数。

 

算法的正确性证明： 数组中，数值相同的数都会投赞成票，数值不同的都会投反对票，有一个数出现的次数超过一半，其它数得到的反对票必然大于一半，所以其它数中，任何一个得票都会小于0，遭到淘汰。剩下来的只能是超过一半的那个数。
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int fun(int inp[],int size)
{
  assert(inp != NULL && size>2);
  int i=0,candidate=inp[0],vote=0;
  for(;i<size;i++){
    printf("i = %d; candidate is:%d; vote=%d\n",i,candidate,vote);
    if(inp[i] == candidate) vote++;
    else{
       vote--;
       if(vote < 0){
         candidate = inp[i];
         vote = 1;
       }
    }
  }
  return candidate;
}

/*
int main()
{
  int input[] = {1,2,3,1,2,1,1,6,1,1};
  int ret = fun(input,10);
  printf("the number is:%d\n",ret);
  return 0;
}

结果：
复制代码

[root@admin Desktop]# ./a.out
i = 0; candidate is:1; vote=0
i = 1; candidate is:1; vote=1
i = 2; candidate is:1; vote=0
i = 3; candidate is:3; vote=1
i = 4; candidate is:3; vote=0
i = 5; candidate is:2; vote=1
i = 6; candidate is:2; vote=0
i = 7; candidate is:1; vote=1
i = 8; candidate is:1; vote=0
i = 9; candidate is:1; vote=1
the number is:1
[root@admin Desktop]# 

*/