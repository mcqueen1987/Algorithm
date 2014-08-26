/*

实现字符串的原地翻转：

*/

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
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

int main(){
        char test[]="test";
        printf("input is : %s\n",test);
        printf("result is : %s\n",strReverse(test));
        return 0;
}

/*

结果：

xu@xu-ThinkPad-X61:~/algorithm$ gcc strReverse.c 
xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
input is : test
result is : tset
*/