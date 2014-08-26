/*

http://www.cnblogs.com/McQueen1987/p/3546729.html

c：翻转一个长句中的每个单词

问题：

输入：“how are    you     baby--   "

输出：”woh era    uoy     --ybab   "

*/

#include<stdio.h>
#include<string.h>
#define SWAP(a,b) (a)^=(b);(b)^=(a);(a)^=(b)

char* sentenceReverse(char* input){
        if(NULL == input) return;
        char *r,*f;
        char *inp = (char*)malloc(sizeof(char)*(strlen(input)+1));
        //当input是const时其内容不能修改，此时需要在堆上new一个新数组;
        strcpy(inp,input);
        r=f=inp;
        printf("input is:%s-----\n",inp);
        char *rear,*front;//用于标记一个单词的词首和词尾
        while(*r){
                while(*r==' ') r++;
                f=r;
                while(*r!=' ' && *r!='\0') r++;
                r--;
                front=f;rear=r;
                while(rear > front){//翻转一个单词
                        SWAP(*rear,*front);
                        front++;
                        rear--;
                }
                if(*(++r)=='\0') break;
        }
        return inp;
}

int main(){
        char test1[]="1oow   lsije     ";
        char *test2="sdklf  ";
        char *ret2;
        printf("test1 result is:%s-----\n",ret2=sentenceReverse(test1));
        printf("test2 result is:%s-----\n",sentenceReverse(test2));
        free(ret2);//free掉malloc开辟的空间
        return 0;
}

/*

输出结果：

xu@xu-ThinkPad-X61:~/algorithm$ gcc sentenceReverse.c 
xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
input is:1oow lsije -----
test1 result is:woo1 ejisl -----
input is:sdklf -----
test2 result is:flkds -----


总结：

一，当函数参数是test2时（注意它声明时是char * 类型），内存做了以下操作：1.在堆上保存test2指针。2.将其内容："sdklf "保存在“常量区”（具体我也不清楚，反正该区域内容不能修改）。找到下面连接，问题解释的比较清晰：

http://blog.chinaunix.net/uid-26456800-id-3262510.html

二，当函数sentenceReverse（）对数组char *test2内容修改时，总会报错“

段错误 (核心已转储)”。

三，解决方案：在堆上重新开辟新空间进行操作。如上函数中新建数组inp[ ];

四，当函数参数是test1时（注意是它声明时是char [ ]类型）就不存在内存“段错误”问题。其内容存储在堆上可以直接修改。

*/