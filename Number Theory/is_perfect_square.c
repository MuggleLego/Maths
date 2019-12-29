//a very naive solution...

#include<stdio.h>

int isSquare(int n){
        if(n<0)
                return 0;
        else if(n==0 || n==1)
                return 1;
        else{
                for(int i=1;i<n/2;i++){
                         if (i*i==n)
                                return 1;
        }
        return 0;
        }
}
int main(){
        int n;
        scanf("%d",&n);
        if(isSquare(n)==1)
                printf("true\n");
        else
                printf("false\n");
        return 0;
        }
