/*
http://www.cnblogs.com/McQueen1987/p/3550162.html

c语言，string库函数itoa实现：将int转换为char*

      原型：char  *itoa(int   value,char   *string)  
      功能:将整数value转换成字符串存入string,默认为十进制;
      说明：返回指向转换后的字符串的指针 

*/

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#define SWAP(a,b) (a)^=(b);(b)^=(a);(a)^=(b) 

char* strReverse(char* str){
        assert(str!=NULL);//if(NULL == str) return;
        char *front,*rear;
        front=rear=str;
        while(*rear) rear++;
        rear--;
        while(rear > front){
                SWAP(*rear,*front);
                front++;
                rear--;
        }
        return str;
}

char* myitoa(int value,char* result){
        assert(result!=NULL);
        bool isNegative=false;
        char* str = result;
        if(value<0){
                isNegative=true;
                value*=-1;
        }
        do{
                *str ++ = value % 10 + '0';
                printf("result is:%c\n",*(str-1));
        }while(value /= 10);
        if(isNegative) *str++ = '-';
        *str = '\0';
        return strReverse(result);
}

int main(){
        int value=-123456;
        char str[10]={};
        char* ret = myitoa(value,str);
        printf("result is:%s\n",ret);
        return 0;
}

/*

输出结果：

xu@xu-ThinkPad-X61:~/algorithm$ gcc itoa.c
xu@xu-ThinkPad-X61:~/algorithm$ time ./a.out
input is:-123456
result is:6
result is:5
result is:4
result is:3
result is:2
result is:1
result is:-123456

real	0m0.002s
user	0m0.000s
sys	0m0.000s

*/