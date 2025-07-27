import matplotlib.pyplot as plt

# Dữ liệu số lượng luồng
threads = [3, 5, 7, 9, 11]

# Dữ liệu thời gian chạy tương ứng
time_openmp = [0.219, 0.172, 0.127, 0.117, 0.082]
time_pthreads = [0.159154, 0.121195, 0.118344, 0.116951, 0.105257]
time_mpi = [0.162197, 0.124804, 0.097196, 0.105784, 0.070094]

# Vẽ biểu đồ
plt.figure(figsize=(10, 6))
plt.plot(threads, time_openmp, marker='o', label='OpenMP')
plt.plot(threads, time_pthreads, marker='s', label='Pthreads')
plt.plot(threads, time_mpi, marker='^', label='MPI')

# Thêm tiêu đề và nhãn
plt.title('Thời gian chạy theo số luồng cho các kỹ thuật song song')
plt.xlabel('Số luồng (threads)')
plt.ylabel('Thời gian chạy (giây)')
plt.grid(True)
plt.legend()
plt.tight_layout()

# Hiển thị biểu đồ
plt.show()
