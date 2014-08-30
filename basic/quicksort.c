/*

c语言：快速排序

练手代码（分治实现）:

input：

int input[] = {12,6,3,9,10,6,2};

*/

int partition(int input[],int low,int high){
    int pivot = input[low];
    while(low < high){
    　　while(low < high && input[high] >= pivot) high--;
    　　input[low] = input[high];
   　　 while(low < high && input[low] <= pivot) low++;
    　　input[high] = input[low];
    }//low=high时跳出
    input[low] = pivot;
    return low;
}

int quicksort(int input[],int inplen,int low,int high){//快速排序
        int k=0;
        if(low < high){
            k = partition(input,low,high);   
            quicksort(input,inplen,low,k-1);
            quicksort(input,inplen,k+1,high);
        }
        return 0;
}

int main(){
        printf("=======================\n");
        int input[] = {12,6,3,9,10,6,2};
        int input1[] = {2,1,3};
        int len = sizeof(input)/sizeof(int);
        printf("len = %d\n",len);
        quicksort(input,len,0,len-1);
        int i=0;
        for(;i<len;i++){
            printf("input[%d]=%d\n",i,input[i]);
        }
        return 0;
}

/*

output：

=======================
len = 7
input[0]=2
input[1]=3
input[2]=6
input[3]=6
input[4]=9
input[5]=10
input[6]=12

*/