//date:2019.12.31
//input:a positive integer n
//function:factor n into the product of the power of primes,store those factors in a link-list

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
int sieve_of_Eratosthenes(int n){
        int* tmp=(int*)malloc(sizeof(int)*(n+1));
        for(int i=2;i<=n;i++)
                tmp[i]=1;
        for(int p=2;p*p<=n;p++){
                if(tmp[p]==1){
                        for(int i=2*p;i<=n;i+=p){
                                if(i==n)
                                        return 0;
                                tmp[i]=0;
                        }
                }
        }
        int res=tmp[n];
        free(tmp);
        return res;
}

//let p be the smallest prime factor of n
//this function find p^k where p^k is a factor of n too
int aux_factor(int n){
        if(sieve_of_Eratosthenes(n)) //prime is the only factor of itself(except for 1)
                return n;
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
