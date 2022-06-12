#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <math.h>

int range = 100000;
int num_threads = 4;

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

int eratosthenes(int n, int num_threads)
{

    omp_set_num_threads(num_threads);

    int *primes = (int *)malloc(n * sizeof(int));

#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < n; i++)
    {
        primes[i] = isPrime(i);
    }

    int res = 0;
#pragma omp parallel for reduction(+ \
                                   : res)
    for (int i = 2; i < n; i++)
    {
        res += primes[i];
    }
    return res;
}

int main(int argc, char *argv[])
{
    // gcc -o par -fopenmp primes_par.cpp -lstdc++ -lm
    if (argc > 1)
    {
        range = atol(argv[1]);
        num_threads = atol(argv[2]);
    }

    double start, stop;
    int res;

    start = omp_get_wtime();
    res = eratosthenes(range, num_threads);
    stop = omp_get_wtime();
    printf("%d -> %f\n", res, stop - start);
    return 0;
}