//date:2020.10.15
//input:integer n
//output:all the prime factor of n

//sieve of eratosthenes
//input:int p
//output:primes that in [2,p]
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
        res[i] = 0;//initialiuze,to mark unused space
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


