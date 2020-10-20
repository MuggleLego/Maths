//date:2020.10.15
//input:a prime p
//output:the smallest primitive root of p,which is also the generator of Z_p*

#include <stdio.h>
#include <stdlib.h>

//sieve of eratosthenes
int *sieve(int p)
{
    int *table = (int *)malloc(sizeof(int) * (p + 1));
    for (int i = 0; i < p + 1; i++)
    {
        table[i] = 1;
    }
    for (int i = 2; i < p + 1; i++)
    {
        if (!table[i])
            continue; //already checked
        for (int j = 2; j * i <= p; j++)
        {
            table[i * j] = 0;
        }
    }
    return table;
}


//use an array to store prime factors of integer n(not include n itself)
int *prime_factor(int n)
{
    int *res = (int *)malloc(sizeof(int) * n);
    int *table = sieve(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = 0;//initialize,to mark unused space
    }
    int top = 0;
    for (int i = 2; i < n; i++)
    {
        if (!table[i])
            continue; //i is not a prime
        if (!(n % i))
            res[top++] = i; //i is a prime factor of n
    }
    free(table);
    return res;
}


//compute a^exp mod n by repeated square
int power(int a, int exp, int n)
{
    int res = 1;
    while (exp)
    {
        if (exp & 1)
        {
            res = (res * a) % n;
        }
        a = (a * a) % n;
        exp >>= 1;
    }
    return res;
}

//input:relative primes a and p
//output:if a is a primitive root of p
//In other words,to see if the order of a is p-1 under Z_p*
int is_root(int a,int p){
    int* pf=prime_factor(p-1);//list prime factors
    int i=0;
    while(pf[i]){
        if(power(a,(p-1)/pf[i],p)==1){//order of a smaller than p-1
            return 0;
        }
        i++;
    }
    return 1;
}

//given a prime p
//find the smallest primitive root of p
int root(int p)
{
    int *pf = prime_factor(p - 1); //find all prime factors of p-1
    int res;
    for (res = 2; res < p; res++)
    { //gcd(res,p)==1
        if(!is_root(res,p)) continue;
        break;
    }
    return res;
}



int main()
{
    int *prime = sieve(10000); //find prime in 1 to 10000
    int max = 0;
    for (int i = 2; i < 10000; i++)
    {
        if (!prime[i]) //i a composite
            continue;
        if (root(i) >= max)
        {
            max = root(i);
            printf("%d:%d\n", i, root(i));
        }
    }
    printf("%d\n", max);
    return 0;
}
