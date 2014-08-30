/*
求字符串长度 strlen（数组指针两种方式）

问题：

求字符串中所含有字符的个数（包括空格），即求字符串长度；
*/
#include <stdio.h>
#include <assert.h>

int _strlen(const char* str)
{
  assert(str != NULL);
  int i=0;
  for(;*str++!='\0';i++);
  //for(;str++!=NULL;i++);//有些说这句也可以，但执行结果是死循环，str++即使越界也未必为NULL;
  return i;
}

int _strlen2(const char str[])
{
  assert(str != NULL);
  int i=0;
  while(str[i] != '\0') i++;
  return i;
}

int main(){
  char tmp[] = "dsgrfr  s00w e324 sd! ";//不管是tmp[]还是tmp*,字符串最后都会有'\0'；
  int lenth = _strlen(tmp);
  int lenth2 = _strlen2(tmp);
  printf("the string length1 is:%d\n",lenth);
  printf("the string length2 is:%d\n",lenth2);
  return 0;
}
/*
输出如下：

 

[root@admin Desktop]# ./a.out
the string length1 is:22
the string length2 is:22
[root@admin Desktop]# 

*/

