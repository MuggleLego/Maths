//a very naive solution...

#include<stdio.h>

int is_square(int n){
        if(n<0)
                return 0;
        else if(!n)
                return 1;
        else{
                for(int i=1;i*i<=n;i++){
                         if (i*i==n)
                                return 1;
        }
        return 0;
        }
}
int main(){
        int n;
        scanf("%d",&n);
        if(is_square(n)==1)
                printf("true\n");
        else
                printf("false\n");
        return 0;
        }
