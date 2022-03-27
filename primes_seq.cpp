#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <math.h>

const int range = 1000 * 1000 * 1000;


int eratosthenes(int range)
{
    range++;

    int *primes = new int[range];

    for (int i = 2; i < range; i++)
        primes[i] = 1;
    
    for (int i = 2; i * i < range; i += 1)
        if (primes[i] == 1)
            for (int j = i * i; j < range; j += i)
                primes[j] = 0;

    int res = 0;
    for (int i = 2; i < range; i++)
        res += primes[i];
    
    delete[] primes;
    return res;
}

int main()
{
    double start, stop;
    start = omp_get_wtime();
    printf("Liczba liczb pierwszych: %d\n", eratosthenes(range));
    stop = omp_get_wtime();
    printf("Czas przetwarzania wynosi %f sekund\n", ((double)stop - start));
    return 0;
}
