//date:2020.10.15
//input n
//decide n is the power of two or not

#include <stdio.h>

int is_square(int n)
{
    return (n > 0) && !(n & (n - 1));
}

int main()
{
    int n;
    scanf("%d", &n);
    if (is_square(n))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
