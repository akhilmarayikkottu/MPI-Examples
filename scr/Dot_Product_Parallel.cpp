#include <mpi.h>
#include "iostream"

int main()
{
int rank, N_proc;

MPI_Init(NULL, NULL);
MPI_Comm_size(MPI_COMM_WORLD, &N_proc);
MPI_Comm_rank(MPI_COMM_WORLD, &rank  );

int N;
N = 1000;
int A[N], B[N], C, Result;
C = 0; Result = 0;

/* Local variables */
int p_Iter = N/N_proc       ;
int p_lo   = rank*p_Iter    ; 
int p_hi   = p_lo+p_Iter    ; 

for ( int i = 0  ; i < N  ; i++){
A[i] = 1 ; B[i] = i;}



for (int i = p_lo; i< p_hi ; i++){
C = C+A[i]*B[i];
} 

MPI_Allreduce(&C , &Result, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

std::cout<< "RANK : "<< rank << "   "  << C << " ---->  " << Result<< std::endl;

MPI_Finalize();
}
