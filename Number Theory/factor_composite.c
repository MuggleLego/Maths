//date:2019.12.31
//input:a positive integer n
//function:factor n into the product of the power of primes

#include<stdlib.h>
#include<stdio.h>

typedef struct _node{
        int value;
        struct _node* next;
}node;

//create a new node
node* new_node(int value){
        node* new=(node*)malloc(sizeof(node));
        new->value=value;
        new->next=NULL;
        return new;
}

//use a dummy to head insert
void head_insert(node* dummy,int value){
        node* new=new_node(value);
        new->next=dummy->next;
        dummy->next=new;
}


void print_node(node* dummy){
        node* tmp=dummy->next;
        while(tmp){
                printf("%d ",tmp->value);
                tmp=tmp->next;
        }
        printf("\n");
}

//let p be the smallest prime factor of n
//this function find p^k where p^k is a factor of n too
int aux_factor(int n){
        int res=1;
        for(int i=2;i*i<=n;i++){
                if(!(n%i)){
                        while(!(n%i)){
                                n/=i;
                                res*=i;
                        }
                        break;
                }
        }
        return res;
}

