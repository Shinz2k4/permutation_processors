# permutation_processors
Bài tập lớn môn Lập trình song song  
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