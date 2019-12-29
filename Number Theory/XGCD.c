#include<stdio.h>
#include<stdlib.h>
//input:integers a and b
//output:the greatest commom divisor d and two integers x and y which satisfy
//the equation:xa+yb=d;


int* XGCD(int a,int b){
        int tmp1,tmp2,tmp3;
        int v1,v2,v3;
        int u1,u2,u3;
        int q;
        int* res=(int*)malloc(sizeof(int)*3);
        v1=1;v2=0;v3=a;
        u1=0;u2=1;u3=b;
        while(u3){
                q=v3/u3;
                tmp1=u1;tmp2=u2;tmp3=u3;
                u1=v1-q*u1;u2=v2-q*u2;u3=v3-q*u3;
                v1=tmp1;v2=tmp2;v3=tmp3;
        }
        res[0]=v1;res[1]=v2;res[2]=v3;
        return res;
}


int main(){
        int a,b;
        int* p;
        scanf("%d%d",&a,&b);
        p=XGCD(a,b);
        printf("(%dx%d)+(%dx%d)=%d\n",p[0],a,p[1],b,p[2]);
        return 0;
}
