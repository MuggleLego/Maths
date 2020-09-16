#include<stdio.h>
//input:int a,b
//output:gcd(a,b)
//case1:a,b are evens,gcd(a,b)=2*gcd(a/2,b/2)
//case2:only a or only b is even,suppose a is even b is odd,gcd(a,b)=gcd(a/2,b)
//proof:suppose gcd(a,b)=d,a=md,so d is odd,m is even.So a/2=md/2,m/2 is an integer,so d \mid a/2;
//case3:a,b are odds,and a>=b,gcd(a,b)=gcd((a-b)/2,b)
//proof:suppose gcd(a,b)=d,a=md,b=nd,then m,n must be odds.(a-b)/2=(m-n)d/2.m-n must be even,so (m-n)/2 is an integer.So d \mid (a-b)/2.


int abs(int a){
    return a>0?a:-a;
}

int min(int a,int b){
    return a>b?b:a;
}

void swap(int* a,int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int rec_bin_gcd(int a,int b){
    if(!a) return b;//base case
    if(!b) return a;//base case
    if(!(a&1) && !(b&1)) return rec_bin_gcd(a>>1,b>>1)<<1;//case 1
    else if(!(a&1)) return rec_bin_gcd(a>>1,b);//case 2
    else if(!(b&1)) return rec_bin_gcd(a,b>>1);//case 2
    else return rec_bin_gcd(abs(a-b)>>1,min(a,b)); //case 3
}

int iter_bin_gcd(int a,int b){
    int k=0;
    while(!(a&1) && !(b&1)){
        a>>=1;
        b>>=1;//if a,b are evens
        k++;//gcd(a,b)=2^k*gcd(a>>k,b>>k)
    }
    while(!(a&1)){
        a>>=1;//a is odd
    }
    while(b){
        while(!(b&1)){
            b>>=1;//a is odd,so gcd(a,b)=gcd(a,b/2),b is odd eventually
        }
        if(a>b) swap(&a,&b);//from then on,b>=a
        b-=a;//gcd(a,b/2)=gcd(b-a,b/2),b-a is even,loop.
    }
    return a<<k;//b=0,a=gcd(a>>k,b>>k),res=2^k*gcd(a>>k,b>>k)
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d %d\n",iter_bin_gcd(a,b),rec_bin_gcd(a,b));
    return 0;
}
