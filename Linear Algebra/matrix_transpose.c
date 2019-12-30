//Date:2019.12.30
//input:a matrix and its size
//output:its transpose

#include<stdio.h>
#include<stdlib.h>

void swap(int* a,int* b){
        int tmp=*a;
        *a=*b;
        *b=tmp;
}

//square matrix
//don't need addition space
void square_transpose(int n,int a[n][n]){
        for(int i=0;i<n;i++)
                for(int j=i;j<n;j++)
                        swap(a[i]+j,a[j]+i);
}

//mxn matrix
int* transpose(int m,int n,int a[m][n]){
        int* res=(int*)malloc(sizeof(int)*m*n);
        for(int i=0;i<m;i++){
                for(int j=0;j<n;j++)
                        *(res+j*m+i)=*(a[i]+j);
        }
        return res;
}

int main(){
        int m,n;
        scanf("%d%d",&m,&n);
        int a[m][n];
        for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                        scanf("%d",&a[i][j]);
                }
        }
        if(m==n){
                square_transpose(n,a);
                printf("\n\n");
                for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++)
                                printf("%d ",a[i][j]);
                        printf("\n");
                }
        }
        else{
                int* tmp=transpose(m,n,a);
                printf("\n\n");
                for(int i=0;i<n;i++){
                        for(int j=0;j<m;j++)
                                printf("%d ",*(tmp+i*m+j));
                        printf("\n");
                }
                free(tmp);
        }
        return 0;
}

