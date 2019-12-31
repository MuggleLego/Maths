//input:an integer n
//output:the number of coprime of n in Z^*_n

#include<stdlib.h>
#include<stdio.h>

//GCD way
int gcd(int a,int b){
        if(b==0)
                return a;
        return gcd(b,a%b);
}

int gcd_phi(int n){
        int res=1;
        for(int i=2;i<n;i++){
                if(gcd(i,n)==1)
                        ++res;
        }
        return res;
}

//factor n into prime factors
int factor_phi(int n){
        int res=n;
        for(int i=2;i*i<=n;i++)
                if(!(n%i)){
                        while(!(n%i))
                                n/=i;  //reverse order of sieve of Eratosthenes
                        res-=res/i;  //cancel all prime factors
                }
        if(n>1) 
                res-=res/n; //the rest of prime factors
        return res;
}

int main(){
        int n;
        scanf("%d",&n);
        printf("%d %d\n",gcd_phi(n),factor_phi(n));
        return 0;
}
