/*

http://www.cnblogs.com/McQueen1987/p/3537969.html

问题：

1.加入输入是{a,b,c};

2.输出abc,acb,bac,bca,cab,cba;

代码描述：

1.递归遍历所有情况

2.方法FUN输入为：要排列的字符串char inp[];inp[]的长度len;排列后结果存入ret[];

*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//count the number of elements in inp[] without '0';
int count(char inp[],int len){
        int i=0;int sum=0;
        for(;i<len;i++){
                if(inp[i]!=0) sum++;
        }
        return sum;
}

//输出所有可能的排列
int FUN(char inp[],int len,char ret[])
{//len is the number of elements in inp[]; 
        if(count(ret,len)==len){
                printf("------------%s\n",ret);//when ret is full,print;
        }
        int i=0;
        for(;i<len;i++){
                if(inp[i]==0) continue;//the element printed before had changed to '0';
                ret[count(ret,len)]=inp[i];//put inp[i] into the tail of ret
                char tmp=inp[i];//change the element printed to 0 :protect the scene;
                inp[i]=0;
                FUN(inp,len,ret);
                inp[i]=tmp;
                ret[count(ret,len)-1]=0;
        }
        return 0;
}

int main()
{

        char input[]={'a','b','c','d','e',0};
        char result[6]={0};//save the sort result of input       
        FUN(input,5,result);
        return 0;
}

/*

xu@xu-ThinkPad-X61:~/algorithm$ gcc bianli.c
xu@xu-ThinkPad-X61:~/algorithm$ ./a.out
------------abcde
------------abced
------------abdce
------------abdec
------------abecd
------------abedc
------------acbde
------------acbed
------------acdbe
------------acdeb
------------acebd
------------acedb
------------adbce
------------adbec
------------adcbe
------------adceb
------------adebc
------------adecb
------------aebcd
------------aebdc
------------aecbd
------------aecdb
------------aedbc
------------aedcb
------------bacde
------------baced
------------badce
------------badec
------------baecd
------------baedc
------------bcade
------------bcaed
------------bcdae
------------bcdea
------------bcead
------------bceda
------------bdace
------------bdaec
------------bdcae
------------bdcea
------------bdeac
------------bdeca
------------beacd
------------beadc
------------becad
------------becda
------------bedac
------------bedca
------------cabde
------------cabed
------------cadbe
------------cadeb
------------caebd
------------caedb
------------cbade
------------cbaed
------------cbdae
------------cbdea
------------cbead
------------cbeda
------------cdabe
------------cdaeb
------------cdbae
------------cdbea
------------cdeab
------------cdeba
------------ceabd
------------ceadb
------------cebad
------------cebda
------------cedab
------------cedba
------------dabce
------------dabec
------------dacbe
------------daceb
------------daebc
------------daecb
------------dbace
------------dbaec
------------dbcae
------------dbcea
------------dbeac
------------dbeca
------------dcabe
------------dcaeb
------------dcbae
------------dcbea
------------dceab
------------dceba
------------deabc
------------deacb
------------debac
------------debca
------------decab
------------decba
------------eabcd
------------eabdc
------------eacbd
------------eacdb
------------eadbc
------------eadcb
------------ebacd
------------ebadc
------------ebcad
------------ebcda
------------ebdac
------------ebdca
------------ecabd
------------ecadb
------------ecbad
------------ecbda
------------ecdab
------------ecdba
------------edabc
------------edacb
------------edbac
------------edbca
------------edcab
------------edcba
sorry，有点点长！

*/

