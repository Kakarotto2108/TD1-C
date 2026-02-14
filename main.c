#include <stdio.h>
#include <string.h>
#define N 10

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

void print_tableau(int tab[], int size)
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

void print_tableau_ligne(int tab[], int n)
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

int nb_bits(int n){
    int count = 0;
    while (n != 0){
        if (n % 2 == 1){
            count++;
        }
        n = n / 2;
    }
    return count;
}

void creer_nombre(int a[N], char *s){
    int i = 0;
    int n = strlen(s);
    while (i != N){
        if (i < n){
            a[i] = *(s + n - i - 1) - '0';
        } else {
            a[i] = 0;
        }
        i++;
    }

}

void afficher_nombre(int a[N]){
    int i = N - 1;
    while (a[i] == 0) {
        i--;
    }
    while (i >= 0){
        printf("%d", a[i]);
        i--;
    }
    printf("\n");
}

void addition_nombre(int a[N], int b[N]){
    int retenu = 0;
    for (int i = 0; i < N; i++){
        a[i] += b[i] + retenu;
        retenu = 0;
        if (a[i] >= 10){
            a[i] -= 10;
            retenu = 1;
        }
    }
}

void multiplication_nombre(int a[N], int b[N]){
    int temp[N] = {0};

    // Multiplication
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + j < N) {
                temp[i + j] += a[i] * b[j];
            }
        }
    }

    // Gestion des retenues
    for (int i = 0; i < N - 1; i++) {
        temp[i + 1] += temp[i] / 10;
        temp[i] %= 10;
    }

    // Copier dans a
    for (int i = 0; i < N; i++) {
        a[i] = temp[i];
    }
}

void soustraction_nombre(int a[N]){
    int i = 0;
    while (i < N && a[i] == 0){
        a[i] = 9;
        i++;
    }

    if (i < N){
        a[i] -= 1;
    }
}

void factorielle_nombre(int a[N], int n) {
    int b[N];
    char str1[20];

    if (n == 0) {
        creer_nombre(a, "1");
        return;
    }

    sprintf(str1, "%d", n);
    creer_nombre(a, str1);
    creer_nombre(b, str1);

    while (n > 1){
        soustraction_nombre(b);
        multiplication_nombre(a,b);
        n--;
    }
}

int main(void)
{
    int tab[50];
    for (int i = 0; i < 50; i++) {
        tab[i] = i*2;
    }
    int a[N];
    factorielle_nombre(a, 10);
    afficher_nombre(a);
    return 0;
}

