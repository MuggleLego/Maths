//date:2019.12.30
//input:an integer n
//function:determine whether n is a prime number

#include<stdio.h>
#include<stdlib.h>

//naive version
int is_prime(int n){
        if(n==1)
                return 0;
        for(int i=2;i*i<=n;i++){
                if(!(n%i))
                        return 0;
        }
        return 1;
}

//Sieve of Eratosthenes
int filter(int n){
        int* tmp=(int*)malloc(sizeof(int)*(n+1));
        for(int i=2;i<=n;i++)
                tmp[i]=1;
        for(int p=2;p*p<=n;p++){
                if(tmp[p]){
                        for(int i=2;i*p<=n;i++){
                                if(i*p==n)
                                        return 0;
                                tmp[i*p]=0;
                        }
                }
        }
        free(tmp);
        return 1;
}

int main(){
        int n;
        scanf("%d",&n);
        if(filter(n))
                printf("True\n");
        else
                printf("False\n");
        return 0;
}
