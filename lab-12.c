#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функція для введення масиву
void input_array(double *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("Введіть елемент arr[%d]: ", i);
        scanf("%lf", &arr[i]);
    }
}

// Тип вказівника на функцію (приймає double, повертає double)
typedef double (*func_ptr)(double);

// Функція для обчислення A, B, C або D
double calculate(double *arr, int n, func_ptr f1, func_ptr f2) {
    double sum1 = 0.0, sum2 = 0.0;
    for (int i = 0; i < n; i++) {
        sum1 += arr[i] * f1(arr[i]);
        sum2 += arr[i] * arr[i] * f2(arr[i]);
    }
    return sum1 + sum2;
}

// Основна функція
int main() {
    system("chcp 65001");
    int nx, ny, nz, nq;
    double *x, *y, *z, *q;

    printf("Введіть кількість елементів масиву x: ");
    scanf("%d", &nx);
    x = (double*)malloc(nx * sizeof(double));
    input_array(x, nx);

    printf("Введіть кількість елементів масиву y: ");
    scanf("%d", &ny);
    y = (double*)malloc(ny * sizeof(double));
    input_array(y, ny);

    printf("Введіть кількість елементів масиву z: ");
    scanf("%d", &nz);
    z = (double*)malloc(nz * sizeof(double));
    input_array(z, nz);

    printf("Введіть кількість елементів масиву q: ");
    scanf("%d", &nq);
    q = (double*)malloc(nq * sizeof(double));
    input_array(q, nq);

    // Обчислення A, B, C, D
    double A = calculate(x, nx, sin, cos);
    double B = calculate(y, ny, cos, sin);
    double C = calculate(z, nz, sin, sin);
    double D = calculate(q, nq, cos, cos);

    printf("\nРезультати:\n");
    printf("A = %.6f\n", A);
    printf("B = %.6f\n", B);
    printf("C = %.6f\n", C);
    printf("D = %.6f\n", D);

    // Звільнення пам'яті
    free(x);
    free(y);
    free(z);
    free(q);

    return 0;
}
