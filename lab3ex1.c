#include <stdio.h>
#include <stdlib.h>

void f4(int x);
void f3(int *x);
void f2(int *x);
void f1(int x);

void f4(int x) {
    x++;
    printf("f4_v: %d , f4_a: %p\n", x, &x);
}

void f3(int *x) {
    (*x)++;
    printf("f3_v: %d , f3_a: %p\n", *x, x);
    f4(*x);
}

void f2(int *x) {
    (*x)++;
    printf("f2_v: %d , f2_a: %p\n", *x, x);
    f3(x);
}

void f1(int x) {
    x++;
    printf("f1_v: %d , f1_a: %p\n", x, &x);
    f2(&x);
}

int main() {
    int x = 0;
    x++;
    printf("Main: Valoare :%d , Adresa :%p\n", x, &x);
    f1(x);
    printf("Main final: Valoare :%d\n", x);
    return 0;
}