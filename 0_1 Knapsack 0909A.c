// #include <stdio.h>
// int max(int a, int b) {
//     return (a > b) ? a : b;
// }

// void knapsack(int W, int wt[], int val[], int n) {
//     int i, j;
//     int T[n + 1][W + 1];
//     for (i = 0; i <= n; i++) {
//         for (j = 0; j <= W; j++) {
//             if (i == 0 || j == 0)
//                 T[i][j] = 0;
//             else if (wt[i - 1] <= j)
//                 T[i][j] = max( T[i - 1][j], val[i - 1] + T[i - 1][j - wt[i - 1]]);
//             else
//                 T[i][j] = T[i - 1][j];
//         }
//     }
//     printf("Maximum value Matrix:\n");
//     for (i = 0; i <= n; i++) {
//         for (j = 0; j <= W; j++) {
//             printf("%d\t", T[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\nMaximum value for a knapsack of capacity %d is %d\n", W, T[n][W]);
// }

// int main() {
//     int val[] = {3, 4, 5, 6};
//     int wt[] = {2, 3, 4, 5};
//     int W = 5;
//     int n = sizeof(val) / sizeof(val[0]);
//     knapsack(W, wt, val, n);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int W, int n, int w[], int v[], int **T) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                T[i][j] = 0;
            } else if (w[i-1] <= j) {
                T[i][j] = max(T[i-1][j], v[i-1] + T[i-1][j-w[i-1]]);
            } else {
                T[i][j] = T[i-1][j];
            }
        }
    }
}

void printMatrices(int n, int W, int **T) {
    printf("Knapsack Matrix:\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            printf("%d\t", T[i][j]);
        }
        printf("\n");
    }printf("Maximum profit is: %d",T[n][W]);
}

int main() {
    int n, W;
    printf("Enter number of items and weight limit: ");
    scanf("%d %d", &n, &W);
    int* w = (int *)malloc(n * sizeof(int));
    int* v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item(%d): ", i + 1);
        scanf("%d %d", &w[i], &v[i]);
    }
    int **T = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        T[i] = (int *)malloc((W + 1) * sizeof(int));
    knapsack(W, n, w, v, T);
    printMatrices(n, W, T);

    return 0;
}