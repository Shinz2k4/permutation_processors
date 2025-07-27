#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void permute(int *arr, int l, int r, long long *count) {
    if (l == r) {
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

    int *arr = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) arr[i] = i + 1;

    long long count = 0;
    clock_t start = clock();
    permute(arr, 0, N - 1, &count);
    clock_t end = clock();

    printf("Tong so hoan vi: %lld\n", count);
    printf("Thoi gian chay: %.6f giay\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(arr);
    return 0;
}
