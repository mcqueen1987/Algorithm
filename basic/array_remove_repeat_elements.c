/*
 一个有序数组（包含重复的），去除重复的数字然后输出

问题：

一个有序数组，其中包含重复的元素，去除重复的数字然后输出；

 

解决：

1.用指针比较方便，这里用数组下标来解决吧；

2.tmp类似指针指向不重复元素的最后一位；

3.num类似指针指向删除重复元素后的数组的最后一位；

代码如下：
*/

#include <stdio.h>
#include <stdlib.h>

int A[] =  {1,2,2,4,5,5,5,5,8,9,10,10};

void fun(int inp[],int size)
{
        int i=1,tmp=inp[0],num=1;
        printf("=====%d\n",inp[0]);
        for(;i<size;i++){
            if(tmp!=inp[i]){
                tmp=inp[i];
                printf("=====%d\n",inp[i]);
                inp[num++]=inp[i];
            }
        }
        while(num<size){
           inp[num++]=0;//后面的空位补0
        }
        for(i=0;i<size;i++){
           printf("result = %d\n",inp[i]);//结果打印
        }
}

int main(){
  fun(A,12);
  return 0;
}

/*
结果：
复制代码

[root@admin Desktop]# ./a.out
=====1
=====2
=====4
=====5
=====8
=====9
=====10
result = 1
result = 2
result = 4
result = 5
result = 8
result = 9
result = 10
result = 0
result = 0
result = 0
result = 0
result = 0
[root@admin Desktop]#
*/