#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int N, num_threads;
long long total = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Hoán đổi hai phần tử
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Sinh hoán vị từ vị trí l đến r, đếm số lượng
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

// Hàm worker cho mỗi luồng
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

// Hàm đo thời gian thực bằng clock_gettime()
double get_runtime_in_seconds(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    printf("Nhap N (1 <= N < 15): ");
    scanf("%d", &N);
    printf("Nhap so luong thread: ");
    scanf("%d", &num_threads);

    pthread_t threads[16];
    int ids[16];

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);  // Bắt đầu đo thời gian

    for (int i = 0; i < num_threads; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, worker, &ids[i]);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);  // Kết thúc đo thời gian

    double runtime = get_runtime_in_seconds(start, end);
    printf("Tong so hoan vi: %lld\n", total);
    printf("Thoi gian chay: %.6f giay\n", runtime);
    return 0;
}
