/*

问题1：实现pow(int x, int y) ,即x的y次方

x的y次方就是有y个x连续乘机，代码如下：

*/

#include <stdio.h>
#include <stdlib.h>

int my_pow(int x,int y){
        if(x==0) return 0;
        int ret=x,i=1;
        for(;i<y;i++){
            ret=ret*x;
            printf("y=%d;ret=%d\n",i+1,ret);
        }
        return ret;
}

int main(){
  int tmp = my_pow(2,10);
  printf("====%d\n",tmp);
  return 0;
}

/*
结果
复制代码

[root@admin Desktop]# ./a.out
y=2;ret=4
y=3;ret=8
y=4;ret=16
y=5;ret=32
y=6;ret=64
y=7;ret=128
y=8;ret=256
y=9;ret=512
y=10;ret=1024
====1024
[root@admin Desktop]# 

复制代码

 

改进：

1.我们发现上面的方法，如果y=100，则乘法计算要进行100次，复杂度较高；

2.我们能否利用上次的计算结果，来简化计算？

   比如2^4,用2*2*2*2=4*2*2=8*2=16;

   上式中共进行了三次乘法;

   把所有重复计算剔除：2^4=2^2*2^2=4*4=16，该过程共计算两次乘法2^2，4*4；

   乘法次数由3次降为2次；

3.幂运算往往容易越界，比如int最大能表示2147483647，如果算出结果超出这个范围就出错了。

   1.对越界做判断和检查；

   2.用合适的数据类型表示结果，貌似C里最大的整形数应该是long double；

 

以下通过递归方式实现以上思想：
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

long double fun(long double x,long double y)
{
  printf("ret is x=%Lf ; y=%Lf\n",x,y);//long double输出用%Lf
  assert(x != 0 && y >= 0);
  if(0 == y) return 1;
  if(1 == y) return x;
  if(2 == y) return x*x;
  long double tmp = 0;
  if(y/2 != 0) tmp = x*fun(x,y-1);
  else tmp = fun(x*x,y/2);
  if(tmp>0){ //如果越界可能出现负数，至于如何更合理判断越界情况，现在还没想好
     printf("TMP > 0 IS: %Lf\n",tmp);
     return tmp;
   }
  else{
     printf("TMP < 0 IS: %Lf\n",tmp);
     return 0;
  }
}

int main(){
  long double ret = fun(10,30);
  printf("result = %Lf\n",ret);
  return 0;
}

/*

看看洋气的输出结果：
复制代码

[root@admin Desktop]# ./a.out
ret is x=10.000000 ; y=30.000000
ret is x=10.000000 ; y=29.000000
ret is x=10.000000 ; y=28.000000
ret is x=10.000000 ; y=27.000000
ret is x=10.000000 ; y=26.000000
ret is x=10.000000 ; y=25.000000
ret is x=10.000000 ; y=24.000000
ret is x=10.000000 ; y=23.000000
ret is x=10.000000 ; y=22.000000
ret is x=10.000000 ; y=21.000000
ret is x=10.000000 ; y=20.000000
ret is x=10.000000 ; y=19.000000
ret is x=10.000000 ; y=18.000000
ret is x=10.000000 ; y=17.000000
ret is x=10.000000 ; y=16.000000
ret is x=10.000000 ; y=15.000000
ret is x=10.000000 ; y=14.000000
ret is x=10.000000 ; y=13.000000
ret is x=10.000000 ; y=12.000000
ret is x=10.000000 ; y=11.000000
ret is x=10.000000 ; y=10.000000
ret is x=10.000000 ; y=9.000000
ret is x=10.000000 ; y=8.000000
ret is x=10.000000 ; y=7.000000
ret is x=10.000000 ; y=6.000000
ret is x=10.000000 ; y=5.000000
ret is x=10.000000 ; y=4.000000
ret is x=10.000000 ; y=3.000000
ret is x=10.000000 ; y=2.000000
TMP > 0 IS: 1000.000000
TMP > 0 IS: 10000.000000
TMP > 0 IS: 100000.000000
TMP > 0 IS: 1000000.000000
TMP > 0 IS: 10000000.000000
TMP > 0 IS: 100000000.000000
TMP > 0 IS: 1000000000.000000
TMP > 0 IS: 10000000000.000000
TMP > 0 IS: 100000000000.000000
TMP > 0 IS: 1000000000000.000000
TMP > 0 IS: 10000000000000.000000
TMP > 0 IS: 100000000000000.000000
TMP > 0 IS: 1000000000000000.000000
TMP > 0 IS: 10000000000000000.000000
TMP > 0 IS: 100000000000000000.000000
TMP > 0 IS: 1000000000000000000.000000
TMP > 0 IS: 10000000000000000000.000000
TMP > 0 IS: 100000000000000000000.000000
TMP > 0 IS: 1000000000000000000000.000000
TMP > 0 IS: 10000000000000000000000.000000
TMP > 0 IS: 100000000000000000000000.000000
TMP > 0 IS: 1000000000000000000000000.000000
TMP > 0 IS: 10000000000000000000000000.000000
TMP > 0 IS: 100000000000000000000000000.000000
TMP > 0 IS: 1000000000000000000000000000.000000
TMP > 0 IS: 9999999999999999999731564544.000000
TMP > 0 IS: 99999999999999999997315645440.000000
TMP > 0 IS: 999999999999999999955976585216.000000
result = 999999999999999999955976585216.000000
[root@admin Desktop]# 

复制代码

显然后面的结果不对，但是没有出现负数的情况。疑惑，烦请高人指点一二。
*/

