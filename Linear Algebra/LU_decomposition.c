//Date:2019.12.28
//input:a square matrix and the size of the matrix
//output:a lower triangle and the matrix after elimination
//function:LU decomposition

#include<stdio.h>
#include<stdlib.h>

double* LU_decomposition(int n,double a[n][n]){
        double* lower_tri=(double*)malloc(sizeof(double)*n*n);

        for(int i=0;i<n;i++){   //initialize the lower triangle
                for(int j=0;j<n;j++){
                        if(i==j)
                                *(lower_tri+i*n+j)=1;
                        else
                                *(lower_tri+i*n+j)=0;
                }
        }

        double q; //the divisor
        for(int i=0;i<n;i++){ //walk every cols
                for(int j=i+1;j<n;j++){    //walk every entry under the diagonal in a col
                        q=*(a[j]+i) / (*(a[i]+i));
                        *(lower_tri+j*n+i)=q;
                        q*=-1;

                        for(int k=i;k<n;k++)  //elimination
                                *(a[j]+k)+=q*(*(a[i]+k));
                }
        }
        return lower_tri;
}

int main(){
        int n;
        scanf("%d",&n);
        double a[n][n];
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        scanf("%lf",&(a[i][j]));
                }
        }

        double* tmp=LU_decomposition(n,a);
        printf("\n\n");
        for(int i=0;i<n;i++){
              for(int j=0;j<n;j++)
                      printf("%.2f ",*(tmp+i*n+j));
                printf("    ");
                for(int k=0;k<n;k++)
                        printf("%.2f ",a[i][k]);
                printf("\n");
        }
        free(tmp);
        return 0;
}
