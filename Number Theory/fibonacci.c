//input:n
//output:the n^th fibonacci number
//Theta(log(N)) but the matirx multiplication is very naive

#include<stdio.h>
#include<stdlib.h>

int* matrix_multi(int *a,int *b,int m,int n,int p){
        int *res=(int*)malloc(sizeof(int)*m*p);
        for(int r=0;r<m*p;r++)
                *(res+r)=0;
        for(int i=0;i<m;i++){       //a is a m by n matrix;
              for(int j=0;j<p;j++){ //b is a n by p matrix;
                        for(int k=0;k<n;k++){
                                *(res+i*n+j)+=(*(a+i*n+k)) * (*(b+k*p+j));
                        }
                }
        }
        return res;
}

int fib(int n){
        int base[4]={1,0,1,1};
        int m[4]={0,1,1,1};
        int res[4]={1,0,0,1};
        int* tmp;
        while(n){
                if(n&1){
                        tmp=matrix_multi(res,m,2,2,2);
                        for(int i=0;i<4;i++)
                                *(res+i)=*(tmp+i);//res*=m
                }
                tmp=matrix_multi(m,m,2,2,2);
                for(int j=0;j<4;j++)
                        *(m+j)=*(tmp+j);//m*=m
                n>>=1;
        }
        tmp=matrix_multi(res,base,2,2,2);
        int ret=*(tmp+1);
        free(tmp);
        return ret;
}

int main(){
        int n;
        scanf("%d",&n);
        printf("%d\n",fib(n));
        return 0;
}
