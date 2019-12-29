//input:n
//output:the n^th fibonacci number

#include<stdio.h>
#include<stdlib.h>

//Theta(log(N)) but the matirx multiplication is very naive
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

//naive version
int FacIter(int n){
        int res=1;
        for(int i=1;i<=n;i++){
                res=res*i;
        }
        return res;
}

//naive version
int FacRec(int n){
        if (n==1)
                return 1;
        else
                return n*FacRec(n-1);
}

//use multiplication to calculate
//Theta(log(N))
int multi_fib(int n){
        int a=0,b=1,c=1,d=1;
        int res_a=0,res_b=1,res_c=1,res_d=1;
        int tmp_a,tmp_b,tmp_c,tmp_d;
        while(n){
                if(n&1){
                        tmp_a=res_a*a+res_b*c;
                        tmp_b=res_a*b+res_b*d;
                        tmp_c=res_c*a+res_d*c;
                        tmp_d=res_c*b+res_d*d;
                        res_a=tmp_a;
                        res_b=tmp_b;
                        res_c=tmp_c;
                        res_d=tmp_d;
                }
                        tmp_a=a*a+b*c;
                        tmp_b=a*b+b*d;
                        tmp_c=a*c+c*d;
                        tmp_d=b*c+d*d;
                        a=tmp_a;
                        b=tmp_b;
                        c=tmp_c;
                        d=tmp_d;
                n>>=1;
        }
        return res_a;
}



int main(){
        int n;
        scanf("%d",&n);
        printf("%d\n",fib(n));
        return 0;
}
