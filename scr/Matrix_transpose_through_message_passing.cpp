#include "iostream"
#include <mpi.h>

int main(){

int rank, N_proc;

MPI_Init(NULL,NULL);
MPI_Comm_size(MPI_COMM_WORLD, &N_proc);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);

int m, n;
m=5; n = 7;
int A[m][n], A_transpose[n][m];

MPI_Datatype send_mpi, recv_mpi;

if ( rank == 0){

for (int i = 0; i < m; i++)
 {
  for (int j =0; j< n; j++)
   {
    A[i][j] = i+j*j;
   } 
 }

std::cout << "/*** Original matrix on rank 0 ***/" << std::endl;

for (int i =0; i<m; i++){
 for (int j=0; j<n; j++){
  std::cout << A[i][j] << "   " ;
    } 
    std::cout << "\n" ;
  }

/* Send colums of the original matrix using the 
 MPI derived datatype      */

MPI_Type_vector(m, 1, n, MPI_INT, &send_mpi);
MPI_Type_commit(&send_mpi);

for ( int k = 0; k<n; k++){
MPI_Send(&A[0][k], 1, send_mpi, 1, k, MPI_COMM_WORLD);
}

}

MPI_Barrier(MPI_COMM_WORLD);

if ( rank == 1) {

/* Recive the original A matrix colums and lay it 
along the contiguous memory spaces of its transpose */

for (int k=0; k<n; k++){
MPI_Recv(&A_transpose[k][0], 5, MPI_INT, 0, k, MPI_COMM_WORLD, NULL);
}

std::cout << "/*** Transpose on rank 1 ***/" << std::endl;

for (int i =0; i<n; i++){
 for (int j=0; j<m; j++){ 
  std::cout << A_transpose[i][j] << "   " ;
    }
    std::cout << "\n" ;
  }
}

MPI_Finalize();
}
