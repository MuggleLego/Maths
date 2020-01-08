//date:2019.12.31
//input:a positive integer n(n>1)
//function:factor n into the product of the power of primes,store those factors in a link-list
//a very very ugly version :(

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

//is_prime
int is_prime(int n){
        if(n==1)
                return 0;
        for(int i=2;i*i<=n;i++){
                if(!(n%i))
                        return 0;
        }
        return 1;
}

//let p be the smallest prime factor of n
//this function find p^k where p^k is a factor of n too
int aux_factor(int n){
        if(is_prime(n)) //prime is the only factor of itself(except for 1)
                return n;
        int res=1;
        for(int i=2;i*i<=n;i++){
                if(!(n%i)){  //find the smallest factor
                        while(!(n%i)){
                                n/=i;  
                                res*=i;  //find the largest factor with the power of i
                        }
                        break; //find one is enough
                }
        }
        return res;
}

//store  factors in a link-list
node* factorization(int n){
        node* dummy=new_node(0);
        while(n!=1){
                head_insert(dummy,aux_factor(n));
                n/=aux_factor(n);
        }
        return dummy;
}

int main(){
        int n;
        scanf("%d",&n);
        node* dummy=factorization(n);
        print_node(dummy);
        return 0;
}
