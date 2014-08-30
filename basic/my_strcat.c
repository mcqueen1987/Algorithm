/*
问题：字符串拼接 strcat

方法1：

开辟新空间，存放结果：
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* _strcat(char* str1, char* str2){
  assert(str1 != NULL && str2 != NULL);
  char* ret = (char*)malloc((strlen(str1)+strlen(str2)+1)*sizeof(char));
  char* tmp = ret;
  while(*str1 != '\0') *tmp++ = *str1++;
  while(*str2 != '\0') *tmp++ = *str2++;
  return ret;
}

int main(){
  char str1[] = "abc";
  char str2[] = "def";
  char tmp = _strcat(str1,str2);
  printf("result = %s\n",tmp);
  free(ret);
  return 0;
}

/*
结果：

[root@admin Desktop]# ./a.out
result = abcdef
[root@admin Desktop]# 

方法2：

不开辟空间，直接在str1后面追加拼接str2；

起初我代码这么写的：
*/

void _strcat2(char* str1,char* str2){
  while(*str1++ != '\0');
  while((*str1++ = *str2++) != '\0');
}

/*
int main(){
  char* str1 = "abc";
  char* str2 = "def";
  _strcat2(str1,str2);
  printf("result = %s\n",str1);
  return 0;
}

出现段错误，后来改char* str1 = "abc";为char str1[] = "abc"后问题解决；

然后出现的问题是，输出结果是"abc"而不是"abcdef"，在while(*str1++ != '\0');后添加str1--；解决。

 

下面讨论这两个问题：

1.   char str* 和char str[]区别.

下面说二者的不同之处。如下一段代码：

char ss[]="C++";  
ss[0]='c';                  // 合法  
char *p="C++";  
p[0]='c';                   // 合法但不正确 

问题出在p[0]='c'这一语句。该语句试图修改p指向的字符串的首个字符，出现了错误。

原因在于两种方式对字符数组操作的机制不同：使用char *p="C++"语句后，编译器在内存的常量区分配一块内存，保存”C++“这一字符串字面值，然后在栈上分配内存保存p，p的内容为"C++"的地址。p[0]='c'试图修改常量”C++“，程序当然就会崩溃了。而char ss[]="C++"语句，定义了一个数组，编译器为其在栈上分配了内存空间，因而可以进行修改操作。

因此，可以总结如下：
char ss[]定义了一个数组，ss可认为是一个常指针，ss不可改变，但ss指向的内容可以发生改变。
char *p定义了一个可变指针，p可以指向其它对象。但对于char *p=”abc“这样的情况，p指向的是常量，故内容不能改变。

 

再看看这个：

char* strA()  
{  
    char str[]="Hello";  
    return str;  
}

    调用该函数，不一定能够得到正确的结果。因为str定义了一个局部变量，存在于函数strA中的栈中。当函数调用完成后，临时空间被重置，为函数分配的栈空间被收回，str所指向的地址也就不存在了。

将上述代码修改为：

char *strA()  
{  
    char *str="Hello";  
    return str;  
}  

就没有问题。

 

问题2：++运算符怎么用
在while(*str1++ != '\0');这句，我们看看执行过程：
1.先判断 *str1 != '\0' 然后 str1++；
2.执行到最后一个的时候 *str1 == '\0'时, 还会执行一次 str1++；
3.所以最后str1指向的是'\0'之后的位置；
 
所以错误出在已经跳过str1最后的'\0'了，导致拼接以后结果是"a b c \0 d e f \0";
当printf到c时遇到‘\0‘停止输出。
*/
