#include <stdlib.h>
#include <stdio.h>

typedef struct _Node{//定义单链表的节点
        int value;
        struct _Node *next;
}Node;


Node* link(int len){//新建一个单链表
        int i=0;
        Node* head = (Node*)malloc(sizeof(Node));
        head->value = -1;
        Node* tail = head;
        for(;i<len;i++){
                Node* tmp = (Node*)malloc(sizeof(Node));
                tmp->value=i;
                tmp->next=NULL;
                tail->next=tmp;
                tail=tail->next;
        }
        return head;
}
void outputlink(Node* head){//输出一个单链表
        do{
                printf ( "%d ->", head->value );
                head = head->next;
        }while(head!=NULL);
        printf ( "\n" );
}

void freelink(Node* head){//释放单链表申请的空间
        while(head!=NULL){
                Node* tmp = head->next;
                free(head);
                head = tmp;
        }
}

Node* revlink(Node* head){//递归翻转单链表
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        Node *p=head,*q=p->next;
        p->next = NULL;
        Node* ret = revlink(q);
        q->next = p;
        return ret;
}

int main ( int argc, char *argv[] )
{
        Node* head = link(5);
        outputlink(head);
        outputlink(revlink(head));
        freelink(head);
        return EXIT_SUCCESS; 
}