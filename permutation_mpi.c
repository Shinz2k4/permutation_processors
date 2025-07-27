#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

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

int main(int argc, char *argv[]) {
    int N, rank, size;
    long long local_count = 0, global_count = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Nhap N (1 <= N < 15): ");
        fflush(stdout);
        scanf("%d", &N);
    }

    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    double start = MPI_Wtime();

    for (int i = rank; i < N; i += size) {
        int *arr = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++) arr[j] = j + 1;
        swap(&arr[0], &arr[i]);
        permute(arr, 1, N - 1, &local_count);
        free(arr);
    }

    MPI_Reduce(&local_count, &global_count, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    double end = MPI_Wtime();

    if (rank == 0) {
        printf("Tong so hoan vi: %lld\n", global_count);
        printf("Thoi gian chay: %.6f giay\n", end - start);
    }

    MPI_Finalize();
    return 0;
}
