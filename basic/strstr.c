/*
http://www.cnblogs.com/McQueen1987/p/3549849.html

c语言，string库函数strstr实现

说明：
  原型：char *strstr(char *haystack, char *needle);
        
  用法：#include <string.h>
  
  功能：从字符串haystack中寻找needle第一次出现的位置（不比较结束符NULL)。
  
  说明：返回指向第一次出现needle位置的指针，如果没找到则返回NULL。
  
函数myStrstr是我自己写的;
函数standardStrstr是标准函数，可对比参考;

*/

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

char* myStrstr(char srce[],char check[]){
        assert(NULL != srce && NULL != check);
        char *sr,*ch,*ret;
        sr=srce;
        ch=check;
        while(*sr != '\0')
        {
                while(*sr && *sr != *ch) sr++;
                ret=sr;
                while(*sr && *ch && *sr == *ch)
                {
                        ch++;sr++;
                }
                if(*ch == '\0') return ret;
                if(*sr == '\0') return NULL;
                ch=check;
        }
        return NULL;
}

char* standardStrstr(const char *src,const char *dest){
        assert(src!=NULL && dest!=NULL);
        if(!*dest) return src;
        while(*src){
                int i=0;
                for(;*(src+i)==*(dest+i);i++){
                        if(!*(dest+i+1)) return src;
                }
                src++;
        }
        return NULL;
}

int main(){
        char sr[]={'a','b','c','\0'};
        char ch[]={'b','\0'};
        char *sr1="how are you baby";
        char *ch1="";
        char *ret= myStrstr(sr,ch);
        char *ret1= standardStrstr(sr1,ch1);
        if(NULL != ret){//如果打印null会返回段错误
                printf("result is:%c\n",*ret);
                printf("result1 is:%c\n",*ret1);
        }
        return -1;
}

