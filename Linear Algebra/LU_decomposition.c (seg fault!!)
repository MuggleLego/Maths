//Date:2019.12.28
//input:a square matrix and the size of the matrix
//output:a lower triangle and the matrix after elimination

#include<stdio.h>
#include<stdlib.h>

double** LU_decomposition(int m,int n,double a[m][n]){
        double** lower_tri=(double**)malloc(sizeof(double*)*n*n);
        
        for(int i=0;i<n;i++){   //initialize the lower triangle
                for(int j=0;j<n;j++){
                        if(i==j)
                                lower_tri[i][j]=1;
                        else
                                lower_tri[i][j]=0;
                        printf("%.2f ",lower_tri[i][j]);
                }
        }

        double q; //the divisor
        int tmp=m>n?n:m; //take the smaller one

        for(int i=0;i<tmp;i++){ //walk every cols
                for(int j=i+1;j<tmp;j++){    //walk every entry under the diagonal in a col
                        q=*(a[j]+i) / (*(a[i]+i));
                        lower_tri[j][i]=q;
                        q*=-1;
                        
                        for(int k=i;k<n;k++)  //elimination
                                *(a[j]+k)+=q*(*(a[i]+k));
                }
        }
        
         if(n<m){     //if cols less than rows then there will be all zero below the matrix
                for(int i=n;i<m;i++){
                        for(int k=0;k<n;k++)
                                *(a[i]+k)=0;
                }
        }
        
        return lower_tri;
}

int main(){
        int m,n;
        scanf("%d%d",&m,&n);
        double a[m][n];
        for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                        scanf("%lf",&(a[i][j]));
                }
        }
        
        LU_decomposition(m,n,a);
        printf("\n\n");
        
        for(int i=0;i<m;i++){
        //      for(int j=0;j<n;j++)
        //              printf("%.2f ",l[i][j]);
        //      printf("    ");
                for(int k=0;k<n;k++)
                        printf("%.2f ",a[i][k]);
                printf("\n");
        }
        
        return 0;
}
