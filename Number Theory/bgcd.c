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

int gcd(int a,int b){
    if(!a) return b;
    if(!b) return a;
    if(!(a&1) && !(b&1)) return gcd(a>>1,b>>1)>>1;
    else if(!(a&1)) return gcd(a>>1,b);
    else if(!(b&1)) return gcd(a,b>>1);
    else return gcd(abs(a-b)>>1,min(a,b)); 
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",gcd(a,b));
    return 0;
}
