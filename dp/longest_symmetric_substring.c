/*

c语言：最长对称子串（3种解决方案）

问题描述：

输入一个字符串，输出该字符串中最大对称子串的长度。例如输入字符串：“avvbeeb”，该字符串中最长的子字符串是“beeb”，长度为4，因而输出为4。

解决方法：中序遍历

一，全遍历的方法：

1.全遍历的方法，复杂度O（n3）;

2.遍历原字符串的所有子串，然后判断每个子串是否对称；

实现方法是：我们让一个指针i从头至尾遍历，我们用另一个指针j从j=i+1逐一指向i后面的所有字符。就实现了原串的所有子串的遍历（子串为指针i到j中间的部分）;

最后判断得到的子串是否对称即可;

 

二，此外还有个巧妙的方法，值得和大家分享一下（这是自己想的哦，转载请注明出处）：

原串是str1=“avvbeeb”，将其翻转得到str2=“beebvva”，然后错位比较：

1：               avvbeeb 

str2：beebvva             （上下对齐的元素是a;a比较）

 

2：              avvbeeb

str2：beebvva           （上下对齐的量元素av;va比较，不对称）

…………

11：              avvbeeb

str2：                  beebvva           （上下对齐的量元素beeb;beeb比较，得到最长对称子串）

…………

该方法要移动m+n次，每次元素比较个数从1到m不等，复杂度O（n2）;

 

三，最值得推荐的还是下面的方法，复杂度O（n）：

（以下都是自己想的自己写的，码字实在辛苦，转载请注明出处）

1.起始这道题分析起来非常扯淡，花了我两天的空闲时间才搞定！

2.分析过程如下：

3. 1-k位的元素中，其中最长对称子串（包含第k位元素）长度为f（n），我们讨论f（n+1）与f（n）的关系;

4.比如 b xxx a其中xxx代表对称子串，a为第n+1位元素，我们现在求f（n+1）;

5.我们分析所有情况：（我们用xxx代表n位对称子串）

          数组A存放字符数组;

          f（n）表示f（n）位元素对应子串长度;

   分析如下A[n+1]=a的子串长度值f（n+1）值是多少：

   1：bxxxa  ：A[n+1]位元素a与对称子xxx串前的一位元素b不同时;

     1.1: a与左相邻元素不同，即xxx=bxb时，bbxba不是对称子串，f（n+1）=1;

     1.2: a与左相邻元素相同，即xxx=axa时，baxaa，如果是对称子串，则x这个未知部分必须全部是a，即 

            baaaa，f（n+1）=f（n）+1，否则不是对称子串f（n+1）=1;

   axxxa  ：A[n+1]位元素a与对称子串前一位元素相同;

     2.这种情况f（n+1）位元素a与其左相邻元素是否相同都不影响f（n+1）的结果，

        比如：a bacab a        a aaaaa a

        串长：1 13135 7        1 23456 7        也就是xxx不论是何种情况的对称串，f（n+1）=f（n）+2;

 6.综上分析，串A[n+1]位的值f（n+1）只和串中第A[n]位字符以及第A[n-f（n）-1]有关;

    （5中分析的f（n+1）=1的情况可以忽略不考虑，因为最小对称子串值>=1)

    1: A[n+1]和A[n-f（n）-1]相同;

               a                           xxx             x              a           ：acca       aaaa      acdca

     A[n-f（n）-1]                                   A[n]      A[n+1]     

                                                          f（n）     f（n+1）    ：1124       1234      11134

      此时f（n+1）=f（n）+2;

     2: A[n+1]和A[n-f（n）-1]不同;A[n+1]和A[n]相同;

        如：  b                    xxx             a             a           ：bcacaa       baaaaa     

        A[n-f（n）-1]                          A[n]      A[n+1]        ：111332       112345

      此时f（n+1）与它前面有几个a有关;

综上分析代码如下：

*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int FUN(char *inp){//求最大对称子串长度
        int maxlen = 1;//最大长度
        int len=strlen(inp);
        int record[len];//存包含该位及前个元素最长对称子串
        record[0]=1;
        int i=1;
        for(;i<len;i++){
                int max =1;
                if((i-record[i-1]-1)>=0 && inp[i] == inp[i-record[i-1]-1]){
                        max = max>(record[i-1] + 2)? max:(record[i-1] +2);
                }
                int k = 1;
                while(inp[i] == inp[i-k]){
                        k++;
                }
                max = max>k? max:k;
                record[i] = max;
                printf("----- is:%d\n",record[i]);
                if(record[i]>maxlen) maxlen=record[i];
        }
        return maxlen;
}

int main(){
        char *input="abadddkeipdldlfk";
        int retlen = FUN(input);//从前向后递归
        printf("max length is:%d\n",retlen);
        return 0;
}

/*

xu@xu-ThinkPad-X61:~/algorithm$ gcc LongSunmetricSub.c 
xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
----- is:1
----- is:3
----- is:1
----- is:2
----- is:3
----- is:1
----- is:1
----- is:1
----- is:1
----- is:1
----- is:1
----- is:3
----- is:1
----- is:1
----- is:1
max length is:3

*/






