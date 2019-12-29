#include<stdio.h>
//input:remainders and modulus of n congruence equations
//output:an integer that satisfy n congruence equations

int inverse(int a,int b){
        int tmp1,tmp2,v1,v2,u1,u2,q;
        v1=1;v2=a;
        u1=0;u2=b;
        while(u2){
                q=v2/u2;
                tmp1=u1;tmp2=u2;
                u1=v1-q*u1;u2=v2-q*u2;
                v1=tmp1;v2=tmp2;
        }
        if(v1<0)
                v1+=b;
        return v1;
}

int crt(int* a,int* m,int n){
        int sum=0;
        for(int i=0;i<n;i++){
                int tmp=1;
                for(int j=0;j<n;j++){
                        if(j!=i){
                                tmp*=*(m+j);
                        }
                }
        int inv=inverse(tmp,*(m+i));
        sum+=tmp*inv*(*(a+i));
        }
      int tmp=1;
      for(int k=0;k<n;k++)
               tmp*=*(m+k);
        return sum%tmp;
}

int main(){
        int n;
        scanf("%d",&n);
        int a[n];
        int m[n];
        for(int i=0;i<n;i++)
                scanf("%d",&a[i]);
        for(int j=0;j<n;j++)
                scanf("%d",&m[j]);
        printf("%d\n",crt(a,m,n));
        return 0;
}
