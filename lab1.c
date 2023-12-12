#include <stdio.h>

#define N 4 // Number of columns
#define M 2 // Number of rows

void process(int n, int m, int matrix[M][N], int *result)
{
    for (int i = 0; i < m; ++i) {
        result[i] = 0;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] > 0) {
                result[i] += matrix[i][j]; // Sum only positive elements
            }
        }
    }
}

int main(int argc, char** argv)
{
    int matrix[M][N];
    int result[M];
    
    // Reading matrix values
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    process(N, M, matrix, result);

    // Printing the sum of positive elements for each row
    for (int i = 0; i < M; ++i) {
        printf("%d ", result[i]);
    }

    return 0;
}
