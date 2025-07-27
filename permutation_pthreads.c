#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int N, num_threads;
long long total = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

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

void *worker(void *arg) {
    int tid = *(int *)arg;
    long long count = 0;

    for (int i = tid; i < N; i += num_threads) {
        int *arr = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) arr[j] = j + 1;
        swap(&arr[0], &arr[i]);
        permute(arr, 1, N - 1, &count);
        free(arr);
    }

    pthread_mutex_lock(&lock);
    total += count;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    printf("Nhap N (1 <= N < 15): ");
    scanf("%d", &N);
    printf("Nhap so luong thread: ");
    scanf("%d", &num_threads);

    pthread_t threads[16];
    int ids[16];
    clock_t start = clock();

    for (int i = 0; i < num_threads; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, worker, &ids[i]);
    }
    for (int i = 0; i < num_threads; i++) pthread_join(threads[i], NULL);

    clock_t end = clock();
    printf("Tong so hoan vi: %lld\n", total);
    printf("Thoi gian chay: %.6f giay\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
