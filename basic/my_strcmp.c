/*

问题：
原型：extern int strcmp(const char *s1,const char * s2);
所在头文件：string.h
功能：比较字符串s1和s2。
一般形式：strcmp(字符串1，字符串2)
说明：
当s1<s2时，返回为负数
当s1=s2时，返回值= 0
当s1>s2时，返回正数
即：两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇'\0'为止。如：
"A"<"B" "a">"A" "computer">"compare"
特别注意：strcmp(const char *s1,const char * s2)这里面只能比较字符串，不能比较数字等其他形式的参数。
 
实现：
*/

#include <stdio.h>
#include <assert.h>

int _strcmp(const char* str1,const char* str2)
{
  while(*str1++ == *str2++) if('\0' == *str1) return 0;
  str1--;str2--;
  return (*str1>*str2)?1:-1;
}

int main(){
  char s1[] = "computez";
  char s2[] = "computer";
  int ret = _strcmp(s1,s2);
  printf("ret is:%d\n",ret);
  return 0;
}

/*
[root@admin Desktop]# ./a.out
ret is:1
[root@admin Desktop]#

方法2：
*/

#include <stdio.h>
#include <assert.h>

int _strcmp(const char* str1,const char* str2)
{
  for(;*str1 == *str2;str1++,str2++)
    if('\0' == *str1) return 0;
  return (*str1>*str2)?1:-1;
}

/*
int main(){
  char s1[] = "computea";
  char s2[] = "computer";
  int ret = _strcmp(s1,s2);
  printf("ret is:%d\n",ret);
  return 0;
}

[root@admin Desktop]# ./a.out
ret is:-1
[root@admin Desktop]# 
*/




