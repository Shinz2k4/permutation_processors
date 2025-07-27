#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void permute(int *arr, int l, int r, long long *count) {
    if (l == r) {
        #pragma omp atomic
        (*count)++;
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(&arr[l], &arr[i]);
        permute(arr, l + 1, r, count);
        swap(&arr[l], &arr[i]);
    }
}

int main() {
    int N;
    printf("Nhap N (1 <= N < 15): ");
    scanf("%d", &N);

    long long count = 0;
    double start = omp_get_wtime();
    
    omp_set_num_threads(1); 

    #pragma omp parallel for reduction(+:count) schedule(dynamic)
    for (int i = 0; i < N; i++) {
        int *arr = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) arr[j] = j + 1;
        swap(&arr[0], &arr[i]);
        permute(arr, 1, N - 1, &count);
        free(arr);
    }

    double end = omp_get_wtime();
    printf("Tong so hoan vi: %lld\n", count);
    printf("Thoi gian chay: %.6f giay\n", end - start);
    return 0;
}
