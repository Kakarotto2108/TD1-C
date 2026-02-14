#include <stdio.h>

int addone(int x)
{
    return x + 1;
}

int fib_rec(int n)
{
    if (n <= 1)
        return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int fib_array(int n)
{
    if (n <= 1)
        return n;
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

void print_array(int tab[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("tab[%d] = %d\n", i, tab[i]);
    }
}

void somme_tableau(int tab1[], int tab2[], int tab3[], int n)
{
    for (int i = 0; i < n; i++) {
        tab3[i] = tab1[i] + tab2[i];
    }
}

void print_tableau(int tab[], int n)
{
    printf("[");
    for (int i = 0; i < n - 1; i++) {
        printf("%d, ", tab[i]);
    }
    printf("%d]\n", tab[n - 1]);
}

int nth_prime(int n)
{
    int L[7920];
    L[1] = 0;
    for (int i = 2; i < 7920; i++) {
        L[i] = 1;
    }
    for (int p = 2; p < 7920; p++) {
        if (L[p]) {
            for (int multiple = p * 2; multiple < 7920; multiple += p) {
                L[multiple] = 0;
            }
        }
    }
    for (int count = 0, i = 2; i < 7920; i++) {
        if (L[i]) {
            count++;
            if (count == n) {
                return i;
            }
        }
    }
    return -1; // In case n is too large
}


int main(void)
{
    int tab[50];
    for (int i = 0; i < 50; i++) {
        tab[i] = i*2;
    }
    printf("nth_prime(%d) = %d\n", 1000, nth_prime(1000));
    printf("nth_prime(%d) = %d\n", 100, nth_prime(100));

    return 0;
}

