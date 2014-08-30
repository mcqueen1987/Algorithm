/*

字符串子串查找strstr

问题：
函数名: strstr
函数原型：char *strstr(const char *str1, const char *str2);
语法：* strstr(str1,str2)
str1: 被查找目标　string expression to search.
str2: 要查找对象　The string expression to find.
返回值：该函数返回str2第一次在str1中的地址，如果没有找到，返回NULL
例子：
charstr[]="1234xyz";
char*str1=strstr(str,"34");
得到str1="34xyz"

方法1：

一个指针扫描，当首字母相同时两个指针扫描两个字符串比较。

代码如下：

*/

#include <stdio.h>
#include <string.h>
#include <assert.h>

char* mystrstr(const char* str1,const char* str2)//str1 is the original string 
{
    assert(str1 != NULL);
    if(str2 == NULL) return (char*)str1;
    while(str1 != '\0'){
        if(*str1 != *str2) str1++;
        else{
            char* ori = str1;
            char* des = str2;
            while(*des != '\0'){
                if(*ori == *des){
                    ori++;des++;
                }
                else break;
            }
            if(*des == '\0') return str1;
        }
    }
    return NULL;
}

int main(){
    char ori[]="sdggdfhhttyusdfge";
    char des[]="ttyu";
    char* ret=mystrstr(ori,des);
    printf("%s\n", ret);
    return 0;
}

/*

结果是

[root@admin Desktop]# ./a.out
ttyusdfge

 
方法2：

类似的方法，练练手：

*/

#include <stdio.h>
#include <string.h>

char* mystrstr(const char* str1,const char* str2)//str1 is the original string 
{
    int len2 = strlen(str2);
    int len1 = strlen(str1);
    if(!len2) return (char*)str1;
    while(len1 >= len2){
        len1--;
        if(!strcmp(str1,str2,len2)) return (char*)str1;
        str1++;
        }
    }
    return NULL;
}


/*

int main(){
    char ori[]="sdggdfhhttyusdfge";
    char des[]="ttyu";
    char* ret=mystrstr(ori,des);
    printf("%s\n", ret);
    return 0;
}

结果是

[root@admin Desktop]# ./a.out
ttyusdfge

*/




