/*
 1-100的连续整数，乱序，丢失两个数，原地找出这两个数

问题描述：

1.比如inp={2，3，6，4，7}丢失了1，5，原地找出这两个数。

2.为了方便讨论这个连续数组从1开始到7截至，数组扩展到7位inp={2，3，6，4，7，0，0}；

 

解决：

1.利用数组元素值与数组下标关系，遍历整个数组，没有被遍历到的位置则为丢失元素所在位置，具体流程如下：

   1.从头开始读数组inp[0]=2，根据值2跳转到数组下标为inp[2-1]的位置，得到inp[2-1]=3；

   2.修改状态：这个过程中inp[0]位置跳出过，但未跳入过，用0表示这种状态。修改inp[0]=0；

   3.inp[2-1]位置被跳入过，表示该位置已经被访问过，根据数组元素值与数组下标的关系，可以证明存在元素2。用-1表示这种状态。修改inp[2-1]=-1；

   4.以此类推，直到最终数组元素类似{0,-1,-1,-1,0,-1,-1}，数组第0和第4位置元素为0，证明缺少元素1和5；
   */

   #include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int input[] = {2,3,6,4,7,0,0};//

void fun(int inp[], int size)
{
  assert(inp!=NULL && size>1);
  int i=0,j=0,pre=-1;
  int isNew = 1;//内循环while无法判断读到的新元素是跳转过来的（应该置为-1）还是外循环while新读入的（应置0）
  while(j<size){
   i=j;
   while(inp[i]!=-1)
   {
     if(inp[i]==0){inp[i]=-1;}//
     else{
        int pre=inp[i];
        if(isNew != 1){inp[i]=-1;}//该元素不0不-1，且是从其他元素跳转过来的，则该元素被访问过置-1，如果isNew==1（true）为新读入元素，证明未被访问过； 
        else{inp[i]=0;}
        i=pre-1;
     }
     isNew = 0;
   }
   isNew = 1;
   j++;
  }

  i=0;
  while(i<size){
   printf("final result ==== inp[%d] = %d\n",i,inp[i]);
   i++;
  }
}/*
改进以上方法：

1.其实我们并不必要存0和-1两种状态，当该位置被读到时置-1，如果没被读到什么都不做；

2.外循环会保证每个元素都被遍历到；

3.最终数组元素类似{2,-1,-1,-1,7,-1,-1}，则表示缺少数组第0和第4位置元素1和5；
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int input[] = {2,3,6,4,7,0,0};//filling input[] with 0;

void fun(int inp[], int size)
{
  assert(inp!=NULL && size>1);
  int i=0,j=0;
  int isNew = 1;//用于判断该位元素是从其他位置跳转过来的（则该位元素存在标记为-1）还是外循环i++自增到该位（则该位元素为新元素，不用标记为-1）
  while(j<size){
   i=j;
   while(inp[i]!=-1)
   {
        int tmp=inp[i];
        if(isNew != 1){inp[i]=-1;}//当inp[5]=0时，i=inp[i]-1=-1，所以判断inp[i]-1<0时读到值为0处，直接跳出
        if((tmp-1)<0) break;
        else i=tmp-1;
        isNew = 0;
   }
   isNew = 1;
   j++;
  }

   i=0;
   while(i<size){
   printf("finally ==== inp[%d] = %d\n",i,inp[i]);
   i++;
  }
}

/*
int main(){
  fun(input,7);
  return 0;
}

[root@admin Desktop]# ./a.out
finally ==== inp[0] = 2
finally ==== inp[1] = -1
finally ==== inp[2] = -1
finally ==== inp[3] = -1
finally ==== inp[4] = 7
finally ==== inp[5] = -1
finally ==== inp[6] = -1
[root@admin Desktop]# 
*/