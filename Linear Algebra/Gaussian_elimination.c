//input:a matrix and the number of its rows and cols
//function:Gaussian-elimination

#include<stdio.h>

void elimination(int m,int n,double a[m][n]){
        double q; //the divisor
        int tmp=m>n?n:m; //take the smaller one
        
        for(int i=0;i<tmp;i++){ //walk every cols
                for(int j=i+1;j<tmp;j++){ //walk every entry under the diagonal in a col
                        q=*(a[j]+i) / (*(a[i]+i));
                        q*=-1;
                        for(int k=i;k<n;k++)  //elimination
                                *(a[j]+k)+=q*(*(a[i]+k));
                }
        }
        
         if(n<m){   //if cols less than rows then there will be all zero below the matrix
                for(int i=n;i<m;i++){
                        for(int k=0;k<n;k++)
                                *(a[i]+k)=0;
                }
        }
}

int main(){
        int m,n;
        scanf("%d%d",&m,&n);
        double a[m][n];
        for(int i=0;i<m;i++){  //input the matrix
                for(int j=0;j<n;j++){
                        scanf("%lf",&(a[i][j]));
                }
        }
        
        elimination(m,n,a);
        printf("\n\n");
        //output the matrix
        for(int k=0;k<m;k++){
                for(int t=0;t<n;t++){
                        printf("%.2f ",a[k][t]);
                }
                printf("\n");
        }
        printf("\n");
        return 0;
}
