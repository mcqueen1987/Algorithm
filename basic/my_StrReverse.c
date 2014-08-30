/*
反转字符串（数组和指针两种方式）

问题：

1.反转字符串，比如str=“hello world!!!"，反转后ret=“!!!dlrow olleh";

数组方式代码如下：
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* reverse(char inp[],int size){
        assert(inp != NULL && size>=0); //NULL代表空地址，null只是一个符号
        int i=0,j=size-1;
        while(i<j){
          char tmp=inp[i];
          inp[i]=inp[j];
          inp[j]=tmp;
          i++;j--;
        }
        return inp;
}

int main(){
  char input[]={'h','e','l','l','o','!','!','\0'};
  char* ret = reverse(input,7);
  printf("%s\n",ret);
  return 0;
}

/*
输出：

[root@admin Desktop]# ./a.out
!!olleh
[root@admin Desktop]#

指针方式代码如下：
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* reverse(char* inp)
{
  assert(inp != NULL);
  char* p=inp;
  char* q=inp;
  while(*q != '\0') q++;
  q-=1;
  while(p<q)
  {
    printf("    p = %c; q = %c\n ",*p,*q);
    char tmp = *p;
    *p = *q;
    *q = tmp;
    p++;
    q--;
  }
  return inp;
}

/*
int main(){
  char input[] = {'h','e','l','l','o',' ','b','a','b','y','!','!','\0'};
  char* ret = reverse(input);
  printf("result = %s\n",ret);
  return 0;
}

[root@admin Desktop]# ./a.out
    p = h; q = !
     p = e; q = !
     p = l; q = y
     p = l; q = b
     p = o; q = a
     p =  ; q = b
 result = !!ybab olleh
[root@admin Desktop]#

*/