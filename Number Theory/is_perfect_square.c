//a very naive solution...

#include<stdio.h>

int is_square(int n){
        return (n>0) && (n^(n-1));
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
