# permutation_processors
Bài tập lớn môn Lập trình song song  
## Đề bài
Viết chương trình nhập vào một số nguyên `N` (1 ≤ N < 15). Sinh ra tất cả các hoán vị của dãy số từ 1 đến `N`.

### Yêu cầu:
-  Thực hiện sinh hoán vị bằng **giải thuật tuần tự**.
-  Thực hiện sinh hoán vị **song song** bằng các kỹ thuật:
      - OpenMP
      - Pthreads
      - MPI  
-  **Khảo sát hiệu năng** của các chương trình song song với số lượng processor (threads) lần lượt là:
      - `p = 3, 5, 7, 9, 11`.  

## Nội dung báo cáo

-  **Phân tích giải thuật song song**:
  - So sánh **hiệu quả (speedup, scalability)** theo số lượng processor.
  - Đánh giá giữa **lý thuyết** và **thực nghiệm**.

-  **Giải thích kết quả thu được**:
  - Tại sao tốc độ cải thiện hoặc không?
  - Ảnh hưởng của **overhead khi tăng số threads**.

-  **Trình bày báo cáo**:
  - Đẹp, rõ ràng.
  - Có **biểu đồ thời gian**, **bảng số liệu**, và **đánh giá kết luận**.

---

## Lệnh biên dịch và chạy chương trình  
### Chạy tuần tự 
```
gcc permutation_seq.c -o permutation_seq 

.\permutation_seq.exe // chỉ chạy 1 luồng 
```  
### MPI
```
gcc -o permutation_mpi permutation_mpi.c -I"C:\Program Files (x86)\Microsoft SDKs\MPI\Include" -L"C:\Program Files (x86)\Microsoft SDKs\MPI\Lib\x64" -lmsmpi  // lệnh biên dịch với 2 path là nơi chứa thư viện MPI

mpiexec -n 5 .\permutation_mpi.exe // chỉnh số luồng bằng cách thay số vào 5
```  
### Open MP
```
gcc -fopenmp -o permutation_omp permutation_omp.c

.\permutation_omp.exe // thay số vào 1 tại phần này trong code omp_set_num_threads(1); 
```  
### Pthreads
```
gcc permutation_pthreads.c -o permutation_pthreads -lpthread

.\permutation_pthreads.exe // nhập cin
```
