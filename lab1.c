#include <stdio.h>

#define N 4
#define M 2

void process(int n, int m, int matrix[M][N], int *result)
{
    *result = 0;  
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            *result += matrix[i][j];  
        }
    }
}

int main()
{
    int matrix[M][N];
    int result;  

    // Чтение элементов матрицы
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    process(N, M, matrix, &result);

    // Вывод результата
    printf("%d\n", result);

    return 0;
}
