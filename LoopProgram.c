#include <stdio.h>
#include <stdlib.h>

#define N 256

int
main()
{
    static int A[N][N];
    static int B[N][N];
    static int C[N][N];

    // Initialize matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Prevent optimization removal
    printf("Result: %d\n", C[N - 1][N - 1]);

    return 0;
}
