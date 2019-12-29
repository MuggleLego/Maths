//date:2019.12.28
//input:a matrix.
//function: use pivot formula to find the determinant of the matrix.

#include<stdio.h>

double pivot_formula(int m,int n,double a[m][n]){
        if(m!=n)
                return 0;

        double q; //the divisor
        int tmp=m>n?n:m; //take the smaller one

        for(int i=0;i<tmp;i++){ //walk every cols
                for(int j=i+1;j<tmp;j++){ //walk every entry under the diagonal in a col
                        q=*(a[j]+i) / (*(a[i]+i));
                        q*=-1;
                        //elimination:
                        for(int k=i;k<n;k++)
                                *(a[j]+k)+=q*(*(a[i]+k));
                }
        }

        double res=1;
        for(int i=0;i<tmp;i++)
                res*=(*(a[i]+i));
        return res;
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
        printf("%.2f\n",pivot_formula(m,n,a));
        return 0;
}
