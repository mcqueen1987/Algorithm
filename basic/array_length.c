/*
http://www.cnblogs.com/McQueen1987/p/3546544.html

求字符数组的长度
*/

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

int count(const char * str){//计算数组长度
        if(NULL == str) return -1;
        int len=0;
        char const *pt= str;
        while(*pt++)
                len++;  
        return len;
}

int count1(const char* str){//计算数组长度
        assert(str!=NULL);
        const char* pt=str;
        while(*pt) pt++;
        return pt-str;
}

int main(){
        char* input1 = NULL;
        char* input2 = "123";
        const char* input3 = "456";
        char* input4 = "";
        char test[]={1,2,3,4,5,6,7,8,'\0'};
        int length=count(input1);
        printf("%s = %d \n",input1, count(input1));
        printf("%s = %d \n",input2, count1(input2));
        printf("%s = %d \n",input3, count1(input3));
        printf("%s = %d \n",input4, count(input4));
        printf("%s = %d \n",test, count(test));
        return 0;
}

/*

xu@xu-ThinkPad-X61:~/algorithm$ gcc countStringLen.c
xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
(null) = -1 
123 = 3 
456 = 3 
= 0 
（乱码）= 8 

*/
