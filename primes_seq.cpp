#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <math.h>

int range = 1000 * 100;

int isPrime(int num)
{
    int i = 2;
    while (i * i <= num)
    {
        if (num % i == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int eratosthenes(int n)
{

    int *primes = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        primes[i] = isPrime(i);
    }

    int out = 0;
    for (int i = 2; i < n; i++)
    {
        out += primes[i];
    }
    return out;
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        range = atol(argv[1]);
    }

    double start, stop;
    int res;

    start = omp_get_wtime();
    res = eratosthenes(range);
    stop = omp_get_wtime();
    printf("%d -> %f\n", res, stop - start);
    return 0;
}
