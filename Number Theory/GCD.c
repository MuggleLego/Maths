#include<stdio.h>

int gcdInte(int a,int b){
        while(a%b){
                int m=a%b;
                a=b;
                b=m;
        }
        return b;
}


int gcdRec(int a,int b){
        if(a%b==0)
                return b;
        else
                return gcdRec(b,a%b);
}


int main(){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d %d\n",gcdInte(a,b),gcdRec(a,b));
        return 0;
}
