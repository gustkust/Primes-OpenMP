#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <math.h>

const int range = 1000 * 1000 * 500;


int eratosthenes(int range)
{
    omp_set_num_threads(8);

    range++;

    int *primes = new int[range];

    #pragma omp parallel for
    for (int i = 2; i < range; i++)
        primes[i] = 1;
    
    int rangeSQRT = (int) sqrt((double) range);
    #pragma omp parallel for schedule(dynamic)
    for (int i = 2; i < rangeSQRT; i += 1)
        if (primes[i] == 1)
            for (int j = i * i; j < range; j += i)
                primes[j] = 0;

    int res = 0;
    #pragma omp parallel for reduction(+:res)
    for (int i = 2; i < range; i++)
        res += primes[i];
    
    delete[] primes;
    return res;
}

int main()
{
    double start, stop;
    // start = omp_get_wtime();
    // printf("Liczba liczb pierwszych: %d\n", eratosthenes(range));
    // stop = omp_get_wtime();
    // printf("Czas przetwarzania wynosi %f sekund\n", ((double)stop - start));
    // return 0;
    FILE *f;
	f = fopen("par.txt", "w");
    int i, res;

    i = 100000;
    start = omp_get_wtime();
    res = eratosthenes(i);
    stop = omp_get_wtime();
    fprintf(f, "%f\n", stop - start);
    printf("done\n");

    i = 500000;
    start = omp_get_wtime();
    res = eratosthenes(i);
    stop = omp_get_wtime();
    fprintf(f, "%f\n", stop - start);
    printf("done\n");

    i = 1000000;
    start = omp_get_wtime();
    res = eratosthenes(i);
    stop = omp_get_wtime();
    fprintf(f, "%f\n", stop - start);
    printf("done\n");

    i = 5000000;
    start = omp_get_wtime();
    res = eratosthenes(i);
    stop = omp_get_wtime();
    fprintf(f, "%f\n", stop - start);
    printf("done\n");

    i = 10000000;
    start = omp_get_wtime();
    res = eratosthenes(i);
    stop = omp_get_wtime();
    fprintf(f, "%f\n", stop - start);
    printf("done\n");

    i = 50000000;
    start = omp_get_wtime();
    res = eratosthenes(i);
    stop = omp_get_wtime();
    fprintf(f, "%f\n", stop - start);
    printf("done\n");

    i = 100000000;
    start = omp_get_wtime();
    res = eratosthenes(i);
    stop = omp_get_wtime();
    fprintf(f, "%f\n", stop - start);
    printf("done\n");

    i = 500000000;
    start = omp_get_wtime();
    res = eratosthenes(i);
    stop = omp_get_wtime();
    fprintf(f, "%f\n", stop - start);
    printf("done\n");

    i = 1000000000;
    start = omp_get_wtime();
    res = eratosthenes(i);
    stop = omp_get_wtime();
    fprintf(f, "%f\n", stop - start);
    printf("done\n");
    
    fclose(f);
    return 0;
}
