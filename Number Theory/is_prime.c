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

int main(){
        int n;
        scanf("%d",&n);
        if(is_prime(n))
                printf("True\n");
        else
                printf("False\n");
        return 0;
}
