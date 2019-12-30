//input:integer m,n,p;then a mxn matrix A,a nxp matrix B
//the product of A and B


#include<stdio.h>
#include<stdlib.h>

//a naive version
int* matrix_multiplication(int* a,int* b,int m,int n,int p){
        int* res=(int*)malloc(sizeof(int)*m*p);
        for(int i=0;i<m;i++){
                for(int j=0;j<p;j++){
                        int tmp=0;
                        for(int k=0;k<n;k++)
                                tmp+=*(a+i*n+k)*(*(b+k*p+j));
                        *(res+i*p+j)=tmp;
                }
        }
        return res;
}

int main(){
        int m,n,p;
        scanf("%d%d%d",&m,&n,&p);
        int a[m*n];
        int b[n*p];
        for(int i=0;i<m*n;i++)
                scanf("%d",a+i);
        for(int j=0;j<n*p;j++)
                scanf("%d",b+j);
        int* tmp=NULL;
        tmp=matrix_multiplication((int*)a,(int*)b,m,n,p);
        printf("\n\n");
        for(int i=0;i<m;i++){
                for(int j=0;j<p;j++)
                        printf("%d ",tmp[i*p+j]);
                printf("\n");
        }
        return 0;
}
