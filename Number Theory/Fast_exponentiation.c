//input:two integers a and b
//output:a^b

#include<stdio.h>

//iterative way
unsigned int power(unsigned int a,unsigned int b){
        int res=1;
        while(b){
                if(b&1)
                        res*=a;
                a*=a;
                b>>=1;
        }
        return res;
}

//recursion way
unsigned int power_rec(unsigned int a,unsigned int b){
        if(b==0) return 1;
        else{
                if(b&1) return a*power_rec((a*a),b>>1);
                else return power_rec((a*a),b>>1);
        }
}

int main(){
        unsigned int a,b;
        scanf("%u %u",&a,&b);
        printf("%u %u\n",power(a,b),power_rec(a,b));
        return 0;
}
