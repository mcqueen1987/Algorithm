#include <stdlib.h>
#include <stdio.h>

int biTofh(int bi,int len){//二进制转化为正负号
        int i=0;
        while(i<len){
                int tmp = 1;
                if((bi & (tmp<<(len-i-1))) != 0){//从最左位开始比较，该位是1
                        printf(" + ");
                }
                else{
                        printf(" - ");
                }
                i++;    
        }
        printf("\n");
        return 0;
}

int main(){
        int input[] = {1,2,3,4,5};
        biTofh(20,5);
        return 0;
}