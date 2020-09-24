//input:integer a and b
//output:a's inverse of modulus b

#include<stdio.h>

int positive_inverse(int a,int b){
        int tmp1,tmp2,tmp3;
        int v1,v3;
        int u1,u3;
        int q;
        v1=1;v3=a;
        u1=0;u3=b;
        while(u3){
                q=v3/u3;
                tmp1=u1;tmp3=u3;
                u1=v1-q*u1;u3=v3-q*u3;
                v1=tmp1;v3=tmp3;
        }
        while(v1<0){
                v1+=b;
        }
        return v1;
}

int main(){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("the positive a's inverse modulo b is:%d\n",positive_inverse(a,b));
        return 0;
}
