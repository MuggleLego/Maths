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
        res[i] = 0;
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

//given a prime p
//find the smallest primitive root of p
int root(int p)
{
    int *pf = prime_factor(p - 1); //find all prime factors of p-1
    int res;
    for (res = 2; res < p; res++)
    { //gcd(res,p)==1
        int flag = 1;
        for (int i = 0; pf[i]; i++)
        {
            if (power(res, pf[i], p) == 1)
            { //the order of a is smaller than p-1
                flag = 0;
                break;
            }
        }
        if (flag)
            return res;
    }
}
