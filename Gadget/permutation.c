#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//input:int n
//output:a table of all permutation of n
//a very naive permutation,permuating by bubbling.

int fac(int n){
    int res=1;
    for(int i=2;i<=n;i++){
        res*=i;
    }
    return res;
}

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int* permu(int n){
    int *res=(int*)malloc(sizeof(int)*fac(n)*n);
    for(int i=1;i<=n;i++){
        res[i-1]=i;//first row:trivial permutation
    }
    int t=0;//bubble index
    int count=1;
    for(int i=1;i<fac(n);i++){
        for(int j=0;j<n;j++){
            res[i*n+j]=res[(i-1)*n+j];
        }
        t++;count++;
        t%=n-1;
        swap(res+i*n+t,res+i*n+t+1);
        }
        printf("%d\n",count);
    return res;
}

int main(){
    int n;
    scanf("%d",&n);
    int *res=permu(n);
    for(int i=0;i<fac(n);i++){
        for(int j=0;j<n;j++){
            printf("%d ",*(res+i*n+j));
        }
        printf("\n");
    }
    return 0;
}
