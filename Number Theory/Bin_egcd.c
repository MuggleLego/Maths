#include<stdio.h>
#include<stdlib.h>


void swap(int* a,int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

//input:integer a b
//output:gcd(a,b)=d and integer x y which satisfy ax+by=d
int* begcd(int a,int b){
    int r=a;
    int _r=b;
    int k=0;
    while(!(r&1) && !(_r&1)){
        r>>=1;
        _r>>=1;
        k++;//if a b are even,gcd(a,b)=2^k*gcd(a>>k,b>>k)
    }
    int _a=r;
    int _b=_r;
    int x=1;int y=0;int _x=0;int _y=1;//initialize
    while(_r){
        while(!(r&1)){//r is even,r' is odd.So a' is even,b' is odd
            r>>=1;
            if(!(x&1) && !(y&1)){
                x>>=1;y>>=1;//when x,y,r are both even,we can reduce
            }
            else{//ab-ab=ab'*2^k+a'b*2^k=0,So ab'+a'b=0
                x=(x+_b)>>1;//odd+odd=even
                y=(y-_a)>>1;//even+even=even
            }
        }
        while(!(_r&1)){//r'is even,so r is odd,b' is even,a' is odd
            _r>>=1;
            if((_x&_y)&1){
                _x>>=1;_y>>=1;
            }
            else{

                _x=(_x+_b)>>1;
                _y=(_y-_a)>>1;
            }
        }
        if(_r<r){
            swap(&r,&_r);//move a row
            swap(&x,&_x);
            swap(&y,&_y);
        }//_r now greater than r
        _r-=r;_x-=x;_y-=y;//mod
    }
    int *res=(int*)malloc(sizeof(int)*3);
    res[0]=x;res[1]=y;res[2]=(r<<k);
    return res;
}

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int *tmp=begcd(a,b);
    printf("%d*%d+%d*%d=%d\n",a,tmp[0],b,tmp[1],tmp[2]);
    free(tmp);
    return 0;
}
