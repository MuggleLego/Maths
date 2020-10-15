//date:2020.10.15
//input: int a,exp,n
//output:a^exp mod p
//algorithm:repeated square,O(lg(exp))

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
