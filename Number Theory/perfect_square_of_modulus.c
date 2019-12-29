//input:an integer n
//function:find prime number x in range(1,n) and perfect square of modulus x

#include <stdio.h>

int is_perfect_square(int a,int p){
        for(int i=0;i<a;i++){
                if((i*i)%p==a%p)
                        return i;
        }
        return -1;
}

int is_prime(int p){
        if(p==1)
                return 0;
        for(int i=2;i<p;i++){
                if(!(p%i))
                        return 0;}
        return 1;
}

int main(){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
                if(is_prime(i)){
                        for(int j=2;j<=n;j++){
                                if(j%i){
                                        if(is_perfect_square(j,i)!=-1){
                                   printf("is_perfect_square(%d,%d)==%d\n",j,i,is_perfect_square(j,i));}
                                }
                        }
                }
        }
        return 0;
}
